#include <iostream>
#include <math.h>
#include <time.h>
#define limpiar "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

using namespace std;

float duracion;
int t0 = 0;
int t1 = 0;

int  arr1[50000];
int  arr2[100000];
int  arr3[150000];
int  arr4[200000];
int  arr5[250000];
int  arr6[300000];
int  arr7[350000];
int  arr8[400000];
int  arr9[450000];
int  arr10[500000];

int* arreglos[10] = {arr1, arr2,arr3,arr4,arr5,arr6,arr7,arr8,arr9,arr10};
int tamanos[10] ={50000,100000,150000,200000,250000,300000,350000,400000,450000,500000};


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




//Funciona que divide el arreglo
int particionar(int a[],int start,int end){
    int pivote = a[start];
    int i = start+1;

    for(int j = i; j<=end; j++){
    	if(a[j] < pivote){
            swap(a[i],a[j]);
            i++;
        }
     }
    swap(a[start],a[i-1]);
    return i-1;
 }

 //Funcion que elije un pivote aleatorio y lo reemplaza por el de la primera poscion
 int particionarRandomizado(int a[],int low,int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap a[random] with a[low]
    swap(a[random], a[low]);

    return particionar(a, low, high);

 }


void imprimir_arreglo(int arre[],int tam){
    cout<<"{ ";
    for(int i = 0; i<tam;i++){
        cout<<arre[i]<<" ";
    }
    cout<<"}"<<endl;
}

//Funcion base de Quicksort
void quicksort(int *a, int imin, int imax) {
    if (imin >= imax)
        return;
    int k = particionar(a, imin, imax);
    quicksort(a, imin, k-1);
    quicksort(a, k+1, imax);
    }

//Funcion Quicksort para el pivote random
void quicksort2(int *a, int imin, int imax) {
    if (imin >= imax)
        return;
    int k = particionarRandomizado(a, imin, imax);
    quicksort(a, imin, k-1);
    quicksort(a, k+1, imax);
    }

