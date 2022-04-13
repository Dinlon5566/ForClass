void setup(){
  size(1000,400);
  frameRate(4);
}
int x=200;
int y=200;
int s=0;
void draw(){
  background(0);
  fill(255,255,73);
  ellipse(x,y,300,300);
  fill(0);
  ellipse(x+50,y-50,30,30);
  if(s%2==0){
    triangle(x,y,x+400,y-200,x+400,y+200);
  }
  s++;
  x+=20;
  if(x>600){
    x=200;
  }

}
