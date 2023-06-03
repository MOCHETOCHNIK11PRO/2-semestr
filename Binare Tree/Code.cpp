#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

struct Node {
	int Key;
	Node* Left;
	Node* Right;
	Node(int Key)
	{
		this->Key = Key;
		this->Left = this->Right = nullptr;
	}
};
struct Trunk
{
	Trunk* Previous;
	string str;

	Trunk(Trunk* Previous, string str)
	{
		this->Previous = Previous;
		this->str = str;
	}
};

struct Binary_Tree {
	Node* Root = NULL;
	int Size = 0;

	void Insert(int Key) {
		if (Root)
			Insert(Key, Root);
		else {
			Root = new Node(Key);
			Root->Key = Key;
			Root->Left = NULL;
			Root->Right = NULL;
		}
	}

	void Destroy() {
		Destroy_Tree(Root);
	}

	void Show() {
		Print_Tree(Root, NULL, false);
	}

	void Read_From_File() {
		ifstream Massiv;
		Massiv.open("Massiv.txt");
		if (Massiv.is_open()) {
			int i;
			vector<int> arr;
			while (!Massiv.eof()) {
				Massiv >> i;
				arr.push_back(i);
			}
			for (int n : arr)
				Insert(n);
		}
		Massiv.close();
	}

	int Search(int Key) {
		Search(Key, Root);
		if (Search(Key, Root) != NULL) {
			cout << "Данное число есть в дереве" << '\n';
			return 1;
		}
		cout << "Данного числа нет в дереве" << '\n';
		return 0;
	}

	void Find_Min() {
		cout << "Минимальное значение: " << Find_Min(Root)->Key << '\n';
	}

	void Find_Max() {
		cout << "Максимальное значение: " << Find_Max(Root)->Key << '\n';
	}

	void Delete_Key(int Item) {
		Delete_Key(Root, Item);
	}

	void Size_Tree() {
		Size_Tree(Root);
		cout << "Размер бинарного дерева: " << Size << '\n';
	}

	void Direct_Bypass() {
		Direct_Bypass(Root);
	}

	void Reverse_Bypass() {
		Reverse_Bypass(Root);
	}

	void Width_Bypass() {
		Width_Bypass(Root);
	}

	void Print_In_File(string R) {
		ofstream Output(R);
		Print_Tree(Root, NULL, false, Output);
		Output.close();
	}

	void Insert(int Key, Node* Leaf) {
		if (Key < Leaf->Key) {
			if (Leaf->Left != NULL)
				Insert(Key, Leaf->Left);
			else {
				Leaf->Left = new Node(Key);
				Leaf->Left->Key = Key;
				Leaf->Left->Left = NULL;
				Leaf->Left->Right = NULL;
			}
		}
		else {
			if (Leaf->Right != NULL)
				Insert(Key, Leaf->Right);
			else {
				Leaf->Right = new Node(Key);
				Leaf->Right->Key = Key;
				Leaf->Right->Left = NULL;
				Leaf->Right->Right = NULL;
			}
		}
	}

	void Destroy_Tree(Node* Leaf) {
		if (Leaf) {
			Destroy_Tree(Leaf->Left);
			Destroy_Tree(Leaf->Right);
			delete Leaf;
		}
	}

	Node* Delete_Key(Node* Leaf, int Item) {
		if (Leaf->Key == Item) {
			if (Leaf->Left == NULL && Leaf->Right == NULL)
				return NULL;
			if (Leaf->Left == NULL)
				return Leaf->Right;
			if (Leaf->Right == NULL)
				return Leaf->Left;

			const Node* Min_Node_In_Right_Tree = Find_Min(Leaf->Right);
			Leaf->Key = Min_Node_In_Right_Tree->Key;
			Leaf->Right = Delete_Key(Leaf->Right, Min_Node_In_Right_Tree->Key);
			return Leaf;
		}
		if (Item < Leaf->Key) {
			if (Leaf->Left == NULL) {
				cout << "Элемента нет в дереве " << "\n";
				return Leaf;
			}
			Leaf->Left = Delete_Key(Leaf->Left, Item);
			return Leaf;
		}
		if (Item > Leaf->Key) {
			if (Leaf->Right == NULL) {
				cout << "Элемента нет в дереве" << '\n';
				return Leaf;
			}
			Leaf->Right = Delete_Key(Leaf->Right, Item);
			return Leaf;
		}
	}

