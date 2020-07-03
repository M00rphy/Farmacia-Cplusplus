#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <cstdlib>
#include <conio.h>
#include "direct.h"
#include <cctype>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <mshtml.h>

using namespace std;

float precio, aux1, precioTemp1, descuento, precioTemp2, total, precioPostDesc;
int descuentoInsen, existenciaProducto, seleccion;
string nomProducto, precioProducto, medidaProducto;
char resp, opcion;

const int NPRODUCTOS = 10;

string objetos[NPRODUCTOS] = {"AMITTRIPTILINA",
                              "PARACETAMOL",
                              "DIPIRONA",
                              "GARDENAL",
                              "NEOSALDINA",
                              "CEFALEXINA",
                              "INDOMETACINA",
                              "NIMESULIDA",
                              "MORFINA",
                              "PREDNISONA"};
string id[NPRODUCTOS] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
int precios[NPRODUCTOS] = {38, 3, 7, 11, 15, 15, 15, 98, 45, 23};
string medidas[NPRODUCTOS] = {
    "400 mg",
    "650 mg",
    "45 mg",
    "700 mg",
    "400 mg",
    "500 mg",
    "35 g",
    "700 mg",
    "1 g",
    "600 mg",
};
int existencias[NPRODUCTOS] = {8, 35, 12, 20, 13, 16, 22, 45, 6, 2};

class core
{
public:
    struct Item
    {
        string nombre;
        string id;
        int precio;
        string medida;
        int existencia;
    };

    Item *inventario = new Item[NPRODUCTOS];
    char articulo[30][100];
    int cantidad[30];
    int n;

    int fileOut(string titulo)
    {
        string nomArch = titulo + ".txt";
        ofstream myfile(nomArch.c_str());
        cout << "Archivo creado correctamente";
        return 0;
    }

    int guardar(int articulos, string compras, string titulo, string precios)
    {
        string nomArch = titulo + ".txt";
        ofstream g(nomArch.c_str());
        if (!g.is_open())
        {
            cout << "Archivo no encontrado\n";
            fileOut(titulo);
        }
        g << compras << "\n";
        g << precios << "\n";
        g.close();
        return 1;
    }

