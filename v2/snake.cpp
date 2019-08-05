#include <iostream>
using Color = unsigned char;     //���ַ���ʾ��ɫ

class Window {
	int width{ 60 }, height{ 50 }; //����
	Color bg_color{ ' ' };     //������ɫ�ÿո��ַ���ʾ
	Color *frame_buffer{ nullptr }; //֡���棬��ɫͼ�����ʾ���ڴ�
public:
	Window(int w, int h, Color bgColor) //����һ�����ڶ���
		:width{ w }, height{ h }, bg_color{ bgColor },
		frame_buffer{ new Color[w*h] }{	}
	~Window() {
		delete[] frame_buffer;       //ɾ����̬�ڴ�
	}
	//����һ��(x,y)�������أ�����������һ����ɫColor
	void set_pixel(int x, int y, Color color) {
		auto k = y * width + x;
		frame_buffer[k] = color;
	}

	//��ѯ(x,y)�����ص���ɫ
	Color get_pixel(const int x, const int y) const {
		auto k = y * width + x;
		return frame_buffer[k];
	}

	//---------��մ���--------
	void clear() {
		if (!frame_buffer) return;
		auto n = width * height;
		for (auto i = 0; i != n; i++)
			frame_buffer[i] = bg_color; //���ø�����Ϊ������ɫ
	}

	//--------��ʾ���ڵ�����
	void show() {
		for (auto y = 0, k = 0; y < height; y++) {
			for (auto x = 0; x < width; x++, k++)
				std::cout << frame_buffer[k];
			std::cout << '\n';
		}
	}

	int get_width() { return width; }
	int get_height() { return height; }
	Color get_bg_color() { return bg_color; }
};

class BackGround {
	Color top_boundary_color{ ' ' }, bottom_boundary_color{ '_' };
	Color left_right_boundary_color{ '|' };
public:
	void draw(Window &window) {
		auto right{ window.get_width() - 1 };
		auto bottom{ window.get_height() - 1 };
		for (auto x = 0; x < window.get_width(); x++) {
			window.set_pixel(x, 0, top_boundary_color);
			window.set_pixel(x, bottom, bottom_boundary_color);
		}

		for (auto y = 0; y < window.get_height(); y++) {
			window.set_pixel(0, y, left_right_boundary_color);
			window.set_pixel(right, y, left_right_boundary_color);
		}
	}
};

class Egg {
	int x, y;      //����λ��
	int size{ 1 };  //������С
	Color color;  //������ɫ
public:
	Egg(int x, int y, Color color ='G', int s = 1) :x{ x }, y{ y },
		size{ s }, color(color){}
	void draw(Window& window) {  //��canvas��ʾ�Ļ����ϻ��Ƽ�����״
		window.set_pixel(x, y, color);
	}
	Color get_color() { return color; }
};
//��ʾһ��λ��
class Position {
	int x{ 0 }, y{ 0 };
public:
	Position(int x = 0, int y = 0) :x{ x }, y{ y }{}
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	auto get_x() { return x; }
	auto get_y() { return y; }
};
//һ�������������ڴ��еĽ���ʾ
class SnakeNode {
	Position pos{};                      //��������λ��
	SnakeNode* next{ nullptr };            //��һ���������ؽ���ָ��
public:
	SnakeNode(const Position pos, SnakeNode* n = nullptr)
		:pos{ pos }, next{ n }{}
	Position get_pos() { return pos; }
	SnakeNode* get_next() { return next; }   //���ظý���nextֵ����ָ����һ������ָ��
	void set_next(SnakeNode* n) { next = n; } //�޸�nextֵ
};

class Snake {
	//������2�����ָ������ֱ�ָ�������ͷ����β��㡣
	SnakeNode *head{ nullptr }, *tail{ nullptr };
	int direction{};               //��ǰ������
	Color body_color, head_color;
	bool is_dead{ false };                  //���Ƿ�����
	int width{ 0 }, height{ 0 };
	bool eating{ false };
public:
	//��ʼ�����ڷ�Χ[width��height]��ָ�����ȵ�һ����
	Snake(const int width, const int height, int length = 3,
		Color body_color = 'o', Color head_color = '@');
	
