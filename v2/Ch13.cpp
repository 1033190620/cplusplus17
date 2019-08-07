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
#include <string>
int main() {
	int a;  std::string s;
#if 0
	std::cin >> a >> s;
	std::cout << a << '\t' << s;
#else
	std::cin >> std::noskipws >> a >> s;
	std::cout << a << '\t' << s;
#endif
	if (!std::cin)
		std::cout << "���������ڴ���״̬!";
}
#endif 

#if 0
#include <iostream>
using namespace std;
int main()
{
	char c;
	cout << "������:" << endl;
	while (cin.get(c))
		cout <<c;
	return 0;
}
#endif 

#if 0
#include <iostream>
#include <fstream>
int main() {
	std::ofstream outfile("test.txt");
	char ch;
	std::cout << "����һЩ�ı���ֱ�����������ַ�#\n";
	do {
		ch = std::cin.get();
		outfile.put(ch);
	} while (ch != '#');

	return 0;
}

#endif 

#if 0
#include <iostream>
#include <sstream>
int main() {
	std::istringstream is("My name is hwdong");
	char str[10];
	while (is.get(str, 10, ' ')) {  //�ָ����ǿո��ַ�
		is.get(); //�����ָ���
		std::cout << str << '\n';
	}
}
#endif

#if 0
#include <iostream>     
#include <fstream>      
int main() {
	char str[256];
	std::cout << "������ڵ��ļ���: ";
	std::cin.get(str, 256);

	std::ifstream is(str); //���������ļ�������is
	char c;
	while (is.get(c))
		std::cout << c;

	is.close();  //�رմ򿪵��ļ�
}

#endif

#if 0
#include <iostream>
#include <sstream>

int main() {
	std::istringstream is("hwdong|hw-dong|hw.dong");
	char str[10];

	while (is.getline(str, 8, '|'))
		std::cout << str << '\n';

}
#endif

#if 0
#include <iostream>     
#include <fstream>      
int main() {
	std::ifstream is("test.txt");
	char buf[1024];
	while (is.getline(buf, 1024))
		std::cout << buf << '\n';
}
#endif

#if 0
#include <iostream>     
#include <fstream>      
int main() {
	//binary��ʾ�Զ����Ʒ�ʽ���ļ�
	std::ifstream is("test.txt", std::ifstream::binary);
	std::ofstream os("test2.txt", std::ofstream::binary);
	char buf[10];
	while (is.read(buf, 10)) {
		os.write(buf, is.gcount());
	}
	os.write(buf, is.gcount());
	os.close(); //�ر��ļ�

	char buf2[4096];
	std::ifstream is2("test2.txt", std::ifstream::binary);
	is2.read(buf2, 4096);
	int num = is2.gcount();
	buf2[num] = '\0';
	std::cout << buf2;
}
#endif

#if 0
#include <iostream>     
#include <string>      
int main() {
	char c = std::cin.peek();
	if (c >= '0'&&c <= '9') {//���cin�еĵ�һ���ַ������֣������һ������
		int num; std::cin >> num;
		std::cout << "��������һ��������" << num << std::endl;
	}
	else {   //���򣬶���һ���ַ���
		std::string str;  getline(std::cin, str);
		std::cout << "��������һ���ַ�����" << str << std::endl;
	}
}
#endif 

#if 0
#include <iostream> 
int main() {
	std::cout << "hi" << std::endl; // ���hi�ͻ��з���Ȼ��ˢ�»�����
	std::cout << "hi" << std::flush; //���hi��Ȼ��ˢ�»�����
	std::cout << "hi" << std::ends<<"world"; // ���hi�Ϳ��ַ���Ȼ��ˢ�»�����

}
#endif 

#if 0
#include <iostream>
#include <fstream>
#include <iterator> 
#include <string>
int main() {
	std::ifstream iF("test.txt");
	std::istream_iterator<std::string> it(iF);  // ��iF��ȡ����
	std::istream_iterator<std::string> eof;    // β������	
	while (it != eof)
		std::cout << *it++ << '\t';
}

#endif 


#if 0
#include <vector>
#include <algorithm>
#include <iostream>

struct Sum{
	Sum() : sum{ 0 } { }
	void operator()(int n) { sum += n; }
	int sum;
};

