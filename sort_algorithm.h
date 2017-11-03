#ifndef SORT_LAGORITHM_H 
#define SORT_LAGORITHM_H 

//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


template<class T>
class sort_algorithm
{
public:
	sort_algorithm(void);
	~sort_algorithm(void);
	//√∞≈›≈≈–Ú
	void buble_Sort(T* arr,int len);
	//øÏÀŸ≈≈–Ú
	void Quick_Sort(T* arr,int p,int r);
	int Partition(T* arr,int p,int r);
	int rand_Partiton(int* arr,int start_pos,int end_pos);
	//≤Â»Î≈≈–Ú
	void Insert_Sort(T* arr,int len);
	//πÈ≤¢≈≈–Ú
	void Merge(T* arr,int p,int q, int r);
	void Merge_Sort(T* arr,int p,int r);
	//∂—≈≈–Ú
	void Heap_Adjust(T* arr,int len,int adjust_node);
	void Gen_Heap(T* arr,int len);
	void Heapsort (T* arr,int len);
	//ª˘ ˝≈≈–Ú
	int Getpos(int input_value,int d);
	void RadixSort_LSD(int* arr,int len,int d);
	T* m_arr;
};

#endif