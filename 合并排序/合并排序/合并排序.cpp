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
	  MergeSort(iDates, iBuffer, 0, iNum - 1);//���ú��� �ֶ���֮
		for(i = 0; i < iNum; i++)
			printf("%d ", iDates[i]);
		printf("\n");
		scanf("%d", &iNum);//����-1 ѭ����ֹ
	}
	system("pause");
}
void MergeSort(int iDatesr[], int iBuffer[], int startIndex, int endIndex)//���� ԭ����iDatesr ��������iBuffer ��ϸ����������ʽ�ϵ��ײ���β��
{
	int midIndex;
	if(startIndex < endIndex)
	{
		midIndex = (startIndex + endIndex) / 2;//�и��ϸ ��ݹ����
	  MergeSort(iDatesr, iBuffer, startIndex, midIndex);//��ϸ���ǰ��μ���ϸ��
	  MergeSort(iDatesr, iBuffer, midIndex + 1, endIndex);//��ϸ����μ���ϸ��
	  Merge(iDatesr, iBuffer, startIndex, midIndex, endIndex);//��֮ ���ϲ�����
		for(int i = startIndex; i <= endIndex; i++)//��������������
			iDatesr[i] = iBuffer[i];
	}
}//ʵ��Ϊ�����ϸ�ֺ�������� ��ϸ����

void Merge(int iDatesr[], int iBuffer[], int startIndex, int midIndex, int endIndex)//��Ҫ������ֵ��ȷ���ֽ�����������������������С����
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while(i != midIndex + 1 && j != endIndex + 1)//δ������ѭ��
	{
		if(iDatesr[i] > iDatesr[j])//��������������iBuffer
		iBuffer[k++] = iDatesr[j++];
		else
		iBuffer[k++] = iDatesr[i++];
	}
	while(i != midIndex + 1)//����ǰ���δ����Ԫ��
		iBuffer[k++] = iDatesr[i++];	//��ֶξ��������� ����ֱ�����뼴��
	while(j != endIndex + 1)//�������δ����Ԫ��
		iBuffer[k++] = iDatesr[j++];
}