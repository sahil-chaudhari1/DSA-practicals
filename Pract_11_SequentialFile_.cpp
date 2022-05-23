#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct record
{
	int roll_No;
	char name[50];
	char division[50];
	char address[50];

public:

	void Get_Data();
	void Display();
};

void record::Get_Data()
{
	cout << "Enter roll number : ";
	cin >> roll_No;
	cin.ignore(10000, '\n');
	cout << "Enter name : ";
	cin.getline(name, 100, '\n');
	cout << "Enter division : ";
	cin.getline(division, 100, '\n');
	cout << "Enter the address : ";
	cin.getline(address, 100, '\n');
}
void record::Display()
{
	cout << "Roll number : ";
	cout << roll_No << "\n";
	cout << "Name : " << name << "\n";
	cout << "Division : " << division << "\n";
	cout << "Address : " << address << "\n";
}


int main()
{
	record student, studs[100];
	fstream obj;


	cout << "Enter new record press 'w' :\n";
	cout << "Delete record press 'd' :\n";
	cout << "Search record press 's' :\n";
	cout << "To Exit press 'e' : \n";

	char op = 0;
	int r = 0, i = 0;;
	bool pos = 0;

	while (op!= '@')
	{
		cout << "\nInput : ";
		cin >> op;
		switch (op)
		{
		case 'w':
			obj.open("student.txt", ios_base::in | ios_base::out | ios_base::app);
			student.Get_Data();
			obj.write((char*)&student, sizeof(student));
			obj.close();
			break;

		case 'd':
			cout << "Enter the roll no : ";
			cin >> r;
			obj.open("student.txt", ios_base::in | ios_base::out | ios_base::app);
			i = 0;
			while (!obj.eof())
			{
				obj.read((char*)&student, sizeof(student));
				if (student.roll_No != r)studs[i] = student;
				i++;
			}
			obj.close();

			obj.open("student.txt", ios_base::in | ios_base::out);
			for (int j = 0; j < i; j++)
			{
				obj.write((char*)&studs[j], sizeof(studs[j]));
			}

			for (int i = 0; i < 100; i++)studs[i].roll_No = -1;
			obj.close();
			cout << "Student record whose roll no is " << r << " is deleted successfully \n";
			break;

		case 's':
			obj.open("student.txt", ios_base::in | ios_base::out | ios_base::app);
			cout << "Enter the roll no of student : ";
			cin >> r;
			pos = 0;
			obj.seekg(0, ios_base::beg);
			while (!obj.eof())
			{
				obj.read((char*)&student, sizeof(student));
				if (student.roll_No == r)
				{
					cout << "Record found \n";
					student.Display();
					cout << "\n";
					pos = 1;
					break;
				}
			}
			if (!pos)cout << "Roll no " << r << " not found \n";
			obj.close();
			break;
		case 'e':
			op = '@';
			break;

		default:
			break;
		}
	}

	return 0;
}