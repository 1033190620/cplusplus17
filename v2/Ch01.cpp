#if 0
/*
   ��һ������
   hello world
   cout�Ǵ�����Ļ�������������������cout���ڱ�׼���ֿռ�std
*/
#include <iostream>  //�������ͷ�ļ�

int main() {
	std::cout << "hello world!";
	std::cout << std::endl;
	std::cout << 3 + 4 << std::endl;
	return 0;
}
#endif

#if 0
/*
  ����һ����������״
*/
#include <iostream>  

int main() {
	std::cout << "      *\n";
	std::cout << "    *   *\n";
	std::cout << "    *   *\n";
}
#endif 


#if 0
#include <iostream>
int main() {
	double radius = 3.6;
	double area = 3.1415926*radius*radius;
	std::cout << "�뾶��"<<radius<<"Բ������ǣ�"
		<<area << std::endl;
	radius = 9.8; //�޸�radius������ֵΪ9.8
	area = 3.1415926*radius*radius;
//	std::cout << "�뾶��" << radius << "Բ������ǣ�"
//		<< area << std::endl;
}
#endif

#if 0
//���������>>
//cin��һ��������̵�����������Ҳ�����ڱ�׼���ֿռ�std
#include <iostream>
int main() {
	double radius;
	std::cin >> radius;
	double area = 3.1415926*radius*radius;
	std::cout << "�뾶��" << radius << "Բ������ǣ�"
		<< area << std::endl;
}
#endif 

#if 0
//�����������ĳ����
#include <iostream>
void f() {
	std::cout << "��ã�" << std::endl;
	std::cout << "hello world��" << std::endl;
}
int main() {
	f();
	return 0;
}
#endif

#if 0
#include <iostream>
#define PI 3.1425926 
int main() {
	double radius = 3.6;
	double area = PI *radius*radius;
	std::cout << "�뾶��" << radius << "Բ������ǣ�"
		<< area << std::endl;
	radius = 9.8; //�޸�radius������ֵΪ9.8
	area = PI *radius*radius;
	std::cout << "�뾶��" << radius << "Բ������ǣ�"
			<< area << std::endl;
}
#endif

#if 0
#include <iostream>  
int main() {
#if 0
	std::cout << "hello world!";
#else
	std::cout << "���!";
#endif
	return 0;
}
#endif

#if 0
#define DEBUG
#ifdef  DEBUG
#include <iostream>  
int main() {
	std::cout << "hello world!";
	return 0;
}
#endif

#ifdef Windows
...
#endif
#ifdef Linux
...
#endif

#ifndef F_342345_.h
#define F_342345_.h
#include <iostream>
void f() {
	std::cout << "��ã�" << std::endl;
	std::cout << "hello world��" << std::endl;
}
#endif
#endif

