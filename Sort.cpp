#include <stdio.h>
#include <stdlib.h>

/*冒泡排序*/
void BubbleSort(int* pData, int Count)
{
	int iTemp = 0;
	for(int i = 1; i < Count; i++)
	{
		for(int j=Count-1; j >= i; j--)
		{
			if(pData[j-1] > pData[j])
			{
				iTemp = pData[j-1];
				pData[j-1] = pData[j];
				pData[j] = iTemp;
			}
		}
	}
}
/*选择排序*/
void SelectSort(int* pData, int Count)
{
	int iTemp = -1;//用于存放临时最小值
	int ipos = -1;//用于存放临时最小值的下标

	for (int i = 0; i < Count-1; ++i)
	{
		iTemp = pData[i];//假定第一个元素就是最小的
		ipos = i;

		for(int j=i+1; j < Count; ++j)
		{
			if(pData[j] < iTemp)
			{
				iTemp = pData[j];
				ipos = j;
			}
		}
		pData[ipos] = pData[i];
		pData[i] = iTemp;
	}
}
/*插入排序*/
void InsertSort(int* pData, int Count)
{
	int iTemp = -1;
	int ipos = -1;

	for (int i = 1; i < Count; ++i)
	{
		iTemp = pData[i];
		ipos = i-1;
		while((ipos>=0) && iTemp < pData[ipos])
		{
			pData[ipos+1] = pData[ipos];
			ipos--;
		}
		pData[ipos+1] = iTemp;
	}
}

//快速排序
inline void swap(int* data, int k, int j)
{
	int temp = -1;
	temp = data[k];
	data[k] = data[j];
	data[j] = temp;
}
void QuikSort(int* data, int left, int right)
{
	int j, last;
	if (left >= right)
		return;

	swap(data, left, (left + right)/2);
	last = left;
	for(j = left+1; j <= right; j++)
	{
		if (data[j] < data[left])
		{
			swap(data, ++last, j);
		}
		swap(data, left, last);
		QuikSort(data, left, last-1);
		QuikSort(data, last+1, right);
	}
}

/*打印数组*/
void PrintData(int* pData, int Count)
{
	int i = 0;
	for(i = 0; i < Count; i++)
	{
		printf("%d ",pData[i]);
	}
	printf("\n");
}

int main(void)
{
	int data[] = {1, 5, 9, 8, 7, 6, 2, 3, 0, 4};

	PrintData(data, sizeof(data) / sizeof(int));
	BubbleSort(data, sizeof(data) / sizeof(int));//冒泡排序
	//SelectSort(data, 10);//选择排序
	//InsertSort(data, 10);//直接插入排序
	//QuikSort(data, 0, 10);//快速排序
	PrintData(data, 10);
	while(1);
	return 0;
}