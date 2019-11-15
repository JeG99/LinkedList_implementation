#include <iostream>
#include "LinkedList.h"

int main(){
	
	LinkedList<int> miLista1;
	LinkedList<int> miLista2;
	LinkedList<int> miLista3;

	std::cout << (miLista1.isEmpty() ? 'T' : 'F' ) << '\n';
	std::cout << (miLista2.isEmpty() ? 'T' : 'F' ) << '\n';
	std::cout << (miLista3.isEmpty() ? 'T' : 'F' ) << '\n';

	miLista1.addLast(1);
	miLista1.addLast(2);
	miLista1.addLast(3);
	miLista1.addLast(4);

	miLista2.addFirst(1);
	miLista2.addLast(23);
	miLista2.addLast(24);	

	miLista1.print();
	miLista2.print();


	std::cout << (miLista2==miLista1 ? 'T' : 'F') << '\n';

	miLista1 += 69;
	miLista1 += 70;
	miLista1.print();
	miLista1 += miLista2;
	miLista1 += miLista2;
	miLista1.print();
	miLista1 += 70;
	miLista1.print();
	//miLista3 += 3;
	miLista3 += miLista1;
	miLista3.print();

	LinkedList<int> miChile(miLista3);
	miChile.addLast(123);
	miChile.print();
	//miChile.addFirst(6);
	//miChile.print();
	miChile.reverse();
	miChile.print();
	
	std::cout << '\n';
	
	miChile.addFirst(3);
	miChile.print();
	
	std::cout << '\n';
	
	miChile.shift(1);
	miChile.print();
	miChile.shift(-1);
	miChile.print();
	
	std::cout << '\n';

	LinkedList<std::string> holaputos1;
	LinkedList<std::string> holaputos2;
	std::cout << (holaputos1 == holaputos2 ? 'T' : 'F' ) << '\n';

	std::cout << '\n';

	LinkedList<int> test;
	for(int i = 0; i < 10; i++){
		test.addLast(i);
	}
	test.print();
	test.shift(1);
	test.print();

}

