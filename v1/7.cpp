/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   ΢�Ź��ںţ�hwdong���
*/

#if 0
#include <iostream>
struct Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
int main() {
	Date day;	
	day.year = 2018;// ͨ����Ա���������.���������day�ĳ�Աyear
	day.month = 6;
	day.day = 1;
	std::cout << day.year << '-' << day.month << '-' << day.day << '\n';
}
#endif 

#if 0
#include <iostream>
struct Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
};

void print(Date *date) {//date��Date*ָ�����ͣ�����һ��Date����
	 // ��ӷ��������->����dateָ���Date����ĳ�Աyear��month��day
	std::cout << date->year << "-" << date->month << "-" << date->day << '\n';
}

int main() {
	Date day;
	day.year = 2018;// ͨ����Ա���������.���������day�ĳ�Աyear
	day.month = 6;
	day.day = 1;
	print(&day); //��day�ĵ�ַ��Ϊָ�봫��print����
}

int main() {
	Date day;
	print(&day); //��day�ĵ�ַ��Ϊָ�봫��print����
	day.year = 2018;// ͨ����Ա���������.���������day�ĳ�Աyear
	day.month = 6;
	day.year = 1;
	print(&day); //��day�ĵ�ַ��Ϊָ�봫��print����
}

#endif

#if 0
#include <iostream>
class Date {
public:
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
void print(Date *date) {	
	std::cout << date->year << "-" << date->month << "-" << date->day << '\n';
}
int main() {
	Date day;
	day.year = 2018;// ͨ����Ա���������.���������day�ĳ�Աyear
	day.month = 6;
	day.day = 1;
	print(&day);
}
#endif 

#if 0
#include <iostream>
class Date {
public:          //public֮��ĳ�Ա���ǹ�����
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() {
		//print����֪��year��month��day���Ǹ�����ĳ�Ա   
		std::cout << year << "-" << month << "-" << day << '\n';
	}
};
int main() {
	Date day;
	day.year = 2018;
	day.month = 6;
	day.day = 1;
	day.print();  //����ͨ�������day������Date�ĺ�����Աprint()
}
#endif 


#if 0

#include <iostream>
class Date {
public:          //public֮��ĳ�Ա���ǹ�����
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() {   //ע�⣺����д��: void print(Date *this){ 
		//ͨ��ָ�����this������ָ������year��month��day��Ա
		std::cout << this->year << "-" << this->month << "-" << this->day << '\n';
	}
};
int main() {
	Date day, day1;
	day.print();
	day1.print();
}

#endif 

#if 0
#include <iostream>
class Date {
public:          //public֮��ĳ�Ա���ǹ�����
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& setDay(int d) {
		day = d;
		return *this; //����thisָ��ָ��Ķ��������
	}
	Date& setYear(int y) {
		year = y;
		return *this; //����thisָ��ָ��Ķ��������
	}
};
int main() {
	Date day;
	day.year = 2018;
	day.month = 6;
	day.day = 1;
	day.print();
	day.setYear(2019).setDay(20); //day.setYear(2019)�ķ�����day����
								  //��˶������Լ�������setDay(20)
}
#endif 

#if 0
#include <iostream>
class Date {
public:          //public֮��ĳ�Ա���ǹ�����
	int year{ 2000 }, month{ 1 }, day{ 1 };
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& setDay(int d) {
		day = d;
		return *this; //����thisָ��ָ��Ķ��������
	}
	Date* setYear(int y) {
		year = y;
		return this;  //����thisָ��
	}
};
int main() {
	Date day,day2;
	day.year = 2018;
	day.month = 6;
	day.day = 1;
	day.print();
	day.setYear(2019)->setDay(20); //day.setYear(2019)�ķ�����day��ָ�룬
                                //ͨ�����ָ����Լ�ӵ���setDay(20)
	day2.print();
}

#endif 

#if 0
#include <iostream>
class X {
	int a, b, c;
	double d;
};
int main() {	
	X x;
	std::cout << sizeof(int) << '\t' << sizeof(double) << '\n';
	std::cout << sizeof(x) << '\t' << sizeof(X) << '\n';
}

#endif 
//���캯��

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() {} //���캯������������ͬ��û�з�������
	          //Ĭ�Ϲ��캯��û���κβ����ͺ��������
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1;
	day.print();
	day1.print();
}

