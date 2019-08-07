/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   qqȺ��101132160
   ΢�Ź��ںţ�hwdong���
   C++17�����ŵ���ͨ��Դ���룩��https://github.com/hwdong-net/cplusplus17
*/

#if 0
#include <iostream>
using namespace std;
int main() {
	int i = 3;
	char ch = 'A';
	double radius = 2.56;
	bool ok = false;

	cout << "int����ռ���ڴ棺 "<<sizeof(int)<<"�ֽ�"<<endl;
	cout << "iռ���ڴ棺 "<<sizeof(i)<<"�ֽ�" <<endl;
    cout << "chռ���ڴ棺 "<< sizeof(ch)<<"�ֽ�" <<endl;
	cout << "radiusռ���ڴ棺 "<<sizeof(radius)<<"�ֽ�" <<endl;
	cout << "okռ���ڴ棺 "<<sizeof(ok)<<"�ֽ�"<<endl;
}

#endif


#if 0
#include <iostream>
using namespace std;
int main() {
	cout << typeid(18u).name() << '\n'
		<< typeid(022L).name() << '\n'
		<< typeid(18LL).name() << '\n'
		<< typeid(0x12UL).name() << '\n'
		<< typeid(18ULL).name() << '\n';
}

#endif 

#if 0

#if 0
/* �÷�б�ܿ�ʼ��ת���ַ����б�ʾĳ���ַ����磺
  \n��ʾ���з���\t��ʾ�Ʊ����\0��ʾ���ַ�(������)����
*/
#include<iostream>
int main() {
	std::cout << "\\hello\tworld\n";
	
	std::cout << "\\hello\tworld\n";
}
#endif
#if 0
/*���е�ASCII�ַ��������÷�б��\����8λASCII��ʾ��
\0(���ַ�)       \7  (����)      \12 (���з�)    \40(�ո�)
\115 (��M��)          \x4d (��M��)

\���ֵ���ܳ���256����ˣ�һ�㲻����3λʮ����������\1234��ʾ�����ַ�\123�͡�4��
��\402��Ƿ���
*/
#include<iostream>
int main() {
	std::cout << "\0hello";
	std::cout << "\7he\12ll\123o\115\t\x4d\n";
	std::cout << "\1234\n";	
	std::cout << "\40\402\n";	
}
#endif

#if 0
#include<iostream>
int main() {
    unsigned short a = '\\';
	unsigned short b = '\r';
	unsigned short c = '\x2e';
	std::cout << a << '\t' << b << '\t' << c << '\n';
	std::cout << '\\' << '\t' << '\r' << '\t' << '\x2e' << '\n';
	std::cout << "hello\rworld";
}
#endif
#if 1
/*
��R��ͷ������ת���ַ����С�
	R "delimiter( raw_characters )delimiter"
delimiter�ǳ�Բ����()����б�ܺͿո��ַ�֮����ַ����С�
*/
#include<iostream>
int main() {	
	std::cout << R"d2f(\\hello\rwor\0ld)d2f";
}
#endif
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	bool b{ true };
	std::cout << b << '\t';
	std::cout << std::boolalpha << b << std::endl;
#if 0
	cout << std::hex << 18 << '\t' << 25 << '\n';
	cout << std::oct << 18 << '\t' << 25 << '\n';
	cout << std::dec << 18 << '\t' << 25 << '\n';
#endif

#if 0
	std::cout << std::fixed << 0.01 << '\n'
		<< std::scientific << 0.01 << '\n'
		<< std::hexfloat << 0.01 << '\n'
		<< std::defaultfloat << 0.01 << '\n';
#endif

}
#endif 

#if 0
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout << std::setprecision(2) << 3.1415926 << '\n';
	cout << std::setw(10) << 3.1415926 << '\n';
	cout << std::setw(10) << std::setfill('-') << 3.1415926 << '\n';
}


#endif 
#if 0
#include <iostream>
using namespace std;
int main() {
	bool b = 42;  //int��ֵ42ת��Ϊboolֵtrue,�ٶ�b��ʼ����b��ֵ����true	
	int i = b; // b��ֵtrueת��Ϊint��ֵ1���ٳ�ʼ��int����i��
	std::cout << boolalpha << b << '\t' << i << std::endl;
	i = 3.14; //double��ֵ3.14ת��Ϊint��ֵ3���ٶԱ���i��ֵ��i��ֵ����3
	std::cout << i << std::endl;
	unsigned char c = -1; //unsigned char��ȡֵ��Χ��[0,255]
			  // -1����[0,255]������Ϊ  (-1+256) % 256 = 255
	signed char c2 = 256; //256����char��ȡֵ��Χ[-127,128]���������֪
	std::cout << (unsigned short)c << std::endl;
	std::cout << (short)c2 << std::endl;
	return 0;
}
#endif

#if 0
//���ͱ���ʹ������п�ƽ̨�ԣ�ֻ�����������뿪�ء�
#define USING_COMPILER_A
#if defined USING_COMPILER_A
using Int32 = __int32;
using Int64 = __int64;
#elif defined USING_COMPILER_B
using Int32 = int;
using Int64 = long long;
#endif

#endif 

#if 0
#include <iostream>
#include <string>

int main() {
	typedef std::basic_string<char> string;
	std::basic_string<char> s("hello");
	std::string   s2("world");
	std::cout<<s<<"\n" << s2 << "\n";
}


#endif 

#if 0
#if 1
enum class Color { red, green, blue };
enum class Color2 { red, green, blue,yellow };
int main() {
	Color c = Color::green;
	Color2 c2 = Color2::red;
	c2 = c;
}
#else
enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
#include <iostream>
int main() {
	Day d{ Day::Tuesday };	
}
#endif

#endif 

#if 0
#include <iostream>
int g_var;
int main() {
	int var{ 2 };
	{
		std::cout << g_var << '\t' << var << '\n';
		int var{ 0 };
		var = 5;
		std::cout << g_var << '\t' << var << '\n';
	}
	std::cout << g_var << '\t' << var << '\n';
}

#endif 

#if 0
#include <iostream>
#include <string>
using namespace std;
enum class Color { red, green, blue };
int main() {
	string str;
	Color color;
	cin >> str;
	if (str == "red") color = Color::red;
	//...
}


}
#endif

#if 0
int main() {
	int month{ 8 }, day{ 6 };
	//int month{08},day{ 06 };
}
#endif


#if 0
#include <iostream>
int main() {
	int a = 0;
	decltype((a)) b = a;
	b++;
	std::cout << a <<'\t' << b;
}
#endif
