#include <stdio.h>
int a[2] = {1, 2};
int main(){
	int *p1, *p2, *p3;
	p1 = p2 = p3 = a;
	printf("%d,%d,%d\n", *p1, *p1++, *p1); 
	//分析: 函数中参数的传递的顺序是从右往左传递
	//     1.*p1 = 1  ==> no3 = 1
	//     2.*p1++ ==> *p1 = 1 , p1 += 1; ==> no2 = 1
	//     3.*p1 ==> a[1] ==> no3 = 2
	printf("%d,%d,%d\n", *p2, (*p2)++, *p2);
	//     1.*p2 = 1  ==> no3 = 1
	//     2.(*p2)++ ==> *p2 = a[0], no2 = 1, a[0] = 2    
	//     3.*p2 = a[0] = 2 ==> no1 = 2;
	printf("%d,%d,%d\n", *p3, *++p3, *p3);
	//     1.*p3 = a[0]  ==> no3 = 2
	//     2.*++p3 ==> p3= p3+1 = &a[1] =>   no2 = *&a[1] = 2
	//     3.*p3 = a[1] = 2 ==> no1 = 2;
	return 0;
}
// 2 1 1
// 2 1 1
// 2 2 2