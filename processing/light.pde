void setup(){
  size(400,400);
 background(0);
  frameRate(5);
}
int x=200;
int y=200;
void draw(){
   fill(1);
   stroke(random(255),random(255),random(255));
   line(200,200,200+random(200)-100,200+random(200)-100);

}
