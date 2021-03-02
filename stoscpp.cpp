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
int top(element* top);
int empty(element* top);
int pop(element* top, int& size);

int main() {
	element* top1 = NULL;
	int size1 = 0;

	init(top1);
	std::cout << top(top1) << std::endl;
	push(10, &top1);
	std::cout << top(top1) << std::endl;
	push(20, &top1);
	std::cout << top(top1) << std::endl;
	push(230, &top1);
	std::cout << top(top1) << std::endl;
	push(210, &top1);
	std::cout << top(top1) << std::endl;
	std::cout << pop(top1, size1) << std::endl;
	std::cout << pop(top1, size1) << std::endl;
	std::cout << pop(top1, size1) << std::endl;
	std::cout << empty(top1) << std::endl;
	std::cout << top(top1) << std::endl;

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
int empty(element* top) {
	return top == NULL;
}

/*Wyswietla liczbe na gorze stosu*/
int top(element* top) {
	return empty(top) ? -1 : top->number;
}

/// <summary>
/// Usuwa element z gory stosu
/// </summary>
/// <param name="top">wskaznik na gore stosu</param>
/// <param name="size">aktualny rozmiar stosu</param>
/// <returns>Usuniety element lub -1 dla pustej listy</returns>
int pop(element *top, int &size) {
	if (top == NULL) {
		return -1;
	}
	else {
		element* temp = top;
		int deleted = top->number;
		top = top->next;
		temp->next = NULL;
		return deleted;
	}
}