//一个数组中共有n个元素，其中某个元素出现次数为奇数次，其他元素出现次数均为偶数次，如何求出出现奇数次元素的值
#include <stdio.h>
void Look_For_Odd_Occurrences(int N, int* num)
{
	int find_odd = 0;
	for (int i = 0; i < N; i++) {
		find_odd = find_odd ^ num[i];
	}
	
	printf("%d",find_odd);
}


//拓展：
//一个数组中共有n个元素，其中有两个元素出现次数为奇数次，其他元素出现次数均为偶数次，如何求出出现奇数次元素的值
void Look_For_Odd_Occurrences_2(int N, int* num)
{
	//假设两个元素为a,b，首先进行异或运算得到a^b的值
	int find_odd = 0;
	for (int i = 0; i < N; i++) {
		find_odd = find_odd ^ num[i];
	}
	//对a^b取反加一在于本身进行与运算，得到a^b最右边位为一的数
	//这一位为一表示a和b在这一位不同
	int rightone = ((~find_odd) + 1)&find_odd;

	//将数组的各个元素与rightone做与运算，可将所有数组元素分为两类
	//该位为1和该位为0；
	int find_odd_1 = 0;
	for (int i = 0; i < N; i++) {
		if ((rightone & num[i]) == 0)
			find_odd_1 = find_odd_1 ^ num[i];
	}
	int find_odd_2 = find_odd ^ find_odd_1;

	printf("第一个：%d\n第二个:%d", find_odd_1, find_odd_2);
}

int main(void)
{
	int a[8] = { 11,11,22,22,3,5,0,0 };

	Look_For_Odd_Occurrences_2(8, a);

	return 0;
}
//



