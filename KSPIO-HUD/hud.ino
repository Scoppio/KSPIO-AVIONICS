
byte clearImage = 0, cLon, cLat, w, pointer = 0;
byte mapOverlay [128];


int a[] = {65 , 48};
int b[] = {int(65-10*cos(degToRad(VData.Roll))) , int(48+10*sin(degToRad(VData.Roll))) };
int c[] = {int(65+10*cos(degToRad(VData.Roll))), int(48-10*sin(degToRad(VData.Roll))) };
int d[] = {int(65-5*cos(degToRad(VData.Roll+90))), int(48+5*sin(degToRad(VData.Roll+90))) };
int e[] = {int(65+(15*sin(degToRad(VData.Pitch)))*cos(degToRad(VData.Roll+90))), int(48-(15*sin(degToRad(VData.Pitch)))*sin(degToRad(VData.Roll+90))) };

void hud() {

  refresh = millis();
  if ((refresh-rate) > 100) {
    rate = refresh;
    clearImage++;
    
    if( (old_screen != screen) || (clearImage > 10)){
      old_screen = screen;
      Monitor.clear_screen();
      clearImage = 0;
    }
    
  if (screen == NAVI1) {
  /*
    Tela de navegação 1
    Informações    
  */
    Monitor.print(0,0,"ALT ");  
       printConverted(VData.Alt);        
    Monitor.print(0,LINE*1,"APO ");
      printConverted(VData.AP);
    Monitor.print(0,LINE*2,"PER ");
      printConverted(VData.PE);
    
    Monitor.print(0,LINE*4,"PIT ");
    Monitor.print(VData.Pitch);
    Monitor.print(0,LINE*5,"ROL ");
    Monitor.print(VData.Roll);
    Monitor.print(0,LINE*6,"HEA ");
    Monitor.print(VData.Heading);
    
    Monitor.print(0,LINE*8,"GFc ");
    Monitor.print(VData.G);
    
    Monitor.print(0,LINE*9,"VOr ");
      printConverted(VData.VOrbit);
    Monitor.print(0,LINE*10,"VSu ");
      printConverted(VData.Vsurf);
      
      
    Monitor.print(0,LINE*11,"SOI ");  
      switch (VData.SOINumber) {
        case 100: 
        Monitor.print("Kerbol");
        break;
        case 110:
        Monitor.print("Moho");
        break;
        case 120:
        Monitor.print("Eve");
        break;
        case 121:
        Monitor.print("Gilly");
        break;
        case 130:
        Monitor.print("Kerbin");
        break;
        case 131:
        Monitor.print("Mun");
        break;
        case 132:
        Monitor.print("Minmus");
        break;
        case 140:
        Monitor.print("Duna");
        break;
        case 150:
        Monitor.print("Dres");
        break;
        case 160:
        Monitor.print("Jool");
        break;
        case 161:
        Monitor.print("Laythe");
        break;
        case 162:
        Monitor.print("Vall");
        break;
        case 163:
        Monitor.print("Tylo");
        break;
        case 164:
        Monitor.print("Bop");
        break;
        case 165:
        Monitor.print("Pol");
        break;
        case 170:
        Monitor.print("Eelo");
        break;
        default:
        Monitor.print("ERRO 404");
        break;
  }
      
    }
    
  if (screen == NAVI2) {
  
        Monitor.draw_circle(65,48,41, WHITE);
        Monitor.draw_circle(65,48,35, BLACK,BLACK);
        
        Monitor.print(5,41-8,"SPEED");  
        Monitor.print(106,41-8,"ALT");       
        Monitor.print(103,44+8,"PTCH");
          
        Monitor.print(56,3,VData.Heading,0);
        Monitor.print(7,44,VData.Vsurf,0);
        Monitor.set_cursor(103-6,44);
        printConverted(VData.RAlt,0);
        Monitor.print(103,44+8+8,VData.Pitch,0);


        Monitor.select_font(font4x6);  
        if( VData.G > 8) {
           Monitor.print(127-4*7,95-24,"HIGH G!");        
        }else {
           Monitor.print(127-4*7,95-24,"G: ");
           Monitor.print(VData.G,2);
        }
        Monitor.print(127-4*9,95-12,"GEAR ");

        if(  bitRead(VData.ActionGroups,AGGear))
          Monitor.print("DOWN");
        else
          Monitor.print("UP  ");
        Monitor.print(127-4*9,95-6,"SAS ");          
        if(  bitRead(VData.ActionGroups,AGSAS))
          Monitor.print("ON ");
        else
          Monitor.print("OFF"); 
        
        Monitor.select_font(font6x8);  
        b[0] = int(65-10*cos(degToRad(VData.Roll)));
        b[1] = int(48+10*sin(degToRad(VData.Roll)));
        c[0] = int(65+10*cos(degToRad(VData.Roll)));
        c[1] = int(48-10*sin(degToRad(VData.Roll)));

        d[0] = int(65-(5*sin(degToRad(VData.Pitch+90)))*cos(degToRad(VData.Roll+90)));
        d[1] = int(48+(5*sin(degToRad(VData.Pitch+90)))*sin(degToRad(VData.Roll+90)));

        e[0] = 65;
        e[1] = int(48-(15*sin(degToRad(VData.Pitch))));

        
        Monitor.draw_line( a[0], a[1], b[0], b[1], WHITE);
        Monitor.draw_line( a[0], a[1], c[0], c[1], WHITE);        
        Monitor.draw_line( b[0], b[1], d[0], d[1], WHITE);        
        Monitor.draw_line( c[0], c[1], d[0], d[1], WHITE);        
        
        Monitor.draw_line( d[0], d[1], e[0], e[1], WHITE);                
        Monitor.draw_line( e[0], e[1], b[0], b[1],WHITE);
        Monitor.draw_line( e[0], e[1], c[0], c[1],WHITE);
        //Linha do horizonte
        Monitor.draw_line(int(65-33*cos(degToRad(VData.Pitch))),int(48+33*sin(degToRad(VData.Pitch))), int(65+33*cos(degToRad(VData.Pitch))),int(48+33*sin(degToRad(VData.Pitch))), WHITE);       
    }
     
  if (screen == STAT1) {
   Monitor.print(0,0,"LOX ");  
//       Monitor.print(VData.OxidizerS / VData.OxidizerTotS * 100, 2); 
       Monitor.print(VData.OxidizerS, 2); 
       Monitor.print(" u");
//       Monitor.print("%");
    Monitor.print(0,LINE*1,"RP1 ");       
//      Monitor.print( VData.LiquidFuelS / VData.LiquidFuelTotS * 100, 2); 
      Monitor.print( VData.LiquidFuelS, 2); 
      Monitor.print(" u");      
//      Monitor.print("%");
      
    Monitor.print(0,LINE*2,"MNP ");       
      Monitor.print(VData.MonoProp/VData.MonoPropTot*100, 2); 
      Monitor.print("%");
    Monitor.print(0,LINE*3,"AIR ");
      Monitor.print(VData.IntakeAir/VData.IntakeAirTot*100);
      Monitor.print("%");
    Monitor.print(0,LINE*4,"ECH ");
    Monitor.print(VData.ECharge/VData.EChargeTot);
    Monitor.print(0,LINE*6,"DeV ");
    Monitor.print(VData.MNDeltaV);
    Monitor.print("m/s");
   
    Monitor.print(0,LINE*8,"Period ");
    if(VData.period > 3600){    
    Monitor.print(VData.period/3600);
    Monitor.print("h");
    }
    else if (VData.period > 60){
    Monitor.print(VData.period/60);
    Monitor.print("m");
    } else
    Monitor.print(VData.period);
    Monitor.print("s");    
    
    Monitor.print(0,LINE*9,"LOX-A ");
      Monitor.print(VData.Oxidizer);
    Monitor.print(0,LINE*10,"RP1-A ");
      Monitor.print(VData.LiquidFuel);
      
    Monitor.print(91,0,"ACG1 ");     
    Monitor.draw_circle( 121, 4, 3, WHITE,bitRead(VData.ActionGroups,6));
    Monitor.set_pixel(121-1,4-1,INVERT);

    Monitor.print(91,LINE*1,"ACG2 ");
    Monitor.draw_circle(121,LINE*1+4, 3, WHITE,bitRead(VData.ActionGroups,7));
    Monitor.set_pixel(121-1,LINE*1+4-1,INVERT);

    Monitor.print(91,LINE*2,"ACG3 ");
    Monitor.draw_circle(121,LINE*2+4, 3, WHITE,bitRead(VData.ActionGroups,8));
    Monitor.set_pixel(121-1,LINE*2+4-1,INVERT);

    Monitor.print(91,LINE*3,"ACG4 ");
    Monitor.draw_circle(121,LINE*3+4, 3, WHITE,bitRead(VData.ActionGroups,9));
    Monitor.set_pixel(121-1,LINE*3+4-1,INVERT);

    Monitor.print(91,LINE*4,"ACG5 ");
    Monitor.draw_circle(121,LINE*4+4, 3, WHITE,bitRead(VData.ActionGroups,10));
    Monitor.set_pixel(121-1,LINE*4+4-1,INVERT);

    Monitor.print(91,LINE*5,"ACG6 ");
    Monitor.draw_circle(121, LINE*5+4, 3, WHITE,bitRead(VData.ActionGroups,11));
    Monitor.set_pixel(121-1,LINE*5+4-1,INVERT);

    Monitor.print(91,LINE*6,"ACG7 ");
    Monitor.draw_circle(121,LINE*6+4, 3, WHITE,bitRead(VData.ActionGroups,12));
    Monitor.set_pixel(121-1,LINE*6+4-1,INVERT);

    Monitor.print(91,LINE*7,"ACG8 ");
    Monitor.draw_circle(121,LINE*7+4, 3, WHITE,bitRead(VData.ActionGroups,13));
    Monitor.set_pixel(121-1,LINE*7+4-1,INVERT);

    Monitor.print(91,LINE*8,"ACG9 ");
    Monitor.draw_circle(121,LINE*8+4, 3, WHITE,bitRead(VData.ActionGroups,14));
    Monitor.set_pixel(121-1,LINE*8+4-1,INVERT);
    
    Monitor.print(91,LINE*9,"ACG0 ");
    Monitor.draw_circle(121,LINE*9+4, 3, WHITE,bitRead(VData.ActionGroups,15));
    Monitor.set_pixel(121-1,LINE*9+4-1,INVERT);
      
      
    }
   
  if (screen == GPS1) {
    if ( VData.SOINumber == 130){
      Monitor.bitmap( 0, 0, kerbinmap);
   
   /*
      Kerbin = 128x64 (0,0) - (127,63)
          
      63px 31px = 0LON 0LAT
      38-31 = 285LON 0LAT
      
      */
  
        mapper(VData.Lat, VData.Lon);      
  
        Monitor.draw_line( 0, cLat, 127, cLat, WHITE);//Y line      
        Monitor.draw_line( cLon, 0, cLon, 63, WHITE); //X line

        mapOverlay[cLon] = cLat;
        
        for (byte x = 127, y = 4, c = 0; x != 0; x--) {
            if ( mapOverlay[x] && mapOverlay[x+1] ){
              Monitor.draw_line( x+1,mapOverlay[x+1], x, mapOverlay[x], WHITE);             
              //Monitor.set_pixel( x, mapOverlay[x], WHITE);             
            }
        };
        
        Monitor.print(0,65, "LAT ");
        //Monitor.print(cLat,DEC);
        if (VData.Lat < 0){
          Monitor.print(VData.Lat*-1,3);
          Monitor.println(" S");    
        } else{
          Monitor.print(VData.Lat,3);
          Monitor.println(" N");    
        }
        Monitor.print("LON ");    
        //Monitor.print(cLon,DEC);
        if (VData.Lon < 180) {
          Monitor.print(VData.Lon*-1,3);                
          Monitor.print(" E");
        } else {
          Monitor.print(VData.Lon,3);
          Monitor.print(" W");
        }
        
      } else {        
        Monitor.print(10,31, "OUTSIDE KERBIN SOI"); 
        
      }
    
    }
   
  if (screen == AGRO1) {

    for (byte r = 0, w = 0, v = 0, d = 13, action = 6; r < 10; r++, w++, action++) {

      if ( r == 5) {
        v = 31;
        w = 0;
      }      
      Monitor.draw_rect( 0+v, 0+w*d, 8, 10,WHITE,BLACK);   
      if ( r <= 8)
        Monitor.print( 2+v, 2+w*d, r+1, DEC);            
      else
        Monitor.print( 2+v, 2+w*d, "0");            
        
      Monitor.draw_circle( 14+v, 5+w*d, 3, WHITE, bitRead(VData.ActionGroups,action));
      Monitor.set_pixel( 14-1+v, 6-1+w*d, INVERT);

    }
    
    for (byte r = 0, w = 0, v = 62, d = 13; r < 8; r++, w++) {

      if ( r == 5) {
        v = 93;
        w = 0;
      }   
      
      Monitor.draw_rect( 0+v, 0+w*d, 8, 10,WHITE,BLACK);
     
      switch ( r) {
        case 0:    
          Monitor.print( 2+v, 2+w*d, "S");
          Monitor.draw_circle( 14+v, 5+w*d, 3, WHITE, bitRead(VData.ActionGroups,AGSAS));
          Monitor.set_pixel( 14-1+v, 6-1+w*d, INVERT);          
          break;
        case 1: 
          Monitor.print( 2+v, 2+w*d, "R");
          Monitor.draw_circle( 14+v, 5+w*d, 3, WHITE, bitRead(VData.ActionGroups,AGRCS));
          Monitor.set_pixel( 14-1+v, 6-1+w*d, INVERT);          
          break;
            // break;
           //case LIGHTS : 
        case 2:
          Monitor.print( 2+v, 2+w*d, "L");
          Monitor.draw_circle( 14+v, 5+w*d, 3, WHITE, bitRead(VData.ActionGroups,AGLight));
          Monitor.set_pixel( 14-1+v, 6-1+w*d, INVERT);          
          break;
           //case GEAR:
        case 3:      
          Monitor.print( 2+v, 2+w*d, "G");
          Monitor.draw_circle( 14+v, 5+w*d, 3, WHITE, bitRead(VData.ActionGroups,AGGear));
          Monitor.set_pixel( 14-1+v, 6-1+w*d, INVERT);          
          break;
           //case BRAKES : 
        case 4:
          Monitor.print( 2+v, 2+w*d, "B");
          Monitor.draw_circle( 14+v, 5+w*d, 3, WHITE, bitRead(VData.ActionGroups,AGBrakes));
          Monitor.set_pixel( 14-1+v, 6-1+w*d, INVERT);          
          break;
        case 5:
          Monitor.print( 2+v, 2+w*d, "P");
          break;
        case 6:
          Monitor.draw_rect( 0+v, 0+w*d, 32, 10,WHITE, bitRead(VData.ActionGroups,AGAbort));   
          Monitor.print( 2+v, 2+w*d, "ABORT");
          break;
        case 7:
          Monitor.draw_rect( 0+v, 0+w*d, 32, 10,WHITE,BLACK);
          Monitor.print( 2+v, 2+w*d, "STAGE");        
          break;
        default:
          break;
      }
    }
      Monitor.print( 0, 80, pointer,DEC);
      hudOverlay();
      
    }  
  }
}

