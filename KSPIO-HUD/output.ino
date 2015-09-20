void output() {
  now = millis();
  controlTime = now - controlTimeOld; 
  if (controlTime > CONTROLREFRESH){
    controlTimeOld = now;
    controls();
  }    
}

void controls() {

if (digitalRead (BT_A)) {
  if (digitalRead(BT_UP))
    screen = NAVI2;
  
  if (digitalRead(BT_DOWN))
    screen = AGRO1;
  
  if (digitalRead(BT_LEFT)) {
    while (digitalRead(BT_LEFT));
    if ( screen == NAVI1){
      screen = STAT1;
    }else{
      screen = NAVI1;
    }
  }
    
  if (digitalRead(BT_RIGHT)){
    screen = GPS1;
  }
  
} else {
    if ( screen == AGRO1) {      
      if (digitalRead(BT_UP)){
        while (digitalRead(BT_UP));        
        if ( pointer == 0) {
          pointer = 18; 
        } else {
          pointer--;
        }
        
      }
      
      if (digitalRead(BT_DOWN)){
        while (digitalRead(BT_DOWN));                
        if ( pointer == 18) {
          pointer = 0; 
        } else {
          pointer++;
        }
        
      }
    
      if (digitalRead(BT_RIGHT)){
        while (digitalRead(BT_RIGHT));
        if ( !pointer) {
          pointer = 1;
        } else {        
        if ( pointer < 14) {
          pointer += 5; 
        } else if ((pointer == 14 )|| (pointer == 15)) {
          pointer = 18; 
        } else if (pointer >= 16) {
          pointer -=15; 
        }
      }
      }
      
     if (digitalRead(BT_LEFT)){
        while (digitalRead(BT_LEFT));        
        if ( pointer > 5) {
          pointer -= 5; 
        } else if (pointer < 4 ) {
          pointer = 15 + pointer;
        } else {
          pointer = 18;         
        }
      }
      
      if (digitalRead(BT_B)) {
        switch (pointer){
          case 0:
            break;
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
          case 9:
           case 10:
            ControlGroups( pointer, ~bitRead(VData.ActionGroups,pointer+5));
            break;
          case 11:
            MainControls(SAS, ~bitRead(VData.ActionGroups,AGSAS));             
            break;
          case 12: 
            MainControls(RCS, ~bitRead(VData.ActionGroups,AGRCS)); 
            break;
          case 13: 
            MainControls(LIGHTS, ~bitRead(VData.ActionGroups,AGLight));
            break;
          case 14:
            MainControls(GEAR,~bitRead(VData.ActionGroups,AGGear)); 
            break;
          case 15:
            MainControls(BRAKES,~bitRead(VData.ActionGroups,AGBrakes));
            break;
          case 16: 
            MainControls(PRECISION, ~precision); 
            precision = ~precision;
            break;
          case 17:
            MainControls(ABORT, ~bitRead(VData.ActionGroups,AGAbort));
            break;
          case 18:
            MainControls(STAGE, HIGH);                          
            break;         
        }
          
        if (Connected) {
          KSPBoardSendData(details(CPacket)); 
        }                          
        while(digitalRead(BT_B));
        MainControls(STAGE, LOW); 
        
      }
    }
  /*scf  
      if (digitalRead(BT_UP))  //--------- This is how you do main controls
        MainControls(SAS, HIGH);
      else
        MainControls(SAS, LOW);
  
      if (digitalRead(RCSPIN))
        MainControls(RCS, HIGH);
      else
        MainControls(RCS, LOW);
  
      if (digitalRead(CG1PIN))   //--------- This is how you do control groups
        ControlGroups(1, HIGH);
      else
        ControlGroups(1, LOW);      
  
      //This is an example of reading analog inputs to an axis, with deadband and limits
      CPacket.Throttle = constrain(map(analogRead(THROTTLEPIN),THROTTLEDB,1024-THROTTLEDB,0,1000),0, 1000);
      if (digitalRead(BT_B)
        KSPBoardSendData(details(CPacket));
        */


  }
}


void controlsInit() {  
  pinMode ( BT_UP   , INPUT);
  pinMode ( BT_RIGHT , INPUT);
  pinMode ( BT_LEFT , INPUT);
  pinMode ( BT_DOWN, INPUT); 
  pinMode ( BT_A , INPUT);
  pinMode ( BT_B, INPUT); 
}

void MainControls(byte n, boolean s) {
  if (s)
    CPacket.MainControls |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.MainControls &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}

void ControlGroups(byte n, boolean s) {
  if (s)
    CPacket.ControlGroup |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.ControlGroup &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}


