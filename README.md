# Frogger Arcade Game
We created a Frogger Arcade game using C programming language in a LandTiger NXP LPC1768 Micro-Controller board that uses a ARM Cortex-M3 Processor                     

The LPC1768 Development Board Manual can be viewed here: https://copperhilltech.com/content/LandTiger-V2-Manual.pdf  			    
The User Manual for the LPC1768 can be viewed here: https://www.nxp.com/docs/en/user-guide/UM10360.pdf

## Engineers
* Osama Abaali - Senior Student in Electrical Engineering at the University at Buffalo, The State University of New York (SUNY).
* Michael Lawrenson - Senior Student in Electrical Engineering at the University at Buffalo, The State University of New York (SUNY).

## Description of the game
Frogger is an arcade game introduced in 1981. It was developed by Konami, and licensed for worldwide distribution by Sega/Gremlin. The game is regarded as a classic and was noted for its novel gameplay and theme. The object of the game is to direct frogs to their homes one by one. To do this, each frog must avoid cars while crossing a busy road and navigate a river full of hazards. The skillful player may obtain many bonuses along the way. 

Frogger is widely regarded as one of the classic arcade games and holds a definitive place as one of the great video games.
There are many online versions of the game. One classic versions can be viewed here: http://www.free80sarcade.com/frogger.php

## Features Added
### Feature 1: Navigating the Frog using a PC keyboard
We used a PC keyboard to send UART Commands to the board to navigate the frog around the map instead of a joystick that is integrated in the development board. The baud rate of the UART is set at 57600 Bd.
#### Navigating the Frog Up
The user can navigate the frog forward by pressing the 'w' key.

![ezgif com-resize](https://user-images.githubusercontent.com/40522456/57873294-cb11df00-77db-11e9-8729-c8d1ccfdca78.gif)
#### Navigating the Frog Down
The user can navigate the frog backward by pressing the 's' key.


![ezgif com-resize (1)](https://user-images.githubusercontent.com/40522456/57873641-cac61380-77dc-11e9-9e56-3a4acab14ac8.gif)
#### Navigating the Frog to the Right
The user can navigate the frog to the right by pressing the 'd' key.

![ezgif com-resize (2)](https://user-images.githubusercontent.com/40522456/57873999-969f2280-77dd-11e9-9109-16f2e811a39f.gif)
#### Navigating the Frog to the Left
The user can navigate the frog to the left by pressing the 'a' key.

![ezgif com-resize (3)](https://user-images.githubusercontent.com/40522456/57874233-15945b00-77de-11e9-99a1-235fb785b762.gif)
### Feature 2: Pause/Resume option
We used a momentary pushbutton to pause/resume the game. The schematic below illustrates the pins and polarity of the pushbutton.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57874754-504ac300-77df-11e9-8014-a0e9579ff909.PNG">
Based on this, we see that P2.12 (the board schematic has a typo – it is not P2.22) can be used to read the state of two of the pushbuttons. If the button is pressed, will we read a '0' value at the pin.

Below are 2 pictures when the game is paused, and when the game is resumed.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57875211-5e4d1380-77e0-11e9-8694-3d9221219e0b.PNG">
<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57875229-6efd8980-77e0-11e9-9578-ee5d50bcf89d.PNG">