    int factura()
    {
        int cedula, factura, dinero, precio, unidad, a;
        string nombre, apellido, descripcion;

        cout << "Introduzca su Nombre y apellido seguido de un enter";
        cout << " \n";
        cin >> nombre >> apellido;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida ";
            cin >> nombre >> apellido;
        }
        cout << " \n";
        cout << "Introduzca su cedula";
        cout << " \n";
        cin >> cedula;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida ";
            cin >> cedula;
        }
        cout << " \n";
        cout << "Introduzca el numero de factura";
        cout << " \n";
        cin >> factura;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida ";
            cin >> factura;
        }
        cout << " \n";
        cout << "introduzca la descripcion o nombre del producto";
        cout << " \n";
        cin >> descripcion;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida ";
            cin >> descripcion;
        }
        cout << " \n";
        cout << "introduzca la cantidad del producto a comprar";
        cout << " \n";
        cin >> unidad;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida ";
            cin >> unidad;
        }
        cout << " \n";
        cout << "introduzca el precio";
        cout << " \n";
        cin >> precio;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida ";
            cin >> precio;
        }
        cout << " \n";
        a = unidad * precio;
        fileOut("factura");
        string nomArch = "factura.txt";
        ofstream g(nomArch.c_str());
        cout << " \n";
        cout << "Factura Numero";
        cout << " \n";
        cout << factura;
        g << factura << "\n";
        cout << " \n";
        cout << "Cliente";
        cout << " \n";
        cout << nombre << " " << apellido;
        g << nombre << " " << apellido << "\n";
        cout << " \n";
        cout << "cedula";
        cout << " \n";
        cout << cedula;
        g << cedula << "\n";
        cout << " \n";
        cout << "Su compra es";
        cout << " \n";
        cout << descripcion;
        g << descripcion << "\n";
        cout << " \n";
        cout << "Cantidad";
        cout << " \n";
        cout << unidad;
        g << unidad << "\n";
        cout << " \n";
        cout << "Precio por unidad";
        cout << "\n";
        cout << precio;
        g << precio << "\n";
        cout << " \n";
        cout << "Total a pagar";
        cout << " \n";
        cout << a;
        cout << "Pesos Mexicanos";
        g << "$" << a << "\n";
        g.close();
        mainMenu();
        return 1;
    }

    int loginReg()
    {
        system("cls");
        string
            command,
            name, password,
            inName, inPassword,
            registroName, registroPassword;
        while (1)
        {
            cout << "Inicio de sesion\n";
            cout << "(registro/salir/inicio)\n"
                 << "Opcion: ";
            getline(cin, command);
            if (command == "salir")
            {
                return 1;
            }
            if (command == "registro")
            {
                ofstream g("registration.txt");
                if (!g.is_open())
                {
                    cout << "Archivo no encontrado\n";
                    fileOut("registration");
                }
                cout << "\n\n"
                     << "New Username: ";
                getline(cin, registroName);
                cout << "New Password: ";
                getline(cin, registroPassword);
                g << registroName;
                g << '\n';
                g << registroPassword;
                g.close();
            }
            if (command == "inicio")
            {
                ifstream f("registration.txt");
                if (!f.is_open())
                {
                    cout << "Archivo no encontrado\n";
                    fileOut("registration");
                }
                getline(f, name, '\n');
                getline(f, password, '\n');
                f.close();

                while (1)
                {
                    cout << "\n"
                         << "Ingresa Usuario: ";
                    getline(cin, inName);
                    cout << "\n"
                         << "Ingresa Contrasena: ";
                    getline(cin, inPassword);
                    if (inName == name && inPassword == password)
                    {
                        cout << "Bienvenido, "
                             << inName;
                        mainMenu();
                        break;
                    }
                    cout << "usuario o contrasena incorrecta\n";
                }
            }
            cout << "\n\n";
        }
        return 1;
    }

    int almacen()
    {
        //Cada vez que venda un articulo, vaya restando de la existencia. En caso de no haber articulos en existencia, no puede realizar la venta.
        //vamos a tener  3 productos, pero si quieres mas aumente NPRODUCTOS y agregalos abajo
        bool salir = false;
        //Item inventario[NPRODUCTOS];

        queue<Item> cola; //COLA del tipo de Item "INFINITA", o al menos mientras tengas memoria
        while (!salir)
        { //mientras no queremos salir
            int opcion = 0;
            string producto;

            system("cls");
            cout << "Entre con el nombre o ID del producto. Pulse 0 para salir"
                 << endl; // Escriba el producto tal cual esta en la lista Item especificada arriba.
            cin >> producto;

            if (producto != "0")
            {
                //opcion = 1;
                articulos();
            }
            else
            {
                opcion = 0;
            }

            bool encontrado = false;
            switch (opcion)
            {
            case 1:
                encontrado = false;
                //miramos si el producto esta en la lista de items antes de añadir a la cola
                for (int i = 0; i < NPRODUCTOS; i++)
                {
                    //Si esta en la lista
                    if (producto == inventario[i].id || producto == inventario[i].nombre)
                    {
                        encontrado = true;
                        cout << inventario[i].nombre << " " << inventario[i].precio << inventario[i].medida
                             << inventario[i].existencia << endl;
                        cola.push(inventario[i]);
                        nomProducto = inventario[i].nombre;
                        precioProducto = inventario[i].precio;
                        medidaProducto = inventario[i].medida;
                        existenciaProducto = inventario[i].existencia;
                        system("cls");
                        articulos();
                        break;
                    }
                }
                //Si no esta en la lista decimos que nanain XD
                if (encontrado == false)
                {
                    cout << "Producto inexistente" << endl;
                    system("pause>null");
                }
                break;
            case 0:
                cout << "Compra terminada." << endl;
                salir = true;
                break;
            }
            system("pause");
        }
        //ahora en esta parte se imprime la lista completa de productos sin importar cuantos sean.
        Item itemPrint;
        while (!cola.empty())
        { //mientras la cola no este vacia...
            itemPrint = cola.front();

            cout << itemPrint.nombre << endl; //Imprimimos el producto
            cola.pop();                       //Sacamos el producto de la cola.
        }
        cin.ignore();
        return 0;
    }

    void mainMenu()
    {

        //Utilice un menu para poder navegar entre las diferentes opciones y pantalla del sistema.

        int selec;

        opcion = 'n';
        system("cls");
        while (opcion == 'n')
        {
            printf("Menu principal\n");
            printf("\n");
            printf("1: Comprar medicamentos\n");
            printf("2: Facturacion\n");
            printf("3: almacen\n");
            printf("4: Busca un articulo\n");
            printf("5: Captura Vendedores \n");
            printf("Seleccion:");
            cin >> selec;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Respuesta no valida ";
                cin >> selec;
            }
            switch (selec)
            {
            case 1:
                opcion = 's';
                system("cls");
                menuCompra();
                break;
            case 2:
                opcion = 's';
                system("cls");
                factura();
                break;
            case 3:
                opcion = 's';
                system("cls");
                almacen();
                break;
            case 4:
                opcion = 's';
                system("cls");
                capturaArt();
                break;
            case 5:
                opcion = 's';
                system("cls");
                vendedores();
                break;
            }
        }
    }

    void menuCompra()
    {

        string compra = "", med = "", precioStr = "";
        char desc;
        int arts = 0, contador = 1, tempDesc = 0, tempex = 0;
        int existenciaC[NPRODUCTOS];
        for (int i = 0; i < NPRODUCTOS; i++)
        {
            existenciaC[i] = existencias[i];
        }

        descuentoInsen = 0;

        descuento = 0;
        precioTemp2 = 0;

        opcion = 'n';
        while (opcion == 'n')
        {
            system("cls");
            printf("=====================================================================================\n");
            printf("==FARMACIA ONLINE== VALOR TOTAL DE TU COMPRA CON DESCUENTO:  %.2f", descuento);
            printf("\n=====================================================================================\n");
            articulos();
            printf("=====================================================================================\n");
            printf("ID del medicamento:");
            cin >> seleccion;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Respuesta no valida ";
                cin >> seleccion;
            }

            switch (seleccion)
            {
            case 1:
                precio = 38, 99;
                med = "AMITTRIPTILINA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 2:
                precio = 3, 99;
                med = "PARACETAMOL";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 3:
                precio = 7, 99;
                med = "DIPIRONA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 4:
                precio = 11, 99;
                med = "GARDENAL";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 5:
                precio = 15, 99;
                med = "NEOSALDINA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 6:
                precio = 15, 99;
                med = "CEFALEXINA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 7:
                precio = 15, 99;
                med = "INDOMETACINA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 8:
                precio = 98, 99;
                med = "NIMESULIDA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 9:
                precio = 45, 99;
                med = "MORFINA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            case 10:
                precio = 23, 99;
                med = "PREDNISONA";
                printf(("MEDICAMENTO: " + med + "\n").c_str());
                printf("precio: ");
                printf("%.2f", precio);
                break;
            }
            arts++;

            int i = seleccion;
            tempex = existenciaC[i];
            tempex--;
            existenciaC[i] = tempex;

            existencias[i] = existenciaC[i];

            stringstream cont;

            cont << contador;
            compra += cont.str();
            compra += ": ";
            compra += med;
            compra += "/ ";

            precioTemp1 = precio;
            precioTemp2 = precio;
            aux1 = precio * descuentoInsen / 100;
            precioPostDesc = precioTemp1 - aux1;

            total += precioTemp2;
            descuento += precio;

            stringstream ss;

            ss << precioTemp1;

            precioStr += cont.str();
            precioStr += ": ";
            precioStr += ss.str();
            precioStr += "/ ";

            printf("================================\n");
            printf("====== COMPRA ======   VALOR TOTAL DE COMPRA:  %.2f", descuento);
            printf("\n================================\n");

            printf("\n");
            printf("precio A PAGAR: ");
            printf("%.2f", precioPostDesc);
            printf("\n================================");
            printf("\n");
            printf("FINALIZAR A COMPRA(s/n)?");
            cin >> opcion;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Respuesta no valida";
                cin >> opcion;
            }
            printf("================================");
            if (opcion == 's')
            {
                break;
            }
            contador++;
        }
        printf("\n");
        printf("TU PAGO SERA DE CONTADO(s/n)?");
        cin >> desc;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida";
            cin >> desc;
        }
        printf("\n================================\n");
        if (desc == 's')
        {
            tempDesc = 10;
        }
        else
        {
            tempDesc = 0;
        }
        descuentos(arts, resp, tempDesc);
        guardar(arts, compra, "compra", precioStr);
        printf("================================\n");
        printf("===Agradecemos su Preferencia!===\n");
        printf("================================\n");
        printf("================================\n");
        printf("TOTAL DE SU COMPRA: R$ %.2f", total);
        printf("\n================================\n");
        printf("TOTAL A PAGAR: R$ %.2f", descuento);
        printf("\n================================\n");
    }

    void descuentos(int articulos, char resp, int descSec)
    {
        //En caso de que la compra sea de contado, se le hara un 10% de descuento.

        //Solamente los medicamentos se aplica el descuento del INCEN, esto es, si el cliente de la 3 edad compra 3 medicamentos, 2 dulces, solamente el descuento sera valido or los 3 medicamentos.

        printf("ES MAYOR DE 68 ANOS?");
        cin >> resp;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Respuesta no valida";
            cin >> resp;
        }
        if (resp == 's' && articulos >= 3)
        {
            descuentoInsen = 10;
            descuentoInsen += descSec;
            int temp = total * descuentoInsen / 100;
            descuento = total - temp;
            printf("DESCUENTO APLICADO!\n");
        }
        else
        {
            descuentoInsen = 0;
            descuentoInsen += descSec;
            int temp = total * descuentoInsen / 100;
            descuento = total - temp;
        }
    }

    int capturaArt()
    {
        //Crear una opcion para la captura de la clave del articulo, nombre del medicamento, nombre generico, precio de costo, precio de venta, y articulos en existencia.
        string claveArt, nomMed, nomGen, pCosto, pVenta;
        int existencia;

        int opc; //Declaración de variable de tipo entero

        do
        {
            system("cls");
            cout << "\t Inventario" << endl
                 << endl
                 << endl;
            cout << "MENU" << endl
                 << endl;
            cout << " 1. Registrar articulos. " << endl;
            cout << " 2. Ver lista de articulos. " << endl;
            cout << " 3. Consultar articulos en 0 de existencias. " << endl;
            cout << " 4. Salir. " << endl;
            cout << endl
                 << endl
                 << " Por favor eleja una de las opciones: " << endl
                 << endl;
            cin >> opc;
            switch (opc)
            {
            case 1:
                system("cls");
                cout << endl
                     << "1. Registrar articulo " << endl;
                registrararticulocantidad();
                system("pause"); //Detiene la ejecución del programa hasta que el usuario digite una tecla
                break;
            case 2:
                system("cls");
                cout << endl
                     << "2. Ver lista de articulos. " << endl;
                listardatos();
                system("pause"); //Detiene la ejecución del programa hasta que el usuario digite una tecla
                break;
            case 3:
                system("cls");
                cout << endl
                     << " 3. Consultar articulos en 0 de existencias. " << endl;
                //mostrarexistenciascero();
                buscar();
                //cout<<"\n no hay exitencias en cero "<<endl<<endl;
                system("pause"); //Detiene la ejecución del programa hasta que el usuario digite una tecla
                break;
            default:
                break;
            }
        } while (opc != 4);
        cout << endl
             << endl;
        system("pause"); //Detiene la ejecución del programa hasta que el usuario digite una tecla
        return 0;
    }

    int vendedores()
    {
        //Crear una opcion para la captura de las claves de los vendedores y sus respectivos nombres.

        string vendedor;
        string clave;

        printf("CUAL ES TU NOMBRE?\n");
        cin >> vendedor;
        printf("INGRESA TU CLAVE\n");
        cin >> clave;

        string nomArch = "vendedores.txt";
        ofstream g(nomArch.c_str());
        if (!g.is_open())
        {
            cout << "Archivo no encontrado\n";
            fileOut(nomArch);
        }
        g << vendedor << "\n";
        g << clave << "\n";
        g.close();
        return 1;
    }

    void consultas()
    {
        /*
         Crear un modulo de consulta que contenga:
    a. Total de las ventas realizadas.
	b. El numero de clientes atendidos
	c. El Total de descuento aplicado
	d. El total de articullos vendidos
	e. El total de medicamentos vendidos.
	f. Consulta de los articulos mas vendidos
	g. Consulta de los articulos menos vendidos.
	h. Promedio de ventas realizadas.
	i. Consulta de los vendedores con mas ventas
	j. Consulta de los vendedores con menos ventas (1) Las consultas y/o reportes se visualizan en pantalla.
         * */
    }

    void ventaArticulos()
    {
        //Crear un modulo de venta del articulo. Cuando capture la clave del articulo devera� de aparecer automaticamente. los datos respectivos de cada articulo, porque previamente ud los capturo en un arreglo.
    }

    void impresionTotal()
    {
        //Imprima el total a pagar con la leyenda en letras, con vectores referenciados.
    }

    void articulos()
    {

        for (int i = 0; i < NPRODUCTOS; ++i)
        {
            inventario[i].nombre = objetos[i];
            inventario[i].id = id[i];
            inventario[i].precio = precios[i];
            inventario[i].medida = medidas[i];
            inventario[i].existencia = existencias[i];
        }
        imprimirArt("inventario");
    }

    int imprimirArt(string titulo)
    {
        /*
        string nomArch = titulo + ".txt";
        ofstream g(nomArch.c_str());
        if (!g.is_open())
        {
            cout << "Archivo no encontrado\n";
            fileOut(titulo);
        }
        */
        for (int i = 0; i < NPRODUCTOS; ++i)
        {
            cout << " || "
                 << "Nombre: " << inventario[i].nombre << " || "
                 << " id: " << inventario[i].id << " || "
                 << " Precio: " << inventario[i].precio << " || "
                 << " Medida: " << inventario[i].medida << " || "
                 << " Existencia: " << inventario[i].existencia << " || " << endl;
            /*
            g << " || "
              << "Nombre: " << inventario[i].nombre << " || "
              << " id: " << inventario[i].id << " || "
              << " Precio: " << inventario[i].precio << " || "
              << " Medida: " << inventario[i].medida << " || "
              << " Existencia: " << inventario[i].existencia << " || " << endl;
              */
        }
        //g.close();
        return 1;
    }

    void registrararticulocantidad() //Funcion que permite registrar los articulos y su cantidad
    {
        int i;
        int j;
        int rta;

        system("cls");
        //Inicializo los arreglos
        cout << " Por favor escriba la cantidad de articulos que desea ingresar " << endl
             << endl;
        cin >> n;
        for (i = 1; i < n + 1; i++)
        {
            cantidad[i] = 0;
            for (j = 1; j < n + 1; j++)
                strcpy(articulo[i], " ");
        }
        cout << endl
             << " Registrar articulos " << endl;
        for (i = 1; i < n + 1; i++)
        {
            cout << endl
                 << " digite el articulo, presione enter " << endl
                 << endl;
            cout << " Articulo " << i << " ";
            cin >> articulo[i];
            cout << endl
                 << " digite la cantidad de este articulo " << endl
                 << endl;
            cout << " cantidad " << i << " ";
            cin >> cantidad[i];
            rta = strcmp(articulo[i - 1], articulo[i]); //compara las cadenas
            if (rta == 0)
            {
                cout << "\n Articulo ya existe, por favor ingrese otro diferente \n";
                for (i = i; i < n + 1; i++)
                {
                    cout << " Articulo " << i << " ";
                    cin >> articulo[i];
                    cout << endl
                         << " digite la cantidad de este articulo " << endl
                         << endl;
                    cout << " cantidad " << i << " ";
                    cin >> cantidad[i];
                    cout << endl;
                }
            }
        }

        system("pause");
    }

    void listardatos() //Funcion que muestra los datos ingresados
    {
        int i;

        system("cls");
        cout << endl
             << " Listar los datos ingresados " << endl
             << endl;
        for (i = 1; i < n + 1; i++)
        {
            cout << " articulo " << i << " " << articulo[i] << endl
                 << " cantidad " << i << " " << cantidad[i] << endl;
        }
    }

    void buscar()
    {
        int i;
        //char j='n';
        int acum = 0;
        int valor = 0; // Variable para el ciclo

        for (i = 1; i < n + 1; i++)
        {
            if (valor == cantidad[i]) // condicional para encontrar el elemento
            {
                cout << " los articulos con exitencias en cero son articulo " << i << " " << articulo[i];
                cout << " cantidad " << i;
                cout << endl;
            }
        }

        for (i = 1; i < n + 1; i++)
        {
            if (valor != cantidad[i]) // condicional para encontrar el elemento
            {
                // j='s';
                acum++;
            }
        }
        if (acum == n)
            cout << "\n no hay existencias en cerooooo " << endl
                 << endl;
        //if(j=='s')cout<<"\n no hay exitencias en cero "<<endl<<endl;
    }
};

int main(int argc, char **argv)
{
    system("Color 1F");

    core meds;
    meds.loginReg();
}
