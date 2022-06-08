#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<class T>
class graph{
    protected:
        map<T, vector<T>>outgoing; //uso de map con templates y un vector
    public:
        graph<T>(const vector<T> &starts, const vector<T> &ends); //constructor recibe como parametros 2 vectores uno inicial y otro final
        int numOutgoing(const T nodeID) const; //Devuelve el número de aristas salientes
        const vector<T> &adjacent(const T nodeID) const; //Devuelve una referencia a la lista de nodos
};
template<class T>
graph<T>::graph(const vector<T> &starts, const vector<T> &ends){
    if(starts.size() != ends.size()){
        throw invalid_argument("Tienen diferente tamaño"); //Por si lso 2 vectores tienen diferente tamaño
    }
    for(int i=0; i<starts.size(); i++) {
        T start = starts [i], end = ends[i];
        outgoing[start].push_back(end); //almaceno todo en el map
        outgoing[end];
    }
    
}
template<class T>
int graph<T>::numOutgoing(const T nodeID) const{
    return adjacent(nodeID).size(); //retorno el numero de aristas
}
template<class T>
const vector<T> &graph<T>::adjacent (T nodeID) const{
    map<int, vector<int> >::const_iterator i; //iterador para buscar el elemento
    i = outgoing.find(nodeID); //busca el elemento
    if(i==outgoing.end()){
        throw invalid_argument("Invalido"); //por si llega al final y no lo encuentra
    }
    return i->second;
}

int main(){ 
    vector<int> g1 = {1,1,1,5,5,4};
    vector<int> g2 = {2,3,4,4,2,2};
    
    graph<int> grafo(g1,g2);
    cout<<"Numero de aristas en 5: "<<grafo.numOutgoing(5)<<endl;
    cout<<"Numero de aristas en 4: "<<grafo.numOutgoing(4)<<endl;
    cout<<"Numero de aristas en 1: "<<grafo.numOutgoing(1)<<endl;
  
    
    return 0;
}
