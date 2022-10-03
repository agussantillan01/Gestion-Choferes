#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
class Examen{
public:
    void punto1();
    void punto2();
    void punto3();
    void punto4();

};
//PUNTO 1
bool CancelacionDeViajes (int ID);
//PUNTO 2
int usuarioIngresaID ();
int cuentaViajes (int ID);
int cuentaCancelaciones (int ID);
float calculoPorcentajeCancelado (int cantidadViajesCancelados, int cantidadViajes);

//PUNTO 3
float acumuloImportePorCliente(int dni);

#endif // EXAMEN_H_INCLUDED
