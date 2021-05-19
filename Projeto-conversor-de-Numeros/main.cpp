#include <iostream>
#include"TADconversiones.hpp"

using namespace std;

int main()
{
    Nodo*inicio = NULL;
    char opcion;
    do
    {
       opcion = menuPrincipal(inicio);
       limparLista(inicio);
    }while(opcion!='4');
    cout<<" GRACIAS "<<endl;
    return 0;
}
