#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


template<class T>
class sort_algorithm
{
public:
	sort_algorithm(void);
	~sort_algorithm(void);
	//Ã°ÅİÅÅĞò
	void buble_Sort(T* arr,int len);
	//¿ìËÙÅÅĞò
	void Quick_Sort(T* arr,int p,int r);
	int Partition(T* arr,int p,int r);
	int rand_Partiton(int* arr,int start_pos,int end_pos);
	//²åÈëÅÅĞò
	void Insert_Sort(T* arr,int len);
	//¹é²¢ÅÅĞò
	void Merge(T* arr,int p,int q, int r);
	void Merge_Sort(T* arr,int p,int r);
	//¶ÑÅÅĞò
	void Heap_Adjust(T* arr,int len,int adjust_node);
	void Gen_Heap(T* arr,int len);
	void Heapsort (T* arr,int len);
	//»ùÊıÅÅĞò
	int Getpos(int input_value,int d);
	void RadixSort_LSD(int* arr,int len,int d);
	T* m_arr;
};