#if 0
#include <iostream>
int main() {
	{
		std::cout << "��ã�" << std::endl;
		std::cout << "hello world��" << std::endl;
	}
	{
		std::cout << 3 + 4 << std::endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	if (score >= 60)
		std::cout << "�㼰���ˣ�\n";
	else
		std::cout << "�㲻����\n";
	return 0;
}
#endif

#if 0
#include <iostream>
int main() {
	double score;
	std::cin >> score;
	while (score >= 0) 
	{
		if (score >= 60)
			std::cout << "�㼰���ˣ�\n";
		else
			std::cout << "�㲻����\n";
		std::cin >> score;
	}
	return 0;
}
#endif 

#if 0
#include <iostream>
#include <string>       //����string���͵�ͷ�ļ�
int main() {
	std::string s;      //stringҲ�����ڱ�׼���ֿռ�std������
	std::cin >> s;
	std::cout << "hello," << s << std::endl;
	return 0;
}
#endif 

#if 0

#include <iostream>       // std::cout
#include <string>         // std::string
int main() {
	std::string s("hello world");
	std::string s2 = s.substr(0, 6);
	std::cout << s2 << "  " << s2.size() << std::endl;
	std::cout << s + s2 << std::endl;
}
#endif


#if 0
#include <iostream>
using namespace std;
// ʮ����ת��Ϊ������ 
void decToBinary(int n){
	// array to store binary number 
	int binaryNum[1000];

	// counter for binary array 
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array 
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}
int main()
{
	int n = 17;
	decToBinary(n);
	return 0;
}
#endif 

#if 0

#if 0
/*
�������srand()��rand()
*/
#include <iostream>
#include <cstdlib>
#include <ctime> 

int main() {
	srand((unsigned)time(0));   //�������������	
	int M = 4, m = 1;
	char ch;
	do {
		std::cout << (rand() % (M - m) + m) << '\n';
	} while (std::cin >> ch);
}
#else
#include <random>
#include <iostream>
int main(){
	std::random_device rd;  // ������Ϊ���������������
	std::mt19937 gen(rd()); // �Բ��ֱ�׼ mersenne_twister_engine
	std::uniform_int_distribution<> dis(1, 6);

	for (int n = 0; n < 10; ++n)
		// �� dis �任 gen �����ɵ���� unsigned int �� [1, 6] �е� int
		std::cout << dis(gen) << ' ';
	std::cout << '\n';
}
#endif
#endif 


#if 0
/*
���дһ��ѧ���ɼ�ͳ�Ʒ�������Ҫ��
1)�����롢��ѯ���޸ġ�ɾ��ѧ���ɼ���¼��
2)��ͳ�Ʋ�ͬ�����ε��������ٷֱȡ��־�(�����ͷֵĲ�)

һ��ѧ���ɼ���¼�������༶��������ѧ�š�ƽʱ�ɼ���ʵ��ɼ�����ĩ�ɼ��������ɼ�
���������ɼ� = c1*ƽʱ�ɼ�+c2*ʵ��ɼ�+c3*��ĩ�ɼ���c1��c2��c3�Ӽ������롣
����Ӧ�þ��У������¼�¼����ʾ����ѧ����¼����ѯ��ɾ�����޸ĵȹ��ܡ�

��һ���ṹ���ͱ�ʾһ��ѧ����¼���磺
typedef struct{
    char class[20],name[10];
	in id;
	double score_gen,score_exp,score_test,score;
}Student;

����ʱ����Ҫ���ַ������бȽϣ�Ӧ����C���Ե��ַ�����������ͷ�ļ�
<cstring>
�����ö�̬�ڴ����洢ѧ���ɼ����ݣ���ȻҲ�����þ�̬���顣
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>

using namespace std;
void help() {
	cout << "���������\n" ;
	cout << "����ѧ���ɼ���¼��I(i)\n";
	cout << "��ʾ����ѧ���ɼ���S(s)\n";
	cout << "��ѯѧ���ɼ���¼��Q(q)\n";
	cout << "ɾ��ĳ��ѧ���ɼ���D(d)\n";
	cout << "�޸�ĳ��ѧ���ɼ���M(m)\n";
	cout << "��ʾ�������H(h)\n";
	cout << "�˳�����Esc����CTRL+Z(Windows)��CTRL+D(Unix)\n";
}
int main() {
	cout << "===========��ӭʹ�á�ѧ���ɼ���������===================";
	help();
	char cmd;
	while (cin >> cmd) {
		if (cmd == 'H' || cmd == 'h') {
			help(); continue;
		}
	}
}
#endif 

#if 0
#include <iostream>
int main() {
	std::cout << R"d(
          ,-~-. _.---._ ,-~-.
         / .- ,'       `. -. \
         \ ` /`        ' \ ' /
          `-/   'a___a`   \-'
            |   ,'(_)`.   |
            \  ( ._|_. )  /
             \  `.___,'  /
            .-`._     _,'-.
          ,'  ,' `---' `.  `.
         /   /     :     \   \
       ,'   /      :      \   `.
     ,'     |      :      |     `.
    |     ,'|      :      |`.     |
    `.__,' .-\     :     /-. `.__,'
          /   `.   :   ,'   \
   .""-.,'      `._:_,'      `.,-"".
  / ,-. `         ) (         ' ,-. \
 ( (   `.       ,'   `.       ,'   ) )
  \ \    \   _,'       `._   /    / /
   `.`._,'  /             \  `._,','
     `.__.-'               `-.__,'

)d";
			

}
#endif 