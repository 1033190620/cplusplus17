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
#include <sstream>
using namespace std;
bool isFloat(string s) {
	istringstream iss(s);
	float dummy;
	iss >> noskipws >> dummy;
	return iss && iss.eof();     // Result converted to bool
}
int main() {
	string str;
	std::cin >> str;
	if (isFloat(str))
		std::cout << str << "��һ��floatʵ��!\n";

}
#endif 

#if 0
if constexpr (cond)
���1; // ��� cond��false�����������
else
���2; // ��� cond��true�����������
#endif

#if 0
#if 0
template<int  N>
constexpr int fibonacci() { return fibonacci<N - 1>() + fibonacci<N - 2>(); }
template<>
constexpr int fibonacci<1>() { return 1; }
template<>
constexpr int fibonacci<0>() { return 0; }
#else
template<int N>
constexpr int fibonacci(){
	if constexpr (N >= 2)
		return fibonacci<N - 1>() + fibonacci<N - 2>();
	else
		return N;
}
#endif

#include <iostream>
int main() {
	std::cout << fibonacci<9>() << "\n";
}
#endif

#if 0
#include <iostream>
auto sum() {
	return 0;
}

template<typename T1, typename... T>
auto sum(T1 s, T... ts) {
	return s + sum(ts...);
}

int main() {
	std::cout << sum(1, 2) << std::endl;
	std::cout << sum(1, 2,3,4,5) << std::endl;
}

#endif 


#if 0
#include <string>
struct Student{
	int id;
	std::string name;
	float score;
};
template <int i> auto& get(Student &s) { if(i<0||i>2) throw "error"; }
template <> auto& get<0>(Student &s) { return s.id; }
template <> auto& get<1>(Student &s) { return s.name; }
template <> auto& get<2>(Student &s) { return s.score; }
#endif


#if 0
template <typename Type, Type value> constexpr Type TConstant = value;
constexpr auto const MySuperConst = TConstant<int, 100>;
#else
template <auto value> constexpr auto TConstant = value;
constexpr auto const MySuperConst = TConstant<100>;
#endif


#if 0
#include <iostream>
#include <vector>

#if 0 //C++11

template <typename T>
void print(T t) {                       //�����Σ�ֻ��һ�������β�
	std::cout << t << '\t';
}
template <typename T, typename... Rest>
void print(T t, Rest...rest) {              //�ݹ����Σ��ж�������β�
	std::cout << t << "\t";	print(rest...);
}
#else
//https://stackoverflow.com/questions/43070062/using-fold-expressions-to-print-all-variadic-arguments-with-newlines-inbetween
#if 0
template<typename ...Args> 
void print(Args ...args) {
	((std::cout << args << '\t'), ...) << "\n";
	//(std::cout  << ... << std::forward<Args>(args)) << "\n" ;
}
#else 
#endif
template<typename ... Args>
void print(Args ... args)
{
	([](const auto& x) { std::cout << x << "\t"; }(args), ...) ;
	std::cout << "\n";
}
#endif

template <typename... Args>
auto sum(Args... args){
	return (... + args);
}

int main() {
	print("Li");           //���õ���print(T t)
	print(2, "Li");          //���õ���print(T t, Rest...rest)
	print(2, "Li", 80.5);      //���õ���print(T t, Rest...rest)
	std::cout << sum(1, 2) << "\n";
	std::cout << sum(1, 2, 3, 4, 5) << "\n";
	std::vector x{ 2., 4.3, 8. };
//	std::vector y{ 2, 4.3, 8. };

	std::tuple t(1, 2, 3);              // �Զ��ƶ�3��ֵ�����Ͷ���int
	std::tuple<int, int, int> t2(1, 2, 3); //ָ��3��ֵ�����Ͷ���int
	std::tuple t3(1, 2., 3.f); // �Զ��ƶ�3��ֵ�����Ͷ���int��double��float
	std::cout<<typeid(std::get<0>(t3)).name()<<"\n";
	std::cout << typeid(std::get<1>(t3)).name() << "\n";
	std::cout << typeid(std::get<2>(t3)).name() << "\n";

}
#endif






