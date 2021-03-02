// Implementacja stosu na listach
#include <iostream>
#define MAX_SIZE 5 //maksymalny rozmiar stosu

//struktura przechowujaca liczbe i adres nastepnej liczby
struct element {
	int number;
	element* next;
};

void init(element* top);
void push(int number, element** top);
bool empty(element* top);

int main() {
	element* top1 = NULL;
	init(top1);
	push(10, &top1);
	std::cout << empty(top1);
	return 0;
}



//przygotowanie stosu
//zwraca wskaznik na gore stosu
void init(element* top) {
	//ustawiamy pierwszy element na NULL i mamy gotowy pusty stos
	top = NULL;
}

void push(int number, element** top) {
	//wstawiamy na poczatek stosu przez co nie musimy iterowac na koniec i jest wydajniej
	//nowy element 
	element* new_element = NULL;
	new_element = new element;

	new_element->number = number;
	new_element->next = *top;
	*top = new_element;
}
//zwraca 1 jesli stos je pusty i 0 w przeciwnym wypadku
bool empty(element* top) {
	return (top == NULL) ? true : false;
}
