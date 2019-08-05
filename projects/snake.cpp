#include <iostream>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


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


using Color = unsigned char;

class Canvas {
	int width{60},height{50 }; //����
	Color bg_color{ ' ' };
	Color *frame_buffer{ nullptr }; //֡���棬��ɫͼ�����ʾ���ڴ�
public:
	Canvas(int w, int h, Color bgColor) 
		:width{ w }, height{ h }, bg_color{ bgColor },
		frame_buffer{ new Color[w*h] }{}
	

	//����һ��(x,y)�������أ�����������һ����ɫColor
	void set_pixel(int x, int y,Color color) {
		auto k = y * width + x;
		frame_buffer[k] = color;
	}

	//��ѯ(x,y)�����ص���ɫ
	Color get_pixel(const int x, const int y) const{
		auto k = y * width + x;
		return frame_buffer[k];
	}

	//---------��ջ���--------
	void clear() {
		if (!frame_buffer) return;
		auto n = width * height;
		for (auto i = 0; i != n; i++)
			frame_buffer[i] = bg_color;
	}

	//--------��ʾ����canvas�е�����
	void show() {
		for (auto y = 0,k=0; y < height; y++) {
			for (auto x = 0; x < width; x++,k++)
				std::cout << frame_buffer[k];
			std::cout << '\n';
		}
	}

	int get_width() { return width; }
	int get_height() { return height; }
	Color get_bg_color() { return bg_color; }
};

class Egg {	
	int x, y;
	int size{ 1 };
	Color color;
public:
	Egg(int x, int y, Color color='G', int s = 1) :x{x}, y{y},
		size{s}, color(color){}
	void draw(Canvas& canvas) {
		canvas.set_pixel(x, y,color);
	}
	Color get_color() { return color; }
};

//��ʾһ��λ��
class Position {
	int x{ 0 }, y{ 0 };
public:
	Position(int x=0, int y=0) :x{ x }, y{ y }{}
	void set_x(int x) { this->x = x; }
	void set_y(int y) { this->y = y; }
	auto get_x() { return x; }
	auto get_y() { return y; }
};
//һ�������������ڴ��еĽ���ʾ
class SnakeNode{
	Position pos{};
	SnakeNode* next{nullptr};
public:
	SnakeNode(const Position pos, SnakeNode* n = nullptr)
		:pos{pos}, next{ n }{}
	Position get_pos() { return pos; }
	SnakeNode* get_next() { return next; }
	void set_next(SnakeNode* n) { next = n; }
};


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Snake {
	//������2�����ָ������ֱ�ָ�������ͷ����β��㡣
	SnakeNode *head{nullptr}, *tail{ nullptr };
	unsigned int direction{}; //������
	Color body_color, head_color;
	bool is_dead{ false }; //���Ƿ�����
	int width{ 0 }, height{ 0 };
	bool moving{ false };
public:
	bool is_moving() { return moving; }
	//��ʼ�����ڷ�Χ[width��height]��ָ�����ȵ�һ����
	Snake(const int width,const int height,int length = 3,
		Color body_color = 'o', Color head_color = '@');

	//�ظ�������ǰ����ǰ����������Ҫ����Ƿ�������ײ
	void move(unsigned int direct);
	void update(bool to_eat=false);     //
	void draw(Canvas& canvas);	

	SnakeNode *get_head() { return head; } //���������ͷ���
	SnakeNode *get_tail() { return tail; } //���������ͷ���
	Color get_body_color() { return body_color; }
	Color get_head_color() { return head_color; }
	

	void print();
};

Snake::Snake(const int width, const int height, int length ,
	Color body_color, Color head_color ) {
	this->width = width;
	this->height = height;
	this->body_color = body_color;
	this->head_color = head_color;

	//����������ߵ�λ��
	auto x_min{ length + 1 }, x_max{ width - x_min },
		y_min{ length + 1 }, y_max{ height - y_min };
	auto x = random_int(x_min, x_max);
	auto y = random_int(y_min, y_max);

	SnakeNode *p = new SnakeNode(Position(x, y));//������β���
	tail = p; //�ý���������β��㣨���Ľ�㣩
	head = new SnakeNode(Position(), p); //�������������ͷ���
	auto d = random_int(0, 4);//���������0,1,2,3	
	for (auto i = 1; i != length; i++) {
		if (d == 0) x++;
		else if (d == 1) x--;
		else if (d == 2) y++;
		else y--;
		p = new SnakeNode(Position(x, y), head->get_next());
		head->set_next(p);
	}
	if (d == 0) direction = KEY_LEFT; 
	else if (d == 1) direction = KEY_RIGHT;
	else if (d == 2) direction = KEY_UP;
	else  direction = KEY_DOWN; 
}



void Snake::draw(Canvas& canvas) {
	SnakeNode *p = head->get_next();	
	while (p!=tail) {
		canvas.set_pixel(p->get_pos().get_x(),
			p->get_pos().get_y(), body_color);
		p = p->get_next(); //ָ��p����ƶ�
	}
	canvas.set_pixel(p->get_pos().get_x(),
		p->get_pos().get_y(), head_color);
}



