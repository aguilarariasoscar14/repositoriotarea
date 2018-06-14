#include<iostream>
using namespace std;
/*Hola soy oskar*/
/*saludos*/


//************************** NODO *********************************//
typedef struct Nodo
{
 
 int dato;
 
 struct Nodo *sgt;

}TNodo;
//*****************************************************************//


//************************ LISTA **********************************//
typedef struct LE
{

  TNodo *inicio;

}TLE;

//*****************************************************************//


//************************* CREA NODO *****************************//
TNodo *crearNodo(int x)
{

 TNodo *nodo = (TNodo*)malloc(sizeof(TNodo));

 nodo->dato = x;

 nodo->sgt = NULL;

 return nodo;

}
//*****************************************************************//


//************************ CREA LISTA *****************************//
TLE *crearLista()
{

 TLE *lista = (TLE*)malloc(sizeof(TLE));

 lista->inicio = NULL;
 
 return lista;

}

//*****************************************************************//


//************************ INSERTAR *******************************//
void Insertar(TLE *lista, int x)
{

 TNodo *nodo = crearNodo(x);

 if(lista->inicio == NULL)

    lista->inicio = nodo;
 
 else

    nodo->sgt = lista->inicio->sgt;
    
  lista->inicio->sgt = nodo;
    

}

//*****************************************************************//


//*********************** ELIMINAR ********************************//
void Eliminar(TLE *lista, int dato)
{

 TNodo *p = lista->inicio;

 TNodo *ant = NULL;

 int encontrado=0;
 
 do
   {
     if( p->dato == dato)
        {
          
          cout<<"   "<<p->dato;
          
          encontrado=1;
        }
         
     else

         {
        
          ant=p;
        
          p=p->sgt;
        
         }    
   }
   
 while(!encontrado && p!=lista->inicio);

      
 if(lista->inicio != NULL)
   {
    
    if (ant==NULL)
        lista->inicio=(lista->inicio)->sgt;
       
    else


       ant->sgt=p->sgt;

   free(p);

  }


}
//*****************************************************************//


//************************ BORRAR *********************************//
void Borrar(TLE *lista)
{

 TNodo *p = NULL;
 
 while(lista->inicio->sgt != lista->inicio)
      {
       
       p = lista->inicio->sgt;
       
       lista->inicio->sgt = p->sgt;
       
       free(p);
      
      }
  
}

//*****************************************************************//


//********************** REPORTAR ********************************//
void Reportar(TLE *lista)
{
 TNodo *p = lista->inicio;;
 
 cout<<"      Lista -> ";
 
 do
      {
 
       cout<<" "<<p->dato<<" -> ";
 
       p = p->sgt;
 
      }
 while(p!=lista->inicio);
       
 cout<<"Lista";
  
 cout<<endl<<endl;
 
 system("pause");
 
 cout<<endl;    
}

//*****************************************************************//


//*********************** ESTA VACIA ******************************//
void Vacia(TLE *lista)
{
 
 if(lista->inicio == NULL)
 
    cout<<endl<<"      - La Lista Esta Vacia !!! "<<endl;
 
 else
 
    cout<<endl<<"      - La Lista No Esta Vacia !!! ";
    
 cout<<endl<<endl;
 
 system("pause");
 
 cout<<endl;
    
}

//*****************************************************************//


//*****************************************************************//
//*****************************************************************//
int main()
{
 
 system("color f2");
 
 TLE *L=crearLista();
 
 int N,E,i=0;
 
 int opcion;
 
  cout<<endl<<"\t----------------------------------------------------------------- ";
  cout<<endl<<"\t|                   LISTAS ENLAZADAS CIRCULARES                  |";
  cout<<endl<<"\t|            - [ UNIVERSIDAD NACIONAL DE TRUJILLO ] -            |";   
  cout<<endl<<"\t|      Copyright © Company Informatic World (Yan Sandoval V.)    |";          
  cout<<endl<<"\t----------------------------------------------------------------- "<<endl;

  cout<<endl<<endl;
  cout<<"      MENU LISTAS CIRCULARES"<<endl;
  cout<<"      ---------------------- ";

 while(1)
  {
   cout<<endl<<endl;        
   cout<<"   ---------------------------- "<<endl;
   cout<<"   | 1.  Insertar              |"<<endl;
   cout<<"   | 2.  Eliminar Elemento     |"<<endl;
   cout<<"   | 3.  Borrar Lista          |"<<endl;
   cout<<"   | 4.  Mostrar Lista         |"<<endl;
   cout<<"   | 5.  Lista Esta Vacia      |"<<endl;
   cout<<"   | 6.  Salir                 |"<<endl;
   cout<<"   ----------------------------- "<<endl;   
 
  do

    {
     
     cout<<endl<<endl<<"   -> Ingrese Opcion"<<endl;
     cout<<"      --------------->  ";
   
     cin>>opcion;
    
    }
    
 while(opcion < 1 || opcion > 6);

 
 switch(opcion)
       {
        case 1:
       
                i++;
   
                cout<<endl<<"       - Ingrese ["<<i<<"] elemento: "; 
   
                cin>>N;
   
                Insertar(L,N); 
   
                break;
                
        case 2:
       
                cout<<endl<<"       - Ingrese Elemento a Eliminar: ";
   
                cin>>E;
   
                Eliminar(L,E);
   
                break;
        
        case 3:
               
                Borrar(L);
                
                cout<<endl<<endl;
                
                cout<<"       - Se Elimino La Lista Correctamente... ";
                
                cout<<endl<<endl;
 
                system("pause");
 
                cout<<endl;
               
                break;              
                  
        case 4:      
   
                cout<<endl;     
   
                Reportar(L); 
   
                cout<<endl;
   
                break;

        case 5:      
           
                Vacia(L); 
           
                break;
        
        case 6:
           
                exit(1);
        
        default:
                cout<<endl<<endl;
                
                cout<<"     La Opcion No es Valida !!!!!!!!!:";
      } 
       
}                     
 
 cout<<endl<<endl;
 
 system("PAUSE");
 
 return EXIT_SUCCESS;
 
}

//*****************************************************************//