int main(){
	std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };

	auto print = [](const int& n) { std::cout << " " << n; };

	std::cout << "��print���������:";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << '\n';

	// ��ÿ����ִ��lambda���ʽ����ÿ��������1
	std::for_each(nums.begin(), nums.end(), [](int &n) { n++; });

	// ��ÿ����ִ�к�������Sum::operator()
	Sum s = std::for_each(nums.begin(), nums.end(), Sum());

	std::cout << "after: ";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << '\n';
	std::cout << "sum: " << s.sum << '\n';
}

#endif 

#if 0
// merge algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::merge, std::sort
#include <vector>       // std::vector

int main() {
	int first[] = { 5,10,15,20,25 };
	int second[] = { 50,40,30,20,10 };
	std::vector<int> v(10);

//	std::sort(first, first + 5);
//	std::sort(second, second + 5);
	std::merge(first, first + 5, second, second + 5, v.begin());

	std::cout << "The resulting vector contains:";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
#endif 

#if 0

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> v{ 5, 23, 22, 9, 8 };

	std::cout << "initially, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::make_heap(v.begin(), v.end());  //��������[v.begin(): v.end())Ϊһ����
//	std::make_heap(v.begin(), v.end(), [](double a, double b) {return b<a; });
#if 0
	std::cout << "after make_heap, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	v.push_back(56);                    //��56׷�ӵ�����v����

	std::cout << "before push_heap: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::push_heap(v.begin(), v.end()); //�����һ��Ԫ�ؼ�v.end()-1��Ԫ�ز��뵽����

	std::cout << "after push_heap: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';

	std::pop_heap(v.begin(), v.end()); //���Ѷ�Ԫ�ص���������һ��Ԫ�غ����һ��Ԫ�ؽ���
	auto largest = v.back();
	v.pop_back();                      //��v�����һ��Ԫ��ɾ��
	std::cout << "largest element: " << largest << '\n';

	std::cout << "after removing the largest element, v: ";
	for (auto i : v) std::cout << i << ' ';
	std::cout << '\n';
#endif
	std::sort_heap(v.begin(), v.end());

	std::cout << "sorted:\t";
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

#endif 

#if 0
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>



int main()
{
	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto &i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5, 5, 5 };
		std::vector<int> v2 = { 3, 4, 5, 6, 7 };
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
			v2.begin(), v2.end(),
			std::back_inserter(dest1));

		for (const auto &i : dest1) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}

#endif 

#if 0
//����CTRL+Z����

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
	vector<int> vec;
	istream_iterator<int> is(cin);//�󶨱�׼����װ��
	istream_iterator<int> eof;//�����������λ��
	copy(is, eof, back_inserter(vec));
	sort(vec.begin(), vec.end());

	ostream_iterator<int> os(cout, ", ");//�󶨱�׼���װ��
	copy(vec.begin(), vec.end(), os);
}
#endif

#if 0


/************************************************************************/
//���ܣ��ӱ�־�����ȡ���е��������֣����򣬽����ظ����ļ���ӡ����Ļ                                                             
/************************************************************************/
#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main(){
	vector<string> strVector;
	//istream_iterator ��������������
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(strVector));
	sort(strVector.begin(), strVector.end());

	//��unique�㷨���������ڵ���ͬԪ��ֵ��ostream_iterator �����������
	unique_copy(strVector.begin(), strVector.end(), ostream_iterator<string>(cout, "\n"));
}


#endif

#if 0
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>

template<typename C>
void print(const C& c) {
	for (auto e : c) 	std::cout << e << " ";
	std::cout << '\n';
}
int main() {
	std::array<int, 5> s = { 5, -7, 4, -2, 8 };
	//��������
	std::reverse(s.begin(), s.end()); //��s����Ϊ��8, -2, 4, -7, 5
	print(s);
	// ʹ��Ĭ�ϵ������operator<
	std::sort(s.begin(), s.end());  //Ĭ��Ԫ�صĴ�С����
	print(s);
	// ʹ�ñ�׼��ıȽϺ�������
	std::sort(s.begin(), s.end(), std::greater<int>());  //�ò���std::greater����
	print(s);
	// ʹ�ö��Ƶĺ�������
	struct {
		bool operator()(int a, int b) const
		{
			return a < b;
		}
	} customLess;
	std::sort(s.begin(), s.end(), customLess);  //�ò���customLess����
	print(s);
	// ��lambda���ʽ�Ƚ�
	std::sort(s.begin(), s.end(), [](int a, int b) {return a > b;	}); //��Lambda��������
	print(s);
}

#endif 