#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include "console.h" //ȭ������ ���
#include "cal_damage.h" //������ ���� ó�����
#include "character.h" //ĳ����, ���� ����â
#include "status.h" //��ü ����â
#include "card.h"

void DrawBox(int width, int height) //120,30 ���� ȭ�� üũ�� �Լ�
{
    int i, j;

    // Top border
    printf("��");
    for (i = 1; i < width - 1; i++)
    {
        printf("��");
    }
    printf("��\n");

    // Middle rows
    for (i = 0; i < height - 2; i++)
    {
        printf("��");
        for (j = 1; j < width - 1; j++)
        {
            printf(" ");
        }
        printf("��\n");
    }

    // Bottom border
    printf("��");
    for (i = 1; i < width - 1; i++)
    {
        printf("��");
    }
    printf("��\n");
}



int main() {
	//SetConsoleSize(120, 30);
    DrawBox(120, 30);
	system("pause");
	//return 0;
}