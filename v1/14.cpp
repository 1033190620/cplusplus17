/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   ΢�Ź��ںţ�hwdong���
*/

#include <iostream>

#if 0
int do_task(){
	// ...
	if (����������ĳЩ����)
		return result;  //���ؽ��
	else
		throw Some_error{}; //�׳�����
}

void taskmaster()
{
	try {
		auto result = do_task();
		// ʹ�÷��صĽ�� result
	}
	catch (Some_error) {
		//  do_task������ĳ���쳣: ��������쳣
	}
}


try {
	f();
}
catch (const std::overflow_error& e) {
	// ���f()�׳�(throw)����std::overflow_error������ͬ���ͣ�
}
catch (const std::runtime_error& e) {
	//���f()�׳�(throw)����std::underflow_error (�������)
}
catch (const std::exception& e) {
	//���f()�׳�(throw)����std::logic_error (�������)
}
catch (...) {
	// ���� f()�׳������������͵��쳣
}

#endif 

#if 0
#include <iostream>
#include <string>

class MyError{
};

void g() {
	auto i{0};
	std::cin >> i;
	if (i == 0) 
		throw std::string("I am zero");
	else if (i < 0) 
		throw MyError();
	else if (i ==1)
		throw std::exception();
}

void f() {
	auto j{ 3 };
	j++;
	try {
		g();
	}
	catch (std::string &e) {
		std::cout << e << '\n';
	}
	catch (MyError ) {
		std::cout << "MyError" << '\n';
	}
	catch (...) {
		std::cout << "�κ����͵��쳣" << '\n';
	}
}

int main() {
	f();
}
#endif

#if 0
#include <iostream>
#include <string>

class MyError {
};

void g3() {
	auto i{ 0 };
	std::cin >> i;
	try {
		auto d{ 0. };
		if (i == 0)
			throw "I am zero";
		else if (i < 0)
			throw MyError();
		else if (i == 1)
			throw std::exception();
		else if (i == 3)
			throw i;
		std::cout << i * i << '\n';
	}
	catch (int &e) {
		std::cout << e++ << '\t'<<e<<'\n';
	}
	std::cout<<i<<'\n';
}

void g2() {
	auto j{ 3 };
	j++;
	try {
		g3();
	}
	catch(MyError e) {
		std::cout<<"MyError"<< '\n';
	}
	j *= 3;
	std::cout << j << '\n';
}

void g1() {
	//...
	try {

	}
	catch (const char *s) {
		std::cout << s << '\n';
		throw std::string(s);
	}
	//...
}
void main() {
	//...
	try {

	}
	catch (std::string s) {
		std::cout << s << '\n';
	}
	//...
}

#endif

#if 0
#include <mutex>
#include <iostream>
#include <string> 
#include <fstream>
#include <stdexcept>

#if 0
void write_to_file(const std::string & message) {
	// ���ڱ����ļ����ʵĻ����������̹߳���mutex
	static std::mutex mutex;

	// �ڷ����ļ�֮ǰ����������mutex
	std::lock_guard<std::mutex> lock(mutex);

	// ��ͼ���ļ�
	std::ofstream file("example.txt");
	if (!file.is_open())
		throw std::runtime_error("unable to open file");
	
	file << message << std::endl; // ���ļ���д��Ϣ

	//�����Ƿ����쳣���ļ������뿪��Χʱ���رգ�
	//������mutex����������lock������������	
}
#endif

// ���ڱ����ļ����ʵĻ����������̹߳���mutex
static std::mutex mutex;
void write_to_file(const std::string & message) {

	mutex.lock();

	// ��ͼ���ļ�
	std::ofstream file("example.txt");
	if (!file.is_open())
		throw std::runtime_error("unable to open file");

	file << message << std::endl; // ���ļ���д��Ϣ

	//�����Ƿ����쳣���ļ������뿪��Χʱ���رգ�
	mutex.unlock(); //�쳣����ʱ���޷�������һ�䣬��ˣ�mutex�޷�����
}

