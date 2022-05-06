#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main()
{
    int opc;
    do{
        opc = menuInicial();
        switch (opc)
        {
            case 1:
                menuCliente();
            break;
            case 2:
                menuGerente(); 
            break;
            case 3: 
                menuRepartidor();
            break;
            case 4: 
                menuAlmacenista();
            break;
        }
        system("cls");
    }while(opc != 5);
}
