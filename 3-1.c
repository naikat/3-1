// memset
// memory -内存   set-设置

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char arr[] = "niubi  niubi";
	memset(arr, '*', 5);
	//将 niubi niubi  中前五个字符 换成 *  即 ***** niubi
	printf("%s\n", arr);

	return 0;
}




 ret_type fun_name(paral,*)
 {
     statement;//语句项
 }

  ret_type 返回类型
  fun_name 函数名
  paral    函数参数




//定义函数

int get_max(int x, int y) //因为最后返回是值是一个整数 所以用int 
{
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	int a = 23;
	int b = 1235;
	int max = get_max(a, b);
	printf("max = %d",max);
	return 0;
}



 相互交换函数



int main()
{
	int e = 12;
	int* pe = &e;//pe 指针变量
	*pe = 23;//解引用操作
	printf("%d\n", e);
	return 0;
}


void Swap1(int x, int y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;

}

void Swap2(int* pe, int* pi)//送过来的是一个地址 &a &b
{
	int tmp = 0;
	tmp = *pe;
	*pe = *pi;
	*pi = tmp;

}

int main()
{
	int a = 24;
	int b = 33;
	//Swap1(a, b);   //传值调用
	//printf("a = %d b = %d\n", a, b);
	Swap2(&a, &b);  //传址调用
	printf("a = %d b = %d\n", a, b);
	return 0;
}




 形参 与 实参



实际参数（实参）：
真实传给函数的参数，叫实参。实参可以是：常量，变量 ，表达式，函数等。无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参



形式参数（形参）：
形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配
内存单元），所以叫形式参数。形式参数当函数调用完成之后就自动销毁了。因此形式参数只在函数中有效
 

上面Swap1和Swap2函数中的参数 x，y，pe，pi 都是形式参数。在main函数中传给Swap1的a b和传给Swap2函数的&a，&b是实际参数



在这里可以看到Swap1 函数在调用 的时候 x y拥有自己的空间，同时拥有了和实参一模一样的内容，所以我们可以简单的认为：
   形参实例化之后其实就是实参的一份临时拷贝





//使用 函数 打印  100-200之间的素数

#include<math.h>


int is_prime(int e)
{
	int j = 0;
	for(j=2;j<=sqrt(e);j++)
	{
		if (e % j == 0)
			return 0;
		//else
			//return 1;  这样写 如果上面 if 不成立 则 直接 else 了  会直接输入 1  错误的 b  
			
	}
	return 1;
}


int main()
{
	//打印100-200之间的素数
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
			printf("%d ", i);

	}
	return 0;
}




// 写一个函数判断是否为闰年


int is_leap_year(int e)
{
	if ((e % 4 == 0 && e % 100 != 0) || (e % 400 == 0))
		return 1;
	else
		return 0;
}

int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		//判断year是否为闰年
		if (1 == is_leap_year(year))
		{
			printf("%d ", year);
		}
	}
	return 0;
}

 //  二分查找函数


int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;//中间元素的下标
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;

}



int main()
{
	//二分查找法

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int e = 5;
	int sz = sizeof(arr) / sizeof(arr[0]);//如果将此条程序 写入 函数中 则 传输过去的是首个字符
	int ret = binary_search(arr, e, sz);

	if (ret == -1)
	{
		printf("找不到指定的数字\n");
	}
	else
	{
		printf("找到了，下标是：%d\n",ret);

	}
	return 0;
}