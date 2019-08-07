/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   qqȺ��101132160
   ΢�Ź��ںţ�hwdong���
   C++17�����ŵ���ͨ��Դ���룩��https://github.com/hwdong-net/cplusplus17
*/

#include <iostream>
# if 0 
#include <iostream>

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

#if 0
int* Max(int * a, int* b) {
	return a > b ? a : b;
}
#endif 

template <>
int * Max<int *>(int* a, int* b) {
	return *a > *b ? a : b;
}

#if 0
int * Max(int* a, int* b) {
	return *a > *b ? a : b;
}
#endif 

int main() {
	int x = 10, y = 20;
	int *p = &x, *q = &y;
    std::cout << *Max(p, q) << '\n';
}
#endif 

#if 0
#include <iostream>
using std::cout;

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

int* Max(int * a, int* b) {
	cout << "hehe\n";
	return *a > *b ? a : b;
}

template <typename T>
T Max(T arr[], int n) {
	T ret{ arr[0] };
	for (int i=1;i!=n;i++)
		if (arr[i]>ret ) ret = arr[i];
	return ret;
}

template <typename T>
T* Max(T* a, T* b) {
	return *a > *b ? a : b;
}

int main() {
	int x{ 10 }, y{ 20 };
	cout << Max(x, y) << '\n';
	cout << *Max(&x, &y) << '\n';
	double ds[]{ 3.1,0.2,4.6,7.8 };
	cout << Max(ds, std::size(ds))<<'\n';
}
#endif

#include <iostream>
using std::cout;
#if 0
template <typename T1,typename T2>
auto add(T1 a, T2 b)decltype(a + b) {
	return a +b;
}
#endif 

#if 0
template <typename T1, typename T2>
decltype(auto) add(T1 a, T2 b) {
	return a + b;
}
#endif 

#if 0
template <typename T, int lower, int upper>
T average(const T arr[])
{
	T ret{ arr[lower] };
	for (auto i = lower + 1; i <= upper; i++)
		ret += arr[i];
	return ret;
}

int main() {
	int arr[]{ 1,2,3,4,5 };
	std::cout<<average<int, 0, 4>(arr)<<'\t';
	std::cout << average<int, 1, 3>(arr) << '\t';
	double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
	std::cout << average<double, 1, 3>(arr2) << '\t';
}
#endif

#if 0
template <int lower, int upper, typename T>
T average(const T arr[])
{
	T ret{ arr[lower] };
	for (auto i = lower + 1; i <= upper; i++)
		ret += arr[i];
	return ret;
}

int main() {
	int arr[]{ 1,2,3,4,5 };
	std::cout << average<0,4>(arr) << '\t';
	std::cout << average<1,3>(arr) << '\t';
	double arr2[]{ 1.2,2.2,3.4,4.7,5.8 };
	std::cout << average<1, 3>(arr2) << '\t';	
}
#endif 

#if 0
template <typename T=int,int e=2>
T power(const T x) {
	T ret{ x};
	for (auto i = 1; i < e; i++)
		ret *= x;
	return ret;
}

int main() {
	std::cout << power(3)<<'\t';
	std::cout << power(3.5) << '\t';	
	std::cout << power<double,3>(3.5) << '\t';
}
#endif

template <typename T>
class Vector{
private:
	T* data{nullptr}; // T*����ָ��ָ������Ԫ��������T�Ķ�̬����
	size_t capacity{0}; //��̬�ռ�Ĵ�С
	size_t size_{0}; // ʵ�ʵ�����Ԫ�ظ���
public:
	explicit Vector(size_t cap=5);
	~Vector();

	T& operator[](size_t index); // �±������
	const T& operator[](size_t index) const; // �±������-const

	Vector(const Vector<T>& array); // �������캯��
	Vector& operator=(const Vector<T>& rhs); // ��ֵ�����

	bool push_back(const T &e);
	
	size_t size() const { return size_; } // ����ʵ������Ԫ�صĸ���
};

template <typename T> 
Vector<T>::Vector(size_t cap) :data{ new T[cap] }, size_{ 0 }, capacity{ cap }
{
	//if (data) { capacity = cap; }
}

template <typename T>
Vector<T>::~Vector() {
	delete[] data;
}
#if 0
template <typename T>
T& Vector<T>::operator[](size_t index) // �±������
{
	if (index >= size_) throw "�±�Ƿ�";
	return data[index];
}
#endif

template <typename T>
const T& Vector<T>::operator[](size_t index) const // �±������-const
{
	if (index >= size_) throw "�±�Ƿ�";
	return data[index];
}

