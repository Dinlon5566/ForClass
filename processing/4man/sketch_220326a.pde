PImage img;
int wxa,wya,px,py;
int wxw,wyw;
int wxd,wyd;
int wxs,wys;

void setup(){
  size(800,600);
  background(255);
  img=loadImage("p3_4.png");
  wxa=500;
  wya=200;
  wxd=200;
  wyd=500;
  wxw=200;
  wyw=200;
  wxs=500;
  wxs=500;
  px=0;
  py=48;
  frameRate(30);
}
void draw(){
  background(255);
  image(img,wxa,wya,32,48,px,py,px+32,py+48);
  image(img,wxs,wys,32,48,px,py-48,px+32,py);
  image(img,wxd,wyd,32,48,px,py+48,px+32,py+96);
  image(img,wxw,wyw,32,48,px,py+96,px+32,py+144);
  wxa-=4;
  wxd+=4;
  wyw-=4;
  wys+=4;
  px+=32;
  if(px>=128){
    px=0;
   }
   if(wxa<-40){
     wxa=820;
   }
   if(wxd>=825){
     wxd=-40;
   }
   if(wys>=620){
     wys=-8;
   }
   if(wyw<=-8){
     wyw=620;
   }


}
