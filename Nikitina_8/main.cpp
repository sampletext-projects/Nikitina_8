#include <iomanip>
#include <iostream>

#define DAYS 30

using namespace std;

void write_mas(double* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << m[i] << " ";
		if (i % 10 == 0)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}

void randomize_weather(double* m)
{
	for (int i = 0; i < DAYS; i++)
	{
		//рандом от -100 до 100 / 10 даст значения от -10 до 10
		m[i] = (rand() % 200 - 100) / 10.;
	}
}

int count_days_below_zero(double* m)
{
	int count = 0;
	for (int i = 0; i < DAYS; i++)
	{
		if (m[i] < 0)
		{
			count++;
		}
	}
	return count;
}

int count_days_above_zero(double* m)
{
	int count = 0;
	for (int i = 0; i < DAYS; i++)
	{
		if (m[i] > 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	cout << "Автор: Никитина Дарья Сергеевна\n";
	cout << "Программа для оценки погоды\n";

	double weather[DAYS];
	randomize_weather(weather);

	cout << "Погода в этом месяце: \n";
	write_mas(weather, DAYS);

	int days_above_zero = count_days_above_zero(weather);
	int days_below_zero = count_days_below_zero(weather);

	cout << "Дней с > 0: " << days_above_zero << "\n";
	cout << "Дней с < 0: " << days_below_zero << "\n";

	system("pause");

	return 0;
}