#if 0
template <typename T>
T& Vector<T>::operator[](size_t index) // �±������
{
	return const_cast<T&> (static_cast<const Vector<T>&>(*this)[index]);
}
#endif 

#if 0
#include <utility>
template <typename T>
T& Vector<T>::operator[](size_t index) // �±������
{
	return const_cast<T&> (std::as_const(*this)[index]);
}

template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector{ vec.capacity }
{
	size_ = vec.size_;
	for (size_t i{}; i < size_; ++i)  //����ÿ������Ԫ��
		data[i] = vec.data[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (&rhs != this) // ���Ҳ������������Լ�ʱ���Ÿ�ֵ
	{ 
		Vector<T> ret{ rhs };
		std::swap(data, ret.data);		

		size_ = ret.size_;
		capacity = ret.capacity;
	}
	return *this; // �������������
}

template <typename T>
bool Vector<T>::push_back(const T&e)
{
	if (capacity == size_) // �ռ�����
	{
		T* temp= new T[2*capacity]; //������Ҳ�����ͬ����С�Ŀռ�
		if (!temp) return false;  //ʧ��
		capacity*=2;
		//�����ݴӾɿռ俽������¿ռ�
		for (size_t i{}; i < size_; ++i)
			temp[i] = data[i];
			    
		delete[] data; // �ͷű������ڴ�
		data = temp;		
	}
	//��������e�ӵ���������Ԫ�ص������
	data[size_] = e; size_++;
	return true;
}

#endif 

#if 0
template <>
class Vector<const char*>
{
	// �����ض����� const char*����Vector...
};



template<typename T,int s=10>
class X {
	//...
};

template<int s>
class X<const char*,s> {
	//...
};

template<typename T, int s>
class X<T*, s> {
	//...
};


int main() {
	Vector<int> a;
	for (auto i = 0; i <= 6; i++)
		a.push_back(2 * i + 1);
	a[3] = 30;
	for (auto i = 0; i != a.size(); i++)
		std::cout << a[i] << '\t';
	std::cout << '\n';

	Vector<int> b;
	b = a;
	for (auto i = 0; i != a.size(); i++)
		std::cout << b[i] << '\t';

//	Vector x{1.,2.,3.5 ,4.2, 5.5 };
	//std::vector x{ 1.,2.,3.5 ,4.2, 5.5 };

	Vector<const char *> vec;

	X<const char *, 3> x;

	return 0;
}
#endif 

#if 0
template<typename T>
class X{
	int a{ 0 };
	//...
	friend void f();
	friend class A;
};

void f() {
	X<char> x;
	X<double> y;
	std::cout<< x.a << '\t' << y.a << '\n';
}

int main() {
	f();
}
#endif 

#if 0

template<typename T>
class Y{
	int a{0};		
	//...
	friend auto g(const Y<T>& e);
};

template<typename T>
auto g(const Y<T>& e) {
	std::cout << e.a << '\n';
}

int main() {
	Y<char> y;
	Y<double> y2;
	
	g<char>(y);
//	g<double>(y2);
	return 0;
}
#endif


#if 0
#include <iostream>
class Point {
	int x, y;
public:
	Point(int x0, int y0) :x{ x0 }, y{ y0 }{}
	Point(std::initializer_list<int> list) {
		auto it = list.begin();//begin()����һ��ָʾlist��һ��Ԫ��λ�õĵ�����
		x = *it++; //�Ƚ�itָ���Ԫ��ֵ*it��ֵ��x,Ȼ��it++��ʹ��itָ����һ��Ԫ��
		y = *it++;
	}
	void print() {
		std::cout << x << "," << y;
	}
};

int main() {
	Point p{ 2,5 }; //OK��������������ƥ��
	Point q{ 2,5,3 }; //��������û��3�������Ĺ��캯��
}
#endif

#if 0
template <template<class> class X, class A>
void f(const X<A> &value) {
	/*...*/
}

#endif 

#if 0
template <typename... T>
void f(T... args) {/*...*/}

#if 0
template <typename... Args>
void print(Args&...args) {
	for (auto arg : args)
		std::cout << arg;	
}
#endif 

template <typename T>
void print(T t) {
	std::cout << t << '\t';
}

template <typename T,typename... Rest>
void print(T t,Rest...rest) {
	std::cout << t << "\t";
	print(rest...);
}
int main() {
	print("Li") ;
	print(2,"Li");
	print(2, "Li",80.5);
}
//https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/
//https://www.cnblogs.com/qicosmos/p/4325949.html
#endif 