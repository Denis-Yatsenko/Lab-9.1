#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Faculty { KN,IT,ME,FI,TN };
string FacultyStr[] = { "Компютерні науки", "Інформатика", "Математика та Економіка","Фізика та інформатика","Трудове навчання" };
struct Student
{
	string prizv;
	unsigned rik_nar;
	Faculty faculty;
	double physics;
	double maths;
	union
	{
		double programuvnnya;
		double chysmetody;
		double pedagogika;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	double proc = LineSearch(p, N);
	cout << "Відсоток Студентів, чия оцінка з фізики дорівнює 5:" << endl;
		cout << proc << "%" << endl;
	return 0;
}
void Create(Student * p, const int N)
{
	int fac;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " рік нар.: "; cin >> p[i].rik_nar;
		cout << " факультет (0 - «Комп’ютерні науки», 1 - «Інформатика», 2 - «Математика та економіка», 3 - «Фізика та інформатика», 4 - «Трудове навчання»): ";
		cin >> fac;
		cout << " математика : "; cin >> p[i].maths;
		cin.get();
		cout << " фізика : "; cin >> p[i].physics;
		cin.get();
		p[i].faculty = (Faculty)fac;
		switch (p[i].faculty)
		{
		case KN:
			cout << " програмування : "; cin >> p[i].programuvnnya;
			cin.get();
			break;
		case IT:
			cout << " чисельні методи : "; cin >> p[i].chysmetody;
			cin.get();
			break;
		case ME:
		case FI:
		case TN:
			cout << " педагогіка : "; cin >> p[i].pedagogika;
			cin.get();
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "======================================================================================================================="
		<< endl;
	cout << "| № | Прізвище | Рік.нар. | Факультет              | Математика | Фізика | Програмування | Числ.Методика | Педагогіка |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(8) << right << p[i].rik_nar << " "
			<< "| " << setw(23) << left << FacultyStr[p[i].faculty];
		switch (p[i].faculty)
		{
		case KN:
			cout << "| " << setw(10) << setprecision(2) << fixed<<right
				<< p[i].maths << " |" << setw(7) << setprecision(2) << fixed << right
				<< p[i].physics << " |" << setw(14) << setprecision(2) << fixed << right
				<< p[i].programuvnnya << " |" << setw(16) << right << "|" << setw(13) <<  "|" << endl;
			break;
		case IT:
			cout << "| " << setw(10) << setprecision(2) << fixed << right
				<< p[i].maths << " |" << setw(7) << setprecision(2) << fixed << right
				<< p[i].physics << " |" << setw(16) << setprecision(2) << fixed << right
			    << " |" << setw(15) << setprecision(2) << fixed << right <<  p[i].chysmetody << fixed << right
				<< "|" << setw(13) << right << "|" << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << "| " << setw(10) << setprecision(2) << fixed << right
				<< p[i].maths << " |" << setw(7) << setprecision(2) << fixed << right
				<< p[i].physics << " |" << setw(16) << setprecision(2) << fixed << right
				<< " |" << setw(16) << "|" << setw(12) << setprecision(2) << fixed << right << p[i].pedagogika << "|" << endl;
			break;
		}
	}
	cout << "======================================================================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	cout << "Прізвища Студентів, чия оцінка з фізики дорівнює 5:" << endl;
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
			if (p[i].physics == 5)
			{
				k++;
				cout << setw(3) << right << k
					<< " " << p[i].prizv << endl;
			}
		
	}
	return 100.0 * k / N;
}

