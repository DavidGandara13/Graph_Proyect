#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

using namespace std;



class Grafo {
	protected:
		int V;
		vector<vector<int>> matrizAdyacencia;
		vector<vector<int>> listaAdyacencia;
		
	public:
		Grafo(int n)  {
			V=n;
			matrizAdyacencia.resize(n, std::vector<int>(n, 0));
			listaAdyacencia.resize(n);
		}
		
	void agregarArista(int inicio, int fin) {
        matrizAdyacencia[inicio][fin] = 1;
        listaAdyacencia[inicio].push_back(fin);
    }
	
	void llenarGrafo(int aristas){
		for (int i=0; i<aristas; i++){
			int num1=rand() % V, num2=rand() % V;
			matrizAdyacencia[num1][num2]=1;
			listaAdyacencia[num1].push_back(num2);
		}
	}	
	
	void imprimirMatrizAdyacencia() {
	cout<<"Matriz:"<<endl;
	cout<<"\t\t ";
        for(int i=0;i<V;i++){
		cout<<"   "<<i;
	}
	
	for(int i=0;i<V;i++){
		
		cout<<"\n\t\t"<<i;
	
		for(int b=0;b<V;b++){
			cout<<"   "<<matrizAdyacencia[i][b];
		}
	}
    }
    
    void imprimirListaAdyacencia() {
	cout<<"Lista:"<<endl;
	cout<<"\t\t ";
        
	for(int i=0;i<V;i++){
		
		cout<<"\n\t\t"<<i;
		
		for (const auto& nodo : listaAdyacencia[i]) {
    		cout<<"   "<< nodo;
		}
		
	}
	
    }
    
};

int main(){
	srand(time(NULL));
	int arist, nodo_o, nodo_f;
	char ans;
	Grafo g(5);
	cout<<"Quieres que llenemos el grafo por ti? Y or N"<<endl;
	cin>>ans;
	ans=toupper(ans);
	if (ans=='Y'){
		cout<<"De cuantas aristas quieres el grafo?"<<endl;
		cin>>arist;
		g.llenarGrafo(arist);
	}else{
		jump:
			cout<<"Ingresa el nodo origen"<<endl;
			cin>>nodo_o;
			cout<<"Ingresa el nodo final"<<endl;
			cin>>nodo_f;
			g.agregarArista(nodo_o, nodo_f);
			cout<<"Quieres agregar otra arista? Y or N"<<endl;
			cin>>ans;
			ans=toupper(ans);
			if (ans=='Y'){
				system("cls");
				goto jump;
			}
		}
		
	g.imprimirMatrizAdyacencia();
	cout<<endl;
	g.imprimirListaAdyacencia();
	return 0;
}
