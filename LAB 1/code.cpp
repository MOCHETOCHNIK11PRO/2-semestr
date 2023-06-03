#include <iostream> 
#include <string>  
#include <Windows.h> 

using namespace std;

struct Students {																			
	string Firs_Middle_Last_Names;															
	unsigned int Group_Number, Number_In_Group;												
	short unsigned int Floor, Alg_And_Geom, Math_Analysis, Programming, Physics,			
		Pysical_Education, Philosophy, History, Ecology;									
	float Avarage_Mark;																		
};

const int Size = 10;																	
struct Students students[Size];															

void Data_Add(int Quantity) {																
	SetConsoleCP(1251);																		
	cout << "Данные студента\n\n"															
		"Введите ФИО: ";																	
	getline(cin >> ws, students[Quantity].Firs_Middle_Last_Names);							
	SetConsoleCP(866);																	
	
	while (true) {																			
		cout << "Введите пол\n"																
			"1) Мужской\n"																    
			"2) Женский\n\n"															    
			"Ответ: ";																       
		cin >> students[Quantity].Floor;												    
		if (students[Quantity].Floor == 1 || students[Quantity].Floor == 2) {		        
			break;																			 
		}
	}

	cout << "Введите номер группы: ";														
	cin >> students[Quantity].Group_Number;													
	
	cout << "Введите номер студента в группе: ";											
	cin >> students[Quantity].Number_In_Group;												

	cout << "\n\nОцнки за прошлую сессию\n\n"												
		"Алгебра и геометрия: ";															
	cin >> students[Quantity].Alg_And_Geom;													
	while (students[Quantity].Alg_And_Geom < 2 || students[Quantity].Alg_And_Geom > 5) {	
		cout << "???";																		
		cin >> students[Quantity].Alg_And_Geom;												
	}

	cout << "Математический анализ: ";														
	cin >> students[Quantity].Math_Analysis;												
	while (students[Quantity].Math_Analysis < 2 || students[Quantity].Math_Analysis > 5) {  
		cout << "???";																		
		cin >> students[Quantity].Math_Analysis;											
	}

	cout << "Программирование: ";															
	cin >> students[Quantity].Programming;													
	while (students[Quantity].Programming < 2 || students[Quantity].Programming > 5) {		
		cout << "???";																		
		cin >> students[Quantity].Programming;												
	}

	cout << "Физика: ";																		
	cin >> students[Quantity].Physics;														
	while (students[Quantity].Physics < 2 || students[Quantity].Physics > 5) {				
		cout << "???";																		
		cin >> students[Quantity].Physics;													
	}

	cout << "Физ-ра: ";																		
	cin >> students[Quantity].Pysical_Education;											
	while (students[Quantity].Pysical_Education < 2 || students[Quantity].Pysical_Education > 5) { 
		cout << "???";																			  
		cin >> students[Quantity].Pysical_Education;											 
	}

	cout << "Философия: ";																	
	cin >> students[Quantity].Philosophy;													
	while (students[Quantity].Philosophy < 2 || students[Quantity].Philosophy > 5) {	
		cout << "???";																		
		cin >> students[Quantity].Philosophy;												
	}

	cout << "История: ";															
	cin >> students[Quantity].History;														
	while (students[Quantity].History < 2 || students[Quantity].History > 5) {			
		cout << "???";																		
		cin >> students[Quantity].History;													
	}

	cout << "Экология: ";																
	cin >> students[Quantity].Ecology;														
	while (students[Quantity].Ecology < 2 || students[Quantity].Ecology > 5) {			
		cout << "???";																		
		cin >> students[Quantity].Ecology;													
	}
																							
	students[Quantity].Avarage_Mark = (students[Quantity].Alg_And_Geom + students[Quantity].Math_Analysis + students[Quantity].Programming + students[Quantity].Physics + students[Quantity].Pysical_Education + students[Quantity].Philosophy + students[Quantity].History + students[Quantity].Ecology) / 8;
	system("pause");																		
}

