/* ----------hwdong�Ľ�ѧ��Դ---------------
   ��ѧ���ͣ�https://hwdong.net
   youtubeƵ���� hwdong
   twitter�� hwdong
   Bվ��΢����hw-dong
   qqȺ��101132160
   ΢�Ź��ںţ�hwdong���
   C++17�����ŵ���ͨ��Դ���룩��https://github.com/hwdong-net/cplusplus17
*/

#include <iostream>
#include "Vector.h"
#include <string>

#if 0
#include <random>

template<typename T>
T random_real(const T lower_bound = 0., const T upper_bound = 1.) {
	std::uniform_real_distribution<T> unif(lower_bound, upper_bound);
	static std::default_random_engine re;
	return unif(re);
}
int random_int(const int lower_bound = 1, const int upper_bound = 52) {
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(lower_bound, upper_bound);
	return dis(gen);
}


template<typename T>
class QT {
public:
	std::string action_name;   //������
	T Q_value;              //Q(s,a����ֵ
	int next_state;           //ת�Ƶ���״̬
	T reward;              //ֱ�ӻر�
	QT(std::string a = " ", const int ns = 0, T r = 0, T qvalue = 0) :
		action_name{ a }, reward{ r }, next_state{ ns }, Q_value{ qvalue } {}
};


template<typename T>
class QLearning {
	using State_QT_Table = Vector < QT<T>>;     //һ��״̬��QT������
	using QT_Table = Vector<State_QT_Table>;    //����״̬��QT������
	QT_Table QT_table;                        //����״̬��QT��
public:
	QLearning();
	QLearning(const Vector<Vector<int>> &maze);

	void Q_Learning(const int MAX_EPISODES = 15,
		const T EPSILON = 0.2, const T ALPHA = 0.1, const T GAMMA = 0.9);

	int random_start_state(); //���ѡ�����״̬
	//ѡ��һ������
	int choose_action(const int state, T EPSILON = 0.1);
	//�ӵ�ǰ״̬state�Ͷ���action����û����ķ�����
	//����һ��״̬next_state��ֱ�ӽ���reward��next_state�Ƿ���ֹ״̬)
	bool get_env_feedback(const int state, const int action,
		int &next_state, T &reward);
	T max_Qvalue(const int s, int& action); //״̬�µ����Qvalue����Ӧ��action

	bool is_terminal(const int state);
	void print(); //��ӡQT_table
	void print_Q();//ֻ��ӡQ��
	Vector<int> shortest_path(const int state);
};
template<typename T>
QLearning<T>::QLearning() {
	State_QT_Table s_QT_table;
	s_QT_table.push_back({ "s", 5, -1 });
	s_QT_table.push_back({ "e",1,0 });
	QT_table.push_back(s_QT_table);       //״̬0

	s_QT_table.clear();
	s_QT_table.push_back({ "w", 0, 0 });
	s_QT_table.push_back({ "e",2,0 });
	QT_table.push_back(s_QT_table);       //״̬1
	s_QT_table.clear();
	s_QT_table.push_back({ "s", 6, 1 });
	s_QT_table.push_back({ "w",1,0 });
	s_QT_table.push_back({ "e",3,0 });
	QT_table.push_back(s_QT_table);       //״̬2
	s_QT_table.clear();
	s_QT_table.push_back({ "w", 2, 0 });
	s_QT_table.push_back({ "e",4,0 });
	QT_table.push_back(s_QT_table);       //״̬3
	s_QT_table.clear();
	s_QT_table.push_back({ "w", 3, 0 });
	s_QT_table.push_back({ "s",7,-1 });
	QT_table.push_back(s_QT_table);       //״̬3
	s_QT_table.clear();
	QT_table.push_back(s_QT_table);       //״̬5����ֹ״̬���յ�QT��
	QT_table.push_back(s_QT_table);      //״̬6����ֹ״̬���յ�QT��
	QT_table.push_back(s_QT_table);      //״̬7����ֹ״̬���յ�QT��
}

//�ж�һ��״̬state�Ƿ�����ֹ״̬
template<typename T>
bool  QLearning<T>::is_terminal(const int state) {
	return QT_table[state].size() == 0;
}

template<typename T>
void QLearning<T>::Q_Learning(const int MAX_EPISODES,
	const T EPSILON, const T ALPHA, const T GAMMA) {
	//   ѭ���Ļغ���
	for (auto episode = 0; episode != MAX_EPISODES; episode++) {
		auto step_counter{ 0 };
		auto s = random_start_state(); //ѡ���������״̬
		std::cout << "step: " << episode << " start State: " << s << '\n';
		auto is_terminated{ false };
		print_Q();

		//update_env(S, episode, step_counter)
		while (!is_terminated) { //ѭ��ֱ��һ����Ϸ����
			auto action = choose_action(s, EPSILON);      // ����״̬ѡ����
			int s_next;
			T R;
			is_terminated = get_env_feedback(s, action, s_next, R);  // ��ȡ�����ķ���
			auto  q_predict = QT_table[s][action].Q_value;
			auto q_target = R; //���s_next�ǽ���״̬��
			if (!is_terminated) { // ���s_next���ǽ���״̬���͸���q_targetֵ
				T max_qvalue;
				auto  max_action{ 0 };
				max_qvalue = max_Qvalue(s_next, max_action);
				q_target = R + GAMMA * max_qvalue;
			}
			QT_table[s][action].Q_value += ALPHA * (q_target - q_predict);  //����Qֵ
			s = s_next;  //������һ״̬
		//	print_Q();				
		}
	}
	return;
}

