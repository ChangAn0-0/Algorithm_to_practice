//һ�������й���n��Ԫ�أ�����ĳ��Ԫ�س��ִ���Ϊ�����Σ�����Ԫ�س��ִ�����Ϊż���Σ�����������������Ԫ�ص�ֵ
#include <stdio.h>
void Look_For_Odd_Occurrences(int N, int* num)
{
	int find_odd = 0;
	for (int i = 0; i < N; i++) {
		find_odd = find_odd ^ num[i];
	}
	
	printf("%d",find_odd);
}


//��չ��
//һ�������й���n��Ԫ�أ�����������Ԫ�س��ִ���Ϊ�����Σ�����Ԫ�س��ִ�����Ϊż���Σ�����������������Ԫ�ص�ֵ
void Look_For_Odd_Occurrences_2(int N, int* num)
{
	//��������Ԫ��Ϊa,b�����Ƚ����������õ�a^b��ֵ
	int find_odd = 0;
	for (int i = 0; i < N; i++) {
		find_odd = find_odd ^ num[i];
	}
	//��a^bȡ����һ���ڱ�����������㣬�õ�a^b���ұ�λΪһ����
	//��һλΪһ��ʾa��b����һλ��ͬ
	int rightone = ((~find_odd) + 1)&find_odd;

	//������ĸ���Ԫ����rightone�������㣬�ɽ���������Ԫ�ط�Ϊ����
	//��λΪ1�͸�λΪ0��
	int find_odd_1 = 0;
	for (int i = 0; i < N; i++) {
		if ((rightone & num[i]) == 0)
			find_odd_1 = find_odd_1 ^ num[i];
	}
	int find_odd_2 = find_odd ^ find_odd_1;

	printf("��һ����%d\n�ڶ���:%d", find_odd_1, find_odd_2);
}

int main(void)
{
	int a[8] = { 11,11,22,22,3,5,0,0 };

	Look_For_Odd_Occurrences_2(8, a);

	return 0;
}