void Data_Correct(int Quantity) {																				
	short unsigned int Correct_Number, Choice;																	
	cout << "Введите номер студента который хотите исправить: ";													
	while (true) {																									
		cin >> Correct_Number;																					
		Correct_Number--;																						
		system("cls");																								
		if (Correct_Number < Quantity) {																		
			while (true) {																							
				cout << "\n   Выбирете хотите исправить:"															
					"\n1) ФИО"																						
					"\n2) Пол"																						
					"\n3) Номер группы"																				
					"\n4) Номер в группе"																			
					"\n   Оценки за:"																				
					"\n5) Алгебра и геометрия"																		
					"\n6) Математический анализ"																	
					"\n7) Программирование"																			
					"\n8) Физика"																					
					"\n9) Физ-ра"																					
					"\n10) Философия"																				
					"\n11) История"																					
					"\n12) Экология"																				
					"\n\n13) Назад"																					
					"\n0) Выход"																					
					"\n\nОтвет: ";																					
																													
				cin >> Choice;																						
				system("cls");																						
				cout << "Исправление: ";																			
																													
				if (Choice == 0 || Choice == 13) {																	
					break;																							
				}																									
				if (Choice == 1) {																					
					SetConsoleCP(1251);																				
					getline(cin >> ws, students[Correct_Number].Firs_Middle_Last_Names);							
					SetConsoleCP(866);																				
				}																									
				if (Choice == 2) {																					
					while (true) {																					
						cout << "\n"																				
							"1) Мужской\n"																			
							"2) Женский\n\n"																		
							"Ответ: ";																				
						cin >> students[Correct_Number].Floor;														
						if (students[Correct_Number].Floor == 1 || students[Correct_Number].Floor == 2) {			
							break;																					
						}																					
					}																								
				}																									
				if (Choice == 3) {
					cin >> students[Correct_Number].Group_Number;
				}
				if (Choice == 4) {
					cin >> students[Correct_Number].Number_In_Group;
				}
				if (Choice == 5) {
					cin >> students[Correct_Number].Alg_And_Geom;
					while (students[Correct_Number].Alg_And_Geom < 2 || students[Correct_Number].Alg_And_Geom > 5) {
						cout << "???";
						cin >> students[Correct_Number].Alg_And_Geom;
					}
				}
				if (Choice == 6) {
					cin >> students[Correct_Number].Math_Analysis;
					while (students[Correct_Number].Math_Analysis < 2 || students[Correct_Number].Math_Analysis > 5) {
						cout << "???";
						cin >> students[Correct_Number].Math_Analysis;
					}
				}
				if (Choice == 7) {
					cin >> students[Correct_Number].Programming;
					while (students[Correct_Number].Programming < 2 || students[Correct_Number].Programming > 5) {
						cout << "???";
						cin >> students[Correct_Number].Programming;
					}
				}
				if (Choice == 8) {
					cin >> students[Correct_Number].Physics;
					while (students[Correct_Number].Physics < 2 || students[Correct_Number].Physics > 5) {
						cout << "???";
						cin >> students[Correct_Number].Physics;
					}
				}
				if (Choice == 9) {
					cin >> students[Correct_Number].Pysical_Education;
					while (students[Correct_Number].Pysical_Education < 2 || students[Correct_Number].Pysical_Education > 5) {
						cout << "???";
						cin >> students[Correct_Number].Pysical_Education;
					}
				}
				if (Choice == 10) {
					cin >> students[Correct_Number].Philosophy;
					while (students[Correct_Number].Philosophy < 2 || students[Correct_Number].Philosophy > 5) {
						cout << "???";
						cin >> students[Correct_Number].Philosophy;
					}
				}
				if (Choice == 11) {
					cin >> students[Correct_Number].History;
					while (students[Correct_Number].History < 2 || students[Correct_Number].History > 5) {
						cout << "???";
						cin >> students[Correct_Number].History;
					}
				}
				if (Choice == 12) {
					cin >> students[Correct_Number].Ecology;
					while (students[Correct_Number].Ecology < 2 || students[Correct_Number].Ecology > 5) {
						cout << "???";
						cin >> students[Correct_Number].Ecology;
					}
				}
				if (Choice >= 5 && Choice <= 12) {																	
					students[Correct_Number].Avarage_Mark = (students[Correct_Number].Alg_And_Geom + students[Correct_Number].Math_Analysis + students[Correct_Number].Programming + students[Correct_Number].Physics + students[Correct_Number].Pysical_Education + students[Correct_Number].Philosophy + students[Correct_Number].History + students[Correct_Number].Ecology) / 8;
				}
			}
		}
		if (Correct_Number >= Quantity) {
			cout << "???";																					
		}
		if (Choice == 0) {
			break;
		}
	}
}

void Output(int i) {																							
	cout << "Номер записи: "<< i+1
		<< "\n\nФИО: " << students[i].Firs_Middle_Last_Names;
	if (students[i].Floor == 1)
	{
		cout << "\nПол: Мужской";
	}
	else
	{
		cout << "\nПол: Женский";
	}
	cout << "\nГруппа: " << students[i].Group_Number
		<< "\nНомер в группе: " << students[i].Number_In_Group
		<< "\n\n\nОценки\n\n"
		"Алгебра и геометрия: " << students[i].Alg_And_Geom
		<< "\nМатематический анализ: " << students[i].Math_Analysis
		<< "\nПрограммирование: " << students[i].Programming
		<< "\nФизика: " << students[i].Physics 
		<< "\nФиз-ра: " << students[i].Pysical_Education
		<< "\nФилософия: " << students[i].Philosophy
		<< "\nИстория: " << students[i].History
		<< "\nЭкология: " << students[i].Ecology
		<< "\n________________________________________________________________________________________________\n\n";
}

void All_Data_Output(int Quantity) {																		
	for (int i = 0; i < Quantity; i++) {																			
		Output(i);																									
	}
	system("pause");
}