#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() { std::cout << "����Date����" << std::endl; print(); }
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day;	//���������ʱ�Զ�����ƥ��Ĺ��캯��
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "����Date����" << '\t'; 
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018,8,18),	//���������ʱ�Զ�����ƥ��Ĺ��캯��
	     day2{ 2019,6,1 };
	Date day;    //��û�к��ʵ�Ĭ�Ϲ��캯������
	Date day(2010, 1, 2, 3);  //��û�����غ������� 4 ������
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date() = default;
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "����Date����" << '\t';
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018, 8, 18),	//���������ʱ�Զ�����ƥ��Ĺ��캯��
		day2{ 2019,6,1 };
	Date day;    //Ok,����Ĭ�Ϲ��캯��
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date() = default;
	Date(int y = 2000, int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day,day1(2011),day2{ 2019,6},
		day3{ 2019,13,8 };
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(Date &d) :year(d.year),month(d.month),day(d.day){}

	Date(int y = 2000, int m = 1, int d = 1) :year(y),month(m),day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date &operator=(const Date& date) {
		std::cout << "��ֵ�����\n";
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this; //���ر���ֵ����Ķ����������
	}
};

int main() {
	Date day(2018, 1, 1);
	Date day2, day3;
	day3 = day2 = day; //��ִ��day2 = day�������day2����ִ��day3 = day2
					 //day2 = dayʵ����day2.operator=(day)
}
#endif 

#if 0
int main() {

	Date day{ 2018,1,1 },day2{day}
	day.print();
	day2.print();


	Date day{ 2018,1,1 }, day3;
	day3 = day;
	day.print();
	day3.print();
}
#endif


#if 0
#include <iostream>
class A {	
public:
	A(int x) { std::cout << "��" << x << "�������"; }
};
void f(A a) {}
int main() {
	f(2); // 1����ͨ�����캯��A(int)ת����A���Ͷ����ٶ�a1��ʼ��
}

#endif 

#if 0
#include <iostream>
class Circle{
	double radius{0.};
public:
	explicit   Circle(double r):radius(r) {}
	auto area() { return 3.1415*radius*radius; }
	auto isAreaLargerThan(Circle c) { return area() > c.area(); }
};
int main() {
	Circle c(2), c2(5);
	std::cout << "a��c2������ǣ�" << c.area() << '\t' << c2.area() << '\n';
	if (c2.isAreaLargerThan(c))
		std::cout << "c2�������c��\n";
	else 
		std::cout << "c2�������cС\n";
	if (c2.isAreaLargerThan(50))
		std::cout << "c2�������50��\n";
	else 
		std::cout << "c2�������50Сc\n";
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1):year(y), month(m), day(d) {
	}
	Date(int *p) :Date(p[0], p[1], p[2]) { //ί��Date(int y=2000,int m=1,int d=1)���캯��    
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
#endif 

#if 0
class A {
public:
	A(int) {/*...*/ }
	A(double) = delete;
	A& operator=(const A& o) = delete;
	A(const A& o) = delete;
};
int main() {
	A a(1);
	A a1(3.14);  //�� A(double)����ֹ��
	A a2(a);     //��A(const A& o) ����ֹ��
	a2 = a1;     //��A& operator=(const A& o) ����ֹ��
}
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1);
	void print();
};
Date::Date(int y, int m, int d) :year(y), month(m), day(d) {}
void Date::print() { std::cout << year << "-" << month << "-" << day << '\n'; }
#endif


#if 0
#include <iostream>
class Date {	
public:
	Date(int y = 2000, int m = 1, int d = 1):year(y), month(m), day(d) {
	}
	Date(int *p) :Date(p[0], p[1], p[2]) { //ί��Date(int y=2000,int m=1,int d=1)���캯��    
	}
	//get��������������������
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

	//set�������޸�����������
	void setYear(int y) { if (y > 0) year = y; }
	void setMonth(int m) { if (m > 0) month = m; }
	void setDay(int d) { if (d > 0) day = d; }
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
private:
	int year{ 2000 }, month{ 1 }, day{ 1 };
};
int main() {
	Date day;
	day.setYear(2018);
	std::cout << day.getMonth() << '\n';
}


