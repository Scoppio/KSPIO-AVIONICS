void output() {
  now = millis();
  controlTime = now - controlTimeOld; 
  if (controlTime > CONTROLREFRESH){
    controlTimeOld = now;
    controls();
  }    
}

void controls() {


  if (digitalRead(BT_UP))
    screen = NAVI2;
  
  if (digitalRead(BT_DOWN))
    screen = STAT1;
  
  if (digitalRead(BT_LEFT))
    screen = NAVI1;
    
  if (digitalRead(BT_RIGHT))
    screen = AGRO1;
  
  if (Connected) {
/*
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


