#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Array.h"

/*Створити шаблонний клас – одновимірний масив. Тип елементів масиву визначається
параметром шаблона (цілі числа, дійсні числа, символи або символьні рядки). Передбачити
функції для виконання таких операцій: введення елементів у масив, обчислення контрольної
суми (сума кількостей одиниць у машинному зображенні елементів масиву), виведення
елементів масиву на екран.*/
int main()
{
	printf("Input a number of int array elements\n");
	int size_int;
	scanf("%d", &size_int);
	Array<int> * m_int = new Array<int>(size_int, 0);
	for (int i = 0; i < m_int->GetSize(); i++)
	{
		int a;
		scanf("%d", &a);
		m_int->SetValue(a, i);

	}
	m_int->Insert(134, 3);
	printf("\nAdded one element\n");
	for (int i = 0; i < m_int->GetSize(); i++)
	{
		printf("\n%d", (*m_int)[i]);
	}
	m_int->Delete(3);
	printf("\nDeleted one element\n");
	for (int i = 0; i < m_int->GetSize(); i++)
	{
		printf("\n%d", (*m_int)[i]);
	}
	delete m_int;
	printf("\nInput a number of double array elements\n");
	int size_double;
	scanf("%d", &size_double);
	Array<double> * m_double = new Array<double>(size_double, 0.0);
	for (int i = 0; i < m_double->GetSize(); i++)
	{
		double a;
		scanf("%.2lf", &a);
		m_double->SetValue(a, i);

	}
	m_double->Insert(134.7, 3);
	printf("\nAdded one element\n");
	for (int i = 0; i < m_double->GetSize(); i++)
	{
		printf("\n%.2lf", (*m_double)[i]);
	}
	m_double->Delete(3);
	printf("\nDeleted one element\n");
	for (int i = 0; i < m_double->GetSize(); i++)
	{
		printf("\n%.2lf", (*m_double)[i]);
	}
	delete m_double;
}