#endif 

#if 0
int main() {
	int i;
	const int ci = 1;
	ci = 3; //�������޸�const����(����)
	const int *p = &i; //p��ָ��const int���������󡱵�ָ�����
	*p = 3;  //�������޸�pָ��ĳ�����(const����)
	const int &r = i;  //p��const int�������󡱵�����
	r = 3;   //�������޸�r���õĳ�����(const����)
}
#endif

#if 0
class X {
public:
	int ival{ 0 };
};
int main() {
	const X x;
	std::cout << x.ival << std::endl; //OK
	x.ival = 10;  //��const����x���ĳ�Ա�����ܱ��޸�
	
	X y;
	y.ival = 10;  // y����const���󣬵�Ȼ�����޸������ĳ�Ա��
	const X *p = &y;
	p->ival = 20;  //������ͨ��pȥ�޸���ָ���const X���������󡱣�
	               // ��ʹ��ʼ��p��y�ǿ����޸ĵ�
	const X &r = y;  //const X�����ñ���r�󶨵�y
	r.ival = 20;   //������ͨ�����ñ���r�޸������õ�const X���������󡱣�
	              //��ʹ��ʼ��r��y�ǿ����޸ĵ�
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date(int y = 2000, int m = 1, int d = 1):year(y), month(m), day(d) {
	}
	Date(int *p) :Date(p[0], p[1], p[2]) { //ί��Date(int y=2000,int m=1,int d=1)���캯��    
	}
	//get��������������������
	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }

	//set�������޸�����������
	void setYear(int y)const  { if (y > 0) year = y; }
	void setMonth(int m) { if (m > 0) month = m; }
	void setDay(int d) { if (d > 0) day = d; }
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	const Date day;
	day.setYear(2008);    //������ȥ�޸�const����day
	std::cout << day.getYear() << std::endl;  //Ok!    
}
#endif 

#if 0
#include <iostream>
class Date {
	int _year{ 2000 }, _month{ 1 }, _day{ 1 };
public:
	int& year() { return _year; }
	int& month() { return _month; }
	int& day() { return _day; }
};
int main() {
	Date day;
	day.year() = 2008;    //OK
	std::cout << day.year() << std::endl; //OK
	const Date day2;
	day2.year() = 2008;  //��������Ǻ���ģ���Ϊ����const������
	std::cout << day2.year() << std::endl; //������󡣲�����Ϊʲô���ܲ�ѯconst������Ϣ��    
}
#endif 

#if 0
#include <iostream>
class Date {
	int _year{ 2000 }, _month{ 1 }, _day{ 1 };
public:
	int& year() { return _year; }
	int& month() { return _month; }
	int& day() { return _day; }
	const int& year() const { return _year; }
	const int& month() const { return _month; }
	const int& day() const { return _day; }
};
int main() {
	Date day;
	day.year() = 2008;    //OK
	std::cout << day.year() << std::endl; //OK
	const Date day2;
	//day2.year() = 2008;  //��������Ǻ���ģ���Ϊ�����޸�const����
	std::cout << day2.year() << std::endl; //OK,û�б������    
}
#endif 

#if 0
class X {
	mutable int count{ 0 };
	int ival{ 0 };
public:
	int val()const {
		count++; //mutable��Ա���ǿ��Ա��޸�
		return ival;
	}
};

#endif 

#if 0
#include <iostream>
class X {
	int x{ 0 };
public:
	void set_x(int i) { x = i; }
	void print() { std::cout << x; }
};
int main() {
	X x;
	x.print(); std::cout << '\n';
	X arr[3];
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
	for (auto i = 0; i != 3; i++) arr[i].set_x(2 * i + 1);
	for (auto x : arr) {
		x.print(); std::cout << '\t';
	}
	std::cout << '\n';
}
#endif

#if 0
class X {
	int x{ 0 };
public:
	X(int i) :x(i) {}
};
int main() {
	X arr[3];
}
#endif 