template<typename T>
T QLearning<T>::max_Qvalue(const int s, int& action) {
	auto s_QT_table = QT_table[s];
	T max = s_QT_table[0].Q_value;
	action = 0;
	for (auto i = 1; i != s_QT_table.size(); i++) {
		if (s_QT_table[i].Q_value > max) {
			max = s_QT_table[i].Q_value;
			action = i;
		}
	}
	return max;
}
template<typename T>
int QLearning<T>::choose_action(const int state, T EPSILON) {
	T rnd{ random_real(0.,1.) };
	if (rnd < EPSILON)
		return  random_int(0, QT_table[state].size() - 1);
	else {
		auto  action{ 0 };
		max_Qvalue(state, action);
		return action;
	}
}

template<typename T>
int QLearning<T>::random_start_state() {
	int s{ 0 };
	do {
		s = random_int(0, QT_table.size() - 1);
	} while (is_terminal(s));
	return s;
}
template<typename T>
bool QLearning<T>::get_env_feedback(const int state, const int action
	, int &next_state, T &reward) {
	next_state = QT_table[state][action].next_state;
	reward = QT_table[state][action].reward;

	return is_terminal(next_state);
}


//2�������Ĵ�ӡ�����������QT�����Ϣ

#include <iomanip>      // std::setw
template<typename T>
void QLearning<T>::print_Q() {
	for (auto i = 0; i != QT_table.size(); i++) { //����ÿ��״̬
		if (QT_table[i].size() == 0)continue;
		std::cout << "state " << std::setw(3) << i << ":" << std::setw(3);
		for (auto j = 0; j != QT_table[i].size(); j++)  //���������״̬��QT��
			std::cout << "(" << QT_table[i][j].action_name << ","
			<< QT_table[i][j].Q_value << ")\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template<typename T>
void QLearning<T>::print() {
	for (auto i = 0; i != QT_table.size(); i++) {   //����ÿ��״̬
		if (QT_table[i].size() == 0)continue;
		std::cout << "state " << std::setw(3) << i << ":" << std::setw(3);
		for (auto j = 0; j != QT_table[i].size(); j++)  //���������״̬��QT��
			std::cout << "(" << QT_table[i][j].action_name << ","
			<< QT_table[i][j].next_state << ","
			<< QT_table[i][j].reward << "," << QT_table[i][j].Q_value << ")\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
Vector<int> QLearning<T>::shortest_path(const int state) {
	Vector<int> path;
	auto s{ state };
	while (!is_terminal(s)) {
		path.push_back(s);
		auto  action{ 0 };
		max_Qvalue(s, action);
		s = QT_table[s][action].next_state;
	}
	path.push_back(s);
	return path;
}



//�����main()�����Ի�����Ѱ������⣬��Q - Learning�㷨������С�״̬ - �������ļ�ֵ����Q(s, a)��
int main() {

#define ROBOT 

#ifdef ROBOT
	QLearning<double> ql;  //����һ��QLearningʵ���������
	

#else
	Vector<Vector<int>> maze{ {0, 0, 0, 0},
								 {0,-1, 0, 0},
							 {0,-1,-1, 0},
						 {0, 0, 0, 1} };

	QLearning<double> ql(maze);
	ql.print();
	
#endif 
	ql.print();

	std::cout << "�۲�QT�����û���⣬�������κ��ַ���ʼִ��Q_Learning�㷨\n";
	char ch;	
	std::cin >> ch;

#ifdef  ROBOT
	ql.Q_Learning();
#else
	ql.Q_Learning(100);   //�� Q-Learning�㷨���Q(s,a)ֵ
#endif

	//�����һ��״̬s����������ֹ״̬�����·��
	auto s{ 0 };
	auto path = ql.shortest_path(s);
	std::cout << "shortest_path from " << s << std::endl;
	for (auto i = 0; i != path.size(); i++)
		std::cout << path[i] << '\t';
	std::cout << std::endl;
}


template<typename T>
QLearning<T>::QLearning(const Vector<Vector<int>> &maze) {
	const auto m{ maze.size() }, n{ maze[0].size() };
	int s{ 0 };
	for (auto i = 0; i < m; i++) {
		for (auto j = 0; j < n; j++, s++) {    	            //״̬s��(i,j)λ��
			State_QT_Table s_QT_table;                 //s״̬��QT��
			if (maze[i][j] != 0) {                         //��ֹ״̬
				QT_table.push_back(s_QT_table); continue;
			}
			if (i >= 1) {     //�������˶�
				auto s_next = s - n;
				s_QT_table.push_back({ "U", s_next,
					static_cast<T>(maze[i - 1][j]) });
			}
			if (i < m - 1) {   //�������˶�
				auto s_next = s + n;
				s_QT_table.push_back({ "D", s_next,
					static_cast<T>(maze[i + 1][j]) });
			}
			if (j >= 1) {   //�������˶�
				auto s_next = s - 1;
				s_QT_table.push_back({ "L", s_next,
					static_cast<T>(maze[i][j - 1]) });
			}
			if (j < n - 1) {   //�������˶�
				auto s_next = s + 1;
				s_QT_table.push_back({ "R", s_next,
					static_cast<T>(maze[i][j + 1]) });
			}
			QT_table.push_back(s_QT_table);
		}
	}
}

#endif