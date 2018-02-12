#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<dos.h>

int bank = 0;

void setbank(void){
   asm{
   mov ax,4f05h    
   xor bx,bx  
   mov dx,[bank]  
   int 10h     
   }
}

void putpixel(int x,int y,unsigned char col){
   int ofs;
   asm{
      mov ax,640
      mov bx,y
      mul bx     
      add ax,x  
      jnc noc    
      inc dx 
   }
       
   noc:
   asm{
      mov ofs,ax  
      cmp dx,bank 
      jz same     
      mov bank,dx 
   }

   setbank(); 
   same:
   asm{
      push di
      mov ax,0a000h  
      mov es,ax
      mov di,ofs
      mov al,col
      mov [es:di],al
      pop di 
   }
 
}
 
void setVideo(){

  asm{
    mov ax, 4f02h
    mov bx, 101h
    int 10h
  }

}


void linea(int x0, int y0, int x1, int y1, int color) {
 
   int dy = y1 - y0;
   int dx = x1 - x0;
   float t = 0.5f; 
   putpixel(x0, y0, color);

   if ((int)dx > (int)dy   ) { 
      float m = (float) dy / (float) dx; 
      t += y0;
      dx = (dx < 0) ? -1 : 1;
      m *= dx;
      while (x0 != x1) {
         x0 += dx; 
         t += m; 
         putpixel( x0, (int) t, color);
        }
      }  else {

      float m = (float) dx / (float) dy;
      t += x0;
      dy = (dy < 0) ? -1 : 1;
      m *= dy;
      while (y0 != y1) {
      y0 += dy;
      t += m;
      putpixel((int) t, y0, color);
      }
   }
}

void lineaGrosor1(int x0, int y0, int x1, int y1, int color) {
 
   int dy = y1 - y0;
   int dx = x1 - x0;
   int i;
   float t = 0.5f; 
   putpixel(x0, y0, color);

   if ((int)dx > (int)dy   ) { 
      float m = (float) dy / (float) dx; 
      t += y0;
      dx = (dx < 0) ? -1 : 1;
      m *= dx;
      while (x0 != x1) {
         x0 += dx; 
         t += m; 
      for(i=0; i<=2; i++){
        putpixel((int) t+i, y0+i, color);
      }
        }
      }  else {

      float m = (float) dx / (float) dy;
      t += x0;
      dy = (dy < 0) ? -1 : 1;
      m *= dy;
      while (y0 != y1) {
      y0 += dy;
      t += m;
      for(i=0; i<=10; i++){
        putpixel((int) t+i, y0+i, color);
      }
 
      }
   }
}

void lineaGrosor2(int x0, int y0, int x1, int y1, int color) {
 
   int dy = y1 - y0;
   int dx = x1 - x0;
   int i;
   float t = 0.5f; 
   putpixel(x0, y0, color);

   if ((int)dx > (int)dy   ) { 
      float m = (float) dy / (float) dx; 
      t += y0;
      dx = (dx < 0) ? -1 : 1;
      m *= dx;
      while (x0 != x1) {
         x0 += dx; 
         t += m; 
      for(i=0; i<=3; i++){
          putpixel((int) t+i, y0+i, color);
      }        }
      }  else {

      float m = (float) dx / (float) dy;
      t += x0;
      dy = (dy < 0) ? -1 : 1;
      m *= dy;
      while (y0 != y1) {
      y0 += dy;
      t += m;
      for(i=0; i<=25; i++){
        putpixel((int) t+i, y0+i, color);
      }
 
      }
   }
}

void circulo(int xCenter, int yCenter, int radius, int c) {
        int x, y, r2;
        r2 = radius * radius;
        putpixel(xCenter, yCenter + radius, c);
        putpixel(xCenter, yCenter - radius, c);
        for (x = 1; x <= radius; x++) {
            y = (int) (sqrt(r2 - x*x) + 0.5);
            putpixel(xCenter + x, yCenter + y,c);
            putpixel(xCenter + x, yCenter - y,c);
            putpixel(xCenter - x, yCenter + y,c);
            putpixel(xCenter - x, yCenter - y,c);
        }
}