#if 0
#include <iostream>
class IntArray {
	int *data{ nullptr };//ָ�����ָ��̬�����int����
	int size{0}; //dataָ�������Ĵ�С
public:
	IntArray(int s) :size(s) {
		data = new int[s];
		if (data)  size = s; 
		std::cout << "������һ����С��" << s << "��IntArray����\n";
	}
	~IntArray() { 
		std::cout << "��������\n";
		if (data) delete[] data;
	}
	void put(int i,int x) { 
		if (i >= 0 && i < size) data[i] = x; }
	int get(int i) { 
		if (i >= 0 && i < size) return data[i];
		else return 0;
	}
};

int main(){
	std::cout << "������������";
	int s; std::cin >> s;
	IntArray arr(s);
	std::cout << "���������䣺";
	for (auto i = 0; i < s; i++) {
		int age;
		std::cin >> age;
		arr.put(i, age);
	}
	std::cout << '\n';
	std::cout << "����������ǣ�\n";
	for (auto i = 0; i < s; i++) 
		std::cout << arr.get(i)<<'\t';
	std::cout << '\n';

}
#endif

#if 0
#include <iostream>
class X
{
public:
	static inline int count{};   //X����ĸ���
public:
	int get_count() { return count; };
	X() { count++; }   //������һ���µ�X����,count����1
	~X() { count--; }  //������һ���µ�X����,count����1
};
//int X::count = 0; //�� int X::count {};

int main() {
	X x,x2;
	X arr[3];	
	std::cout << x.count<< '\t' << arr[1].count << '\t' << X::count << '\n';
}
#endif
#if 0
class Circle {
public:
	static inline const double PI{ 3.1415926 };
	Circle(double r) :radius(r) {}
	auto area() { return PI * radius*radius; }
private:
	double radius{ 0. };
};

#endif

#if 0
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:
	const static Date default_date;
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
const Date Date::default_date{ 2010,1,1 };
#endif

#if 0
#include <iostream>
class Date {	
	int year{ default_date.year }, month{ default_date.month }, 
		day{ default_date.day };
public:
	static Date default_date;
	static void set_default(const Date &d) {
		default_date.year = d.year;
		default_date.month = d.month;
		default_date.day = d.day;
	}
	Date(int y = default_date.year, int m = default_date.month, 
		int d = default_date.day) :year(y), month(m), day(d) {
	}	
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
Date Date::default_date{2010,1,1};
int main() {
	Date arr[3];
	Date d(2018,6,8);
	d.set_default(d); //��Date::set_default(d)
	Date arr2[5];
}


#endif 

#if 0
#include <iostream>
class X{
public:
	static inline int count{};   //X����ĸ���
public:
	static int get_count() { return count; };
	X() { count++; }   //������һ���µ�X����,count����1
	~X() { count--; }  //������һ���µ�X����,count����1
};

int main() {
	X x, x2;
	X arr[3];
	std::cout << x.get_count() << '\t' << arr[1].get_count() << '\t'
		<< X::get_count() << '\n';
}
#endif 


//ϰ��
#if 0

#include <iostream>
using namespace std;

class 	Point{
	int x{ 0 }, y{ 0 };
public:
	Point(){
		cout << "Constructor Called"<<endl;
	}	
	Point(int X, int Y = 20){
		//?
		cout << "Constructor Called" <<x<<","<<y<< endl;
	}	
	~Point(){
		cout << endl << "Destructor Called" << x << "," << y << endl;
	}
	void set_x(const int x) {?}
	void print()	{
		cout << x << "," << y << endl;		
	}
};

int main(){
	Point p1 = Point(10);
	cout << "p1 Value Are : ";
	p1.print();
	Point p2 = Point(30, 40);
	cout << "p2 Value Are : ";
	p2.print();
	p1.set_x(2);
	p1.print();
	return 0;
}


//https://www.includehelp.com/cpp-programs/cpp-class-program-to-read-time-in-seconds-and-convert-in-time-format-hh-mm-ss-using-class.aspx
#include <iostream>
using namespace std;

class Time{
private:
	int hours,minutes,seconds;
public:
	Time(int h, int m, int s);
	Time(const char *str); //str���ַ�����ʽ��ʱ�䡰02��08��15��
	void getTime(void);
	void putTime(void);
	void addTime(Time T1, Time T2);
	int seconds();//��ʱ��ת��Ϊ��
};
#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){
		std::cout << "�������캯��\n"; print(); }
	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();
}
#endif

