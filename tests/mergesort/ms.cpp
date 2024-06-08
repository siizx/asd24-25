#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std; // minchia, mi ero dimenticato tutte ste cazzatine

void mergesort(vector<int> &v){
	if(v.size() > 0) ms(v, 0, v.size()-1);
}

void ms(vector<int> &v, int inizio, int fine){
	if(inizio < fine){
		int centro = (inizio + fine) / 2;
		ms(v, inizio, centro);
		ms(v, centro+1, fine);
		fondi(v, inizio, centro, fine);
	}
}

void fondi(vector<int> &v, int inizio, int centro, int fine){
	if(inizio < fine){
		
		// creo 2 vector che utilizzero' per effettuare gli scambi in place:
		vector<int> d,s;
		// li popolo:
		for(int i=0; i < centro; i++){
			s.pushback(v[i]);
		}
		for(int j = centro; j<= fine; j++){
			d.pushback(v[j]);
		}

		// ora creo tutte le variabili ausiliarie:

	}
}

int main(){
	
	std::vector<int> v = { 22, 536, 75 ,1 ,95, 83, 99, 20, 17, 53 };

	cout << "Vector disordinato: ";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

	
	mergesort(v);

	
	cout << "Vector ordinato: ";
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;

}
