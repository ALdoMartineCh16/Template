#include <iostream>
#include <vector>

using namespace std;

template<class T>

class Stack{
    public:
        vector<T> pila;
        void push(const T &item){
            pila.push_back(item);
        }
        bool empty(){
            bool band = true;
            if(pila.empty()){
               band = false; 
            }
            return band;
        }
        T top(){
            return pila.back();
        }
        
        void pop(){
            pila.pop_back();
        }
        void print(){
            for (size_t i = 0; i < pila.size(); i++) {
                cout << pila[i] << "; ";
            }
        }
        
};

template<class T>
Stack<T> operator+(Stack <T> const a,Stack <T> const b){
    Stack <T> nuevo_nodo;
    nuevo_nodo = a;
    for (auto i = b.pila.begin(); i < b.pila.end(); i++) {
        nuevo_nodo.push(*i);
    }
    return nuevo_nodo;
}

int main(){
    Stack <int> a,b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Stack<int> c = a+b;
    c.print();
    cout<<"\nUltimo elemento:"<<c.top();
    cout<<"a";
    return 0;
}

