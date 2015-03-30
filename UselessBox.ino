#include <Servo.h> 

Servo doorServo;
Servo fingerServo;

int swPin = 2;               //switch on pin 2

int pos = 0;
int selectedMove = 0;             //move selector

void setup()
{
  pinMode(swPin, INPUT);
  doorServo.attach(9);           //set door servo on Pin 9 pwm
  fingerServo.attach(10);          //set finger servo on Pin 10 pwm
  doorServo.write(80);           //set door to hiding position 
  fingerServo.write(0);            //set finger to hiding position
}


void loop(){

  //if the switch is on, move door and finger to switch it off
  if(digitalRead(swPin) == HIGH)
  {
    
    if (selectedMove > 9) { 
    selectedMove = 0; 
    } //when all moves are played, repeat the moves from beginning 
    
    if (selectedMove == 0) { 
    simpleClose(); 
    }
    else if (selectedMove == 1) { 
    simpleClose(); 
    }   
    else if (selectedMove == 2) { 
    simpleClose2(); 
    }
    else if (selectedMove == 3) { 
    crazydoor(); 
    }
    else if (selectedMove == 4) { 
    slow(); 
    }
    else if (selectedMove == 5) { 
    serious(); 
    }
    else if (selectedMove == 6) { 
    trollClose(); 
    }
    else if (selectedMove == 7) { 
    simpleClose(); 
    }
    else if (selectedMove == 8) { 
    matrix(); 
    }
    else if (selectedMove == 9) { 
    sneak(); 
    }
     
   selectedMove += 1;         //swith to next move 
   
  }
}



// Moves

   // basic move 
   void simpleClose() 
   {    
   //Moving door
    for(pos = 80; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
   
    //Moving hand
    for(pos = 0; pos < 129; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }  
    
    //hiding hand
    for(pos = 129; pos>=0; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    } 
      
    //hiding door
    for(pos = 155; pos>=80; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 
   } 
     
   // open and wait, then move finger and wait, then switch of and hide  
    void simpleClose2()
   {
  //Moving door
    for(pos = 80; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
    delay(800); 
    //Moving hand
    for(pos = 0; pos < 100; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }
    delay(1000); 
    for(pos = 100; pos < 129; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }    
    
    //hiding hand
    for(pos = 129; pos>=0; pos-=5)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    } 
      
    //hiding door
    for(pos = 155; pos>=80; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);                    
     
     
   } 
     
   }
  
   //open door then close it many times, wait, then quickly reopen, switch off and hide.
  
   void crazydoor()
  {
    
   //Moving door
    for(pos = 80; pos < 125; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
  
    //hiding door
    for(pos = 125; pos>=80; pos-=5)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 
   //Moving door
    for(pos = 80; pos < 110; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
  
    //hiding door
    for(pos = 110; pos>=80; pos-=15)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 
    delay(700);
   //Moving door
    for(pos = 80; pos < 125; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
    delay(700);
    //hiding door
    for(pos = 125; pos>=80; pos-=5)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 

  //Moving door
    for(pos = 80; pos < 155; pos += 8)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
   
    //Moving hand
    for(pos = 0; pos < 129; pos += 3)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }  
    
    //hiding hand
    for(pos = 129; pos>=0; pos-=3)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    } 
      
    //hiding door
    for(pos = 155; pos>=80; pos-=15)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    }    
    
  }   


 //open door,move finger very slowly forward and back to hiding very slowly, then quickly close door
 void slow()
 {
 
//Moving door
    for(pos = 80; pos < 155; pos += 1)   
    {                                   
    doorServo.write(pos);              
    delay(30);                       
    }
   
    //Moving hand
    for(pos = 0; pos < 129; pos += 1)  
    {                                   
    fingerServo.write(pos);               
    delay(30);                       
    }  
    
    //hiding hand
    for(pos = 129; pos>=0; pos-=1)      
    {                                
    fingerServo.write(pos);               
    delay(30);                        
    } 
      
    //hiding door
    for(pos = 155; pos>=125; pos-=1)     
    {                                
    doorServo.write(pos);              
    delay(30);                      
    }
    delay(100);
    for(pos = 125; pos>=80; pos-=4)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    }     
    
 
 }
 
 //serious
 
 void serious() {
 
//Moving door
    for(pos = 80; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
     
    //Moving hand
    for(pos = 0; pos < 70; pos += 1)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }
    delay(800);
    
    
    //hiding door
    for(pos = 155; pos>=130; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15); 
    }
    
    //hiding door
    for(pos = 130; pos < 155; pos+=3)     
    {                                
    doorServo.write(pos);              
    delay(15); 
    } 
     //hiding door
    for(pos = 155; pos>=130; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15); 
    }   
    //hiding door
    for(pos = 130; pos < 155; pos+=3)     
    {                                
    doorServo.write(pos);              
    delay(15); 
    } 
     
    fingerServo.write(40);
    delay(1000);
      
    //Moving hand
    for(pos = 40; pos < 129; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    } 
    
    //hiding hand
    for(pos = 129; pos>=0; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    } 
    
      
    for(pos = 120; pos>=80; pos -= 1)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
   
   
     
} 

void trollClose(){
//Moving door
    for(pos = 80; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
   
    //Moving hand
    for(pos = 0; pos < 127; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }
    //hiding door
    for(pos = 155; pos>=130; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    }   
    delay(2000);
    
    for(pos = 130; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
    
    for(pos = 155; pos>=140; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);
    }
    for(pos = 140; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
    delay(500);
    //hiding hand
    for(pos = 127; pos>=0; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    } 
      
    //hiding door
    for(pos = 155; pos>=80; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 

}
   
void matrix()
{

 //Moving door
    for(pos = 80; pos < 155; pos += 3)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
   
    //Moving hand
    for(pos = 0; pos < 80; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }
    
    for(pos = 80; pos < 129; pos += 1)  
    {                                   
    fingerServo.write(pos);               
    delay(30);                       
    }  
    delay(300);
    
    for(pos = 129; pos>=0; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(10);                        
    } 
      
    //hiding door
    for(pos = 155; pos>=80; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 
  
}

void sneak() 
   {    
   //Moving door
    for(pos = 80; pos < 130; pos += 1)   
    {                                   
    doorServo.write(pos);              
    delay(30);                       
    }
    delay(2000);
    
    //Moving hand
    for(pos = 0; pos < 40; pos += 1)  
    {                                   
    fingerServo.write(pos);               
    delay(30);                       
    }  
        
    delay(500);
    
    for(pos = 130; pos < 155; pos += 4)   
    {                                   
    doorServo.write(pos);              
    delay(15);                       
    }
    delay(100);
    
    for(pos = 40; pos < 90; pos += 4)  
    {                                   
    fingerServo.write(pos);               
    delay(15);                       
    }  
    delay(500);
    //hiding hand
    for(pos = 90; pos>=70; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    }
    delay(100);
    for(pos = 70; pos < 90; pos += 4)  
    {                                   

    fingerServo.write(pos);               
    delay(15);                       
    }
    delay(100);
    for(pos = 90; pos>=70; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    }
    delay(100);
       
    for(pos = 70; pos < 129; pos += 4)  
    {                                   

    fingerServo.write(pos);               
    delay(15);                       
    }
    
    for(pos = 129; pos>=0; pos-=4)      
    {                                
    fingerServo.write(pos);               
    delay(15);                        
    }    
    //hiding door
    for(pos = 155; pos>=80; pos-=3)     
    {                                
    doorServo.write(pos);              
    delay(15);                      
    } 
   } 
   
   
   
