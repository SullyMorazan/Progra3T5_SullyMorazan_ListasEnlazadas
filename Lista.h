#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
           if(inicio==NULL)//si lo que hay en inicio esta vacio
                return true;//entonces devuelve true
            else
                return false;//de lo contrario devuelve false
            inicio = inicio->sig;// inicio se desplaza al siguiente nodo

    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {

     return inicio->valor;//Devuelve el valor que se encuentra al inicio de la lista

    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
            Nodo<Tipo>*ultimo = inicio; //se crea un nodo que almacenara el ultimo valor de la lista
            while(ultimo->sig!=NULL)//ciclo que se ejecuta mientras el ultimo valor sea distinto de NULL
            {
                ultimo=ultimo->sig;//permite moverse al siguiente nodo de la lista
            }

            return ultimo->valor; //Devuelve el ultimo valor de la lista
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Nodo<Tipo>*temp = inicio;
        Nodo<Tipo> *mayor;
        while(temp!=NULL)//ciclo que termina cuando llega a un valor NULL
        {
        if(mayor<temp)//si mayor es menor que el valor que contiene el nodo temporal
        {
            mayor = temp; // entonces mayor sera igual al valor temporal
        }
        temp=temp->sig;//permite avanzar al siguiente valor de la lista
    }//se cierra el ciclo donde se han comparado todos los nodos de la lista
    return mayor->valor;//retorna la variable que contiene el valor mayor
    }

};
#endif // LISTA_H
