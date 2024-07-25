// FILE DA MODIFICARE
#include <iostream>
#include <fstream>
#include <string>

#include "ASD-queue-list.h"

using namespace queue;
using namespace std;

// implementazione di una doubly linked list
struct queue::cell
{
   Elem el;
   cell *next;
   cell *prev;
};

/**************************************************/
/*      funzioni da implementare                  */
/**************************************************/

/* restituisce la coda vuota */
Queue queue::createEmpty()
{
   // to do
   Queue qret;
   qret.li = EMPTYLIST;
   qret.end = nullptr;
   return qret;
}

/* restituisce true se la queue e' vuota */
bool queue::isEmpty(const Queue &q)
{
   // to do
   return ((!q.li));
}

/* inserisce l'elemento "da una parte" della coda */
void queue::enqueue(Elem e, Queue &q)
{
   // to do
   cell *nl = new cell;
   nl->el = e;
   nl->prev = nullptr;

   if (isEmpty(q))
   {
      q.li = nl;
      q.end = q.li;
      q.li->next = nullptr;
   }
   else
   {
      q.li->prev = nl;
      nl->next = q.li;
      q.li = nl;
   }
}

/* cancella l'elemento (se esiste) "dall'altra parte */
/*della coda" e lo restituisce; se la coda è vuota solleva */
/*una eccezione di tipo string*/
Elem queue::dequeue(Queue &q)
{
   // to do
   Elem ret;
   if (isEmpty(q))
   {
      throw string("equeue(): q is empty");
   }
   else if (q.li->next == nullptr)
   {
      ret = q.li->el;
      delete q.li;
      q.li = EMPTYLIST;
      q.end = nullptr;
   }
   else
   {
      ret = q.end->el;       // valore da restituire
      cell *p = q.end->prev; // p = nuovo ultimo elemento
      delete q.end;
      q.end = p;
      q.end->next = nullptr;
   }
   return ret; // valore restituito
}

/* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo*/
/*se la coda è vuota solleva una eccezione di tipo string*/
Elem queue::first(Queue &q)
{
   // to do
   if (isEmpty(q))
   {
      throw string("first(): q is empty");
   }

   Elem ret = q.end->el;
   return ret;
}

/**************************************************/
/*      funzioni implementate                    */
/**************************************************/
/* riempie una coda da file */
Queue queue::readFromFile(std::string name_file)
{
   ifstream infile;
   string read_data;
   infile.open(name_file);
   Queue qret = createEmpty();
   while (getline(infile, read_data))
   {
      if (read_data.length() > 0)
      {
         enqueue(stoi(read_data), qret);
      }
   }
   return qret;
}

/* legge il contenuto di una coda da standard input */
Queue queue::readFromStdin()
{
   cout << "Inserire una sequenza di numeri separati da spazi seguiti da END per terminare\n";
   Queue qret = createEmpty();
   string read_data;
   cin >> read_data;
   while (read_data != "END")
   {
      enqueue(stoi(read_data), qret);
      cin >> read_data;
   }
   return qret;
}

/* stampa la coda*/
void queue::print(const Queue &q)
{
   cout << tostring(q) << endl;
}

/* produce una string contenente la coda*/
std::string queue::tostring(const Queue &q)
{
   string out = "";
   out += "{";
   list l = q.li;
   while (l != EMPTYLIST)
   {
      out += to_string(l->el);
      if (l != q.end)
      {
         out += ",";
      }
      l = l->next;
   }
   out += "}";
   return out;
}
