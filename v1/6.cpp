#if 0
int Pow(int x, int e = 2) {
	auto ret{1};
	for (auto i = 0; i < e; i++)
		ret *= x;
	return ret;
}

#include <iostream>
int main() {
	std::cout << Pow(3) << '\t' << Pow(3, 4) <<'\n';
}
#endif

#if 0
#include <iostream>
void PrintArr(int arr[],int n) {
	for (auto i = 0;i<n;i++)
		std::cout << arr[i] << '\t';
}
int main() {
	int a[]{ 7,2,4,19 };
	PrintArr(a, 4);
}
#endif

# if 0
void PrintArr(int arr[], int n) {
	for (auto e :arr)
		std::cout << e << '\t';
}
#endif

#if 0
#include <iostream>
void PrintArr(int arr[], int n) {
	for (auto p=arr;p!=arr+n;p++)
		std::cout << *p << '\t';
}

void PrintArr(int arr[], int n);
void PrintArr(int arr[2], int n);
void PrintArr(int arr[10], int n);
void PrintArr(int *arr, int n);
#endif

#if 0
#include <iostream>
void SquareArr(int(&arr)[4]) {
	for (auto &e : arr)
		e *= e;
}
int main() {
	int a[]{ 7,2,4,19 };
	SquareArr(a);
	for (auto e : a)
		std::cout << e << '\t';
}
#endif

/*
void f(int arr[][4], int n); //�ȼ���void f(int (*arr)[4], int n);
void g(int arr[][4][5], int n); //�ȼ���void g(int (*brr)[4][5], int n);
*/

