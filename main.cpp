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
			cout << "Количество параллелограмов введено неверно! Введите натуральное число!\n";
		cout << "Введите кол-во параллелограмов: ";
		cin >> number_of_p;
		invalid_input = number_of_p <= 0;
	} while (invalid_input);
	parallelogram** p_arr = new parallelogram*[number_of_p];
	for (int i = 0; i < number_of_p; i++)
	{
		do {
			invalid_input = false;
			cout << "Параллелограм №" << i + 1 << "\nВведите первую сторону: ";
			cin >> input_p_params[0];
			cout << "Введите вторую сторону: ";
			cin >> input_p_params[1];
			cout << "Диагональ: ";
			cin >> input_p_params[2];
			try {
				p_arr[i] = new parallelogram(input_p_params[0], input_p_params[1], input_p_params[2]);
			}
			catch (int ex)
			{
				if (ex == 1)
				{
					cout << "Неверный ввод величин!Попробуйте ещё раз!";
					invalid_input = true;
				}
				else
				{
					cout << "Непредвиденная ошибка!!!";
					return;
				}
			}
		} while (invalid_input);
	}
	cout << "Выберите параллелограм, с которым хотите работать (индекс в промежутке [1;" << number_of_p << "] ): ";
	do {
		if (invalid_input)
			cout << "Индекс параллелограма введен некорректно!Попробуйте ещё раз:\n";
		cin >> p_index;
		p_index--;
		invalid_input = p_index < 0 || p_index >= number_of_p;
	} while (invalid_input);
	cout << "Выберите операцию из списка:\n1.Увеличение размера в заданное количество раз.\n2.Уменьшение размера в заданное количество раз.\n3.Вычисление квадратного корня из периметра." <<
		"\n4.Вычисление квадратного корня из площади.\n5.Вычисление диагонали.\n6.Вычисление первой стороны.\n7.Вычисление второй стороны.\n8.Вычисление высоты.";
	system("pause");
}