byte clearImage = 0;
void hud() {

  refresh = millis();
  if ((refresh-rate) > 100) {
    rate = refresh;
    clearImage++;
    
  if( (old_screen != screen) || (clearImage > 10)){
    Monitor.clear_screen();
      old_screen = screen;
      clearImage = 0;
    }
    
  if (screen == NAVI1) {
  
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
        Monitor.set_cursor(103,44);
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
        Monitor.draw_line(65,48,int(65-10*cos(degToRad(VData.Roll))), int(48+10*sin(degToRad(VData.Roll))), WHITE);
        Monitor.draw_line(65,48,int(65+10*cos(degToRad(VData.Roll))), int(48-10*sin(degToRad(VData.Roll))), WHITE);        
        Monitor.draw_line(int(65-10*cos(degToRad(VData.Roll))),int(48+10*sin(degToRad(VData.Roll))),int(65-5*cos(degToRad(VData.Roll+90))), int(48+5*sin(degToRad(VData.Roll+90))), WHITE);        
        Monitor.draw_line(int(65+10*cos(degToRad(VData.Roll))),int(48-10*sin(degToRad(VData.Roll))),int(65-5*cos(degToRad(VData.Roll+90))), int(48+5*sin(degToRad(VData.Roll+90))), WHITE);        

        //Linha do horizonte
        Monitor.draw_line(int(65-33*cos(degToRad(VData.Pitch))),int(48+33*sin(degToRad(VData.Pitch))), int(65+33*cos(degToRad(VData.Pitch))),int(48+33*sin(degToRad(VData.Pitch))), WHITE);       
    }
     
  if (screen == STAT1) {
  
    Monitor.print(0,0,"LOX ");  
       Monitor.print(VData.OxidizerS/VData.OxidizerTotS*100, 2); 
       Monitor.print("%");
    Monitor.print(0,LINE*1,"RP1 ");       
      Monitor.print( VData.LiquidFuelS / VData.LiquidFuelTotS*100, 2); 
      Monitor.print("%");
      
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
    }
   
  if (screen == STAT2) {
  
    Monitor.print(0,0,"LOX ");  
       Monitor.draw_rect( 6*4,0,42,7, WHITE, BLACK);
       //Monitor.print(VData.OxidizerS/VData.OxidizerTotS*100); 
       //Monitor.print("%");
       Monitor.draw_rect( 6*4+1, 1, VData.OxidizerS/VData.OxidizerTotS*40 ,5, WHITE, WHITE);
       
    Monitor.print(0,LINE*1,"RP1 ");       
      Monitor.print(VData.LiquidFuelS/VData.LiquidFuelTotS*100); 
      Monitor.print("%");
    Monitor.print(0,LINE*2,"MNP ");       
      Monitor.print(VData.MonoProp/VData.MonoPropTot*100); 
      Monitor.print("%");
    Monitor.print(0,LINE*3,"AIR ");
      Monitor.print(VData.IntakeAir/VData.IntakeAirTot*100);
      Monitor.print("%");
    Monitor.print(0,LINE*4,"ECH ");
      Monitor.print(VData.ECharge/VData.EChargeTot);
      Monitor.print("%");
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
    } else{
    Monitor.print(VData.period);
    Monitor.print("s");    
    }
    
    Monitor.print(0,LINE*9,"LOX-A ");
      Monitor.print(VData.Oxidizer*5);
      Monitor.print("kg");
    Monitor.print(0,LINE*10,"RP1-A ");
      Monitor.print(VData.LiquidFuel*5);
      Monitor.print("kg");
    }
   
  if (screen == AGRO1) {
  
    Monitor.print(0,0,"ACG1 ");     
    Monitor.draw_circle(5*6+6,4, 3, WHITE,bitRead(VData.ActionGroups,6));
    Monitor.set_pixel(5*6+6-1,4-1,INVERT);
    Monitor.print(0,LINE*1,"ACG2 ");
    Monitor.draw_circle(5*6+6,LINE*1+4, 3, WHITE,bitRead(VData.ActionGroups,7));
    Monitor.set_pixel(5*6+6-1,LINE*1+4-1,INVERT);
    Monitor.print(0,LINE*2,"ACG3 ");
    Monitor.draw_circle(5*6+6,LINE*2+4, 3, WHITE,bitRead(VData.ActionGroups,8));
    Monitor.set_pixel(5*6+6-1,LINE*2+4-1,INVERT);
    Monitor.print(0,LINE*3,"ACG4 ");
    Monitor.draw_circle(5*6+6,LINE*3+4, 3, WHITE,bitRead(VData.ActionGroups,9));
    Monitor.set_pixel(5*6+6-1,LINE*3+4-1,INVERT);
    Monitor.print(0,LINE*4,"ACG5 ");
    Monitor.draw_circle(5*6+6,LINE*4+4, 3, WHITE,bitRead(VData.ActionGroups,10));
    Monitor.set_pixel(5*6+6-1,LINE*4+4-1,INVERT);
    Monitor.print(0,LINE*5,"ACG6 ");
    Monitor.draw_circle(5*6+6,LINE*5+4, 3, WHITE,bitRead(VData.ActionGroups,11));
    Monitor.set_pixel(5*6+6-1,LINE*5+4-1,INVERT);
    Monitor.print(0,LINE*6,"ACG7 ");
    Monitor.draw_circle(5*6+6,LINE*6+4, 3, WHITE,bitRead(VData.ActionGroups,12));
    Monitor.set_pixel(5*6+6-1,LINE*6+4-1,INVERT);
    Monitor.print(0,LINE*7,"ACG8 ");
    Monitor.draw_circle(5*6+6,LINE*7+4, 3, WHITE,bitRead(VData.ActionGroups,13));
    Monitor.set_pixel(5*6+6-1,LINE*7+4-1,INVERT);
    Monitor.print(0,LINE*8,"ACG9 ");
    Monitor.draw_circle(5*6+6,LINE*8+4, 3, WHITE,bitRead(VData.ActionGroups,14));
    Monitor.set_pixel(5*6+6-1,LINE*8+4-1,INVERT);
    Monitor.print(0,LINE*9,"ACG0 ");
    Monitor.draw_circle(5*6+6,LINE*9+4, 3, WHITE,bitRead(VData.ActionGroups,15));
    Monitor.set_pixel(5*6+6-1,LINE*9+4-1,INVERT);
    }  
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

