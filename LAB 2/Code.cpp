#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

struct Node {
	int Data;
	Node* Previous = NULL, * Next = NULL;
	Node(int Data) {
		this->Data = Data;
		this->Previous = this->Next;
	}
};

struct Double_Linked_List {
	Node* Head  = NULL, * Tail = NULL;
	
	void Output() {
		Node* Element = Head;
		while (Element != NULL) {
			cout << Element->Data << " ";
			Element = Element->Next;
		}
		cout << endl;
	}
	
	Node* Create_Double_Linked_List(int data) {
		Node* Current_Element = new Node(data);
		Current_Element->Previous = Tail;
		if (Tail != NULL) {
			Tail->Next = Current_Element;
		}
		if (Head == NULL) {
			Head = Current_Element;
		}
		Tail = Current_Element;
		return Current_Element;
	}
	Node* Get_Element(int Index) {
		{
			Node* Current_Element = Head;
			int Count = 0;
			while (Count != Index)
			{
				if (Current_Element == NULL)
					return Current_Element;
				Current_Element = Current_Element->Next;
				Count++;
			}
			return Current_Element;
		}
	}

	Node* Insert_Element(int Index, int Data) {
		Node* Right = Get_Element(Index);
		if (Right == NULL) {
			Node* Current_Element = new Node(Data);
			Current_Element->Data = Data;
			Current_Element->Previous = Tail;
			Tail->Next = Current_Element;
			Current_Element->Next = 0;
			Tail = Current_Element;
			return Current_Element;
		}
		
		Node* Left = Right->Previous;
		if (Left == NULL)
		{
			Node* Current_Element = new Node(Data);
			Current_Element->Data = Data;
			Current_Element->Next = Head;
			Head->Previous = Current_Element;
			Current_Element->Previous = 0;
			Head = Current_Element;
			return Current_Element;
		}

		Node* Current_Element = new Node(Data);
		Current_Element->Next = Right;
		Current_Element->Previous = Left;
		Left->Next = Current_Element;
		Right->Previous = Current_Element;
		Current_Element->Data = Data;
		return Current_Element;
	}

	Node* Delete(Node* var) {
		Node* Current_Element = var;
		if (Current_Element->Previous == NULL)
		{
			Node* Element = Head->Next;
			Element->Previous = NULL;
			delete Head;
			Head = Element;
			return Element;
		}
		if (Current_Element->Next == NULL)
		{
			Node* Element = Tail->Previous;
			Element->Next = NULL;
			delete Tail;
			Tail = Element;
		}
		if (Current_Element->Next != 0 and Current_Element->Previous != 0)
		{
			Node* Left = Current_Element->Previous;
			Node* Right = Current_Element->Next;
			Left->Next = Right;
			Right->Previous = Left;
			delete Current_Element;
		}
	}
	
	void Delete_Element_By_Index(int Index) {
		Delete(Get_Element(Index));
	}


