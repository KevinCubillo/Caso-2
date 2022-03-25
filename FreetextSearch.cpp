#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <math.h>
#include <fstream>
#include <string>

#define limpiar "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

using namespace std;


class TreeNode{

    public:
        string word;
        TreeNode * left;
        TreeNode * right;
        int count;
        int contadorGlobal;

    TreeNode(){

    }
    void Insert(TreeNode*& root, string myWord){
        if (root == NULL)
        {
            root = new TreeNode;
            root->left = NULL;
            root->right = NULL;
            root->word = myWord;
            root->count = 1;
        }
        else if (root->word == myWord)
        {
            root->count++;
        }
        else if (root->word < myWord)
        {
            Insert(root->right, myWord);
        }
        else
        {
            Insert(root->left, myWord);
        }
    }

   void Search(TreeNode* root, string palabra){
        if (root != NULL){
            if (root->word.find(palabra) != string::npos){
                cout<<root->word<< " " << root->count<<endl;
                contadorGlobal+=root->count;
            }
            Search(root->left, palabra);
            Search(root->right, palabra);
        }
    }


    string findWord(ifstream& inFile){
        char word;
        string myWord = " ";

        inFile.get(word);

        while (inFile && !isalnum(word))
        {
            inFile.get(word);
        }

        if (!inFile)
        {
            return myWord;
        }

        else
        {
            do
            {
                word = tolower(word);
                myWord = myWord + word;
                inFile.get(word);
            }
            while (isalnum(word) && inFile);
        }
        return myWord;
    }


};

int main(){

    int t0 = 0;
    int t1 = 0;
    double tiempoActual = 0;

    string opcion = "0";

     string inFileName;
     ifstream inFile;
     string myWord;
     int minLength;
     string palabra;

    while(opcion != "3"){
        cout<<"Pruebas"<<endl;
        cout<<"1. Freetext search con archivos txt default"<<endl;
        cout<<"2. Freetext search con archivo del usuario"<<endl;
        cout<<"\nDigite el numero de opcion: ";
        cin>>opcion;

        if (opcion == "1"){

            TreeNode b, *root = NULL;


            inFileName = "Quijote.txt";
            inFile.open(inFileName.data());
            cout<<"Cargando el texto en el BST"<<endl;

            if(!inFile){
                cout << "Archivo de texto no encontrado";
            }else{
                minLength = 1;

                myWord = b.findWord(inFile);

                while (inFile){
                    if (myWord.length() >= minLength){
                        b.Insert(root, myWord);
                    }
                    myWord = b.findWord(inFile);
                }
                inFile.close();
                while(opcion != "2"){
                    cout<<"Digite la palabra que desea buscar: ";
                    cin>>palabra;
                    cout<<endl;

                    t0 = clock();
                    b.Search(root, palabra);
                    t1 = clock();
                    tiempoActual = double(t1-t0);

                    cout<<"\nTotal de aparcicones de "<<palabra<<": "<<b.contadorGlobal;
                    b.contadorGlobal = 0;
                    cout<<"\nTiempo de busqueda e impresion en consola: "<<tiempoActual<<" milisegundos";
                    cout<<"\n\nDesea buscar otra palabra?\n1. Si\n2. No"<<"\nopcion: ";
                    cin>>opcion;
                }

            }
        }
        if (opcion == "2"){

            TreeNode b, *root = NULL;
            cout<<"Digite la ruta del archivo txt: ";
            cin>>inFileName;
            inFile.open(inFileName.data());
            cout<<"\nCargando el texto en el BST"<<endl;

            if(!inFile){
                cout << "Archivo de texto no encontrado";
            }else{
                minLength = 1;

                myWord = b.findWord(inFile);

                while (inFile){
                    if (myWord.length() >= minLength){
                        b.Insert(root, myWord);
                    }
                    myWord = b.findWord(inFile);
                }
                inFile.close();
                opcion = "0";
                while(opcion != "2"){
                    cout<<"Digite la palabra que desea buscar: ";
                    cin>>palabra;
                    cout<<endl;

                    t0 = clock();
                    b.Search(root, palabra);
                    t1 = clock();
                    tiempoActual = double(t1-t0);

                    cout<<"\nTotal de aparcicones de "<<palabra<<": "<<b.contadorGlobal;
                    b.contadorGlobal = 0;
                    cout<<"\nTiempo de busqueda e impresion en consola: "<<tiempoActual<<" milisegundos";
                    cout<<"\n\nDesea buscar otra palabra?\n1. Si\n2. No"<<"\nopcion: ";
                    cin>>opcion;
                }

            }
        }
        cout<<limpiar;
        opcion = "0";
    }

    return 0;
}