void Snake::move(unsigned int direct) {
	//���������������ҷ����˶�������ĸ��ʾ��ͬ����
	//ע�⣺����β����ʾ��ͷ
	auto head_pos = tail->get_pos();
	auto x{head_pos.get_x()}, y{ head_pos.get_y()};	

	

	if (direct == KEY_UP) {//�����ƶ���y--
		if (y == 1)			return; //���ﶥ���˲����ƶ�
		if(this->direction== KEY_DOWN) return;
		--y;
	}
	else if (direct == KEY_DOWN) {//�����ƶ���y++
		if (y == height-1)			return; //����ײ��˲����ƶ�
		if (this->direction == KEY_UP) return;
		++y;
	}
	else if (direct == KEY_LEFT) {//���-->�����ƶ���y--
		if (x == 1)			return; //��������߲����ƶ�
		if (this->direction == KEY_RIGHT) return;
		--x;
	}
	else if (direct == KEY_RIGHT) {//�Ҽ�-->�����ƶ���y++
		if (x == width-1)			return; //�������ұ߲����ƶ�
		if (this->direction == KEY_LEFT) return;
		++x;
	}
	else return;
	this->direction = direct;

	//����Ƿ�����ײ��


	//�����µ���ͷ�����뵽�����β����
	SnakeNode *p = new SnakeNode(Position( x,y));//������β���
	tail->set_next(p);
	tail = p; //����ͷ���p��Ϊ�µ�����β���

	moving = true;//��ʾ�����ƶ�
}
void Snake::update(bool to_eat) {
	//���û�гԼ�������ɾ����β���
	if (!to_eat) {
		//ɾ��������β�������׽�㣨ͷ������Ǹ���㣩
		SnakeNode *p = head->get_next(); //pָ���׽��
		head->set_next(p->get_next()); //p��next����Ϊhead�ĺ�һ�����
		delete p; //�ͷ�p��������ڴ�
	}
	//����������һ������������ɾ����β��㡣
	moving = false;
}

void Snake::print() {
	auto p = head->get_next();
	while (p) {
		auto pos = p->get_pos();
		std::cout << pos.get_x() << ',' << pos.get_y() << '\t';
		p = p->get_next();
	}
	std::cout << std::endl;
	int a = 0;
	std::cin >> a;
}

class BackGround {
	Color top_boundary_color{' '}, bottom_boundary_color{ '_' };
	Color left_right_boundary_color{ '|' };
public:
	void draw(Canvas &canvas) {
		auto right{ canvas.get_width() - 1 };
		auto bottom{ canvas.get_height() - 1 };
		for (auto x = 0; x < canvas.get_width(); x++) {
			canvas.set_pixel(x,0, top_boundary_color);
			canvas.set_pixel(x, bottom, bottom_boundary_color);
		}

		for (auto y = 0; y < canvas.get_height(); y++) {
			canvas.set_pixel(0, y, left_right_boundary_color);
			canvas.set_pixel(right, y,  left_right_boundary_color);
		}		
	}
};

class GameEngine {
	Canvas *canvas{nullptr};
	Snake *snake{ nullptr };
	Egg *egg{ nullptr };
	BackGround bg;
	bool running{ true };	
public:
	GameEngine(const int w=80,const int h=30) {
		canvas = new Canvas(w, h, ' ');
		canvas->clear();
		//����Snake����		
		snake = new Snake(w,h,4);
		//����Egg����
		auto x = random_int(2, w-2);
		auto y = random_int(2, h-2);
		egg = new Egg(x,y);
	}
	void run() {
		while (running) {
			processEvent();
			update();
			collosion();
			render();
		}
		quit();
	}

	void processEvent() {
		//  �����¼�
		char key;
		if (_kbhit()) {
			key = _getch();
			if (key == 27) running=false;
			snake->move(key);
		}
	}
	void update() {}	
	void collosion() {
		if (!snake->is_moving()) return;
		auto tail = snake->get_tail();
		auto pos = tail->get_pos();//��ͷλ��
		auto x{ pos.get_x() }, y{ pos.get_y() };

		//�Ƿ�ײǽ�ˣ�
		bool is_snake_dsead{ false };
		if(x==0||y==0||x== canvas->get_width()-1||y==canvas->get_height()-1)
			is_snake_dsead = true;
		if (is_snake_dsead) {
			running = false;//��Ϸ����
			return;
		}

		Color color= canvas->get_pixel(x, y);//�õ���λ�õ���ɫ
		if (color == canvas->get_bg_color()) return;

		bool to_eat{ false };
		if (egg&&color == egg->get_color())
			to_eat = true;
		else if(color != snake->get_head_color()) //��ǽ����������ײ
			is_snake_dsead = true;
		if (is_snake_dsead) {
			running = false;//��Ϸ����
			return;
		}
		snake->update(to_eat);//
		if (to_eat) {
			delete egg;  egg = nullptr;
			auto x = random_int(2, canvas->get_width() - 2);
			auto y = random_int(2, canvas->get_height() - 2);
			egg = new Egg(x, y);
		}
	}
	void render() {
		if (!running) return;
		gotoxy(0, 0);
		hideCursor();
		canvas->clear();
		draw_scene();
		canvas->show();
	}
	void draw_scene() {	
		bg.draw(*canvas);
		snake->draw(*canvas);
		if(egg)	egg->draw(*canvas);
	}
	void quit(){}
};


int main() {
	GameEngine game;
	game.run();
}