	void Swap_Elements(int Index_1, int Index_2) {
		Node* First_Element = Head, * Second_Element = Head;
		for (int i = 0; i < Index_1; i++) {
			First_Element = First_Element->Next;
		}
		for (int i = 0; i < Index_2; i++) {
			First_Element = First_Element->Next;
		}
		int Temporary_Variable = First_Element->Data;
		First_Element->Data = Second_Element->Data;
		Second_Element->Data = Temporary_Variable;
	}
};
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	unsigned short int Choise, List_Size, Elemet_Number = 0, Flag = 0;
	int Data;
	unsigned int Unsigned_Data, Index, Index_;
	Double_Linked_List list;
	time_point<steady_clock> start;
	time_point<steady_clock> end;
	while (true)
	{
		cout << "   Меню:\n\n"
			"1) Сформировать двусвязанный список.\n"
			"2) Вставить элемент.\n"
			"3) Удалить элемент.\n"
			"4) Обменять элементы\n"
			"5) Получить элемент.\n\n"
			"0) Выход.\n\n"
			"Ответ: ";
		cin >> Choise;
		system("cls");
		
		if (Choise == 0)
		{
			break;
		}
		
		if (Choise != 1 && Flag == 0) {
			Choise = 1;
			cout << "Для начала сформируйте список.\n\n";
		}

		switch (Choise){
		case 1:
			
			Flag = 1;

			while (true){
				cout << "1) Ввести элементы в ручную (только положительные числа).\n"
					"2) Сгенерировать список рандомно от 0 до 99.\n\n"
					"0) Выход.\n\n"
					"Ответ: ";
				cin >> Choise;
				
				system("cls");

				if (Choise == 0)
				{
					break;
				}
				
				switch (Choise)
				{
				case 1:
					
					start = chrono::steady_clock::now();
					
					while (true) {
						cout << "Введите элемет списка: ";
						cin >> Data;
						
						if (Data < 0) {
							break;
						}
						
						Elemet_Number++;
						list.Create_Double_Linked_List(Data);
						system("cls");
						cout << "Чтобы завершить ввод введите отрицательное число\n\n";
					}
					
					end = chrono::steady_clock::now();
					
					list.Output();
					cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.\n";
					system("pause");
					break;
				case 2:
					cout << "Размер списка: ";
					cin >> List_Size;
					system("cls");
					
					start = chrono::steady_clock::now();
					
					while (Elemet_Number < List_Size) {
						Data = rand() % 100;
						list.Create_Double_Linked_List(Data);
						Elemet_Number++;
					}
					
					end = chrono::steady_clock::now();
					
					list.Output();
					cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.\n";
					system("pause");
					system("cls");
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				cout << "Введите индекс: ";
				cin >> Index;
				Index--;
				system("cls");
				if (Index < Elemet_Number) {
					break;
				}
				cout << "Введите индекс от 1 до " << Elemet_Number << "\n\n";
			}
			
			cout << "Введите значение элеметa: ";
			cin >> Unsigned_Data;
			system("cls");
			
			start = chrono::steady_clock::now();
			
			list.Insert_Element(Index, Unsigned_Data);

			end = chrono::steady_clock::now();

			list.Output();
			cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.\n";
			system("pause");
			system("cls");
			Elemet_Number++;
			break;
		case 3:
			while (true)
			{
				cout << "Введите индекс: ";
				cin >> Index;
				Index--;
				system("cls");
				if (Index < Elemet_Number) {
					break;
				}
				cout << "Введите индекс от 1 до " << Elemet_Number << "\n\n";
			}
			
			start = chrono::steady_clock::now();
			
			list.Delete_Element_By_Index(Index);

			end = chrono::steady_clock::now();

			list.Output();
			cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.\n";
			system("pause");
			system("cls");
			Elemet_Number--;
			break;
		case 4:

			while (true)
			{
				cout << "Введите индексы: ";
				cin >> Index >> Index_;
				Index--;
				Index_--;
				if (Index < Elemet_Number && Index_ < Elemet_Number && Index != Index_) {
					break;
				}
				cout << "Введите индекс от 1 до " << Elemet_Number << "\nИндексы не должны быть равными\n\n.";
			}
			
			start = chrono::steady_clock::now();

			list.Swap_Elements(Index, Index_);

			end = chrono::steady_clock::now();

			list.Output();
			cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.\n";
			system("pause");
			system("cls");
			break;
		case 5:
			while (true)
			{
				cout << "Введите индекс: ";
				cin >> Index;
				Index--;
				system("cls");
				if (Index < Elemet_Number) {
					break;
				}
				cout << "Введите индекс от 1 до " << Elemet_Number << "\n\n";
			}
			start = chrono::steady_clock::now();

			cout <<"Итого:" << list.Get_Element(Index)->Data;

			end = chrono::steady_clock::now();
			cout << "Затраченное время: " << duration_cast<microseconds>(end - start).count() << " мкс.\n";
			system("pause");
			system("cls");
			break;
		default:
			cout << "???";
			break;
		}
	}
}