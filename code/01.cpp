#if 0
/*
 ���ǵ�һ������
 this is a first c++ program 
 //hello world  
*/

#include <iostream> //��������� ͷ�ļ�
int main() {
    std::cout << "hello world"; //���һ���ַ���
	return 0;
}
#endif

#if 0
#include <iostream> //��������� ͷ�ļ�
#define PI 3.1415
int main() {
    std::cout << PI * 2.5 * 2.5<<std::endl;
    std::cout <<2* PI * 2.5<< std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> //��������� ͷ�ļ�
#define PI 3.1415
int main() {
    int i = 3;
    char ch = 'A';
    double d = 3.14;
    bool ok = true;
    std::cout << i << std::endl;
    std::cout << ch << std::endl;
    std::cout << d << std::endl;
    std::cout << ok << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> //��������� ͷ�ļ�
int main() {
    int x, y = 4;
    x = 3;
    z  = 2 * (3 + 4)
    std::cout << z << std::endl;
}
#endif

#if 0
#include <iostream> //��������� ͷ�ļ�
#define PI 3.14159
int main() {
    double radius;
    std::cout << "������Բ�İ뾶��";
    std::cin >> radius;
    std::cout << "Բ������ǣ�" << PI * radius * radius 
        << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream> //��������� ͷ�ļ�
#include <iomanip>
int main() {
    
    std::cout << "int"<<'\t'<< "double" << '\t' << "bool\n";
    std::cout << "int" << std::setw(10) << "double" 
        << std::setw(10) << "bool";
    
    return 0;
}
#endif

#if 0
#include <iostream> //��������� ͷ�ļ�

void hello() {
    std::cout << "hello\t";
    std::cout << "wang\n";
}

void add_34() {
    std::cout << "3+4=:" << 3 + 4 << std::endl;
}

double circle_area(double radius) {//��ʽ����
    return 3.14159 * radius * radius;
}

int main() {
    hello();
    add_34();
    hello(); //���븴��
    std::cout<<circle_area(2.5)<<std::endl;//ʵ�ʲ���
    std::cout << circle_area(3.5) << std::endl;
    std::cout << circle_area(7.5) << std::endl;
    return 0;
}
#endif

#if 0
#include <iostream>
namespace A {
    int a;
    double f() { return 3.14; }
    int g(int i) { return 2 * i; }
}

namespace B {
    double a;
    int f() { return 0; }
    char g;
}

using  A::a;
using  A::f;
int main() {
    int i = 2;
    a = B::f();
    B::a = f();
}
#endif

#if 0
#include <iostream>
int main() {
    double radius;
    std::cout << "������Բ�İ뾶��";
    std::cin >> radius;
    if (radius <= 0)
        std::cout << "Բ�뾶����С��0 ";
    else 
        std::cout << "Բ������ǣ� "<<3.14*radius*radius;
}
#endif

#if 1
#include <iostream>
int main() {
    int i=1, sum = 0;
    while (i <= 100) {
        sum = sum + i;
        i = i + 1;
    }
    std::cout << "1��100������֮���ǣ�" << sum << std::endl;
}
#endif