
#if 0
#include <iostream>
class X {
	int a, b, c;
	double d;
};
int main() {
	X x;
	std::cout << sizeof(3) << '\t' << sizeof(double) << '\n';
	std::cout << sizeof(x) << '\t' << sizeof(X) << '\n';
}
#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1;  //day��day1����Ĭ�Ϲ��캯������
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
	Date day;   //���������ʱ�Զ�����ƥ��Ĺ��캯��
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
	//Date day(2018, 8, 18),	       //���������ʱ�Զ�����ƥ��Ĺ��캯��
	//	day2{ 2019,6,1 };

	Date day;    //��û�к��ʵ�Ĭ�Ϲ��캯������
	Date day(2010, 1, 2, 3);  //��û�����غ������� 4 ������

}

#endif 

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	//Date() {}
	Date() = default;
	Date(int y, int m, int d) {
		year = y; month = m; day = d;
		std::cout << "����Date����" << '\t';
		print();
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day(2018, 8, 18),	       //���������ʱ�Զ�����ƥ��Ĺ��캯��
		day2;

}

#endif

#if 0
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	Date(int y = 2000, int m = 1, int d = 1) {
		year = y; month = m; day = d;
	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};
int main() {
	Date day, day1(2011), day2{ 2019,6 },
		day3{ 2019,13,8 };}

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

#endif 

#if 0
//��ʼ����Ա�б�
//��Ȼ�������ݳ�Ա��Date�ж���Ĵ���year��month��day�Ĵ������γ�ʼ����
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
//	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}	
	Date(int y = 2000, int m = 1, int d = 1) : day(d), month(m), year{ y }{	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {
	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();
}
#endif 

#if 0
//�������캯��
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:
	//	Date(int y = 2000, int m = 1, int d = 1) :year{ y }, month(m), day(d){		}
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){}
	Date(int y = 2000, int m = 1, int d = 1) : day(d), month(m), year{ y }{	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
};

int main() {

	Date day{ 2018,1,1 }, day2{ day };
	day.print();
	day2.print();	

}

#endif 

#if 0
//�������캯���Ĳ�������������
#if 0
class X {	
public:
	X() = default;
	X(X x) {}
};
int main() {
	X x;
	X y(x);
}
#else
class X {
public:
	X() = default;
	X(const X &x) {}
	X& operator=(const X& object);
};
int main() {
	X x;
	X y(x);
}
#endif

#endif 

#if 1
//�������캯��
#include <iostream>
class Date {
	int year{ 2000 }, month{ 1 }, day{ 1 };
public:	
	Date(const Date& d) :year{ d.year }, month(d.month), day(d.day){}
	Date(int y = 2000, int m = 1, int d = 1) : day(d), month(m), year{ y }{	}
	void print() { std::cout << year << "-" << month << "-" << day << '\n'; }
	Date& operator=(const Date& date) {
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