int main(){
    //variables usadas para medir los tiempos e interaccionar con el menu
    double tiempoActual = 0;
    double tamActual = 0;
    double tiempoAnterior = 0;
    double tamAnterior = 0;
    int num = 1;
    int continuar;
    char opcion;

    while(opcion != '4'){
        cout<<"Pruebas"<<endl;
        cout<<"1. Quicksort logaritmico"<<endl;
        cout<<"2. Quicksort cuadratico"<<endl;
        cout<<"3. Influencia del pivote fijo y aleatorio"<<endl;
        cout<<"4. Finalizar programa"<<endl;
        cout<<"\nDigite el numero de opcion: ";
        cin>>opcion;
        if (opcion == '1'){

            for(int i = 0; i<10; i++){  //se llena el arreglo con numeros aleatorios del 1 al 1000
                for(int j = tamanos[i]-1; j>=0; j--){
                    arreglos[i][j] = 1+rand()%(1000);;
                }
            }
            //imprimir_arreglo(arreglos[0],50000);
            cout<< "\nPrueba 1. Quicksort O(n*log(n), con numeros aleatorios:"<<endl;

            for(int i = 0; i<10; i++){ //se usa quicksort con los arreglos de diefrentes tamanos y se calcula su tiempo
                t0 = clock();
                quicksort(arreglos[i],0,tamanos[i]);
                t1 = clock();

                tiempoActual = (double(t1-t0)/CLOCKS_PER_SEC);
                tamActual = tamanos[i]*log2(tamanos[i]);
                cout<<"\nArreglo: "<<i<<endl;
                cout << "Cantidad de elementos: " << tamanos[i] <<endl;
                cout << "Tiempo de ejecucion: " << tiempoActual <<endl;

                if (i>0){
                    cout<<"Tasa de cambio de los tiempos: "<<tiempoActual/tiempoAnterior<<endl;
                    cout<<"Tasa de cambio de la funcion n*log(n): "<<tamActual/tamAnterior<<endl;
                }
                tiempoAnterior = tiempoActual;
                tamAnterior = tamActual;
            }
            cout<<"\nDigite 1 para volver al menu: ";
            cin>>continuar;
            opcion = '0';
        }
        if (opcion == '2'){ //Caso cuadratico

           for(int i = 0; i<10; i++){ //llenamos los arreglos con numero en orden inverso, ya que es el peor caso y el cuadratico.
                for(int j = tamanos2[i]-1; j>=0; j--){
                    arreglos2[i][j] = num;
                    num++;
                }
                num = 1;
            }
           // imprimir_arreglo(arreglos[0],50000);
            cout<< "\nPrueba 2. Quicksort O(n^2), con numeros ordenados a la inversa:"<<endl;
            for(int i = 0; i<10; i++){
                t0 = clock();
                quicksort(arreglos2[i],0,tamanos2[i]);
                t1 = clock();

                tiempoActual = (double(t1-t0)/CLOCKS_PER_SEC);
                tamActual = pow(tamanos2[i],2);
                cout<<"\nArreglo: "<<i<<endl;
                cout << "Cantidad de elementos: " << tamanos2[i] <<endl;
                cout << "Tiempo de ejecucion: " << tiempoActual <<endl;

                if (i>0){
                   cout<<"Tasa de cambio de los tiempos: "<<tiempoActual/tiempoAnterior<<endl;
                   cout<<"Tasa de cambio de la funcion n^2: "<<tamActual/tamAnterior<<endl;
                }
                tiempoAnterior = tiempoActual;
                tamAnterior = tamActual;
            }
            cout<<"\nDigite 1 para continuar con la siguiente prueba: ";
            cin>>continuar;
            opcion = '0';
        }
        if (opcion == '3'){
            for(int i = 0; i<10; i++){ //llenamos los arreglos con numero en orden inverso, ya que es el peor caso y el cuadratico.
                for(int j = tamanos2[i]-1; j>=0; j--){
                    arreglos2[i][j] = num;
                    num++;
                }
                num = 1;
            }

            cout<<"\nPivote Fijo: al estar ordenado es O(n^2), con numeros ordenados a la inversa"<<endl;
             for(int i = 0; i<10; i++){
                t0 = clock();
                quicksort(arreglos2[i],0,tamanos2[i]);
                t1 = clock();

                tiempoActual = (double(t1-t0)/CLOCKS_PER_SEC);
                tamActual = pow(tamanos2[i],2);
                cout<<"\nArreglo: "<<i<<endl;
                cout << "Cantidad de elementos: " << tamanos2[i] <<endl;
                cout << "Tiempo de ejecucion: " << tiempoActual <<endl;

                if (i>0){
                    cout<<"Tasa de cambio de los tiempos: "<<tiempoActual/tiempoAnterior<<endl;
                    cout<<"Tasa de cambio de la funcion n^2: "<<tamActual/tamAnterior<<endl;
                }
                tiempoAnterior = tiempoActual;
                tamAnterior = tamActual;
            }


            for(int i = 0; i<10; i++){ //llenamos los arreglos con numero en orden inverso, ya que es el peor caso y el cuadratico.
                for(int j = tamanos2[i]-1; j>=0; j--){
                    arreglos2[i][j] = num;
                    num++;
                }
                num = 1;
            }

            cout<<"\nPivote Aleatorio: Mejora el tiempo del caso anterior, sin embargo puede ser ineficiente en algunos otros"<<endl;
            cout<<"\nComparando su creciemiento con el de la funcion n*(log(n)) vemos que en algunos casos crecen similiar pero en otros varia"<<endl;

            for(int i = 0; i<10; i++){
                t0 = clock();
                quicksort2(arreglos2[i],0,tamanos2[i]);
                t1 = clock();

                tiempoActual = (double(t1-t0)/CLOCKS_PER_SEC);
                tamActual = tamanos2[i]*log2(tamanos2[i]);
                 cout<<"\nArreglo: "<<i<<endl;
                 cout << "Cantidad de elementos: " << tamanos2[i] <<endl;
                 cout << "Tiempo de ejecucion: " << tiempoActual <<endl;


                if (i>0){
                     cout<<"Tasa de cambio de los tiempos: "<<tiempoActual/tiempoAnterior<<endl;
                     cout<<"Tasa de cambio de la funcion n*log(n): "<<tamActual/tamAnterior<<endl;
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
