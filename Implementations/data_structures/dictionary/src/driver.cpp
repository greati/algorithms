#include <iostream>
#include "dictionary.h"
#include <functional>

using namespace std;

struct StringComp {
	int operator()(string a, string b) {
		if (a == b) return 0;
		else if (a < b) return -1;
		else return 1;
	}
};

int main() {

	cout << "*******************************************" << endl;
	cout << "Testing dictionary implementation." << endl;
	cout << "*******************************************" << endl;
	cout << endl;

	char opt = 'a';
	int cap = 50;

	cout << "What kind of Dictionary do you want? " << endl;
	cout << "u - unordered" << endl;
	cout << "o - ordered" << endl;
	cout << "Choose (u/o): " << endl;
	cin >> opt;
	cout << "Initial capacity (integer): " << endl;
	cin >> cap;
	
	DictionaryUnord<string, int, StringComp> dicUnord {cap};
	DictionaryOrd<string, int, StringComp> dicOrd {cap};
	Dictionary<string, int, StringComp> * dic;

	do {
		if (opt == 'u')
			dic = &dicUnord;
		else if (opt == 'o')
			dic = &dicOrd;
		else cout << "Invalid option." << endl << endl;
	} while (opt != 'u' && opt != 'o');

	string kt;
	int dt;

	for (int i = 0; i < cap; ++i) {
		kt = 'Z' - (i % 26);
		dt = i;
		dic->insert(kt, dt);
	}

	do {
		cout << "Dictionary state:" << endl;
		cout << (*dic);
		cout << "Size/Capacity: " << dic->getSize() << " / " << dic->getCapacity() << endl;
		cout << "Last operation: " << opt << endl << endl;
		cout << endl << endl;
	
		cout << "----------- MENU ------------" << endl;
		cout << "i - insert" << endl; 		
		cout << "r - remove" << endl; 		
		cout << "s - search" << endl; 		
		cout << "M - max" << endl; 		
		cout << "m - min" << endl; 		
		cout << "> - sucessor" << endl; 		
		cout << "< - predecessor" << endl; 		
		cout << "x - exit program" << endl; 		
		cout << "-----------------------------" << endl; 		
		cout << "What would you like to do? " << endl;
		cin >> opt;

		switch(opt) {
			case 'i':	
				cout << "New Key: ";
				cin >> kt;
				cout << "New Data at Key " << kt <<": ";
				cin >> dt;
				if(!dic->insert(kt, dt))
					cout << "Fail on inserting.\n";
				break;
			case 'r':	
				cout << "Key to Remove: ";
				cin >> kt;
				if(dic->remove(kt, dt)) 
					cout << "Removed data: " << dt << endl;
				else cout << "Fail on removing.\n";
				break;
			case 's':	
				cout << "Search for Key: ";
				cin >> kt;
				if(dic->search(kt, dt)) {
					cout << "Data at key " << kt << ": " << dt << endl;	
				} else cout << "Key " << kt << " not found." << endl;
				break;
			case 'M':
				if (dic->max(kt))
					cout << "Max Key: " << kt << endl;
				else cout << "Dictionary is empty." << endl;
				break;
			case 'm':
				if (dic->min(kt))
					cout << "Min Key: " << kt << endl;
				else cout << "Dictionary is empty." << endl;
				break;
			case '>':
				cout << "Key: " << endl;
				cin >> kt;
				if (dic->sucessor(kt, dt))
					cout << "Sucessor of " << kt << " has data " << dt << endl;
				else cout << "The element doesn't exist or has no sucessor." << endl;		
				break;
			case '<':
				cout << "Key: " << endl;
				cin >> kt;
				if (dic->predecessor(kt, dt))
					cout << "Predecessor of " << kt << " has data " << dt << endl;
				else cout << "The element doesn't exist or has no predecessor." << endl;
				break;
			case 'x':
				cout << "Bye! Success exit." << endl;
				break;
			default:
				cout << "Invalid option." << endl;	
		}
	} while (opt != 'x');
	
	return 0;
}
