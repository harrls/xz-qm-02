/*#include"function.h"

void init() {

	//该段代码功能是隐藏光标，调用了win32编程接口，不需要掌握
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title 推箱子1.0");//设定窗口名称
	system("mode con cols=120 lines=30");//设定窗口大小
}
void mainloop() {
	int level;//当前关卡
	int level_option;//选择的关卡
	int scenes;//场景
	char option;//操作指令
	int isEnd;//是否结束

	//初始化参数
	level = 0;//初始化当前关卡为第一关（从0算起，范围为0-maps_num）
	level_option = 1;//初始化选择关卡为第一关（从1算起）
	scenes = 0;//初始化场景为主界面
	isEnd = 0;//初始化结束判断变量为0（false）

	//绘制界面
	//主界面
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t 推箱子",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    开始(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   退出(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//主菜单2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t 推箱子\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   从头开始(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    选关(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    返回(R)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};
*/



#include"function.h"

void init() {

	//该段代码功能是隐藏光标，调用了win32编程接口，不需要掌握
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title 推箱子1.0");//设定窗口名称
	system("mode con cols=120 lines=30");//设定窗口大小
}

void mainloop() {

	//init

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	//主界面
	char main_interface[50][50] = {
		"\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t 推箱子",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    开始(S)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   退出(ESC)   |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|",
	};

	//主菜单2
	char menu2[50][50] = {
		"\n\n\n\n\n\n\n\n",
		"\t\t\t\t\t\t\t 推箱子\n",
		"\t\t\t\t\t\t   |===============|",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |   从头开始(A) |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    选关(X)    |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |    返回(ESC)  |",
		"\t\t\t\t\t\t   |               |",
		"\t\t\t\t\t\t   |===============|"
	};


	while (1)
	{

		//render
		system("cls");//清空屏幕
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 11; i++)
				puts(main_interface[i]);
			break;
		case 1:
			for (int i = 0; i < 11; i++)
				puts(menu2[i]);
			break;
		default:
			break;
		}


		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'S':
			case 's':
				scenes = 1;
				break;
			case 27:

				isEnd = 1;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (key)
			{
			case 'A':
			case 'a':
				gameloop(1);
				break;
			case 27:
				scenes = 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


		//update
		switch (scenes)
		{
		case 0:

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	}


	//clear

}


