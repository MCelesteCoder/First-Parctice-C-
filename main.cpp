/*

Autora : Mar�a Celeste Uma�a Castro.
Fecha: 3er Cuatrimestre del 2023
Descripci�n: Programa para el ingreso de frases, contabilizacion de estas, adem�s de las vocales en estas mismas.

Referencias:

1. ALGORITMODETAREA (17 feb del 2014). Contar las vocales de una palabra en c++.
https://www.youtube.com/watch?v=NfycdcdWCUY&t=227s

2. Programaci�n ATS.(5 nov del 2015). 63. Programaci�n en C++ || Funciones || Definici�n de Funciones.
https://www.youtube.com/watch?v=vLZymLKd6Mo

3.Deitel, P. J., Deitel, H.  (2021). C�mo programar en C++. [[VitalSource Bookshelf version]].  Retrieved from vbk://9786073255424

4. Todo programador.(23 feb del 2020). Variables de tipo cadena - Entrada de datos con espacios; en lenguaje C++.
https://www.youtube.com/watch?v=l_YFaCmbois

5.Programaci�n ATS.(5 nov del 2015).68. Programaci�n en C++ || Funciones || Paso de par�metros por Referencia.
https://www.youtube.com/watch?v=XNXdytXmYVM
*/

#include <iostream>
#include <locale>
#include <string>

using namespace std;
// Declaraci�n de la funci�n preguntaMenu.
void preguntaMenu(char &respuesta);

int main()
{
    // Declaraci�n e iniciaci�n de las variables.
    int opcion;
    char respuesta;
    string frase;
    int caracteres = 100;
    int frasesContabilizadas = 0;
    int vocalesContabilizadas = 0;
    int vocalesFrase = 0;

    //
    setlocale(LC_ALL, "spanish"); // Configuraci�n regional en espa�ol.

    do
    {
        system("cls");
        cout << "Cuenta Vocales" << endl;
        cout << "\n";
        cout << "[1] Ingresar frase a trabajar" << endl;
        cout << "[2] Contar vocales" << endl;
        cout << "[3] Resultados" << endl;
        cout << "[4] Salir del Programa" << endl;
        cout << "\n";

        cout << "Opci�n que desea seleccionar: ";
        cin >> opcion;
        cin.ignore(); // Referencia 4. Se utiliza para limpiar el b�fer de entrada despu�s de leer un valor con "cin >>".

        switch (opcion)
        {
        case 1:
            do
            {
                system("cls");
                cout << "Ingrese una frase de no m�s de 100 car�cteres: " << endl;
                getline(cin, frase); // Referencia 4. Se limpia el b�fer del teclado.Incluye la lectura de espacios en blanco y signos.

                ++frasesContabilizadas;

                /*Referencia 1.Recorre toda la frase letra por letra y si hay coincidencias con la condicional
                la variable vocalesContabilizadas aumenta.*/
                for (int i = 0; i < frase.length(); i++)
                {
                    char vocal = tolower(frase[i]); // Referencia 3. Convertir a min�scula para crear la comparaci�n.
                    switch (vocal)
                    {
                    case 'a':
                    case '�':
                        vocalesContabilizadas++;
                        break;
                    case 'e':
                    case 'é':
                        vocalesContabilizadas++;
                        break;
                    case 'i':
                    case 'í':
                        vocalesContabilizadas++;
                        break;
                    case 'o':
                    case 'ó':
                        vocalesContabilizadas++;
                        break;
                    case 'u':
                    case 'ú':
                        vocalesContabilizadas++;
                        break;
                    }
                }
                // Referencia 3. La funci�n length obtiene la cantidad de elementos que posee la variable frase y la compara con la viable caracteres.
                if (frase.length() > caracteres)
                {
                    system("cls");
                    cout << "Cantidad de car�cteres m�ximo excedido. intentelo de nuevo..." << endl;
                    cout << "Intentelo de nuevo..." << endl;
                    system("pause");
                }
                else
                {
                    preguntaMenu(respuesta); // Se llama a la funcion preguntaMenu
                }

            } while (respuesta != 'S');
            break;

        case 2:
            system("cls");
            cout << "     TEXTO:" << endl;
            cout << "       " + frase << endl;
            cout << "\n";
            cout << "TOTAL GENERAL DE VOCALES:   ";

            vocalesFrase = 0;

            // Referencia 1. Al estar fuera del ciclo Do-While la variable frase solo contiene la ultima frase.
            for (int i = 0; i < frase.length(); i++)
            {
                char vocal = tolower(frase[i]); // Referencia 3. Convertir a min�scula para crear la comparaci�n.
                switch (vocal)
                {
                case 'a':
                case 'á':
                    vocalesFrase++;
                    break;
                case 'e':
                case 'é':
                    vocalesFrase++;
                    break;
                case 'i':
                case 'í':
                    vocalesFrase++;
                    break;
                case 'o':
                case 'ó':
                    vocalesFrase++;
                    break;
                case 'u':
                case 'ú':
                    vocalesFrase++;
                    break;
                }
            }
            cout << vocalesFrase << endl;
            preguntaMenu(respuesta);
            break;

        case 3:
            system("cls");
            cout << "Resultados" << endl;
            cout << "\n";
            cout << "Total de frases analizadas: ";
            cout << frasesContabilizadas << endl;
            cout << "Total de vocales contabilizadas: ";
            cout << vocalesContabilizadas << endl;
            preguntaMenu(respuesta);
            break;

        case 4:
            system("cls");
            cout << "Saliendo del Programa..." << endl;
            break;

        default:
            system("cls");
            cout << "Opci�n inv�lida, vuelva a intentarlo" << endl;
            break;
        }
        cout << "\n";
        system("pause");

    } while (opcion != 4);

    return 0;
}

// Definici�n de la funci�n preguntaMenu.Referencia 2
void preguntaMenu(char &respuesta) // Referencia 5. El '&' indica que respuesta es una referencia por lo que puede ser modificada en el main.
{
    cout << "\n";
    cout << "Desea regresar al men� principal (S/N): ";
    cin >> respuesta;
    cin.ignore();
    respuesta = toupper(respuesta); // Referencia 3. convierte la letra a mayuscula
    if (respuesta == 'S')
    {

        cout << "Volviendo al men� principal..." << endl;
    }
    else if (respuesta != 'N' && respuesta != 'S')
    {
        system("cls");
        cout << "Por favor ingrese 'S' o 'N'." << endl;
        cout << "\n";
        cout << "Desea regresar al men� principal (S/N): ";
        cin >> respuesta;
        cin.ignore();
    }
    else
    {
        cout << "Lea tranquilamente la informaci�n brindada.";
        cout << "Para continuar es necesario volver al menu principal..." << endl;
    }
}
