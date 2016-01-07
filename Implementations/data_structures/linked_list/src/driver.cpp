#include <iostream>
#include "List.h"

using namespace std;
using namespace Greati;

int main(void) {

	List<string> animais;
	
	string a = "Baleia";
	string b = "Coruja";
	string c = "Amour";
	string d = "Zangado";

	animais.push_front(a);
	animais.push_back(b);

	cout << animais;

	cout << *(animais.find(b)) << endl;

	List<string> animais2; 
	animais2 = animais;

	cout << animais2;

	animais.pop_front();
	animais.pop_back();
	//for (auto i (animais.begin()); i != nomes.end(); ++i) {
	//	cout << *i->dat;
	//}

	return 0;
};
