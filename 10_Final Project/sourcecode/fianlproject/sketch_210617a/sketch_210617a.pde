import processing.serial.*;
int i;
Serial myPort;
float data;
int status = 0;
public static int ON = 1;
public static int OFF = 0;
public static int dark = 0;
public static int light = 0;
PImage img;
void setup(){
 size(1000, 800);
 delay(1000);
 img = loadImage("sky.png");
 String portName = Serial.list()[1];
 
 println(Serial.list());
 myPort = new Serial(this,"/dev/ttyUSB0",115200); 
}
void draw(){

   background(0);
   imageMode(CORNER);
   image(img,0,0,width,height);
   fill(250,150,0);
   ellipse(500,400,data*1.5,data*1.5);
   
   fill(255,255,255);
   textSize(50);
   text("Final Project - Mini street lamp",50,50);
   text("2016116563 yoon seong han",50,100);
   
   textSize(60);
   fill(250,150,0);
   text("SUN -- >",50,500);
   
   
   if (status == ON){
     fill(255,0,0);
     textSize(70);
     text("DAY !!!",50,750);
     
     
   }else if(status == OFF){
    fill(255,0,0);
    textSize(70);
    text("NIGHT zzz",550,750);
   }

}
void serialEvent(Serial p){
  String message = myPort.readStringUntil(10);
  if (message != null)
  {
   print("Received: ");
   println(message);
   data = float(message);
   if(data >=150){
     status = ON;
   }
   else{
     status = OFF;
   }
 
  }
    
}
  
  