#endif 

#if 0
auto get_scores(){
	auto p = new double[100];
	if (!p) throw "û���㹻���ڴ�";
	for (auto i = 0; i != 100; i++) {
		auto score{0.};
		std::cin >> score;
		if (score < 0) throw "������һ�����ķ�����";
		else p[i] = score;
	}
	return p;
	
}

void fun() {	
	try {
		auto scores = get_scores();
		delete[] scores; // ���ܲ��ᵽ����һ�䣬�����ڴ�й© memory leak!
	}
	catch (const char *e) {
		std::cout << e << "\n";
	}
}

int main() {
	fun();
	//...
}
#endif 

#if 0
//��ֹ�����͸�ֵ:��ֹ��Դ������
class NonCopyable{
	NonCopyable(NonCopyable const &) = delete; // private copy constructor
	NonCopyable & operator= (NonCopyable const &) = delete; // private assignment operator
public:
	NonCopyable(){}
};

template <class T>
class WrapPtr{ // : NonCopyable{
	//��ֹ�����͸�ֵ:��ֹ��Դ������
	WrapPtr(WrapPtr const &) = delete; // private copy constructor
	WrapPtr & operator= (WrapPtr const &) = delete; // private assignment operator
public:

	WrapPtr(T * p = 0) : ptr_(p) {}
	~WrapPtr() throw() { std::cout << "�ͷ�ָ��"; delete ptr_; }
	// Array subscript operator
	T& operator[](size_t index) noexcept { return ptr_[index]; }
	const T& operator[](size_t index) const noexcept { return ptr_[index]; }
	T *get_data()const noexcept { return ptr_; }
private:
	T *ptr_;
};

auto get_scores() {
	auto p = new double[100];
	if (!p) throw "û���㹻���ڴ�";

	WrapPtr wp(p);
	for (auto i = 0; i != 100; i++) {
		auto score{ 0. };
		std::cin >> score;
		if (score < 0) throw "������һ�����ķ�����";
		else wp[i] = score;
	}
	return wp.get_data();

}

void fun() {
	try {
		auto scores = get_scores();	
	}
	catch (const char *e) {
		std::cout << e << "\n";
	}
}

int main() {
	fun();
	//...
}
#endif

#if 0
int main() {
	auto *p{ new int }, *q{ new int[3] };//p��qָ��̬�����ڴ�
	auto i{ 3 };
	p = &i;   //pҲ����ָ��һ���Զ�����
	delete q; //��ֻ�ͷ���qָ���3��int�ĵ�1��int�ڴ档
	q = 0;
	delete p; //��pָ��Ĳ��Ƕ�̬�ڴ�
	
	p = new int;
	q = p;
	delete p; p = 0;
	auto j{ *q };

}
#endif 


# if 0
#include <memory>
#include <iostream>

void f() {
# if 0
	std::unique_ptr<double> p{ new double{0.} };
	*p = 3.14;
	std::cout <<*p << '\t';
	double *rp = p.get();
	*rp = 3.1415;
	std::cout << *(p.get()) << '\n';
	
	std::cout << p.get() << '\t';
	p.reset(new double);
	std::cout << p.get() << '\n';
	
	p.reset();
	std::cout << p.get() << '\n';

	p.reset(new double);
	double* rawp = p.release();	
	*rawp = 3.0;
	std::cout << p.get() << '\n';

#endif

#if 0
	std::unique_ptr<char[]> p(new char[5]);
	p[0] = 'A'; p[1] = 'B'; p[2] = 'C';
	for (auto i = 0; i != 3; i++)
		std::cout << p[i];
	std::cout << std::endl;
#endif 

#if 0
	auto q = std::make_unique<double>(3.14);
	std::cout << *q << '\n';
	auto p = std::make_unique<double[]>(3); //����3��doubleԪ�صĶ�̬�ռ�
	p[0] = 'A'; p[1] = 'B'; p[2] = 'C';
	for (auto i = 0; i != 3; i++)
		std::cout << p[i];
	std::cout << std::endl;
	
#endif 

#if 0
	auto p = std::make_unique<double>(3.14);
	auto q{ p }; //�����ܿ�������
	std::unique_ptr<double> r{};
	r = p;    //�����ܸ�ֵ
#endif 
}
#endif 



