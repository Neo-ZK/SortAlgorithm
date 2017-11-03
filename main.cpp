#include <stdio.h>
#include <iostream>
#include "sort_algorithm.h"
#include "sort_algorithm.cpp"
using namespace std;


int main()
{
	double a = 1/3;
	
	sort_algorithm<int>* m_sort_algorithm = new sort_algorithm<int>();
	int len = 7;
	m_sort_algorithm->m_arr = new int[len];
	for (int i = 0;i < len;i++)
	{
		m_sort_algorithm->m_arr[i] = len- i;
	}
	//m_sort_algorithm->buble_Sort(m_sort_algorithm->m_arr,len);
	//m_sort_algorithm->Heapsort(m_sort_algorithm->m_arr,len);
	//m_sort_algorithm->Merge_Sort(m_sort_algorithm->m_arr,0,len-1);
	//m_sort_algorithm->Quick_Sort(m_sort_algorithm->m_arr,0,len-1);
	//m_sort_algorithm->Insert_Sort(m_sort_algorithm->m_arr,len);
	m_sort_algorithm->RadixSort_LSD(m_sort_algorithm->m_arr,len,1);
	
	return 0;
}