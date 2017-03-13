#include "Parallelogram.h"
#include <list>

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	bool invalid_input = false;
	int number_of_p = 0, op_index = 0, p_index = 0;
	double input_p_params[3];
	do {
		if (invalid_input)
			cout << "���������� ��������������� ������� �������! ������� ����������� �����!\n";
		cout << "������� ���-�� ���������������: ";
		cin >> number_of_p;
		invalid_input = number_of_p <= 0;
	} while (invalid_input);
	parallelogram** p_arr = new parallelogram*[number_of_p];
	for (int i = 0; i < number_of_p; i++)
	{
		do {
			invalid_input = false;
			cout << "������������� �" << i + 1 << "\n������� ������ �������: ";
			cin >> input_p_params[0];
			cout << "������� ������ �������: ";
			cin >> input_p_params[1];
			cout << "���������: ";
			cin >> input_p_params[2];
			try {
				p_arr[i] = new parallelogram(input_p_params[0], input_p_params[1], input_p_params[2]);
			}
			catch (int ex)
			{
				if (ex == 1)
				{
					cout << "�������� ���� �������!���������� ��� ���!";
					invalid_input = true;
				}
				else
				{
					cout << "�������������� ������!!!";
					return;
				}
			}
		} while (invalid_input);
	}
	cout << "�������� �������������, � ������� ������ �������� (������ � ���������� [1;" << number_of_p << "] ): ";
	do {
		if (invalid_input)
			cout << "������ �������������� ������ �����������!���������� ��� ���:\n";
		cin >> p_index;
		p_index--;
		invalid_input = p_index < 0 || p_index >= number_of_p;
	} while (invalid_input);
	cout << "�������� �������� �� ������:\n1.���������� ������� � �������� ���������� ���.\n2.���������� ������� � �������� ���������� ���.\n3.���������� ����������� ����� �� ���������." <<
		"\n4.���������� ����������� ����� �� �������.\n5.���������� ���������.\n6.���������� ������ �������.\n7.���������� ������ �������.\n8.���������� ������.";
	system("pause");
}