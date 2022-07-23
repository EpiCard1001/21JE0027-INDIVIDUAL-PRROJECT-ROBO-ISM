

#include <IRremote.h>
int IRpin=9;
IRrecv IR(IRpin);
decode_results cmd;
String myCom;
int rPin=6;
int gPin=10;
int bPin=5;
int rBright=255;
int gBright=255;
int bBright=255;
float dFact=1;

void setup() {
  // put your setup code here, to run once:
IR.enableIRIn();  
Serial.begin(9600);
pinMode(rPin,OUTPUT);
pinMode(gPin,OUTPUT);
pinMode(bPin,OUTPUT);
digitalWrite(rPin,rBright);
digitalWrite(gPin,gBright);
digitalWrite(bPin,bBright);
}

void loop() {
  
  while(IR.decode(&cmd)==0){

  }
  Serial.println(cmd.value,HEX);
  delay(500);
  IR.resume();
  if(cmd.value==0xC00000){
    myCom="zero";
    Serial.println(myCom);
  }
  if(cmd.value==0xC00001){
    myCom="one";
    Serial.println(myCom);
  } 
  // put your main code here, to run repeatedly:
  if(cmd.value==0xC00002){
    myCom="two";
    Serial.println(myCom);
  }
  if(cmd.value==0xC00003){
    myCom="three";
    Serial.println(myCom);
  } 
  if(cmd.value==0xC00004){
    myCom="four";
    Serial.println(myCom);
  }
  if(cmd.value==0xC00005){
    myCom="five";
    Serial.println(myCom);
  }
  if(cmd.value==0xC00006){
    myCom="six";
    Serial.println(myCom);
  }
  if(cmd.value==0xC00007){
    myCom="seven";
    Serial.println(myCom);
  }   
  if(cmd.value==0xC00008){
    myCom="eight";
    Serial.println(myCom);
  }     
  if(cmd.value==0xC00009){
    myCom="nine";
    Serial.println(myCom);
  }   
  if(cmd.value==0xC0000C){
    myCom="pwr";
    Serial.println(myCom);
  } 
  if(cmd.value==0xC00058){
    myCom="up";
    Serial.println(myCom);
  }   

    
 
  if(cmd.value==0xC00059){
    myCom="dn";
    Serial.println(myCom);
  }  
 
  
  if(myCom=="pwr"){
    rBright=0;
    gBright=0;
    bBright=0;
    

    
    
  }
  if(myCom=="one"){
    rBright=255;
    gBright=255;
    bBright=255;

   
  } 
  if(myCom=="two"){
    rBright=255;
    gBright=0;
    bBright=0;
  
    
  }  
  if(myCom=="three"){
    rBright=0;
    gBright=255;
    bBright=0;

  } 
  if(myCom=="four"){
    rBright=0;
    gBright=0;
    bBright=255;

  } 
  if(myCom=="five"){
    rBright=255;
    gBright=0;
    bBright=255;
  
  } 
  if(myCom=="six"){
    rBright=0;
    gBright=255;
    bBright=255;

  } 
  if(myCom=="seven"){
    rBright=255;
    gBright=255;
    bBright=0;
  
  } 
  if(myCom=="eight"){
    rBright=255;
    gBright=80;
    bBright=120;
  
  } 

  
   
  
  if(myCom=="dn"){
    dFact=dFact*.55;
  } 
  if(myCom=="up"){
    dFact=dFact*1.6;
    if(dFact>1){
      dFact=1;
    }}
  analogWrite(rPin,rBright*dFact);
  analogWrite(gPin,gBright*dFact);
  analogWrite(bPin,bBright*dFact);
    
  

}