	Node* Search(int Key, Node* Leaf) {
		if (Leaf) {
			if (Key == Leaf->Key) {

				return Leaf;
			}
			if (Key < Leaf->Key)
				return Search(Key, Leaf->Left);
			else
				return Search(Key, Leaf->Right);
		}
		else {

			return NULL;
		}
	}

	Node* Find_Min(Node* Leaf) {
		if (Leaf->Left == NULL) {
			return Leaf;
		}
		return Find_Min(Leaf->Left);
	}

	Node* Find_Max(Node* Leaf) {
		if (Leaf->Right == NULL) {
			return Leaf;
		}
		return Find_Max(Leaf->Right);
	}

	void Size_Tree(Node* Leaf) {
		if (Leaf) {
			Size++;
			Size_Tree(Leaf->Left);
			Size_Tree(Leaf->Right);
		}
	}

	void Direct_Bypass(Node* Leaf) {
		if (Leaf) {
			cout << Leaf->Key << ' ';
			Direct_Bypass(Leaf->Left);
			Direct_Bypass(Leaf->Right);
		}
	}

	void Reverse_Bypass(Node* Leaf) {
		if (Leaf) {
			Reverse_Bypass(Leaf->Left);
			Reverse_Bypass(Leaf->Right);
			cout << Leaf->Key << ' ';
		}
	}

	void Width_Bypass(Node* Leaf) {
		queue<Node*> nodeQueue;
		nodeQueue.push(Leaf);
		while (!nodeQueue.empty()) {
			Leaf = nodeQueue.front();
			cout << Leaf->Key << ' ';
			nodeQueue.pop();
			if (Leaf->Left) {
				nodeQueue.push(Leaf->Left);
			}
			if (Leaf->Right) {
				nodeQueue.push(Leaf->Right);
			}
		}
	}

	void Show_Trunks(Trunk* p)
	{
		if (p == NULL) {
			return;
		}

		Show_Trunks(p->Previous);
		cout << p->str;
	}

	void Print_Tree(Node* Leaf, Trunk* Previous, bool isRight)
	{
		if (Leaf == NULL) {
			return;
		}

		string Previous_str = "    ";
		Trunk* trunk = new Trunk(Previous, Previous_str);

		Print_Tree(Leaf->Right, trunk, true);

		if (!Previous) {
			trunk->str = "——>";
		}
		else if (isRight) {
			trunk->str = ".——>";
			Previous_str = "   |";
		}
		else {
			trunk->str = "`-—>";
			Previous->str = Previous_str;
		}

		Show_Trunks(trunk);
		cout << " " << Leaf->Key << '\n';

		if (Previous) {
			Previous->str = Previous_str;
		}
		trunk->str = "   |";

		Print_Tree(Leaf->Left, trunk, false);
	}

	void Print_Tree(Node* Leaf, Trunk* Previous, bool isRight, ofstream& f2) {
		if (Leaf == NULL)
			return;
		string Previous_str = "    ";
		Trunk* trunk = new Trunk(Previous, Previous_str);
		Print_Tree(Leaf->Right, trunk, true, f2);
		if (!Previous) {
			trunk->str = "-->";
		}
		else if (isRight) {
			trunk->str = ".-->";
			Previous_str = "   |";
		}
		else {
			trunk->str = "`-->";
			Previous->str = Previous_str;
		}

		ShowTrunk(trunk, f2);
		f2 << Leaf->Key << '\n';

		if (Previous) {
			Previous->str = Previous_str;
		}
		trunk->str = "   |";
		Print_Tree(Leaf->Left, trunk, false, f2);
	}
	void ShowTrunk(Trunk* p, ofstream& f2) {
		if (p == NULL)
			return;
		ShowTrunk(p->Previous, f2);
		f2 << p->str;
	}
};

void Clear(string File) {
	ofstream file(File);
	file << "";
	file.close();
}

