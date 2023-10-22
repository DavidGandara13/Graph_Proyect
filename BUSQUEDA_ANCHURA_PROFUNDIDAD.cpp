#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <queue>
#include <stack>

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
    
    void buscarAnchura(int partida) {
    	int w;
    	bool t=false;
		
		queue<int> cola;
    	vector<int> marcados;
    	
    	marcados.push_back(partida);
    	cola.push(partida);
    	
    	while (!cola.empty()){
    		w = cola.front();
			cola.pop();
			for (int i=0; i<listaAdyacencia[w].size(); i++){
				t=false;
				for (int j=0; j<marcados.size(); j++){
					if (listaAdyacencia[w][i]==marcados[j]){
						t=true;
						break;
					}
				}
					if (!t){
						cola.push(listaAdyacencia[w][i]);
						marcados.push_back(listaAdyacencia[w][i]);
					}
				
				
			}
		}
		
		cout<<"Grafo en Anchura "<<endl;
		for (int i=0; i<marcados.size(); i++){
			cout<<marcados[i]<<" ";
		}
	}
	
	void buscarProfundidad(int partida) {
    	int w;
    	bool t=false;
		
		stack<int> pila;
    	vector<int> marcados;
    	
    	marcados.push_back(partida);
    	pila.push(partida);
    	
    	while (!pila.empty()){
    		w = pila.top();
			pila.pop();
			for (int i=0; i<listaAdyacencia[w].size(); i++){
				t=false;
				for (int j=0; j<marcados.size(); j++){
					if (listaAdyacencia[w][i]==marcados[j]){
						t=true;
						break;
					}
				}
					if (!t){
						pila.push(listaAdyacencia[w][i]);
						marcados.push_back(listaAdyacencia[w][i]);
					}
				
				
			}
		}
		
		cout<<"Grafo en Anchura "<<endl;
		for (int i=0; i<marcados.size(); i++){
			cout<<marcados[i]<<" ";
		}
	}
    
};

int main(){
	int partida;
	Grafo g(5);
	
	g.agregarArista(0,1);
	g.agregarArista(0,2);
	g.agregarArista(1,4);
	g.agregarArista(2,3);
	g.agregarArista(4,2);

	
	cout<<"Ingresa el nodo de partida"<<endl;
	cin>>partida;
	
	g.buscarAnchura(partida);
	
	cout<<endl;
	
	g.buscarProfundidad(partida);
	
	return 0;
}
