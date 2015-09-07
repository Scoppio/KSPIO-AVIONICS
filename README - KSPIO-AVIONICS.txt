This is my project, done with the preliminar demo made by zitron - found at https://sites.google.com/site/zitronfiles/KSPIODemo12.zip

His demo was modified to work as a set of video avionics, with artificial horizon and to display the most important information of the vessel during flight.

I use an Arduino MEGA clone and it works perfectly with my DIY TVOUT shield board (with 6 added buttons for control)

I found a few problems with the idea of sending data from the arduino to the KSP game, mainly due to the TVOUT library. It turns out that the MCU must write to the TV every few cycles, and if it stops to send a packet of data to the computer it will write data to the TV out of phase and therefore the image will wables and flicker. The only way to fix it would be to use a slave MCU only to create the TV output based in some serial input. Unfortunatelly I have only one arduino board and no extra MCU to use in a proto-board.

So the workaround that I came up with is, when I want to send some information from my board to the KSP, it will only send the date when I press the button that acknoledge the action. This way the TV will flick but it will only happen when the button is pressed.

I am still creating this avionics, will add some features like adding several MCU's to control particular TVOUTS to build a real avionics panel.

Planned features:

 - auto-abort - in case of malfunction of the ship, no fuel, falling fast towards the ground with no way to survive, the parachute will deploy automaticaly if the speed is under 330m/s and the G force is under 9g's (otherwise the parachute will just break).

 - Somekind of autopilot - but I'm not really fond of this idea because even tough the sample rate is high, I would only be able to make it work if I use a slave MCU to take care of the TVoutput.

 - Slave MCU for multiple avionic screens - some way to control multiple MCU's via serial or parallel communication, this way I'll be able to add lots of TVs to use as avionic screens.