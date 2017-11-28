#include <stdio.h>
#include <stdlib.h>
void MergeSort(int iDatesr[], int iBuffer[], int startIndex, int endIndex);
void Merge(int iDatesr[], int iBuffer[], int startIndex, int midIndex, int endIndex);
void main()
{	
	int iDates[1000];
	int iBuffer[1000];
	int iNum = 0, i = 0;
	scanf("%d", &iNum);
	while( iNum != -1)
	{
		for(i = 0; i < iNum; i++)
			scanf("%d", &iDates[i]);
	  MergeSort(iDates, iBuffer, 0, iNum - 1);//调用函数 分而治之
		for(i = 0; i < iNum; i++)
			printf("%d ", iDates[i]);
		printf("\n");
		scanf("%d", &iNum);//读入-1 循环终止
	}
	system("pause");
}
void MergeSort(int iDatesr[], int iBuffer[], int startIndex, int endIndex)//传入 原数组iDatesr 缓冲数组iBuffer 分细后的数组的形式上的首部和尾部
{
	int midIndex;
	if(startIndex < endIndex)
	{
		midIndex = (startIndex + endIndex) / 2;//切割分细 后递归调用
	  MergeSort(iDatesr, iBuffer, startIndex, midIndex);//分细后的前半段继续细分
	  MergeSort(iDatesr, iBuffer, midIndex + 1, endIndex);//分细后后半段继续细分
	  Merge(iDatesr, iBuffer, startIndex, midIndex, endIndex);//治之 即合并排序
		for(int i = startIndex; i <= endIndex; i++)//储存排序后的数组
			iDatesr[i] = iBuffer[i];
	}
}//实现为从最大细分后逐层跳出 由细到总

void Merge(int iDatesr[], int iBuffer[], int startIndex, int midIndex, int endIndex)//需要传入中值来确定分界进而总排序两个已自排序的小部分
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while(i != midIndex + 1 && j != endIndex + 1)//未遍历则循环
	{
		if(iDatesr[i] > iDatesr[j])//塑造排序后的数组iBuffer
		iBuffer[k++] = iDatesr[j++];
		else
		iBuffer[k++] = iDatesr[i++];
	}
	while(i != midIndex + 1)//排入前半段未排序元素
		iBuffer[k++] = iDatesr[i++];	//因分段均已自排序 所以直接排入即可
	while(j != endIndex + 1)//排入后半段未排序元素
		iBuffer[k++] = iDatesr[j++];
}