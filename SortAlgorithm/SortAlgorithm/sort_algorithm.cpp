#include "sort_algorithm.h"
using namespace std;
template<class T>
sort_algorithm<T>::sort_algorithm(void):m_arr(NULL)
{
	m_arr = NULL;
}


template<class T>
sort_algorithm<T>::~sort_algorithm(void)
{
}


/************************************************************************/
/* 函数功能：冒泡排序                                                   */
// 入口参数：arr:待排序数组  len：数组长度
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::buble_Sort(T* arr,int len)
{
	T temp;
	for (int i = 0;i < len;i++)
	{
		for (int j = i;j < len;j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
///////////////快速排序////////////////////////////////////
/************************************************************************/
/* 函数功能：快速排序主函数（递归调用实现）                             */
// 入口参数：arr:待排序数组  p:起始位置 r结束位置
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Quick_Sort(T* arr,int p,int r)
{
	int q;
	if (p < r)
	{
		q = Partition(arr,p,r);
		Quick_Sort(arr,p,q-1);
		Quick_Sort(arr,q+1,r);
	}
}

/************************************************************************/
/* 函数功能：快速排序的核心分区函数，用来将标志位置放到正确的位置并返回这
             个已经正确的位置(采用固定选取基准元的方法)                */
// 入口参数：arr:待排序数组  p:起始位置 r结束位置
// 返回参数：已经在正确位置上的数的位置
/************************************************************************/
template<class T>
int sort_algorithm<T>::Partition(T* arr,int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r;j++)
	{
		if (arr[j] < x)
		{
			i = i + 1;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[r];
	arr[r] = arr[i+1];
	arr[i+1] = temp;
	return i+1;
}
/************************************************************************/
/* 函数功能：快速排序的核心分区函数，用来将标志位置放到正确的位置并返回这
             个已经正确的位置(采用随机选取基准元的方法)                 */
// 入口参数：arr:待排序数组  start_pos:起始位置 end_pos：结束位置
// 返回参数：已经在正确位置上的数的位置
/************************************************************************/
template<class T>
int sort_algorithm<T>::rand_Partiton(int* arr,int start_pos,int end_pos)
{
	//随机选取基准元	
	int tag_pos = rand()%(end_pos - start_pos) + start_pos;
	swap(arr[tag_pos],arr[start_pos]);
	int tag = arr[start_pos];
	int i = start_pos;
	int j = end_pos;
	int first_change_tag = 1;
	while (i != j)
	{
		while (i < j && tag <= arr[j])
		{
			j--;
		}
		swap(arr[j],arr[i]);		
		while (i < j && tag >= arr[i])
		{
			i++;
		}
		swap(arr[j],arr[i]);
	}	
	return i;
}

////////////////////////插入排序////////////////////////////
/************************************************************************/
/* 函数功能：插入排序                                                   */
// 入口参数：arr:待排序数组  len：数组长度
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Insert_Sort(T* arr,int len)
{
	for(int i = 1;i < len;i++)	
	{
		int temp = arr[i];
		int j = i - 1;
		while(temp < arr[j] && j >= 0)
		{
			arr[j+1] = arr[j];
			j--;			
		};
		arr[j+1] = temp;
	};
}

////////////////////////归并排序////////////////////////////
/************************************************************************/
/* 函数功能：归并排序主函数，递归的将待排序数组分为一个个小块           */
// 入口参数：arr:待排序数组  p:起始位置 r结束位置
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Merge_Sort(T* arr,int p,int r)
{
	if (p < r)
	{
		int q = (p + r)/2;
		Merge_Sort(arr,p,q);
		Merge_Sort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}

/************************************************************************/
/* 函数功能：归并核心函数，将两个已排序好的数组合并成一个排好序的数组   */
// 入口参数：arr:待排序数组  p:起始位置 q:中间位置 r：结束位置
//                           q-p为第一个数组   r-q为第二个数组
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Merge(T* arr,int p,int q, int r)
{
	int Arr1Length = q - p + 2;
	int Arr2Length = r - q + 1;
	int* Arr1 = new int[Arr1Length];
	int* Arr2 = new int[Arr2Length];
	for(int i = 0;i < Arr1Length - 1;i++)
	{
		Arr1[i] = arr[i + p];
	};
	Arr1[Arr1Length-1] = 1000000;
	for (int j = 0;j < Arr2Length - 1;j++)
	{
		Arr2[j] = arr[j + q + 1];
	};
	Arr2[Arr2Length-1] = 1000000; 
	int m = 0;
	int n = 0;
	for(int k = p;k <= r;k++)
	{
		if (Arr1[m] < Arr2[n])
		{
			arr[k] = Arr1[m];
			m++;
		}
		else
		{
			arr[k] = Arr2[n];
			n++;
		}		
	};
}

/////////////////////////堆排序(小顶堆)///////////////////////////
/************************************************************************/
/* 函数功能：堆排序主函数（产生堆并不断交换堆顶与堆末元素并调整堆）     */
// 入口参数：arr:待排序数组  len:数组长度
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Heapsort(T* arr,int len)
{
	Gen_Heap(arr,len);
	for (int i = len-1;i >= 0;i--)
	{
		swap(arr[i],arr[0]);
		Heap_Adjust(arr,i,0);
	}
}


/************************************************************************/
/* 函数功能：产生堆 并调整堆使之满足堆的性质                            */
// 入口参数：arr:待产生堆的数组  len:数组长度
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Gen_Heap(T* arr,int len)
{
	int last_notree_node = len / 2 - 1;
	for (int i = last_notree_node;i >= 0;i--)
	{
		Heap_Adjust(arr,len,i);
	}
}

/************************************************************************/
/* 函数功能：堆排序核心函数  调整相应的节点使之满足堆的性质             */
// 入口参数：arr:待排序的数组  len:数组长度     adjust_node：待调整的节点
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::Heap_Adjust(T* arr,int len,int adjust_node)
{
	int left_child_node = adjust_node * 2 + 1;
	int right_child_node = adjust_node * 2 + 2;
	int temp_max = adjust_node;
	if (adjust_node <= len/2 - 1)
	{
		if (arr[left_child_node] > arr[adjust_node] && left_child_node < len)
		{
			temp_max = left_child_node;
		}
		if (arr[right_child_node] > arr[adjust_node] && right_child_node < len)
		{
			if (arr[right_child_node] > arr[left_child_node])
			{
				temp_max = right_child_node;
			}			
		}
		if (temp_max != adjust_node)
		{
			swap(arr[adjust_node],arr[temp_max]);
			Heap_Adjust(arr,len,temp_max);
		}
	}	
}
//////////////////////////基数排序////////////////////////////
/************************************************************************/
/* 函数功能：基数排序  获得相应位数的值                                 */
// 入口参数：input_value：输入数值     d：相应的位数
// 返回参数：无
/************************************************************************/
template<class T>
int sort_algorithm<T>::Getpos(int input_value,int d)
{
	int temp_arr[] = {1,1,10,100,1000,10000};
	return ((input_value/temp_arr[d])%10);
}


/************************************************************************/
/* 函数功能：基数排序核心函数                                           */
// 入口参数：arr:待排序的数组  len:数组长度    d：待排序的数的最大位数
// 返回参数：无
/************************************************************************/
template<class T>
void sort_algorithm<T>::RadixSort_LSD(int* arr,int len,int d)
{
	int* m_bucket = new int(len);
	const int radix_num = 10;
	int index_arr[radix_num];	
	for (int d_pos = 1; d_pos <= d; d_pos++)
	{
		for (int i = 0; i < radix_num; i++)
		{
			index_arr[i] = 0;
		}		

		for (int i = 0; i < len; i++)
		{
			int pos = Getpos(arr[i],d_pos);
			index_arr[pos]++;
		}

		for (int i = 1; i < radix_num; i++)
		{
			index_arr[i] = index_arr[i] + index_arr[i - 1];
		}

		for (int i = len-1;i >= 0; i--)
		{
			int pos = Getpos(arr[i],d_pos);
			int a = index_arr[pos] - 1;
			m_bucket[index_arr[pos] - 1] = arr[i];
			index_arr[pos]--;
		}

		for (int i = 0; i < len; i++)
		{
			arr[i] = m_bucket[i];
		}
	}
	delete[] m_bucket;
	m_bucket = NULL;
}