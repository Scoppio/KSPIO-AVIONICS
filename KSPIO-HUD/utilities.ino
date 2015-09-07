void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 101;
}


float degToRad (float deg) {
  deg = (deg * 1000) / 57296;
  return deg;  
}

void printConverted(float c, int a) {
  a = 0;
  if (c < 0) {
   c*=-1;
  
   while (c > 99999) { 
     c = c/1000;
    a++;  
   }
   
   c*=-1;
 
  } else {
    while (c > 99999) { 
      c = c/1000;
      a++;  
    } 
  }
  Monitor.print(c,0);
}


void printConverted(float c) {
byte a = 0;
 if (c < 0) {
   c*=-1;
 while (c > 99999) { 
  c = c/1000;
  a++;  
 }
   c*=-1;
 } else {
 while (c > 99999) { 
  c = c/1000;
  a++;  
 } 
 }
 
Monitor.print(c,0);

    if (a == 0)
      Monitor.print("m");
    else if (a == 1)
      Monitor.print("K");
    else if (a == 2)
      Monitor.print("M");
    else if (a == 3)
      Monitor.print("T");
    else 
      Monitor.print("P");
}

