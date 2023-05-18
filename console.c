#include <windows.h>
#include <stdio.h>

void Clear(void)
{
	system("cls");
}

void GotoXY(int _x, int _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetTitle(char* _szConsoleName)
{
	SetConsoleTitle(_szConsoleName);
}

void SetColor(unsigned char _BgColor, unsigned char _TextColor)
{
	if (_BgColor > 15 || _TextColor > 15) return;

	unsigned short ColorNum = (_BgColor << 4) | _TextColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
}

void SetCursorVisible(BOOL _bShow)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = _bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void SetConsoleSize(int _col, int _lines)
{
	char setText[100];
	sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
	system(setText);
}
/*
/// 콘솔 세팅
void SetConsole()
{
	// 콘솔 사이즈 조절 및 타이틀 설정
	system("mode con: cols=150 lines=30 | title Catching Moles");

	// 커서 사이즈 조절 및 숨기기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

	//마우스 입력 무시
	HANDLE consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(consoleInputHandle, ENABLE_EXTENDED_FLAGS);

	// 콘솔 창 크기 변경 방지 (마우스로 조절 불가능)
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_SIZEBOX);

	// 전체화면 기능 방지
	LONG_PTR style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
}

*/
