#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Faculty { KN,IT,ME,FI,TN };
string FacultyStr[] = { "��������� �����", "�����������", "���������� �� ��������","Գ���� �� �����������","������� ��������" };
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
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������

	int N;
	cout << "������ N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	double proc = LineSearch(p, N);
	cout << "³������ ��������, ��� ������ � ������ ������� 5:" << endl;
		cout << proc << "%" << endl;
	return 0;
}
void Create(Student * p, const int N)
{
	int fac;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " �� ���.: "; cin >> p[i].rik_nar;
		cout << " ��������� (0 - ���������� �����, 1 - ������������, 2 - ����������� �� ��������, 3 - �Գ���� �� �����������, 4 - �������� ���������): ";
		cin >> fac;
		cout << " ���������� : "; cin >> p[i].maths;
		cin.get();
		cout << " ������ : "; cin >> p[i].physics;
		cin.get();
		p[i].faculty = (Faculty)fac;
		switch (p[i].faculty)
		{
		case KN:
			cout << " ������������� : "; cin >> p[i].programuvnnya;
			cin.get();
			break;
		case IT:
			cout << " ������� ������ : "; cin >> p[i].chysmetody;
			cin.get();
			break;
		case ME:
		case FI:
		case TN:
			cout << " ��������� : "; cin >> p[i].pedagogika;
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
	cout << "| � | ������� | г�.���. | ���������              | ���������� | Գ���� | ������������� | ����.�������� | ��������� |"
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
	cout << "������� ��������, ��� ������ � ������ ������� 5:" << endl;
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