void Output_To_Group(int Quantity) {																			
	unsigned int Group_Number, Count;																				
	Count = 0;																										
	cout << "Введите номер группы: ";																				
	cin >> Group_Number;																					

	for (int i = 0; i < Quantity; i++) {																		
		if (students[i].Group_Number == Group_Number) {																
			Output(i);																								
			Count++;																								
		}
	}
	if (Count == 0) {
		cout << "Группа не найдена...\n";
	}
	system("pause");
}

void Men_Women_Count(int Quantity) {																			
	int Men = 0;																									
	int Women = 0;																								
	for (int i = 0; i < Quantity; i++) {																		
		if (students[i].Floor == 1) {																				
			Men++;																							
		}																										
		if (students[i].Floor == 2) {																
			Women++;																								
		}																											
	}																												
	cout << Men << " cтудентов мужского пола\n"																		
		<< Women << " студентов женского пола\n";																	
	system("pause");
}

void Genius_Output(int Quantity) {																				
	short unsigned int Count;																				
	Count = 0;																								
	for (int i = 0; i < Quantity; i++) {																	
		if (students[i].Avarage_Mark == 5) {
			Output(i);																								
			Count++;																						
		}
	}
	if (Count == 0) {
		cout << "Такие студенты не найдены...\n";
	}
	system("pause");
}

void Normis_Output(int Quantity) {																				
	short unsigned int Count;
	Count = 0;
	for (int i = 0; i < Quantity; i++) {
		if (students[i].Avarage_Mark < 5 && students[i].Avarage_Mark >= 4 && students[i].Alg_And_Geom != 3 && students[i].Math_Analysis != 3 && students[i].Programming != 3 && students[i].Physics != 3 && students[i].Pysical_Education != 3 && students[i].Philosophy != 3 && students[i].History != 3 && students[i].Ecology != 3 && students[i].Alg_And_Geom != 2 && students[i].Math_Analysis != 2 && students[i].Programming != 2 && students[i].Physics != 2 && students[i].Pysical_Education != 2 && students[i].Philosophy != 2 && students[i].History != 2 && students[i].Ecology != 2) {
			Output(i);
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Такие студенты не найдены...\n";
	}
	system("pause");
}

void No_Scholarship_Output(int Quantity) {																			
	short unsigned int Count;
	Count = 0;
	for (int i = 0; i < Quantity; i++) {
		if (students[i].Alg_And_Geom == 3 || students[i].Math_Analysis == 3 || students[i].Programming == 3 || students[i].Physics == 3 || students[i].Pysical_Education == 3 || students[i].Philosophy == 3 || students[i].History == 3 || students[i].Ecology == 3 || students[i].Alg_And_Geom == 2 || students[i].Math_Analysis == 2 || students[i].Programming == 2 || students[i].Physics == 2 || students[i].Pysical_Education == 2 || students[i].Philosophy == 2 || students[i].History == 2 || students[i].Ecology == 2) {
			Output(i);
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Такие студенты не найдены...\n";
	}
	system("pause");
}

void Number_In_List_Output(int Quantity) {																		
	unsigned int Number_In_Group, Count;
	Count = 0;
	cout << "Введите номер в группе: ";
	cin >> Number_In_Group;

	for (int i = 0; i < Quantity; i++) {
		if (students[i].Number_In_Group == Number_In_Group) {
			Output(i);
			Count++;
		}
	}
	if (Count == 0) {
		cout << "Группа не найдена...\n";
	}
	system("pause");
}

int main()
{	
	setlocale(0, "Rus");																		
	
	short unsigned int Choice, Quantity;														
	Quantity = 0;

	while (true) {
		system("cls");
		cout << "\tМеню:\n\n"
			"1)Создать запись\n"
			"2)Внести изменения\n"
			"3)Вывод всех данных\n"
			"4)Вывод данных о студентах определенной группы\n"
			"5)Вывод топа самых успешных студентов за прошлую сессию\n"
			"6)Вывод количества студентов мужского и женского\n"
			"7)Вывод успеваемости\n"
			"8)Вывод дынных о студентах по номеру в группе\n\n"
			"0)Выход\n\n"
			"Ответ: ";
		
		cin >> Choice;
		system("cls");

		if (Choice == 0) {
			break;
		}
		if (Choice == 1) {																	
			Data_Add(Quantity);																	
			Quantity++;																			
		}
		if (Choice == 2) {
			Data_Correct(Quantity);
		}
		if (Choice == 3) {
			All_Data_Output(Quantity);
		}
		if (Choice == 4) {
			Output_To_Group(Quantity);
		}
		if (Choice == 5) {
			Genius_Output(Quantity);
		}
		if (Choice == 6) {
			Men_Women_Count(Quantity);
		}
		if (Choice == 7) {
			cout << "Отличники:\n\n";
			Genius_Output(Quantity);
			cout << "\n\nХорошисты:\n\n";
			Normis_Output(Quantity);
			cout << "\n\nБез стипендии:\n\n";
			No_Scholarship_Output(Quantity);
		}
		if (Choice == 8) {
			Number_In_List_Output(Quantity);
		}
	}
	return 0;
}