int gameloop(int level) {

	int x = 6;
	int y = 5;

	int aim_count = 4;
	int aimx[20] = {5,8,3,6};
	int aimy[20] = {2,4,5,7};

	//init

	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	char maps[2][50][50] = { {
		"|==========|",
		"|== ### ===|",
		"|== #X# ===|",
		"|== # #### |",
		"| ###O OX# |",
		"| #X O@### |",
		"| ####O#== |",
		"|=== #X#== |",
		"|=== ###== |",
		"|==========|"
	},{
		"|=========|",
		"|#####====|",
		"|#@  #====|",
		"|# OO#=###|",
		"|# O #=#X#|",
		"|### ###X#|",
		"|=##    X#|",
		"|=#   #  #|",
		"|=#   ####|",
		"|=#####===|",
		"|=========|"
	} };

	char map[50][50];

	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			map[i][j] = maps[0][i][j];

	while (1)
	{

		//render
		system("cls");//清空屏幕
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 10; i++)
				puts(map[i]);
			break;
		case 1:
			printf("good game!\n是否要进行下一关？\n\t是");
			printf("");
			break;
		default:
			break;
		}

		system("cls");//清空屏幕
		switch (scenes)
		{
		case 0:
			for (int i = 0; i < 10; i++)
				puts(map[i]);
			break;
		case 1:
			printf("good game!");
			break;
		default:
			break;
		}

		//event
		key = getch();

		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'W':
			case 'w':
				switch (map[y - 1][x])
				{
				case ' ':
				case 'X':
					map[y - 1][x] = '@';
					map[y][x] = ' ';
					y = y - 1;
					break;
				case 'O':
				case 'Q':
					if (map[y - 2][x] != '#'&&map[y - 2][x] != 'O'&&map[y - 2][x] != 'Q') {
						if(map[y - 2][x] == 'X')
							map[y - 2][x] = 'Q';
						else
							map[y - 2][x] = 'O';
						map[y - 1][x] = '@';
						map[y][x] = ' ';
						y = y - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'S':
			case 's':

				switch (map[y + 1][x])
				{
				case ' ':
				case 'X':
					map[y + 1][x] = '@';
					map[y][x] = ' ';
					y = y + 1;
					break;
				case 'O':
				case 'Q':
					if (map[y + 2][x] != '#'&&map[y + 2][x] != 'O'&&map[y + 2][x] != 'Q') {
						if (map[y + 2][x] == 'X')
							map[y + 2][x] = 'Q';
						else
							map[y + 2][x] = 'O';

						map[y + 1][x] = '@';
						map[y][x] = ' ';
						y = y + 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'A':
			case 'a':
				switch (map[y][x - 1])
				{
				case ' ':
				case 'X':
					map[y][x - 1] = '@';
					map[y][x] = ' ';
					x = x - 1;
					break;
				case 'O':
				case 'Q':
					if (map[y][x - 2] != '#'&&map[y][x - 2] != 'O'&&map[y][x - 2] != 'Q') {
						if (map[y][x-2] == 'X')
							map[y][x-2] = 'Q';
						else
							map[y][x-2] = 'O';
						map[y][x - 1] = '@';
						map[y][x] = ' ';
						x = x - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'D':
			case 'd':
				switch (map[y][x + 1])
				{
				case ' ':
				case 'X':
					map[y][x + 1] = '@';
					map[y][x] = ' ';
					x = x + 1;
					break;
				case 'O':
				case 'Q':
					if (map[y][x + 2] != '#'&&map[y][x + 2] != 'O'&&map[y][x + 2] != 'Q') {
						if (map[y][x + 2] == 'X')
							map[y][x + 2] = 'Q';
						else
							map[y][x + 2] = 'O';
						map[y][x + 1] = '@';
						map[y][x] = ' ';
						x = x + 1;
					}
					break;
				default:
					break;
				}
				break;
			case 27:

				isEnd = 1;
				break;
			default:
				break;
			}
			break;
		case 1:
			switch (key)
			{
			case 'R':
			case'r':
				x = 6;
				y = 5;
				scenes = 0;

				for (int i = 0; i < 50; i++)
					for (int j = 0; j < 50; j++)
						map[i][j] = maps[0][i][j];

				break;
			case 'N':
			case 'n':
				x = 2;
				y = 2;
				scenes = 0;
				aim_count = 3;
				aimx[0]=8;
				aimy[0]=4;
				aimx[1] = 8;
				aimy[1] = 5;
				aimx[2] = 8;
				aimy[2] = 6;
				for (int i = 0; i < 50; i++)
					for (int j = 0; j < 50; j++)
						map[i][j] = maps[1][i][j];

				break;

			case 27:
				isEnd=1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


		//update
		int isOver = 1;
		switch (scenes)
		{
		case 0:


			for (int i = 0; i < aim_count; i++) {
				if (map[aimy[i]][aimx[i]] != 'O'&&map[aimy[i]][aimx[i]] != 'Q')
					isOver = 0;
			}
			if (isOver)
				scenes = 1;

			for (int i = 0; i < aim_count; i++) {
				if (map[aimy[i]][aimx[i]] == ' ')
					map[aimy[i]][aimx[i]] = 'X';
			}

			break;
		case 1:

			break;
		default:
			break;
		}

		//delay

		//isend
		if (isEnd)
			break;
	}


	//clear


	
}
/*
//接收外部文件（C语言的结构体）
struct Map* LoadMap(int level) {

	struct Map temp;
	char buff[256];

	FILE *fp;
	sprintf(buffer, "data/Map/%d.txt", level);
	fp = fopen(buffer, "r");


	for (int;;) {

	}

}
*/

//我的
/*
char maps[2][50][50] = { {
"|==========|",
"|== ### ===|",
"|== #X# ===|",
"|== # #### |",
"| ###O OX# |",
"| #X O@### |",
"| ####O#== |",
"|=== #X#== |",
"|=== ###== |",
"||=========|"
}
{
"|==========|",
"|== ### ===|",
"|== #X# ===|",
"|== # #### |",
"| ###O OX# |",
"| #X O@### |",
"| ####O#== |",
"|=== #X#== |",
"|=== ###== |",
"|==========|"
}
//event
key - getch();




//方向移动
switch (sense) {
	case'W':
	case'w':
		if (map[y - 1][x] == ' ') {
			map[y - 1][x] = '@';
			map[y][x] = ' ';
			y = y - 1;
		}
		break;
	case'S':
	case's':
		if (map[y + 1][x] == ' ') {
			map[y + 1][x] = '@';
			map[y][x] = ' ';
			y = y + 1;
		
}

	...

//推动箱子的方向

switch (map[y - 1][x]) {
case' ':
	map[y - 1][x] = '@';
	map[y][x] = ' ';
	y = y - 1;
	break;
case'0':
	if (map[y - 2][x] != '#'&&map[y - 2][x] != '0') {
		map[y - 2][x] = '0';
		map[y - 1][x] = '@';
		map[y][x] = ' ';
		y = y - 1;
	}
	break;
default:
	break;
}


//判断过关条件
	int aimx[] = { 5,8,4,6 };
	int aimy[] = { 2,4,5,7 };



	*/
