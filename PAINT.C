#include<conio.h>
#include<stdio.h>
#include<mouse.c>
#include<math.h>
#include<dos.h>
#include<figuras.c>

#define limiteX1 150 
#define limiteX2 600
#define limiteY1 40
#define limiteY2 440


int mx, my, mbutton, estado;

void main(void){

   setVideo();
   estado = InitMouse();
   ShowMousePtr();
   RestrictMousePtr(0,0,640,480);
   while (1){


      GetMousePos(&mbutton, &mx, &my);
      if(mbutton == 1 && mx>=limiteX1 && mx<=limiteX2 && my>=limiteY1 && my<=limiteY2)
        putpixel(mx,my,13);

      linea(limiteX1,limiteY1,limiteX1,limiteY2,2);
      linea(limiteX2,limiteY1,limiteX2,limiteY2,2);
      linea(limiteX1,limiteY1,limiteX2,limiteY1,2);
      linea(limiteX1,limiteY2,limiteX2,limiteY2,2);

   }

  getch();

}
