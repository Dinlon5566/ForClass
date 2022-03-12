void setup(){
  size(800,600);
  background(255);
}
void draw(){
  scale(0.8);
  int a=0,b=0;
  for(;a<800;a+=200){
      drawBoy(a,b);
  }
  a=0;
  b=400;
  for(;a<800;a+=200){
      drawBoy(a,b);
  }
  
}

void drawBoy(int x,int y){
  //head
  strokeWeight(3);
  stroke(0);
  fill(255);
  ellipse(x+200,y+100,50,50);
  
  //leg
  stroke(0);
  line(x+175, y+250, x+175, y+270);
  line(x+225, y+250, x+225, y+270);
  //hat
  line(x+180, y+90, x+250, y+100);
  //eye
  strokeWeight(6);
  line(x+210, y+105,x+213, y+105);
  strokeWeight(3);
  //body
   line(x+200,y+125,x+200,y+185);
   
   //hand
   line(x+200,y+150,x+230,y+135);
   line(x+200,y+150,x+160,y+145);
   fill(242,203,160);
   ellipse(x+230,y+135,15,10);
   ellipse(x+160,y+145,15,10);
   //foot
   fill(176,172,167);
   ellipse(x+175, y+270,15,10);
   ellipse( x+225, y+270,15,10);
   fill(0);
   
  //pant
  fill(64,180,230);
  
  beginShape();
  vertex(x+230, y+185);
  
  vertex(x+170, y+185);
  vertex(x+160, y+250);
  vertex(x+175, y+250);
  vertex(x+190, y+250);
  vertex(x+200, y+230);
  vertex(x+210, y+250);
  vertex(x+225, y+250);
  vertex(x+240, y+250);
  vertex(x+230, y+185);
  endShape();

  
}