#if 0

#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) :year(y), month(m), day(d) {
	}
	//ί��Date(int y=2000,int m=1,int d=1)���캯��  
	Date(int *p) :Date(p[0], p[1], p[2]) {	}
//	Date(int *p) :Date(p[0], p[1], p[2]), day{ 20 } {	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	int date[]{ 2018,9,6 };
	Date d(date); d.print();
}
#endif

#if 0
#include <iostream>
class X {
private:
	inline static int count{0};   //X����ĸ���
public:
	int get_count() { return count; };
	X() { count++; }   //������һ���µ�X����,count����1
	~X() { count--; }  //������һ���µ�X����,count����1
};

int main() {
	X x, x2;
	X arr[3];
	std::cout << x.get_count() << '\n';
}

#endif

#if 0
#include <iostream>
class Date {
	int year{ default_date.year }, month{ default_date.month },
		day{ default_date.day };
public:	
	static  const  Date default_date;
	Date(int y = default_date.year, int m = default_date.month,
		int d = default_date.day) :year(y), month(m), day(d) {
	}
	void print()const { std::cout << year << "-" << month << "-" << day << '\n'; }
};
const Date Date::default_date{ 2010,1,1 };
int main() {
	Date day;
	day.print();
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>   //strlen()
class String {
	char *data{ nullptr };
	int size_{0};
public:
	String() = default;
	String(const char *s) {
		auto len = strlen(s);
		data = new char[len + 1];
		if (!data) return;
		strcpy(data, s);//�����ַ������ݴ�s��dataָ��Ŀռ�
		size_ = len;
	}
	~String() { delete[] data; }
	auto size() { return size_; }
};
int main() {
	String s("hello world");
//	String s2(s); //���ÿ������캯������s�������¶���s2�С�
	String  s3;
	s3 = s;
	std::cout << s.size();
	//std::cout << s.find(��helo��);
}

#endif

#if 0
using ElemType = char;
class Vector {
	ElemType *data{ nullptr };
	auto  capacity{0}, n{0};
public:
	Vector(const int cap = 5)   //����������cap��һ�����Ա�
		:capacity{ cap }, data{ new ElemType[cap] }	{}
	bool insert(const int i, const ElemType &e); //��i������Ԫ��
	bool erase(const int i);            //ɾ��iԪ��
	bool push_back(const ElemType &e); //���������һ��Ԫ��
	bool pop_back();  //ɾ��������Ԫ��

	bool get(const int i, ElemType &e)const; //��ȡiԪ��
	bool set(const int i, const ElemType e);//�޸�iԪ��
	int size() const { return n; }  //��ѯ��
private:
	bool add_capacity();             //��������
};

bool Vector::insert(const int i, const ElemType &e) { //��i������Ԫ��
	return true;
}
bool Vector::erase(const int i) {            //ɾ��iԪ��
	return true;
}
bool Vector::push_back(const ElemType &e) { //���������һ��Ԫ��
	return true;
}
bool Vector::pop_back() {  //ɾ��������Ԫ��
	return true;
}

bool Vector::get(const int i, ElemType &e)const { //��ȡiԪ��
	return true;
}
bool Vector::set(const int i, const ElemType e) {//�޸�iԪ��
	return true;
}
bool Vector::add_capacity(){            //��������
	return true;
}
#endif

#if 0
#include <iostream>
#if 0
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}
	Point operator-()const {
		return Point(-this->y, -this->x);
	}
	void print() { std::cout << x << "," << y; }
	//...
};
#else
class Point {
	double x{}, y{};
public:
	Point(double x, double y) :x{ x }, y{ y }{}	
	friend Point operator-(const Point &p);
	void print() { std::cout << x << "," << y; }
	//...
};
Point operator-(const Point &p) {
	return Point(-p.y, -p.x);
}

#endif 

int main() {
	Point p(3, 4);
	(-p).print();
}

#endif


class X {
public:
	inline void f();
};
void X::f() {
	/*...*/
}