#if 0
std::unique_ptr<int> get_unique() {
	auto ptr = std::unique_ptr<int>{ new int{2} }; 
	return ptr; // ptr��move���ƶ�������ʱ�ķ��ؽ����
}


void f() {
	//...
	auto uptr = get_unique(); // get_unique()�ķ���ֵ��move(�ƶ�)��uptr��
	//...
}
#endif 

#if 0
std::unique_ptr<int> get_unique() {
	auto ptr = std::unique_ptr<int>{ new int{2} };
	return ptr; // ptr��move���ƶ�������ʱ�ķ��ؽ����
}



void fun(std::unique_ptr<int> p)
{
	// ...
}

int main()
{
	std::unique_ptr<int> p = get_unique();
	fun(p); // ����ֵ���������ص���move���캯��
	fun(std::move(p)); // ���ԣ���std::move()����ֵת��Ϊ��ֵ����
	return 0;
}
#endif 

#if 0

#include <iostream>
#include <memory>
#include <string>
int main() {
	auto ptr = std::make_shared<std::string>("hello");
	*ptr = "world";
	std::cout << *ptr << '\t' << ptr.use_count()<< '\n';
	auto ptr2 = ptr;  //���ü�����Ϊ2
	*ptr2 = "hello world";
	std::cout << *ptr << '\t' << ptr.use_count() << '\n';
	ptr2.reset(new std::string{"wang"}); //�ͷ�ԭ����rawָ�룬ָ���µ�string����
	std::cout << *ptr << '\t' << ptr.use_count() << '\n';
	ptr.reset();
	std::cout << ptr.use_count() << '\n';
}

#endif 


#if 0
#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
	std::cout << "use_count == " << gw.use_count() << ": ";
	if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
		std::cout << *spt << "\n";
	}
	else {
		std::cout << "gw is expired\n";
	}
}

int main(){
	{
		auto sp = std::make_shared<int>(42);
		gw = sp;

		observe();
	}

	observe();
}
#endif 

#if 0
(a)std::range_error r("error");
throw r;
(b)std::exception *p = &r;
throw *p;

void f(int *b, int *e){
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	// ��������������쳣
}


(a) class exceptionType { };
catch (exceptionType *pet) {}
(b) catch (...) {}
(c) typedef int EXCPTYPE;
catch (EXCPTYPE) {}

a) catch
b) handlers
c) throw
d) none of the mentioned

a. catch (.., )
b. catch (-- - )
c. catch (��)
d. catch (void x)

a.Try
b. catch
c.Finally
d.None of these
#endif 

#if 0
#include <iostream>
using namespace std;

int main(){
	try	{
		throw 'a';
	}
	catch (int param)	{
		cout << "int exceptionn";
	}
	catch (...)	{
		cout << "default exceptionn";
	}
	cout << "After Exception";
	return 0;
}
#endif 

#if 0

#include <iostream>
using namespace std;

class X {
public:
	X() { cout << "Constructor of X " << endl; }
	~X() { cout << "Destructor of X " << endl; }
};

int main() {
	try {
		X  t1;		throw 10;
	}
	catch (int i) {
		cout << "���� " << i << endl;
	}
}
#endif 

#if 0

void f2() {
	double d;
	try {
		auto i{ 0};		std::cin >> i;
		if (i < 0) throw - 1;
		else	if (i ==0) throw "zero";
		else throw 3.14;
	}
	catch (float) { std::cout << "float�쳣\n"; }
}
void f() {	
	try { f2(); }
	catch (int) { std::cout << "int�쳣\n"; }
}
int main() {
	try {
		f();
	}
	catch (double &err) {
		std::cout << "�쳣:" << err << "\n";
	}
}
#endif 
