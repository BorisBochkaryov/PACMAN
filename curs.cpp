#include <graphics.h>

class Map{
      private:
          int matrix[20][20];
      public:
          int getM(int x, int y){ return matrix[(int)x/20][(int)y/20]; }
          void setM(int x, int y){ matrix[(int)x/20][(int)y/20] = 0; }
          int getStat(){ for(int i = 1; i < 19; i++){
                                  for(int j = 1; j < 19; j++){
                                          if(matrix[i][j] == 2) return 1;        
                                  }
                          } 
                          return 0; }
          Map(){
                int matrix[20][20] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                  {1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,1},
                                  {1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
                                  {1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
                                  {1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
                                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                  {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
                                  {1,0,0,0,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1},
                                  {1,1,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,1,1},
                                  {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1},
                                  {1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,1},
                                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                                  {1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
                                  {1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
                                  {1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
                                  {1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,1},
                                  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
                                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
                for(int i = 0; i < 20; i++){
                        for(int j = 0; j < 20; j++){
                                if(matrix[i][j] == 0){
                                       this->matrix[j][i] = 2;
                                } else { this->matrix[j][i] = matrix[i][j]; }
                        }        
                }
                Draw();
          }     
          void Draw(){
                for(int i = 0; i < 20; i++){
                        for(int j = 0; j < 20; j++){
                                if(matrix[i][j] == 1){
                                      setfillstyle(1,BLUE);
                                      bar(i*20,j*20,i*20+20,j*20+20);
                                } else if(matrix[i][j] == 2){
                                      setfillstyle(1,14);
                                      fillellipse(i*20+10,j*20+10,2,2);       
                                }
                        }        
                }
          } 
};

class Person{
      protected:
         int x, y;
      public:
         virtual void Draw() = 0;
         virtual void Dvig() = 0; 
};

class Player:public Person{
      private:
         int status;
         int score;
      public:
         Player(){
              this->status = -1;
              this->x = 210;
              this->y = 210;
              this->score = 0;
         }
         void Draw(){    
              setfillstyle(1,0);
              bar(x-10,y-10,x+10,y+10);   
              setfillstyle(1,13);
              if(status == -1){
                        pieslice(x,y,25,335,10);
              } else if(status == 1){
                        pieslice(x,y,5,355,10);       
              }
              setfillstyle(1,5);   
              fillellipse(x+2,y-4,3,3);
              status *= -1;
              char buf[255];
              outtextxy(5,5,itoa(this->score,buf,10));
         }    
         void Dvig(){}
         void Dvig(int key, Map &M){
              switch(key){
                          case 72: if(getpixel(x,y-20) == 14){ this->score++; M.setM(x,y); }
                                   if(getpixel(x,y-20) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   this->y -= 20; } break;
                          case 77: if(getpixel(x+20,y) == 14){ this->score++; M.setM(x,y); }
                                   if(getpixel(x+20,y) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   this->x += 20; } break;
                          case 80: if(getpixel(x,y+20) == 14){ this->score++; M.setM(x,y); }
                                   if(getpixel(x,y+20) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   this->y += 20; } break;
                          case 75: if(getpixel(x-20,y) == 14){ this->score++; M.setM(x,y); }
                                   if(getpixel(x-20,y) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   this->x -= 20; } break;
                          default: break;            
              }     
         }
};

class War:public Person{
      protected:
             int color;
      public:
             War(int x, int y, int color){
                  this->x = x;
                  this->y = y;     
                  this->color = color;
                  Draw();
             }
             void Draw(){
                  setfillstyle(1,color);
                  bar(x-9,y-9,x+9,y+9);
                  setfillstyle(1,15);
                  fillellipse(x-4,y,2,2);
                  fillellipse(x+4,y,3,3);
             }
             void Dvig(){}
             void Dvig(int n, Map &M){
                  switch(n){
                          case 0:{ if(getpixel(x-2,y-20) == 13){
                                         closegraph();
                                         printf("Game Over\n");
                                         system("PAUSE");
                                         exit(0);
                                   }
                                   if(getpixel(x,y-20) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   if(M.getM(x,y) == 2){
                                        setfillstyle(1,14);               
                                        fillellipse(x,y,2,2);
                                   }
                                   this->y -= 20; 
                                   } } break;
                          case 1:{ if(getpixel(x-2+20,y) == 13){
                                         closegraph();
                                         printf("Game Over\n");
                                         system("PAUSE");
                                         exit(0);
                                   }
                                   if(getpixel(x+20,y) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   if(M.getM(x,y) == 2){
                                        setfillstyle(1,14);               
                                        fillellipse(x,y,2,2);
                                   }
                                   this->x += 20; 
                                   } } break;
                          case 2:{ if(getpixel(x-2,y+20) == 13){
                                         closegraph();
                                         printf("Game Over\n");
                                         system("PAUSE");
                                         exit(0);
                                   }
                                   if(getpixel(x,y+20) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   if(M.getM(x,y) == 2){
                                        setfillstyle(1,14);               
                                        fillellipse(x,y,2,2);
                                   }
                                   this->y += 20; 
                                   } } break;
                          case 3:{ if(getpixel(x-2-20,y) == 13){
                                         closegraph();
                                         printf("Game Over\n");
                                         system("PAUSE");
                                         exit(0);
                                   }
                                   if(getpixel(x-20,y) != 1){
                                   setfillstyle(1,0);
                                   bar(x-10,y-10,x+10,y+10);
                                   if(M.getM(x,y) == 2){
                                        setfillstyle(1,14);               
                                        fillellipse(x,y,2,2);
                                   }
                                   this->x -= 20; 
                                   } } break;
                          default: break;            
                  }
                  Draw();
             }
};

int main(){
    initwindow(400,400);  // открытие графического окна
    Player p; // объект игрока
    Map M; // объекст карты
    int NWar = 4; // количество врагов
    War *mass[NWar]; // динамических массив врагов
    mass[0] = new War(30,30,rand()%13+2); 
    mass[1] = new War(370,30,rand()%13+2);
    mass[2] = new War(370,370,rand()%13+2);
    mass[3] = new War(30,370,rand()%13+2);
    while(1){  // бесконечный цикл игры
        if(M.getStat() == 0){ // если бонусов не осталось, то выигрыш
           closegraph();
           printf("You Win!");
           system("PAUSE");
           exit(0);
        }
        p.Draw();        
        if(kbhit()){ // если была нажата клавиша, то отправляем в метод объекта
           int key = getch();
           p.Dvig(key, M);
           continue;
        }
        for(int i = 0; i < NWar; i++){ // перемещаем врагов
                mass[i]->Dvig(rand()%4+0, M);        
        }
        delay(200); // микрозадержка, для улучшения отрисовки
    }
    system("PAUSE");
    return 0;     
}
