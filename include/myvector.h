#ifndef _MYVECTOR_
#define _MYVECTOR_

using namespace std;

// #1: não precisaria declarar private, pois é padrão
// #2: os membros podem ser implementados diretamente na classe (inline) ou
// fora dela, usando o operador de escopo (normal)
// #3: o construtor não tem retorno e possui o mesmo nome da classe
// ele sempre inicializa o objeto, não podendo ser chamado como uma
// função normal
// #4: o construtor padrão é o que é chamado quando se faz simplesmente MyVector vec;
// #5: seria possivel usar a keyword struct para classes, com a diferença de que
// o escopo padrão é public, em vez de private
// #6: seria possível usar a keyword union também, mas só guardaria um membro de dado
// por vez, apesar de ainda poder definir membros de funções em seu interior. 
// #7: para a sobrecarga de operadores
namespace Greati {
	
	const int DEFAULT_SIZE = 1;

	template<typename T>
	class Vector {
		private:
			T* vecData;
			int vecSize;
		public:
			/* + Vector(int)
			 *
			 * Constructor: takes the size.
			 * As parameter is optional, it can be considered
			 * the default constructor.
			 * */
			Vector(int psize = DEFAULT_SIZE);
			
			/* + Vector(int, T&)
			 *
			 * Constructor: takes the size and an initial value.
			 * */
			Vector(int psize, const T& initial);
			
			/* + Vector(const initializer_list<T> &)
			 *
			 * Constructor: takes a list at initialization.
			 * */
			Vector(const initializer_list<T> &);

			/* + Vector(Vector)
			 *
			 * Construtor cópia.
			 * */
			Vector(const Vector &);

			/* + ~Vector()
			 *
			 * Destructor method.
			 * */
			~Vector(void);

			/* + int size(void) const
			 * 
			 * Returns the size of member data.
			 * Here, "const" means that the function is not allowed
			 * to change members' values.
			 * */
			int size(void) const;

			/* + fill(const T&)
			 *
			 * Fill vector with a value.
			 * */
			void fill(const T&);

			/* ==================
			 * Operators overload
			 * ------------------
			 * */
			// AssigAt operador
			T& operator[](int);
			// At operator
			const T operator[](int) const;
			// Equals operator
			bool operator==(const Vector &) const;
		        // Assign operator
			const Vector& operator=(const Vector &);	
			// Assign list operator
			const Vector& operator=(const initializer_list<T> &);
	};
}
#include "../src/myvector.cpp"
#endif