void hudOverlay () {
  if ( screen == AGRO1) {
    if ( pointer){
      if ( pointer < 17){
        if ( pointer <= 5){
          Monitor.draw_rect(0, (pointer-1)*13, 8, 10, WHITE, INVERT); 
        } else if ( pointer <= 10) {      
            Monitor.draw_rect(31, (pointer-1-5)*13, 8, 10, WHITE, INVERT); 
        } else if ( pointer <= 15) {
            Monitor.draw_rect(62, (pointer-1-10)*13, 8, 10, WHITE, INVERT);                   
        } else {
            Monitor.draw_rect(93, 0, 8, 10, WHITE, INVERT);                   
        }
      } else {
           Monitor.draw_rect(93, (pointer-1-15)*13, 32, 10, WHITE, INVERT);                   
      }
    }
    
    //pointer
    //column 0, 31, 62, 93
    //line = 13
    //8x10
    //if 17 or 18 == 32x10
    
    
      //if (digitalRead(BT_B)) {
    //      Monitor.draw_rect(0,0,8,10,WHITE,INVERT);   
    //      while(digitalRead(BT_B));
    //}     
    
    
  }  
  
}

void hudIdle ()
{
  refresh = millis();
  if ((refresh-rate) > 5000) {
    rate = refresh;
    Monitor.clear_screen();
    Monitor.print(10,10,"SEM CONEXAO"); 
  }
}