	void draw(Window& window);              //�ڻ���canvas�ϻ����Լ���״

	//�ظ�������ǰ����ǰ����������Ҫ����Ƿ�������ײ	
	void move();
	void eat(bool eating);      //����һ������
	void set_direction(int d) {           //�����ߵ��˶�����
		if(d== 0 && direction == 1 ||
			d == 1 && direction == 0 ||
			d == 2 && direction == 3 ||
			d == 3 && direction == 3) return;
		direction = d; 
	} 

	SnakeNode *get_head() { return head; } //���������ͷ���
	SnakeNode *get_tail() { return tail; } //���������β���
	Color get_body_color() { return body_color; }
	Color get_head_color() { return head_color; }
	void print() {
		std::cout << direction << "\n";
		SnakeNode *p = head->get_next();
		while (p != tail) {                          //����ÿ��������
			std::cout<<p->get_pos().get_x()<<" "<<
				p->get_pos().get_y()<<std::endl;  //�ڻ�������������������ؽ�����ɫ
			p = p->get_next();                    //ָ��p����ƶ���ָ����һ�����
		}
		std::cout << "\n\n";
	}
};

#include <cstdlib>
#include <ctime>
inline int random_int(const int x_min, const int x_max) {
	static bool is_seeded = false;
	if (!is_seeded) {
		srand((unsigned)time(0));  //�������������
		is_seeded = true;
	}
	return rand() % (x_max - x_min) + x_min;
}


Snake::Snake(const int width, const int height, int length,
	Color body_color, Color head_color) {
	this->width = width;
	this->height = height;
	this->body_color = body_color;
	this->head_color = head_color;

	//����������ߵ�λ��
	auto x_min{ length + 1 }, x_max{ width - x_min },
		y_min{ length + 1 }, y_max{ height - y_min };
	auto x = random_int(x_min, x_max);
	auto y = random_int(y_min, y_max);

	SnakeNode *p = new SnakeNode(Position(x, y)); //������ͷ���
	tail = p;                                     //�ý���������β��㣨���Ľ�㣩
	head = new SnakeNode(Position(), p);         //�������������ͷ���
	direction = random_int(0, 4);                //���������0,1,2,3	
 	for (auto i = 1; i != length; i++) {         //����������������
		if (direction == 0) y++;          //��ͷ���ϣ���������
		else if (direction == 1) y--;     //��ͷ����
		else if (direction == 2) x++;     //��ͷ������������
		else x--;                         //��ͷ����
		p = new SnakeNode(Position(x, y), head->get_next());
		head->set_next(p);
	}
}

void Snake::draw(Window& window){
	SnakeNode *p = head->get_next();
	while (p != tail) {                          //����ÿ��������
		window.set_pixel(p->get_pos().get_x(),
			p->get_pos().get_y(), body_color);  //�ڻ�������������������ؽ�����ɫ
		p = p->get_next();                    //ָ��p����ƶ���ָ����һ�����
	}
	window.set_pixel(p->get_pos().get_x(),        //�ڻ����ϻ�����ͷ���
		p->get_pos().get_y(), head_color);
}


void Snake::eat(bool eating) {	
	this->eating = eating;
}

