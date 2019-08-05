#include <iostream>

#if 0
int main() {
	int var;
	var = 3;

	
}
#endif 

#if 0
int foo() { return 3; }

int main() {
	foo() = 3;
	return 0;
}
#endif 

#if 0
#include <vector>
int g_var = 2;

int& foo(){
	return g_var;
}

int main(){
	foo() = 10;
	std::vector<int> vec(3);
	vec[1] = 3; 

	const int a = 10;//a��һ����ֵ
	a = 2; //��a���ܱ���ֵ���޸ģ�
	return 0;
}
#endif 

#if 0
int main() {
#if 1
	double a{}, b{ 1 }, c{ -2 };
	double *x = &(a + b); //a+b������ֵ
	double *y = &a;   //a����ֵ
	double *z = &(std::abs(a*b)); //std::abs(a*b)������ֵ
	double *u = &25; // ����25������ֵ
#endif
	int a = 1, b = 2;
	int c = a + b;

	int arr[] = { 1, 2 };
	int* p = &arr[0];
	*(p + 1) = 10;   // OK: p + 1����ֵ, �� *(p + 1)��һ����ֵ

	int var{ 5 };
	int&& rtemp{ var + 3 }; // ��ֵ����rvalue reference
	std::cout << rtemp << std::endl; //������ʽrtemp��ֵ
	int& rcount{ var }; // ��ֵ����lvalue reference
}
#endif 


#if 0

class X {
	//...
public:
	X() = default;
	X(const X&) { std::cout << "�������캯����\n"; }
	X& operator=(const X&) {
		std::cout << "��ֵ��������:\n";
		return *this; 
	}
	//X(const X&&) { std::cout << "�ƶ����캯����\n"; }
};
X fun() {
	X t;
	//...
	return t;
}
int main() {
	X x;
	x = fun();
}

#endif 

#include <utility>
using std::cout;
template <typename T>
class Vector {
private:
	T* data{ nullptr }; // T*����ָ��ָ������Ԫ��������T�Ķ�̬����
	size_t capacity{ 0 }; //��̬�ռ�Ĵ�С
	size_t size_{ 0 }; // ʵ�ʵ�����Ԫ�ظ���
public:
	explicit Vector(size_t cap = 5);
	~Vector();

	T& operator[](size_t index); // �±������
	const T& operator[](size_t index) const; // �±������-const

	Vector(const Vector<T>& array); // �������캯��
	Vector<T>& operator=(const Vector<T>& rhs); // ��ֵ�����

	bool push_back(const T &e);
	size_t size() const { return size_; } // ����ʵ������Ԫ�صĸ���

#if 1

	Vector(Vector&& moved);
	Vector<T>& operator=(Vector<T>&& rhs);
#endif
};

template <typename T>
Vector<T>::Vector(size_t cap) :data{ new T[cap] }, size_{ 0 }, capacity{ cap }
{
//	cout << "���캯����������" << capacity << "Ԫ�صĿռ�\n";
	//if (data) { capacity = cap; }
}

template <typename T>
Vector<T>::~Vector() {
	delete[] data;
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const // �±������-const
{
	if (index >= size_) throw "�±�Ƿ�";
	return data[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index) // �±������
{
	return const_cast<T&> (std::as_const(*this)[index]);
}

template <typename T>
Vector<T>::Vector(const Vector& vec) : Vector{ vec.capacity }
{ 
	cout << "�������캯����������" << vec.size_ << "Ԫ��\n";
    size_ = vec.size_;
	for (size_t i{}; i < size_; ++i)  //����ÿ������Ԫ��
		data[i] = vec.data[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (&rhs != this) // ���Ҳ������������Լ�ʱ���Ÿ�ֵ
	{
		cout << "��ֵ�����\n";
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
		T* temp = new T[2 * capacity]; //������Ҳ�����ͬ����С�Ŀռ�
		if (!temp) return false;  //ʧ��
		capacity *= 2;
		//�����ݴӾɿռ俽������¿ռ�
		for (size_t i{}; i < size_; ++i)
			temp[i] = data[i];

		delete[] data; // �ͷű������ڴ�
		data = temp;
	}
	//��������e�ӵ���������Ԫ�ص������
	data[size_] = e; 
	size_++;
	return true;
}

Vector<int> f() {
	Vector<int> v(20);
	for (auto i = 0; i < 1000; i++)
		v.push_back(2 * i + 1);

	return v;
}

#if 1
// Move constructor
template <typename T>
Vector<T>::Vector(Vector<T>&& vec)
	: size_{ vec.size_ }, data{ vec.data }
{
	cout << "�ƶ����캯�����ƶ��� " << vec.size_ << "Ԫ��\n";
	vec.data = nullptr; // Otherwise destructor of moved would delete[] elements!
}

// Move assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
	cout << "�ƶ���ֵ��������ƶ��� " << rhs.size_ << "Ԫ��\n";
	if (this != &rhs) // prevent trouble with self-assignments
	{
		delete[] data; // delete[] all existing elements
		data = rhs.data; // copy the elements pointer and the size
		size_ = rhs.size_;
		rhs.data = nullptr; // make sure rhs does not delete[] elements
	}
	return *this; // return lhs
}
#endif 

#if 0

int main() {
#if 0
	Vector<int> v1(20);
	Vector<int> v2;
	for (auto i = 0; i < 1000; i++)
		v1.push_back(2 * i + 1);
	cout << "��ֵ�ĸ�ֵ...\n";
	v2 = v1;
#else
	Vector<int> v2;
	cout << "��ֵ�ĸ�ֵ...\n";
	v2 = f();
#endif
}

#endif 

#if 1 
int main(){
	Vector< std::string> str_vec;
	Vector< std::string> string_vec;
	for (auto i = 0; i < 10000; i++)
		string_vec.push_back("mljsdklfjsjfsyuqwhl");
	//str_vec = string_vec;
	str_vec = std::move(string_vec);
#if 0
	template<class _Ty>
	_NODISCARD constexpr remove_reference_t<_Ty>&&
		move(_Ty&& _Arg) _NOEXCEPT
	{	// forward _Arg as movable
		return (static_cast<remove_reference_t<_Ty>&&>(_Arg));
	}
#endif
	std::cout << "........\n";
	//��string_vecת��Ϊ��ֵ����ֵ����ref���������ֵ
	Vector< std::string> &&ref{std::move(string_vec)};
//	Vector< std::string> str_vec2 = ref; //ref��һ����ֵ����ˣ�
	                              //������ͨ�ĸ�ֵ����������ƶ���ֵ
	Vector< std::string> str_vec2 = std::move(ref);//


	return 0;
}
#endif