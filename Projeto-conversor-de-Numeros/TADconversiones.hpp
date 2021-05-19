
#include<iostream>
#include<conio.h>

using namespace std;

struct Nodo
{
    int valor;
    Nodo*sgte;
};

void agregarALista(int valor1,Nodo*&inicio)
{
    Nodo*nuevo = new Nodo();
    nuevo->valor=valor1;
    nuevo->sgte=NULL;
    if(!inicio)
        inicio=nuevo;
    else
    {
        nuevo->sgte=inicio;
        inicio=nuevo;
    }
}

void conversorDeBases(int valor,int base,Nodo*&inicio)
{
    int valor1=0;
    while(valor>=base)
    {
        valor1 = valor%base;
        agregarALista(valor1,inicio);
        valor = valor/base;
    }
    agregarALista(valor,inicio);
}

char menuPrincipal(Nodo*&inicio)
{
    char opcion;
    cout<<" ============================================================================== "<<endl;
    cout<<"                  ********* CONVERSOR DE NUMERO ********** "<<endl;
    cout<<"                       *** DIGITE UNA OPCION ***                       "<<endl;
    cout<<" 1 - BINARIO."<<endl;
    cout<<" 2 - OCTAL."<<endl;
    cout<<" 3 - HEXADECIMAL."<<endl;
    cout<<" 4 - salir."<<endl;
    cout<<" ============================================================================== "<<endl<<endl;
    do
    {
        opcion = getch();
    }
    while(!(opcion>='1' && opcion<='4'));

    system("cls");
    int valor;

    switch(opcion)
    {
    case '1':
    {
        cout<<" DIGITE O VALOR A CONVERTER A BINARIO. "<<endl;
        cin>>valor;
        conversorDeBases(valor,2,inicio);
        system("cls");
        Nodo*aux=inicio;
        cout<<" ================================ CONVERSOR ==========================="<<endl;
        cout<<endl<<" O NUMERO "<<valor<<" CONVERTIDO A BINARIO ES ";
        while(aux)
        {
            cout<<aux->valor;
            aux = aux->sgte;
        }
    }
    break;
    case '2':
    {
        cout<<" DIGITE O VALOR A CONVERTER A OCTAL. "<<endl;
        cin>>valor;
        conversorDeBases(valor,8,inicio);
        system("cls");
        Nodo*aux=inicio;
        cout<<" ================================ CONVERSOR ==========================="<<endl;
        cout<<endl<<" EL NUMERO "<<valor<<" CONVERTIDO A OCTAL ES ";
        while(aux)
        {
            cout<<aux->valor;
            aux = aux->sgte;
        }
    }
    break;
    case '3':
    {
        cout<<" DIGITE O VALOR A CONVERTER A HEXADECIMAL. "<<endl;
        cin>>valor;
        conversorDeBases(valor,16,inicio);
        system("cls");
        Nodo*aux= inicio;
        cout<<" ================================ CONVERSOR ==========================="<<endl;
        cout<<endl<<" O NUMERO "<<valor<<" CONVERTIDO A HEXADECIMAL E : ";

        while(aux)
        {
            int valor2=aux->valor;
            if(valor2>=10)
            {
                switch(valor2)
               {
                 case 10:
                    cout<<"A";
                    break;
                 case 11:
                    cout<<"B";
                    break;
                 case 12:
                    cout<<"C";
                    break;
                 case 13:
                    cout<<"D";
                    break;
                 case 14:
                    cout<<"E";
                    break;
                 case 15:
                    cout<<"F";
                    break;
                 }
              }
               else
                 cout<<aux->valor;
            aux=aux->sgte;
        }
    }

    break;
    }
    cout<<endl<<endl;
    system("pause");
    system("cls");

    return opcion;
}

void limparLista(Nodo*&inicio)//GERENCIMENTO DE MEMORIA, PARA NÃO GERAR MEMORY LICKS
{
    while(inicio)
    {
        Nodo*aux=inicio;
        inicio=inicio->sgte;
        delete aux;
    }
}

