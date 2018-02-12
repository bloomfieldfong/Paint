#include "mouse.h"

int InitMouse(void){
	asm{
		MOV AX, 0;
		INT 33h;
	}
	return;
}

void ShowMousePtr(void){
	asm{
		MOV AX, 1h;
		INT 33h;
	}
}

void HideMousePtr(void){
	asm{
		MOV AX, 2h;
		INT 33h;
	}
}

void MoveMousePts(int x, int y){
	asm{
		MOV AX, 4h;
		MOV CX, x;
		MOV DX, y;
		INT 33h;
	}
}

void RestrictMousePtr(int x1, int y1, int x2, int y2){
	asm{
		MOV AX, 7h;
		MOV CX, x1;
		MOV DX, x2;
		INT 33h;
		MOV AX, 8h;
		MOV CX, y1;
		MOV DX, y2;
		INT 33h;
	}
}

void GetMousePos(int *mbutton, int *mx, int *my){
	asm{
		MOV AX, 3h;
		INT 33h;

		MOV AX, BX;
		MOV BX, mbutton;
		MOV WORD PTR [BX], AX;

		MOV BX, mx;
		MOV WORD PTR [BX], CX;

		MOV BX, my;
		MOV WORD PTR [BX], DX;
	}
}