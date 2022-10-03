#include <iostream>
#include <cstdlib>
#include "Examen.h"
#include "Chofer.h"
#include "FechaHora.h"
#include "Viaje.h"

using namespace std;
void Examen::punto1(){
Chofer reg;
int pos=0;
bool leCancelaron;
int cChoferes=0;
while (reg.LeerDeDisco(pos)){
    leCancelaron= CancelacionDeViajes (reg.getID());
    if (leCancelaron){
        cChoferes++;
    }
    pos++;
}
cout << cChoferes<< " choferes le cancelaron viajes."<<endl;
}

bool CancelacionDeViajes (int ID){
Viaje reg;
int pos=0;
while (reg.LeerDeDisco(pos)){
    if (reg.getIDChofer()==ID){
    if (reg.getCancelado()==true){
        return true;
    }
    }

    pos++;
}
return false;
}

///*********PUNTO 2 ***************

void Examen::punto2(){
Chofer reg;
int pos=0;
int cantidadViajes, cantidadViajesCancelados,cantidadViajesNoCancelados;
bool seEncontroChofer=false;
int numeroUsuario;
numeroUsuario= usuarioIngresaID();
while (reg.LeerDeDisco(pos)){
    if (reg.getID()== numeroUsuario){
        cantidadViajes = cuentaViajes (reg.getID());
        cantidadViajesCancelados= cuentaCancelaciones (reg.getID());
        cout << "ES CORRECTO EL ID"<<endl;
        seEncontroChofer=true;
    }
pos++;
}
if (seEncontroChofer == false){
    cout << "NO SE ENCONTRO ID"<<endl;
}else {
//cantidadViajesNoCancelados= cantidadViajes - cantidadViajesCancelados;
float porcentajeCancelado = calculoPorcentajeCancelado (cantidadViajesCancelados, cantidadViajes);
float porcentajeNoCancelado = 100-porcentajeCancelado;
cout << porcentajeCancelado <<" % Cancelados"<<endl;
cout << porcentajeNoCancelado << " % no cancelados"<<endl;
}
}
int usuarioIngresaID (){
int n;
cout << "DIGITE EL ID DE CHOFER: ";
cin >> n;
while (n<0){
    cout << "NUMERO INCORRECTO."<<endl<< "INGRESE NUEVAMENTE: ";
    cin >> n;
}
return n;
}


int cuentaViajes (int ID){
Viaje reg;
int pos=0;
int cViajes=0;
while (reg.LeerDeDisco(pos)){
    if (reg.getIDChofer()== ID){
        cViajes++;
    }

    pos++;
}
return cViajes;
}


int cuentaCancelaciones (int ID){
Viaje reg;
int pos=0;
int cCancelado=0;
while (reg.LeerDeDisco(pos)){
    if (reg.getIDChofer()==ID){
        if (reg.getCancelado()==true){
            cCancelado++;
        }

    }
    pos++;
}
return cCancelado;
}


float calculoPorcentajeCancelado (int cantidadViajesCancelados, int cantidadViajes){
float por;
por = float(cantidadViajesCancelados *100)/cantidadViajes;
return por;
}
///*********PUNTO 3 ***************
void Examen::punto3(){
Viaje reg;
int pos=0;
float imp;
while (reg.LeerDeDisco(pos)){
    if (reg.getCancelado()==false){
        imp= acumuloImportePorCliente (reg.getDNI());
        if (imp>25000){
            cout << reg.getDNI()<<endl;
        }
    }
    pos++;
}
}
float acumuloImportePorCliente(int dni){
Viaje reg;
int pos=0;
float imp=0;
while (reg.LeerDeDisco(pos)){
    if (reg.getDNI()==dni){
        imp+=reg.getImporte();
    }

    pos++;
}
return imp;
}

///*********PUNTO 4 ***************
void Examen::punto4(){
Viaje reg;
int pos=0;
int cViajesPrimerSemestre=0,cViajesSegundoSemestre=0;
while (reg.LeerDeDisco(pos)){
    if (reg.getFechaHora().getAnio()==2021){
        if (reg.getKms()>100){
            if (reg.getFechaHora().getHora()>=20 && reg.getFechaHora().getHora()<=23){
                if (reg.getFechaHora().getMes()<=6){
                cViajesPrimerSemestre++;
                }
                else {
                    cViajesSegundoSemestre++;
                }
            }
        }
    }


    pos++;
}
if (cViajesPrimerSemestre==0){
    cout << "NO SE SOLICITARON VIAJES ENTRE LAS 20 Y 23 EL ANIO 2021 EN EL PRIMER SEMESTRE"<<endl;
}else {
cout << " EN EL PRIMER SEMESTRE SOLICITARON "<<cViajesPrimerSemestre << " ENTRE LAS 20 Y 23 HS DEL ANIO 2021" <<endl;
}
if (cViajesSegundoSemestre==0){
    cout << "NO SE SOLICITARON VIAJES ENTRE LAS 20 Y 23 EL ANIO 2021 EN EL SEGUNDO SEMESTRE"<<endl;
}
else {
cout << " EN EL SEGUNDO SEMESTRE SOLICITARON "<<cViajesSegundoSemestre << " ENTRE LAS 20 Y 23 HS DEL ANIO 2021" <<endl;
}
}




