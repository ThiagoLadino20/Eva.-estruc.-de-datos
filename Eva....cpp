#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Data {
    int value;
    int priority;
};

void displayData(const queue<Data>& q) 
{
    queue<Data> temp = q;
    while (!temp.empty()) {
        cout << "Dato: " << temp.front().value << " | Prioridad: " << temp.front().priority << endl;
        temp.pop();
    }
}


struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void mostrarArbol (Nodo*int);

class Stack 
{
public:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() 
    {
        return top == nullptr;
    }

    void push(int val) 
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() 
    {
        if (!isEmpty()) 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};


class Queue 
{
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() 
    {
        return front == nullptr;
    }

    void enqueue(int val) 
    {
        Node* newNode = new Node(val);
        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
        rear->next = front; 
    }

    void dequeue() 
    {
        if (!isEmpty()) 
        {
            Node* temp = front;
            if (front == rear) 
            {
                front = rear = nullptr;
            } 
            else 
            {
                front = front->next;
                rear->next = front; 
            }
            delete temp;
        }
    }
};


void agregarPila(Node *&pila, int n)
{
    Node *nuevo_nodo = new Node(n);
    nuevo_nodo->next = pila;
    pila = nuevo_nodo;
}

void sacarPila(Node *&pila, int &n)
{
    Node *aux = pila;
    n = aux->data;
    pila = aux->next;
    delete aux;
}

int main() 
{
    queue<Data> queue_priority1;
    queue<Data> queue_priority2;
    queue<Data> queue_priority3;
    stack<Data> stack_data;

    int choice;
    do
    {
    cout << "Seleccione una opción:" << endl;
    cout << "1. Pila" << endl;
    cout << "2. Cola" << endl;
    cin >> choice;

    if (choice == 1) 
    {
        Stack stack;
        int num;
        char rpt;
    
        do  
        { 
            cout << "Digite un número: ";
            cin >> num;
            stack.push(num);
        
            cout << "\n¿Desea agregar otro número a la pila (s/n)? ";
            cin >> rpt;
        } 
        while (rpt == 's' || rpt == 'S');
    
        cout << "\nNúmeros de la Pila: ";
        while (!stack.isEmpty()) 
        {
            num = stack.top->data;
            stack.pop();
            cout << num << " ";
        }
        cout << endl;
    } 
    
    else if (choice == 2) 
    {
        void mostrarArbol(Nodo*arbol,int cont)
{
    if(arbol==NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++)
        {
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}

    }
        
    }
    return 0;
}