void Snake::move() {
	auto head_pos = tail->get_pos();             //��ǰ��ͷλ�ã�ע�⣺����β����ʾ��ͷ
	//����ǰ������ȷ���µ���ͷλ�ã�
	auto x{ head_pos.get_x() }, y{ head_pos.get_y() };
	if (direction == 0)                      //�����ƶ���y--
		--y;	
	else if (direction == 1)                 //�����ƶ���y++
		++y;	
	else if (direction == 2)                //���-->�����ƶ���y--
		--x;	
	else                                //�Ҽ�-->�����ƶ���
		++x;
	
	//�����µ���ͷ�����뵽�����β����
	SnakeNode *p = new SnakeNode(Position( x,y));    //�����µĽ��
	tail->set_next(p);      //p�ӵ�β���(tail)�ĺ��棬����ͷ���ĺ���
	tail = p;             // p��Ϊ�µ�����β��㡣��p��Ϊ������ͷ���
	//���û�гԼ�������ɾ����β���
	if (!eating) {
		//ɾ��������β�������׽�㣨ͷ������Ǹ���㣩
		p = head->get_next();            //pָ���׽��
		head->set_next(p->get_next());    //p��next����Ϊhead�ĺ�һ�����
		delete p;                       //�ͷ�p���ռ�õ��ڴ�
	}
	//����������һ������������ɾ����β��㡣��Ӧ��ճԵ���־
	else eating = false;  //�����Ѿ�����
}

#include <windows.h>
inline void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
inline void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


class GameEngine {
	Window *window{ nullptr };
	bool running{true};    //��Ϸ�Ƿ��������еı�־
	bool start{ false };   //��Ϸ�Ƿ�ʼ
	BackGround bg;
	Snake *snake{ nullptr };
	Egg *egg{ nullptr };
public:
	GameEngine(const int w = 50, const int h = 40) {
		window = new Window(w, h, ' ');
		//����Snake����	
		snake = new Snake(w, h, 4);		//����һ��λ���������Snake����
		//�������λ�õ�Egg����
		auto x = random_int(2, w - 10);
		auto y = random_int(2, h - 10);
		egg = new Egg(x, y);
	}
	~GameEngine() {
		delete window; delete snake;delete egg;
	}
	//��
	void render() {
		gotoxy(0, 0);
		hideCursor();
		window->clear();
		draw_scene();
		window->show();		
	}
	void draw_scene() {
		bg.draw(*window);
		if(snake)snake->draw(*window);        //���߻����Լ�
		if (egg)	egg->draw(*window);  //�ü��������Լ�
	}
	
	void run() {	
		while (running) {
			collosion();
			processEvent();
			update();			
			render();
		}
		quit();
	}

	void processEvent() {//  �����¼�
		//  �����¼�
		char key;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) running = false;
			else if (key == ' ') start = !start;
			else {
				start = true;
				if (key == KEY_UP)
					snake->set_direction(0);
				else if (key == KEY_DOWN)
					snake->set_direction(1);
				else if (key == KEY_LEFT)
					snake->set_direction(2);
				else if (key == KEY_RIGHT)
					snake->set_direction(3);
			}
		}
	}
	void update() { if(start) snake->move(); }
	void collosion() {
		if (!start) return;
		auto tail = snake->get_tail();
		auto pos = tail->get_pos();//��ͷλ��
		auto x{ pos.get_x() }, y{ pos.get_y() };

		if (x == 0 || y == 0 || x == window->get_width() - 1
			|| y == window->get_height() - 1) {
			running = false; //�������ڣ�������,��Ϸ����
			return;
		}		

		Color color = window->get_pixel(x, y);       //�õ���λ�õ���ɫ
		if (color == window->get_bg_color()) return;  //δ������ײ

	
		if (color != snake->get_head_color()) {
			if (egg&&color == egg->get_color()) {      //�����˼���
				snake->eat(true);
				delete egg;  egg = nullptr;  //���ټ���				
				auto x = random_int(2, window->get_width() - 10);
				auto y = random_int(2, window->get_height() - 10);
				egg = new Egg(x, y);
				
			}
			else {//��ǽ����������ײ,��Ϸ����
				running = false;//��ǽ����������ײ,��Ϸ����
				return;
			}
		}		
	}
	void quit() {}

};

#if 0
int main() {
	GameEngine game;
	game.run();
}
#endif