#if 0
#include <iostream>
void f(int arr[][4], int n) {
	//pָ����Ϊ����int [4],��ָ��һ�ж�Ӧ���Ǹ�����
	for (auto p = arr; p != arr + n; p++) {
		for (auto e : *p)  //*p��������int[4]
			std::cout << e << '\t';
		std::cout <<'\n';
	}
}
int main() {
	int a[][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	f(a,3); //���봫��a�Ĵ�С
}

#endif
#if 0
void f(const int x, const int y);
void g(const int *p, const int n);
void h(int *const q, const int n);
void f2(const int *const s, const int n);
#endif

#if 0
#include <iostream>
int fact(int n) {
	if (n == 1)  // ���n����1����ֱ�ӷ���ֵ1
		return 1;
	return n * fact(n - 1);	
}
int main() {
	std::cout << fact(4) << '\n';     //����� 24
}
#endif

#if 0
#include <iostream>
int fib(int n) {
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main() {
	for (int i{1};i!=8;i++)
		std::cout << fib(i) << '\t';
}
#endif 
#if 0
#include <iostream>
int gcd(int m, int n) {
	if (n == 0)
		return m;
	else
		return gcd(n, m%n);
}
int main() {
  std::cout << gcd(72,27) << '\t' << gcd(24, 36) << '\t';
}
#endif

#if 0

#include <iostream>
auto binarySearch(int a[], const int L,const int H, int value) {
	if (L>H)           //������
		return -1;
	auto Middle = (L+H) / 2;
    if (a[Middle] == value) // 1���м�Ԫ��ֱ�ӱȽ�
		return Middle;
	else 	if (value < a[Middle])
		return binarySearch(a, L, Middle - 1, value);    // 2) ���������
	else
		return binarySearch(a, Middle + 1, H, value);  // 3) ���������
} 

int main() {
	int arr[]{ 5, 7, 12, 25, 34, 37, 43, 46, 58, 80, 82, 105 };
	std::cout<<binarySearch(arr, 0, 11,25)<<'\t';
	std::cout << binarySearch(arr, 0, 11, 13) << '\n';
}
#endif
# if 0
#include <iostream>
// һ�����ӣ�ֱ���ƶ�
void moveDisk(int i, const char x, const char y) {
	std::cout << "moving disk" << i << " from " << x << " to " << y<<'\n';
}

// ����, ��ʼ��, ��ת��, Ŀ����
void move(int n, const char a, const char b, const char c) {
	if (n < 1) return;
	move(n - 1, a, c, b);  // n - 1�����Ӵ�A��������C���Ƶ�B��
	moveDisk(n, a, c);
	move(n - 1, b, a, c);   // n - 1�����Ӵ�B��������A���Ƶ�C��
}
int main() {
	move(3, 'A', 'B', 'C');
}
#endif

#include <iostream>

#if 0

void  partition(int a[], const int  start, const int  end) {
	auto pivotvalue = a[start];
	auto L{start + 1}, R{ end };

	auto done = false;
	while (not done) {
	}

	while L <= R and alist[L] <= pivotvalue :
		L = L + 1

		while alist[R] >= pivotvalue and R >= L :
			R = R - 1

			if R < L :
				done = True
			else :
				alist[L], alist[R] = alist[R], alist[L]
				#temp = alist[L]
				#alist[L] = alist[R]
				#alist[R] = temp

				alist[R], alist[start] = alist[start], alist[R]
				#temp = alist[start]
				#alist[start] = alist[R]
				#alist[R] = temp

				return R
}

}
void qsort(int arr[], const int start, const int  end) {
	if(start >= end) return;
	auto pivot = partition(arr, start, end)  //��[start, end]֮�������һ�λ���Ϊ2���֣�
		                                //  pivot�ǻ�׼��λ��
	qsort(arr, start, pivot - 1)    // ��[start, pivot - 1]֮������е���qsort���ٹ��̣�
	qsort(arr, pivot + 1, end)      // ��[pivot + 1, end]֮������е���qsort���ٹ��̣�
}

#endif

#if 0
int f() {/*...*/}
int f(int) {/*...*/ }
int f(int,int) {/*...*/ }
double f(double) {/*...*/ }


int f(int) {/*...*/ }
double f(int) {/*...*/ }
int f(int )
int f(const int )

int g(int*)         //int�����ָ��
int g(int *const)  //int����ĳ�ָ��

int f(int&)   //int���������
int f(const int&) //const int��Ӧ������

int g(int*)   //int����Ķ�ָ��
int g(const int *) //const int �����ָ�룬ָ�벻��const 

void f()
void f(int)
void f(int,int)
void f(double,double=3.14)

f(5.6)
#endif 

#if 0
void ff(int) { std::cout << "f(int)"; }
void ff(short) { std::cout << "f(short)"; }

int main() {
	ff('c'); //char����Ϊint,��˵��õ���ff(int)
}

inline int add(const int x, const int y) {
	return x + y;
}
int main() {
	add(3, 4);
}
#endif

#if 0
auto f(const int a) {  /*��*/ }


const auto size() {
	int i{ 9 };
	return i;
}

const auto size() {
	int i{ 9 };
	return i;
}
constexpr auto size1(int x) {
	int i{ 9 };
	return i;
}

#endif 
#if 0
int main() {
#if 0
	const auto PI{3.14};
	PI = 3.1415926;//��:�����޸�const����
	const int ci; //��const��������ʼ��

	auto a{2};
	const auto ca = a;  //ok��������һ������
	const auto j = 42;  //ok��������һ��������
	const auto k = get_size(); //ok:����ʱһ������ʱ��ֵ
#endif

#if 0
	auto a{3};
	const auto b{ 4 }; // //����ʱ��������Ϊ4�ǳ������ʽ
	const auto c{ size() }; //����ʱ��������Ϊsize()����ֵ����ʱ����ȷ��
	const auto d{ size1(a) }; //����ʱ��������aʱ����������size1(a)���ǳ������ʽ
	const auto e{ size1(b) }; //����ʱ��������b�ǳ������ʽ������size1(b)�ǳ������ʽ
	char arr[a], arr1[b], arr2[c], arr3[d], arr4[e];
#endif 

	auto a{ 3 };
	const auto b{ 4 }; //����ʱ����������һ���ǳ������ʽ
	constexpr auto c{ 5 };//�������ʽ��Ҳ�Ǳ���ʱ����
	constexpr auto d{ c+1 };//c�ǳ������ʽ�����c+1Ҳ�ǣ����dҲ�ǳ������ʽ
	constexpr auto e{size()}; //��size()�������صĲ��Ǳ���ʱ����
	constexpr auto f{ size1(a) }; //��size1(a)���ǳ������ʽ����Ϊa���Ǳ���ʱ����
	constexpr auto g{ size1(b) };  //OK��size1(b)�ǳ������ʽ����Ϊb�Ǳ���ʱ����

}
#endif


#if 0
int main() {
	const int ci = 3; //const���������non-const�����ʼ��
	int i = ci;       //non-const���������const�����ʼ��
	const int j = i;  //const���������non-const�����ʼ��
	const int &cri = i; // const��������ÿ���const��non-constֵ��ʼ��������������
	const int &cr3 = 3; // const��������ÿ���const��non-constֵ��ʼ��������������
	const int &crj = j; // const��������ÿ���const��non-constֵ��ʼ��������������
	int &r = ci;        //non-const��������ã���ͨ���ã�������const�����ʼ��
	int &r = 3;        //non-const��������ã���ͨ���ã�������const�����ʼ��������������

	const int *cp = &i; // ok: const�����ָ�����const��non-const��ָ��(��ַ)��ʼ��
	const int *cpj = &j; // ok: const�����ָ�����const��non-const��ָ��(��ַ)��ʼ��
	const int *cp3 = &3; //��������û�е�ַ
	int* p = &i;       //��ָͨ�루non-const�����ָ�룩����non-const��ָ��(��ַ)��ʼ��
	int *p2 = cp;   // error: ��ָͨ�벻����const�����ָ���ʼ����p2��cp���Ͳ�ƥ��
	int *pj = &j;   // error: ��ָͨ�벻����const�����ָ���ʼ����p2��cp���Ͳ�ƥ��
}

#endif 
#if 0

int f() {
	int i = 42;
	const int *cp = &i; // ok: const�����ָ�����const��non-const��ָ��(��ַ)��ʼ��
	const int &r = i; // ok: const��������ÿ���const��non-constֵ��ʼ��
	const int &r2 = 42; // ok: const��������ÿ���const��non-constֵ��ʼ��������������
	int* p2 = &i;

	int *p3 = p;
	int *p = cp; // error: ��ָͨ�벻����const�����ָ���ʼ����p��cp���Ͳ�ƥ��
	
	int &r3 = r; // error: ��ͨ���ò�����const��������ó�ʼ���� r3��r���Ͳ�ƥ��
	int &r4 = 42; // error: ��ͨ���ò����ó�����ʼ��
}


#endif

#if 0
void fun(int *) {/*...*/ }
void fun(int &) {/*...*/ }
void g(const int &) {/*...*/ }

int main() {
	int i = 0;
	const int ci = i;
	unsigned  ui = 0;
	fun(&i); // ����fun(int *)
	fun(&ci); // ��: ���ܽ�const int��ָ��ת��Ϊint *
	fun(i); // ����fun(int &)
	fun(ci); // ��: ���ܽ���ͨ����int &�󶨵�һ��const����ci
	fun(18); // ��: ���ܽ���ͨ����int &�󶨵�һ��������
	fun(ui); // ��: ���Ͳ�ƥ�䣬ui��unsigned
	g(37);   // OK: cosnt int�����ÿ�������������ʼ��
}
#endif 

#if 0
#include <iostream>
double average(std::initializer_list<double> scores){
	auto n{ 0 };
	double all{ 0 };
	for (auto score : scores) {
		all += score; n++;
	}
	if(n>0)	return all /= n;
	return 0;
}
int main() {
	std::cout << average({  }) << '\n';
	std::cout << average({60.}) << '\n';
	std::cout << average({ 50.,80 }) << '\n';
	std::cout << average({ 90,50.,80 }) << '\n';
}
#endif 

#if 0
#include <iostream>
int main(){
	while (true) {
		static auto i{ 0 }; //i��һ����̬�ֲ�����
		if (i++ < 6) std::cout << i << '\t';
		else break;
	}
}

#endif 

#if 0
#include <iostream>
void  f() {
	static auto i{ 0 };
	int j{ 0 };
	i++;  j++;
	std::cout << i << '\t' << j << '\n'; 
}

int main() {
	f();
	f();
}

#endif 

#if 0 

using T = int;
int partition(T arr[], const int start, const int end){
	auto pivotvalue{ arr[start] };
	auto L = start + 1, R = end;

	auto done{ false };
	while (!done) {
		while (L <= R and arr[L] <= pivotvalue)
			L = L + 1;
		while (arr[R] >= pivotvalue and R >= L)
			R = R - 1;
		if (R < L)
			done = true;
		else {
			//����L,R��ֵ
			auto temp{ arr[L] };
			arr[L] = arr[R];
			arr[R] = temp;
		}
	}
	//����R��start��ֵ������׼Ԫ���Ƶ���׼λ��R
	auto temp{ arr[R] };
	arr[R] = arr[start];
	arr[start] = temp;

	return R;
}

// ��[start, end]�����Ԫ�ؽ��п�������
void qsort(T arr[], const int start, const int  end) {
	if (start >= end) return;
	//partition��[start, end]֮�������һ�λ���Ϊ2���֣�����pivot�ǻ�׼��λ��
	auto pivot = partition(arr, start, end);
	qsort(arr, start, pivot - 1);    //��[start, pivot - 1]֮������е���qsort���ٹ��̣�
	qsort(arr, pivot + 1, end);     //��[pivot + 1, end]֮������е���qsort���ٹ��̣�	
}

void quickSort(T arr[], const int n) {
	qsort(arr, 0, n - 1);
}


int main() {
	int a[]{ 49, 38, 27, 97, 76, 13, 27, 49 };
	quickSort(a, 8);
	for (auto i{ 0 }; i != 8; i++)
		std::cout << a[i] << '\t';
	std::cout << '\n';
}
#endif 


#if 0
bool  go_maze(int maze[][6], const int x, const int  y,const int n = 6) {
	//��λ���Ƿ��յ㣨2����ǽ��1�����Ѿ��߹���3��
	if (maze[x][y] == 2) {
		std::cout << "�����յ㣺" << x << "," << y << '\n';
		return true;
	}
	else if (maze[x][y] == 1) {
		//std::cout << "ǽ��" << x << "," << y<<'\n';
		return false;
	}
	else if (maze[x][y] >= 3) {
		//std::cout << "�Ѿ����ʹ���" << x << "," << y << '\n';
		return false;
	}
	//�Ӹ�λ����4��̽��
	std::cout << "���ʣ�" << x << "," << y << '\n';
	maze[x][y] = 3;          // ��Ǹ�λ���Ѿ����ʹ�
	// ��4��̽��
	if ((x < n - 1 and go_maze(maze,x + 1, y))
		or (y > 0 and go_maze(maze, x, y - 1))
		or (x > 0 and go_maze(maze, x - 1, y))
		or (y < n - 1 and go_maze(maze, x, y + 1)))
		return true;

	maze[x][y] = 4;     //��·Ҳ��ͨ
	return false;	
}

void print(int maze[][6], const int n = 6) {
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < n; j++) {
			std::cout << maze[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

int main() {
	int maze[][6] = { {0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 0 },
		{0, 1, 1, 0, 0, 1},
		{0, 1, 0, 0, 1, 0 },
		{0, 1, 0, 0, 0, 2} };

	go_maze(maze, 0, 0);
	print(maze);
}
#endif