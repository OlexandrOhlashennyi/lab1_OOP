#include <iostream>
#include <Windows.h>

using namespace std;

class DigitalCounter {
private:
	int min_value;
	int max_value;
	int counter;
	int timer_delay;
public:
	DigitalCounter() { counter = min_value = 0; max_value = 10; timer_delay = 100; }
	DigitalCounter(int a, int b, int t = 100) { counter = min_value = a; max_value = b; timer_delay = t; }
	~DigitalCounter() {}

	int getCounter() { return counter; }			
	int getMinimum() { return min_value; }			
	int getMaximum() { return max_value; }			
	int getTimerDelay() { return timer_delay; }		
	void setMinimum(int a) { min_value = counter = a; }		
	void setMaximum(int a) { max_value = a; }		
	void setTimerDelay(int a) { timer_delay = a; }	//встановлення затримки таймера(для відображення роботи лічильника)
	void setCounter(int a);							//
	void counterIncrease();							//збільшення лічильника на 1
};

void menu(DigitalCounter obj);						//меню для зручності відображення роботи усіх методів класу

int main() {
	DigitalCounter counter1;						//оголошення об'єкта класу
	menu(counter1);									
}

void menu(DigitalCounter obj) {
	while (true)
	{
		system("cls");
		int choise;
		bool exit;
		cout << "\n\n\t1.Start counter\n\t2.Set range\n\t3.Get range\n\t4.Set counter\n\t5.Get counter\n\t6.Set timer delay\n\t7.Get timer delay\n\t0.Exit\n\n";
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "Counter starting...(Esc to stop)\n";	
			exit = false;									
			while (!exit) {									
				cout << obj.getCounter() << endl;			//виведення значення лічильника
				obj.counterIncrease();						//збільшення лічильника на 1
				Sleep(obj.getTimerDelay());					//чекаємо задану кількість секунд
				if (GetAsyncKeyState(VK_ESCAPE))			//вловлюємо натискання esc
				{											
					exit = true;							
				}											
			}
			break;
		case 2:
			int a, b;
		range_inp:
			cout << "Enter counter range[a b](a<b): ";
			cin >> a >> b;
			if (a > b) goto range_inp;						//вловлюємо помилку введення
			obj.setMinimum(a);								//встановлюємо мінімум
			obj.setMaximum(b);								//встановлюємо максимум
			break;
		case 3:
			printf("Counter range: [%d;%d]", obj.getMinimum(), obj.getMaximum());
			break;
		case 4:
			int c;
			cout << "Enter counter number: ";
			cin >> c;
			obj.setCounter(c);								//встановлюємо значення лічильника
			break;
		case 5:
			cout << "Counter start from: " << obj.getCounter();
			break;
		case 6:
			int t;
			cout << "Enter delay in milliseconds: ";
			cin >> t;
			obj.setTimerDelay(t);							//встановлюємо затримку
			break;
		case 7:
			cout << "Timer delay: " << obj.getTimerDelay() << "ms";
			break;
		case 0:
		default:
			return;
		}
		cout << "\n\n";
		system("pause");
	}
}

void DigitalCounter::setCounter(int a)
{
	if (a < min_value) counter = min_value;				//перевіряємо задане значення на коректність
	else if (a > max_value) counter = max_value;
	else counter = a;
}

void DigitalCounter::counterIncrease()
{
	counter++;
	if (counter > max_value) counter = min_value;		//забезпечуємо циклічність
}