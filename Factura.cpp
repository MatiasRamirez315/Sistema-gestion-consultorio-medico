#include "Factura.h"
#include "Validaciones.h"
#include "ArchivoFacturas.h"
#include "ArchivoTurnos.h"
#include "ArchivoPaciente.h"

using namespace std;

void Facturas::setIdFactura(int idFac){
    _idFactura = idFac;
}

void Facturas::setIdTurno(int idTurno){
    _idTurno = idTurno;
}

void Facturas::setFecha(Fecha fecha){
    _fecha.setAnio(fecha.getAnio());
    _fecha.setMes(fecha.getMes());
    _fecha.setDia(fecha.getDia());
}

void Facturas::setImporte(float importe){
    _importe = importe;
}

void Facturas::setPagado(bool pagado){
    _pagado = pagado;
}

void Facturas::setEstado(bool estado){
    _estado = estado;
}

int Facturas::getIdFactura(){
    return _idFactura;
}

int Facturas::getIdTurno(){
    return _idTurno;
}

Fecha Facturas::getFecha(){
    return _fecha;
}

float Facturas::getImporte(){
    return _importe;
}

bool Facturas::getPagado(){
    return _pagado;
}

bool Facturas::getEstado(){
    return _estado;
}

void Facturas::Cargar(int idTurno){
    bool confirma;
    Facturas factura;
    ArchivoFacturas archivo;
    bool ok;

    cout << "Facturando turno " << idTurno << "..." << endl;
    factura.setIdTurno(idTurno);
    cout << "ID de la factura: ";
    factura._idFactura = archivo.getNuevoId();
    cout << factura._idFactura << endl;


    do{
    factura._fecha.CargarFecha();
    ok = FechaMayorIgualActual(factura._fecha);

    if (ok == false){
        cout << "ingrese una fecha valida.. " << endl;
    }

    }while (ok == false);
    cout << "Ingrese el importe: ";
    factura._importe = obtenerEnteroValidado("");
    cout << "Confirme si ya esta pagada. 1-Si 0-No: ";
    factura._pagado = obtenerBooleanoValidado("");
    cout << "Desea confirmar los datos? 1-Si 0-No: ";
    confirma = obtenerBooleanoValidado(" ");

    factura.setEstado(true);

    archivo.guardar(factura);
}

bool Facturas::TurnoYaFacturado(int idTurno){
    Facturas factura;
    ArchivoFacturas archivo;
    int cantFacturas = archivo.contarRegistros();

    for (int i=0; i<cantFacturas; i++){
        factura = archivo.leer(i);
        if (factura.getIdTurno() == idTurno && factura.getEstado()){
            cout << "El turno seleccionado ya fue facturado..." << endl;
            return true;
        }
    }
    return false;
}

void Facturas::Mostrar(){
    cout << "ID Factura: " << _idFactura << endl;
    cout << "Fecha de la factura: " << _fecha.toString() << endl;
    cout << "Importe de la factura: " << _importe << endl;
    if (_pagado == true){
        cout << "Factura pagada." << endl;
    }
    else{
        cout << "Factura no pagada." << endl;
    }
    if(_estado == true){
        cout << "Estado de la factura: Activa" << endl;
    }
    else{
        cout << "Estado de la factura: Inactiva" << endl;
    }

    ArchivoTurnos arcTurnos;
    int posT = 0;
    posT = arcTurnos.BuscarPosXID(_idTurno);
    Turnos turno = arcTurnos.leer(posT);

    ArchivoPaciente arcPacientes;
    int posP = 0;
    posP = arcPacientes.BuscarPosXID(turno.getIdPaciente());
    Paciente paciente = arcPacientes.leer(posP);

    cout << "Paciente facturado: " << endl;
    paciente.MostrarPaciente();

    cout << "-----------------------------" << endl;
}
