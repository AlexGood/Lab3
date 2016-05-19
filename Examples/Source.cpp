#include <omp.h>
#include <iostream>
#include <algorithm>
#include <time.h>
//Пример 6. reduction позволяет получать обобщенные значения из параллельных потоков, создавая для каждого потока свою 
//локальную переменную, а затем все результаты объединяются в исходную переменную 
//int main()
//{
//	double ave = 0.0;
//	double A[100];
//	int i;
//	std::srand(time(0));
//	std::generate(A, A + 100, []() {
//		return std::rand();
//	});
//	#pragma omp parallel for reduction (+:ave)
//	for (int i = 0; i < 100; i++)
//	{
//		ave += A[i];
//	}
//	ave /= 100;
//	std::cout << "Average ist gleich " << ave << std::endl;
//	return 0;
//}
//Пример 5. Теперь благодаря ordered мы получаем вывод элементов массива поочередно и в правильном порядке
//int main()
//{
//	int A[10];
//	std::generate(A, A + 10, []() {
//		return std::rand() % 100 + 1;
//	});
//	#pragma omp parallel for ordered
//	for (int i = 0; i < 10; i++)
//	{
//		#pragma omp ordered
//		{
//			std::cout << "A[" << i << "] = " << A[i] << std::endl;
//		}
//	}
//	return 0;
//}
//
//Пример 4. Заполняет массив 10 случайными числами и выводит массив в консоль поэлементно. Благодаря critical 
//поток вывода может занимать только один поток, что обеспечивает читабельный (но не поочередный) вывод
//int main()
//{
//	int A[10];
//	std::generate(A, A + 10, []() {
//		return std::rand() % 100 + 1;
//	});
//	#pragma omp parallel for
//	for (int i = 0; i < 10; i++) 
//	{
//		#pragma omp critical
//		{
//			std::cout << "A[" << i << "] = " << A[i] << std::endl;
//		}
//	}
//	return 0;
//}
//
//Пример 1. Четыре раза выведет надпись Привет мир, т.к. машина имеет 4 процессора
//int main()
//{
//	#pragma omp parallel
//	{
//		printf("Hello World");
//	}
//	return 0;
//}
//
/* Пример 2. Вывод:
Hello from thread 0 of 4
Hello from thread 1 of 4
Hello from thread 2 of 4
Hello from thread 3 of 4*/
//int main()
//{
//	#pragma omp parallel
//	{
//		printf("Hello from thread %d of %d\n", omp_get_thread_num(),
//			omp_get_num_threads());
//	}
//	return 0;
//}
//
//Пример 3. Вывод: 
//	Hello from thread 0 of 5
//	Hello from thread 1 of 5
//	Hello from thread 2 of 5
//	Hello from thread 3 of 5
//	Hello from thread 4 of 5
//	и строки накладываются друг на друга
//int main()
//{
//	#pragma omp parallel num_threads(5)
//	{
//		std::cout << "Hello World from "<<omp_get_thread_num()<<" of "<<omp_get_num_threads() << std::endl;
//	}
//}
