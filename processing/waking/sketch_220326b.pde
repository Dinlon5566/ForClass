PImage img;
int wx,wy,px,py;
int dir=1;
int step=0;
boolean move=false;

void setup(){
  size(800,600);
  background(255);
  img=loadImage("p3_4.png");
  wx=500;
  wy=200;

  px=0;
  py=48;
  frameRate(30);
}
void draw(){
  background(255);
  fill(255,37,37);
  rect(300,300,40,50);
  image(img, wx, wy, 32, 48, step*32, dir*48, step*32+32, dir*48+48);
  if(keyPressed){
    move=true;
    if(keyCode==DOWN){
      dir=0;
    }
    if(keyCode==LEFT){
      dir=1;
    }
    if(keyCode==RIGHT){
      dir=2;
    }
    if(keyCode==UP){
      dir=3;
    }
    if(key=='s'){
      move=false;
    }
  }
  
  
  if(move){
    step++;
    step%=4;
    if(dir==0)wy+=4;
    if(dir==1)wx-=4;
    if(dir==2)wx+=4;
    if(dir==3)wy-=4;
    if(wx<-40) wx=820;
    if(wx>820) wx=-40;
    if(wy<-40) wy=620;
    if(wy>620) wy=-40;
  }


}
