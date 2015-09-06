#include <iostream>
#include "myvector.h"

using namespace std;
using namespace Greati;

int main() {

	/* #1 Inicialização de objetos (chamadas de construtores): existem quatro maneiras!
	 * 
	 * 1) forma funcional, especificando os valores dos parametros: MyVector myv (10)
	 * 2) assignment syntax, para quando só há um parâmetro: MyVector myv = 10;
	 * 3) uniform initialization, parece com a funcional, mas usa chaves: MyVector myv {10}
	 * 4) POD-like, é como a anterior, mas usando um '=': MyVector myv = {10}
	 * 
	 * Usar o uniforme é bom porque não se confunde a chamada do construtor padrão com
	 * uma declaração de função normal. Ou seja, pode-se chamar o construtor padrão
	 * usando MyVector myv{}; mas não MyVector myv().
	 *
	 * O uso da inicialização uniforme pode permitir o uso de initializer_lists.
	 * 
	 * Inicialização de membros: melhor vista em src/myvector.cpp. É uma forma
	 * de inicializar os membros de uma classe diretamente na assinatura do construtor.
	 * É a única forma de inicilizar membros que são de outra classe que não possuem
	 * um construtor padrão!
	 *
	 * #2 Ponteiros de classes: funcionam como os ponteiros para os plain types.
	 * Por exemplo:
	 *
	 * MyVector * m;
	 * m = new MyVector{5};
	 * */
	
	Vector<int> vec = {1, 2, 3, 5};

	for (int i = 0; i < vec.size(); ++i) cout << vec[i] << endl;

	return 0;
}
