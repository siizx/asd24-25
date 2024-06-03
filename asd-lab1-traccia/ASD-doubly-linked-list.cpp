// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include "ASD-doubly-linked-list.h"

using namespace list;
using namespace std;

/*Descrizione da come e' fatta  la struttura node. */
/*I dettagli interni non saranno visibili dal main*/
struct list::node {  
  Elem info;
  node *prev;
  node *next;
};

/**************************************************/
/*      funzioni da implementare                    */
/**************************************************/
  
/* crea la lista vuota */
void list::createEmpty(List& li){
	//TO DO
	li = new list::node;
	li->next = li;
	li->prev = li;
}

/* "smantella" la lista (tranne la sentinella) */
void list::clear(List& li){
	//TO DO
	if(!isEmpty(li)){
		List curr = li->next->next;
		List del = li->next;

		while(del != li){
			curr = curr->next;
			delete(del);
			del = curr;
			curr = curr->next;
		}
	}
}

/* restituisce true se la lista e' vuota */
bool list::isEmpty(const List& li){
  //TO DO
  return li == li->next;
}

/* restituisce la dimensione della lista */
unsigned int list::size(const List& li){
	//TO DO
	if(isEmpty(li)) return 0;
	List aux = li->next;
	int count = 0;
	while(aux != li){
		aux = aux->next;
		count++;
	}
  return count;
}

/* restituisce l'elemento in posizione pos */
/* se pos non e corretta, solleva una eccezione di tipo string*/
Elem list::get(unsigned int pos, const List& li){
	//TO DO
	if(isEmpty(li)){ // throw exeption
		throw std::string("get(): argument List is empty.");
	}

	List aux = li->next;
	for(int i = 0; i< pos; i++){
		aux = aux->next;
		if(aux == li) throw std::string("get(): pos invalida.");
	}
  return aux->info;
}

/* modifica l'elemento in posizione pos */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::set(unsigned int pos, Elem el, const List& li){
	//TO DO
	if(isEmpty(li)) throw std::string("set(): argument List is empty.");
	List curr = li->next;
	for(int i = 0; i< pos; i++){
		curr = curr->next;
		if(curr == li) throw std::string("set(): pos invalida.");
	}
	curr->info = el;
}

/* inserisce l'elemento in posizione pos*/
/*shiftando a destra gli altri elementi */
/*se pos non e' corretta, solleva una eccezione di tipo string*/
void list::add(unsigned int pos, Elem el, const List& li){
	//TO DO
	if(isEmpty(li) && pos != 0) throw std::string("add(): argument List is empty."); // se la lista e' vuopta e pos non e' 0, errore
	if(isEmpty(li) && pos == 0) {
		List n = new node;
		n->info = el;
		n->next = li;
		n->prev = li;
		li->next = n;
		li->prev = n;
	}else{
		List n = new node; // nuovo nodo
		n->info = el;
		
		List prev = li;
		List curr = li->next;
		
		for(int i = 0; i < pos; i++){
			curr = curr->next;
			prev = prev->next;
			if(curr == li) throw std::string("add(): pos invalida.");
		}
		n->next = curr;
		n->prev = prev;
		prev->next = n;
		curr->prev = n;
	}

}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem el, const List& li){
	//TO DO
	List n = new node;
	n->info = el;

	li->prev->next = n;
	n->next = li;
	li->prev = n;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem el, const List& li) {
	//TO DO
	List n = new node;
	n->info = el;

	li->next->prev = n;
	n->next = li->next;
	n->prev = li;
	li->next = n;
}

/* cancella l'elemento in posizione pos dalla lista */
/* se pos non e' corretta, solleva una eccezione di tipo string*/
void list::removePos(unsigned int pos,const List& li){
	//TO DO
	if(isEmpty(li)) throw std::string("removePos(): la lista e' vuota.");
	List aux  = li->next;
	List prev = li;
	for(int i = 0; i<pos; i++){
		aux = aux->next;
		prev = prev->next;
		if(aux == li) throw std::string("removePos(): invalid pos.)");
	}
	
	List d = aux;
	aux = aux->next;

	prev->next = aux;
	aux->prev = prev;

	delete(d);

}

/* cancella tutte le occorrenze dell'elemento elem*/
/*se presenti, dalla lista */
void list::removeEl(Elem el,const List& li){
	//TO DO
	if(!isEmpty(li)){
		List prev = li;
		List aux = li->next;
		List d;

		while(aux != li){
			if(aux->info == el){
				d = aux;
				aux = aux->next;

				prev->next = aux;
				aux->prev = prev;

				delete(d);
			}else{
				prev = aux;
				aux = aux->next;
			}
		}// fine while
	}// fine if
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
  
/* riempie una lista da file */
void list::readFromFile(string name_file, const List& li){
  ifstream infile;
  string read_data;
  infile.open(name_file);
  while (getline (infile,read_data)){
    if(read_data.length()>0){
      addRear(stoi(read_data),li);
    }
  }
}

/* riempie una lista da standard input */
void list::readFromStdin(const List& li){
  cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
  string read_data;
  cin>>read_data;
  while(read_data!="END"){
    addRear(stoi(read_data),li);
    cin>>read_data;
  }
}

/* stampa la lista */
void list::print(const List& li){
  if(li==li->next){
    cout<<"vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    cout << cur->info;
    cur= cur->next;
    if(cur!=li) cout<<" <-> ";
  }
  cout<<endl;
}

/* produce una string contenendo la lista*/
std::string list::tostring(const List& li){
  string out="";
  if(li==li->next){
    out+="vuota";
  }
  List cur = li->next;  // q "salta la sentinella" e va alla testa della lista
  while (cur != li) {   
    out+=to_string(cur->info);
    cur= cur->next;
    if(cur!=li) out+=" <-> ";
  }
  return out;
}
