#ifndef __MOUSE_H
#define LFTCLICK (1)

int InitMouse(void);
void ShowMousePtr(void);
void MoveMousePtr(int x, int y);
void RestrictMousePtr(int x1, int y1, int x2, int y2);
void HideMousePtr(void);
void GetMousePos(int *mbutton, int *x, int *y);

#endif