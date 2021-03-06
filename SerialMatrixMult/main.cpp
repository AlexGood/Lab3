#include <omp.h>
#include <iostream>
#include <time.h>
int main()
{
	//���������� ��� �������� �������
	long double t1, t2;
	
	//���������� ��������, ������ � ������������ ��������� ������
	const int MATRIX_SIZE = 1000;
	int **first_matrix = new int*[MATRIX_SIZE];
	int **second_matrix = new int*[MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		first_matrix[i] = new int[MATRIX_SIZE];
		second_matrix[i] = new int[MATRIX_SIZE];
	}
	unsigned long long int **result_matrix = new unsigned long long int*[MATRIX_SIZE];
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		result_matrix[i] = new unsigned long long int[MATRIX_SIZE];
	}
	//��������� ����� ������ ����������
	std::srand(time(0));
	//��������� �������
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			first_matrix[i][j] = rand() % 10 + 1;
			second_matrix[i][j] = rand() % 10 + 1;
		}
	}
	/*std::cout << std::endl << "������ ������:" << std::endl;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout << first_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "������ ������:" << std::endl;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout << second_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}*/
	//��������� �����
	t1 = omp_get_wtime();
	//��������� ������������ ���������� ������ � ������������� ���������� �������
	#pragma omp parallel for num_threads(16)
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		#pragma omp parallel for
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			//����� ������������ ��� shared, �� ��� ������ ��-��������� 
			result_matrix[i][j] = 0;
			#pragma omp parallel for 
			for (int z = 0; z < MATRIX_SIZE; z++)
			{
				result_matrix[i][j] += first_matrix[i][z] * second_matrix[z][j];
			}
		}
	}
	//�������� �����
	t2 = omp_get_wtime();
	/*std::cout << std::endl << "�������������� ������:" << std::endl;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			std::cout << result_matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}*/
	//�������� �������
	std::cout << "Elapsed Time: " << t2 - t1 << std::endl;
	for (int i = 0; i < MATRIX_SIZE;i++)
	{
		delete[] first_matrix[i];
		delete[] second_matrix[i];
		delete[] result_matrix[i];
	}
	return 0;
}