#if 0
#include <iostream>
int main() {
	std::cout << "hello world";
	std::cout << std::endl;
	std::cout << "��С�׾�ͨ���";
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main() {
	cout << "hello\n\nworld";
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;
int main() {
	auto b = true;  // true�ǲ������͵�һ��ֵ
	auto ch{ 'x' };    // �����ű�ʾ���ַ���x���Ա���ch��ʼ��
	auto i = 123;   //123��int���͵�ֵ
	auto d{ 1.2 };   // 1.2��ʾ����double�����͵�ֵ
	auto z = d + i;   //�ӱ��ʽd+i��ֵ�ƶ�z����������
	cout << typeid(b).name() << '\t';
	cout << typeid(ch).name() << '\t';
	cout << typeid(i).name() << '\t';
	cout << typeid(d).name() << '\t';
	cout << typeid(z).name() << endl;
}

#endif
#if 0
#include <iostream>
#include <string>
int main() {
	std::string s = "hello", s2 = "world";
	std::cout << s * s2;
	std::cout<<3*s ;
}
/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   qqȺ��101132160
   ΢�Ź��ںţ�hwdong���
   C++17�����ŵ���ͨ��Դ���룩��https://github.com/hwdong-net/cplusplus17
*/

#if 1
#include <iostream>
#include <bitset>
int main_1() {
	std::cout <<"ʮ���ƣ�" << std::dec << 0b101101011101100111100101 <<'\n'
		<< "ʮ�����ƣ�" <<std::hex<< 0b101101011101100111100101 <<'\n'
		<< "�˽��ƣ�" << std::oct << 0b101101011101100111100101 << '\n';

	
	std::cout << "ʮ���ƣ�" << std::bitset<sizeof(unsigned int) * 8>(7654321) << std::endl;
	return 0;
}
#endif