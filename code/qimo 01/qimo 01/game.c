#include"function.h"

void init() {

	//该段代码功能是隐藏光标，调用了win32编程接口，不需要掌握
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title @");//设定窗口名称
	system("mode con cols=120 lines=30");//设定窗口大小
}

void mainloop() {

	//init

	char key = 0;

	int wide = 0;

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

	//变量
	//横纵坐标
	int x = 0;
	int y = 0;
	//按键
	char key = 0;
	//结束
	int isEnd = 0;
	//当前场景
	int scenes = 0;
	//地图宽度
	int wide = 0;

	char maps[50][50];

	Map *map;
	map = LoadMap(level);
	x = map->x;
	y = map->y;


	//游戏主体内容
	while (1)
	{

		//界面打印
		system("cls");//清空屏幕

		/********************
		*
		*没有实现关卡连续进行...
		*
		*
		******************/

		int i = 0; i < map->h; i++;

		if (i < map->h){
			
			switch (scenes)
			{
			case 0:
				for (int i = 0; i < map->h; i++)
					puts(map->map[i]);
				break;
			case 1:
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\tgood game!");
				printf("\n\n\n\n\n\n\n\t\t\t\t\t\t");
				system("pause");
				break;
			default:
				break;

			}
		}

		//游戏键盘按键接收
		key = getch();
		
		switch (scenes)
		{
		case 0:
			switch (key)
			{
			case 'W':
			case 'w':
				switch (map->map[y - 1][x])
				{
				case ' ':
				case 'X':
					map->map[y - 1][x] = '@';
					map->map[y][x] = ' ';
					y = y - 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y - 2][x] != '#'&&map->map[y - 2][x] != 'O'&&map->map[y - 2][x] != 'Q') {
						if (map->map[y - 2][x] == 'X')
							map->map[y - 2][x] = 'Q';
						else
							map->map[y - 2][x] = 'O';
						map->map[y - 1][x] = '@';
						map->map[y][x] = ' ';
						y = y - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'S':
			case 's':

				switch (map->map[y + 1][x])
				{
				case ' ':
				case 'X':
					map->map[y + 1][x] = '@';
					map->map[y][x] = ' ';
					y = y + 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y + 2][x] != '#'&&map->map[y + 2][x] != 'O'&&map->map[y + 2][x] != 'Q') {
						if (map->map[y + 2][x] == 'X')
							map->map[y + 2][x] = 'Q';
						else
							map->map[y + 2][x] = 'O';

						map->map[y + 1][x] = '@';
						map->map[y][x] = ' ';
						y = y + 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'A':
			case 'a':
				switch (map->map[y][x - 1])
				{
				case ' ':
				case 'X':
					map->map[y][x - 1] = '@';
					map->map[y][x] = ' ';
					x = x - 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y][x - 2] != '#'&&map->map[y][x - 2] != 'O'&&map->map[y][x - 2] != 'Q') {
						if (map->map[y][x - 2] == 'X')
							map->map[y][x - 2] = 'Q';
						else
							map->map[y][x - 2] = 'O';
						map->map[y][x - 1] = '@';
						map->map[y][x] = ' ';
						x = x - 1;
					}
					break;
				default:
					break;
				}

				break;
			case 'D':
			case 'd':
				switch (map->map[y][x + 1])
				{
				case ' ':
				case 'X':
					map->map[y][x + 1] = '@';
					map->map[y][x] = ' ';
					x = x + 1;
					break;
				case 'O':
				case 'Q':
					if (map->map[y][x + 2] != '#'&&map->map[y][x + 2] != 'O'&&map->map[y][x + 2] != 'Q') {
						if (map->map[y][x + 2] == 'X')
							map->map[y][x + 2] = 'Q';
						else
							map->map[y][x + 2] = 'O';
						map->map[y][x + 1] = '@';
						map->map[y][x] = ' ';
						x = x + 1;
					}
					break;

				default:
					break;
				}
				break;
			case 'R':
			case'r':
				scenes = 0;
				map = LoadMap(map->level);
				x = map->x;
				y = map->y;

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
				scenes = 0;
				map = LoadMap(map->level);
				x = map->x;
				y = map->y;

				break;
			case 'N':
			case 'n':
				scenes = 0;
				map = LoadMap(map->level + 1);
				x = map->x;
				y = map->y;
				break;

			case 27:
				isEnd = 1;
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


			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] != 'Q')
					isOver = 0;
			}
			if (isOver)
				scenes = 1;

			for (int i = 0; i < map->aim_count; i++) {
				if (map->map[map->aimy[i]][map->aimx[i]] == ' ')
					map->map[map->aimy[i]][map->aimx[i]] = 'X';
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

Map* LoadMap(int level) {

	Map *temp = (Map*)malloc(sizeof(Map));
	char buffer[256];

	FILE *fp;
	sprintf(buffer, "Map/%d.txt", level);//读取地图
	fp = fopen(buffer, "r");

	temp->level = level;
	temp->aim_count = 0;

	for (int i = 0;; i++) {//循环读取文件内容，直到达到退出条件
		fgets(temp->map[i], 256, fp);//读取一行字符串

		temp->map[i][strlen(temp->map[i]) - 1] = '\0';//在字符串末尾手动加上结束符'\0'

		for (int j = 0; temp->map[i][j] != '\0'; j++) {
			switch (temp->map[i][j]) {
			case '@':
				temp->x = j;
				temp->y = i;
				break;
			case 'X':
			case 'Q':
				temp->aimx[temp->aim_count] = j;
				temp->aimy[temp->aim_count] = i;

				temp->aim_count++;
				break;
			}

		}

		if (temp->map[i][1] == '|') {//当字符串第二位出现'|'时表示该行为最后一行，文件读取结束
			temp->map[i][1] = '=';//将该位字符设置为'='
			temp->h = i + 1;
			break;//跳出循环
		}
	}

	fclose(fp);
	return temp;
}