Binary_Tree Create_Tree_Random_Vector(ofstream& output_ans) {
	vector<int> Numb;
	int Massive_Size = rand() % 150;
	for (int k = 0; k < Massive_Size; k++) {
		int ElemMas = rand() % (198) - 99;
		Numb.push_back(ElemMas);
	}
	Binary_Tree New_Tree;
	for (int n : Numb) {
		New_Tree.Insert(n);
	}
	New_Tree.Print_Tree(New_Tree.Root, NULL, false, output_ans);
	return New_Tree;
}

void Print_Menu() {
	system("cls");
	cout << "Что выхотите сделать?" << '\n';
	cout << "1. Вывести в консоль и файл бинарное дерево" << '\n';
	cout << "2. Добавить новый элемент в дерево" << '\n';
	cout << "3. Удалить элемент дерева" << '\n';
	cout << "4. Найти элемент дерева" << '\n';
	cout << "5. Прямой обход дерева" << '\n';
	cout << "6. Обратный обход дерева" << '\n';
	cout << "7. Обход в ширину дерева" << '\n';
	cout << "8. Генерация заданий и их выполнение" << '\n';
	cout << "9. Выйти из программы" << '\n';
}

void Menu() {
	int Variant;
	srand(time(0));
	Binary_Tree Tree;
	Binary_Tree Binary_Tree1;
	ofstream Output_Key("output_Key.txt", ios::app);
	ofstream Output_Task("output_task.txt", ios::app);
	ofstream Output_Ans("output_ans.txt", ios::app);
	Clear("output_Key.txt");
	Clear("output_ans.txt");
	Clear("output_task.txt");
	int N;
	int Var;
	vector<int> Numb;
	vector<int> Numbers;
	cout << "1. Самостоятельно заполнить дерево" << '\n';
	cout << "2. Автоматически заполнить дерево" << '\n';
	cout << "3. Заполнить дерево элементами из файла" << '\n';
	cin >> Var;
	switch (Var) {
	case 1:
		int Number;
		cout << "Вводите числа в массив, для окончания напишите 1000" << '\n';
		cin >> Number;
		while (Number != 1000) {
			Numbers.push_back(Number);
			cin >> Number;
		}
		for (int i : Numbers) {
			Binary_Tree1.Insert(i);
		}
		break;
	case 2:
		cout << "Введите размер дерева: ";
		cin >> N;
		cout << '\n';
		for (int i = 0; i < N; i++) {
			int data = rand() % (199) - 99;
			Binary_Tree1.Insert(data);
		}
		break;
	case 3:
		Binary_Tree1.Read_From_File();
		break;
	}
	do {
		Print_Menu();
		int Value;
		cin >> Variant;
		switch (Variant) {
		case 1:
			Binary_Tree1.Show();
			Binary_Tree1.Print_In_File("Output.txt");
			break;
		case 2:
			cout << '\n' << "Введите значение которое хотите добавить в дерево: ";
			cin >> Value;
			Binary_Tree1.Insert(Value);
			break;
		case 3:
			cout << '\n' << "Введите значение которое хотите удалить из дерева: ";
			cin >> Value;
			Binary_Tree1.Delete_Key(Value);
			break;
		case 4:
			cout << '\n' << "Введите значение которое хотите найти в дереве: ";
			cin >> Value;
			Binary_Tree1.Search(Value);
			break;
		case 5:
			cout << "Прямой обход дерева: " << '\n';
			Binary_Tree1.Direct_Bypass();
			break;
		case 6:
			cout << "Обратный обход дерева: " << '\n';
			Binary_Tree1.Reverse_Bypass();
			break;
		case 7:
			cout << "Обход дерева в ширину: " << '\n';
			Binary_Tree1.Width_Bypass();
			break;
		case 8:
			int N;
			Binary_Tree* pTree = NULL;
			cout << "Введите количество генерируемых заданий: ";
			cin >> N;
			for (int i = 0; i < N; i++) {
				int v = rand() % 3;
				int Massive_Size;
				int Elem;
				switch (v) {
				case 0:
					Output_Task << i << ") Создание бинарного дерева из массива" << '\n';
					Output_Key << i << ") Дерево создано" << '\n';
					Output_Ans << i << ") Созданное дерево: " << '\n';
					Tree = Create_Tree_Random_Vector(Output_Ans);
					pTree = &Tree;
					Output_Ans << '\n';
					break;
				case 1:
					if (pTree) {
						Output_Task << i << ") Удаление элемента из бинарного дерева " << '\n';
						Elem = rand() % (198) - 99;
						Tree.Delete_Key(Elem);
						if (Tree.Search(Elem) != 0) {
							Output_Key << i << ") Элемент " << Elem << " удалён из дерева" << '\n';
							Output_Ans << i << ") Элемент " << Elem << " удалён из дерева, дерево без него:" << '\n';
							Tree.Print_Tree(Tree.Root, NULL, false, Output_Ans);
							Output_Ans << '\n';
						}
						else {
							Output_Key << i << ") Элемент " << Elem << " не был удалён, поскольку его нет в дереве" << '\n';
							Output_Ans << i << ") Элемент " << Elem << " не был удалён, поскольку его нет в дереве" << '\n';
						}
						break;
					}
					else {
						Output_Task << i << ") Удаление элемента из бинарного дерева " << '\n';
						Output_Key << i << ") Дерево ещё не создано, будет создано случайное дерево для удаления элемента" << '\n';
						Output_Ans << i << ") Дерево ещё не создано, будет создано случайное дерево для удаления элемента" << '\n';
						Output_Ans << "Созданное дерево: " << '\n';
						Tree = Create_Tree_Random_Vector(Output_Ans);
						pTree = &Tree;
						Output_Ans << '\n';
						Elem = rand() % (198) - 99;
						Tree.Delete_Key(Elem);
						if (Tree.Search(Elem) != 0) {
							Output_Key << "Элемент " << Elem << " удалён из дерева" << '\n';
							Output_Ans << "Элемент " << Elem << " удалён из дерева, дерево без него:" << '\n';
							Tree.Print_Tree(Tree.Root, NULL, false, Output_Ans);
							Output_Ans << '\n';
						}
						else {
							Output_Key << "Элемент " << Elem << " не был удалён, поскольку его нет в дереве" << '\n';
							Output_Ans << "Элемент " << Elem << " не был удалён, поскольку его нет в дереве" << '\n';
						}
						break;
					}

				case 2:
					if (pTree) {
						Output_Task << i << ") Добавление элемента в дерево " << '\n';
						Elem = rand() % (198) - 99;
						Tree.Insert(Elem);
						Output_Key << i << ") Элемент " << Elem << " был добавлен в дерево" << '\n';
						Output_Ans << i << ") Элемент " << Elem << " был добавлен в дерево, дерево с этим элементом: " << '\n';
						Tree.Print_Tree(Tree.Root, NULL, false, Output_Ans);
						Output_Ans << '\n';
						break;
					}
					else {
						Output_Task << i << ") Добавление элемента в дерево " << '\n';
						Output_Key << i << ") Дерево ещё не создано, будет создано случайное дерево для добавления элемента элемента" << '\n';
						Output_Ans << i << ") Дерево ещё не создано, будет создано случайное дерево для добавления элемента" << '\n';
						Output_Ans << "Созданное дерево: " << '\n';
						Tree = Create_Tree_Random_Vector(Output_Ans);
						pTree = &Tree;
						Output_Ans << '\n';
						Elem = rand() % (198) - 99;
						Tree.Insert(Elem);
						Output_Key << "Элемент " << Elem << "был добавлен в дерево" << '\n';
						Output_Ans << "Элемент " << Elem << " был добавлен в дерево, дерево с этим элементом: " << '\n';
						Tree.Print_Tree(Tree.Root, NULL, false, Output_Ans);
						Output_Ans << '\n';
						break;
					}
				}
			}
			break;
		}
		if (Variant != 9)
			system("pause");
	} while (Variant != 9);
	Binary_Tree1.Destroy();
	Tree.Destroy();
	Output_Ans.close();
	Output_Key.close();
	Output_Task.close();
}

int main() {
	setlocale(0, "");
	srand(time(0));
	Menu();
	Clear("Output.txt");
}