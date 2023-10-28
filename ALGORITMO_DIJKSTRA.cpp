#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <queue>
#include <stack>
#include <limits>

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
    
    void agregarAristaNo(int inicio, int fin) {
        matrizAdyacencia[inicio][fin] = 1;
        matrizAdyacencia[fin][inicio] = 1;
        listaAdyacencia[inicio].push_back(fin);
        listaAdyacencia[fin].push_back(inicio);
    }
	
	void agregarAristaPe(int inicio, int fin, int peso) {
        matrizAdyacencia[inicio][fin] = peso;
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
    
    void componentesConexos(){
    	vector<bool> visitado(V, false);

    for (int v = 0; v < V; v++) {
        if (!visitado[v]) {
            queue<int> cola;
            vector<int> componenteConexo;

            visitado[v] = true;
            cola.push(v);
            componenteConexo.push_back(v);

            while (!cola.empty()) {
                int nodo = cola.front();
                cola.pop();

                for (int i = 0; i < V; i++) {
                    if (matrizAdyacencia[nodo][i] && !visitado[i]) {
                        visitado[i] = true;
                        cola.push(i);
                        componenteConexo.push_back(i);
                    }
                }
            }

            // Imprime el componente conexo actual
            for (int i = 0; i < componenteConexo.size(); ++i) {
                cout << componenteConexo[i] << " ";
            }
            cout << endl;
        }
    }
	}
    
    
    void dijkstra(int fuente){
    	 vector<int> distancia(V, numeric_limits<int>::max());
        vector<bool> visitado(V, false);

        distancia[fuente] = 0;

        for (int i = 0; i < V - 1; ++i) {
            int minDistancia = numeric_limits<int>::max();
            int u;

            // Encuentra el nodo con la distancia mínima
            for (int j = 0; j < V; ++j) {
                if (!visitado[j] && distancia[j] < minDistancia) {
                    minDistancia = distancia[j];
                    u = j;
                }
            }

            // Marca el nodo seleccionado como visitado
            visitado[u] = true;

            // Actualiza las distancias de los nodos adyacentes del nodo seleccionado
            for (int v : listaAdyacencia[u]) {
                if (!visitado[v] && distancia[u] != numeric_limits<int>::max() &&
                    distancia[u] + matrizAdyacencia[u][v] < distancia[v]) {
                    distancia[v] = distancia[u] + matrizAdyacencia[u][v];
                }
            }
        }

        // Imprime las distancias más cortas desde el nodo fuente a todos los demás nodos
        cout << "Distancias más cortas desde el nodo fuente:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Nodo " << i << ": " << distancia[i] << endl;
	}
}

};

int main(){
	Grafo g(5);
    g.agregarAristaPe(0, 1, 2);
    g.agregarAristaPe(0, 2, 4);
    g.agregarAristaPe(1, 2, 1);
    g.agregarAristaPe(1, 3, 7);
    g.agregarAristaPe(2, 4, 3);
    g.agregarAristaPe(3, 4, 1);

    g.dijkstra(0);
	
	return 0;
}
