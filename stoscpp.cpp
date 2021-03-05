// Implementacja stosu na listach
#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h> //bardziej losowe liczby

#define MAX_SIZE 5 //maksymalny rozmiar stosu


//struktura przechowujaca liczbe i adres nastepnej liczby
struct element {
	int number;
	element* next;
};

void init(element* top);
int destroy(element** top, int& size);
int push(int number, element** top, int& size);
int pop(element** top, int& size);
int top(element* top);
int empty(element* top);
int full(element* top, int size);

int main() {
	element* top1 = NULL;
	int size1 = 0;
	
	init(top1); //inicjalizacja stosu

	int i = 0, ilosc_liczb, liczba;
	srand(time(NULL));
	/*biore ilosc liczb z zakresu 1-10, beda one czasami wieksze od MAX_SIZE, a czasami mniejsze*/
	ilosc_liczb = rand() % 10 + 1; 
	
	//cout pomagajacy testowac kod
	std::cout << "Tyle Wylosowalo: " << ilosc_liczb << std::endl;
	std::cout << "Taki jest limit stosu: " << MAX_SIZE << std::endl;

	//wrzucania na stos
	while (i <= ilosc_liczb) {
		liczba = rand() % 100 +1;
		push(liczba, &top1, size1);
		i++;
	}

	//wypisywanie
	while (top1->next != NULL) {
		std::cout << top1->number << std::endl;
		top1 = top1->next;
	}

	//usuwanie stosu bo tak
	destroy(&top1, size1);

	return 0;
}



/*przygotowanie stosu, zwraca wskaznik na gore stosu*/
void init(element* top) {
	//ustawiamy pierwszy element na NULL i mamy gotowy pusty stos
	top = NULL;
}
/*Dodaje element na poczatek listy => gore stosu, zwraca 0 gdy sukcess, 1 gdy stos jest pelny*/
int push(int number, element** top, int &size) {
	//wstawiamy na poczatek stosu przez co nie musimy iterowac na koniec i jest wydajniej

	if (full(*top, size)) return -1;
	
	element* new_element = NULL;
	new_element = new element;

	new_element->number = number;
	new_element->next = *top;
	*top = new_element;
	size += 1;
	return 0;
}
//zwraca 1 jesli stos je pusty i 0 w przeciwnym wypadku
int empty(element* top) {
	return top == NULL;
}

/*Wyswietla liczbe na gorze stosu*/
int top(element* top) {
	return empty(top) ? -1 : top->number;
}

/*Zwraca 1 gdy rozmiar stosu jest wiekszy badz rowny MAX SIZE*/
int full(element* top, int size) {
	return size > MAX_SIZE;
}

/*Usuwa element z gory stosu i zwraca 0 jesli sie udalo lub 0 gdy stos jest pusty*/
int pop(element* *top, int &size) {
	if (top == NULL) {
		return -1;
	}
	else {
		element* temp = (*top);
		*top = (*top)->next;
		delete temp;
		size--;
		return 0;
	}
}

/*Usuwa stos; zwalnia pamiec, zwaraca 0 gdy sie uda*/
int destroy(element** top, int &size) {
	element* temp = *top;
	element* next = NULL;

	while (temp->next != NULL) {
		next = temp->next;
		delete temp;
		temp = next;
	}
	*top = NULL;
	size = 0;
	return 0;
}