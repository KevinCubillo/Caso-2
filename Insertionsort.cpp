#include <iostream>
#include <math.h>
#include <time.h>
#define limpiar "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

using namespace std;

float duracion;
int t0 = 0;
int t1 = 0;

int  arr1[1000000];
int  arr2[2000000];
int  arr3[3000000];
int  arr4[4000000];
int  arr5[5000000];
int  arr6[6000000];
int  arr7[7000000];
int  arr8[8000000];
int  arr9[9000000];
int  arr10[10000000];

int* arreglos[10] = {arr1, arr2,arr3,arr4,arr5,arr6,arr7,arr8,arr9,arr10};
int tamanos[10] ={1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,10000000};


int  arre1[2000];
int  arre2[4000];
int  arre3[6000];
int  arre4[8000];
int  arre5[10000];
int  arre6[12000];
int  arre7[14000];
int  arre8[16000];
int  arre9[18000];
int  arre10[20000];

int* arreglos2[10] = {arre1, arre2,arre3,arre4,arre5,arre6,arre7,arre8,arre9,arre10};
int tamanos2[10] ={2000,4000,6000,8000,10000,12000,14000,16000,18000,20000};


void insertionSort(int arr[], int n){
    t0 = clock();
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
     t1 = clock();
}


int main()
{
    double tiempoActual = 0;
    double tamActual = 0;
    double tiempoAnterior = 0;
    double tamAnterior = 0;
    int num = 1;
    char opcion;
    int continuar;


    while(opcion != '3'){
        cout<<"\nPruebas"<<endl;
        cout<<"1. Insertionsort lienal"<<endl;
        cout<<"2. Insertionsort cuadratico"<<endl;
        cout<<"3. Finalizar programa"<<endl;
        cout<<"\nDigite el numero de opcion: ";
        cin>>opcion;
        if (opcion == '1'){
             for(int i = 0; i<10; i++){ //llenamos los arreglos con numero en orden ascendente, ya que es el mejor caso y el lineal.
                for(int j = 0; j<tamanos[i]; j++){
                    arreglos[i][j] = num;
                    num++;
                }
                num = 1;
            }

            for(int i = 0; i<10; i++){ // Prueba 2 caso lineal
                insertionSort(arreglos[i],tamanos[i]);
                tiempoActual = double(t1-t0);
                tamActual = tamanos[i];
                cout<<"\nArreglo: "<<i<<endl;
                cout << "Cantidad de elementos: " << tamanos[i] <<endl;
                cout << "Tiempo de ejecucion: " << tiempoActual <<" milisegundos"<<endl;
                if (i>0){
                    cout<<"Tasa de cambio de los tiempos: "<<tiempoActual/tiempoAnterior<<endl;
                    cout<<"Tasa de cambio de la funcion n : "<<tamActual/tamAnterior<<endl;
                }
                tiempoAnterior = tiempoActual;
                tamAnterior = tamActual;
            }
            cout<<"\nDigite 1 para volver al menu: ";
            cin>>continuar;
            opcion = '0';

        }

        if (opcion == '2'){
              for(int i = 0; i<10; i++){ //llenamos los arreglos con numero en orden inverso, ya que es el peor caso y el cuadratico.
                for(int j = tamanos2[i]-1; j>=0; j--){
                    arreglos2[i][j] = num;
                    num++;
                }
                num = 1;
              }

            for(int i = 0; i<10; i++){ // Prueba 2 caso lineal
                insertionSort(arreglos2[i],tamanos2[i]);
                tiempoActual = double(t1-t0);

                tamActual = pow(tamanos2[i],2);
                cout<<"\nArreglo: "<<i<<endl;
                cout << "Cantidad de elementos: " << tamanos2[i] <<endl;
                cout << "Tiempo de ejecucion: " << tiempoActual <<" milisegundos"<<endl;

                if (i>0){
                    cout<<"Tasa de cambio de los tiempos: "<<tiempoActual/tiempoAnterior<<endl;
                    cout<<"Tasa de cambio de la funcion n^2 : "<<tamActual/tamAnterior<<endl;
                }
                tiempoAnterior = tiempoActual;
                tamAnterior = tamActual;
            }
            cout<<"\nDigite 1 para volver al menu: ";
            cin>>continuar;
            opcion = '0';

        }
        cout<<limpiar;


    }
    return 0;
}
