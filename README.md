# Embedded Systems Project
[![HitCount](http://hits.dwyl.io/OAAbaali2896/Frogger-Arcade-Game.svg)](http://hits.dwyl.io/OAAbaali2896/Frogger-Arcade-Game)

<img width="425" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57877843-bedf4f00-77e6-11e9-87cf-9e88fa135c81.PNG">

# Frogger Arcade Game
We created a Frogger Arcade game using C programming language in a LandTiger NXP LPC1768 Micro-Controller board that uses a ARM Cortex-M3 Processor. The game is displayed in an LCD display on the development board.                     

The LPC1768 Development Board Manual can be viewed here: https://copperhilltech.com/content/LandTiger-V2-Manual.pdf  			    
The User Manual for the LPC1768 can be viewed here: https://www.nxp.com/docs/en/user-guide/UM10360.pdf

## Description of the game
Frogger is an arcade game introduced in 1981. It was developed by Konami, and licensed for worldwide distribution by Sega/Gremlin. The game is regarded as a classic and was noted for its novel gameplay and theme. The object of the game is to direct frogs to their homes one by one. To do this, each frog must avoid cars while crossing a busy road and navigate a river full of hazards. The skillful player may obtain many bonuses along the way. 

Frogger is widely regarded as one of the classic arcade games and holds a definitive place as one of the great video games.
There are many online versions of the game. One classic versions can be viewed here: http://www.free80sarcade.com/frogger.php

## Functionalities Added
### 1: Navigating the Frog using a PC keyboard
We used a PC keyboard to send UART Commands to the board to navigate the frog around the map instead of a joystick that is integrated in the development board. The baud rate of the UART is set at 57600 Bd.
#### 1-A: Navigating the Frog Up
The user can navigate the frog forward by pressing the 'w' key.

![ezgif com-resize](https://user-images.githubusercontent.com/40522456/57873294-cb11df00-77db-11e9-8729-c8d1ccfdca78.gif)
#### 1-B: Navigating the Frog Down
The user can navigate the frog backward by pressing the 's' key.


![ezgif com-resize (1)](https://user-images.githubusercontent.com/40522456/57873641-cac61380-77dc-11e9-9e56-3a4acab14ac8.gif)
#### 1-C: Navigating the Frog to the Right
The user can navigate the frog to the right by pressing the 'd' key.

![ezgif com-resize (2)](https://user-images.githubusercontent.com/40522456/57873999-969f2280-77dd-11e9-9109-16f2e811a39f.gif)
#### 1-D: Navigating the Frog to the Left
The user can navigate the frog to the left by pressing the 'a' key.

![ezgif com-resize (3)](https://user-images.githubusercontent.com/40522456/57874233-15945b00-77de-11e9-99a1-235fb785b762.gif)
### 2: Pause/Resume option
We used a pushbutton, integrated on the board, to pause/resume the game. The schematic below illustrates the pins and polarity of the pushbutton.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57874754-504ac300-77df-11e9-8014-a0e9579ff909.PNG">
Based on this, we see that P2.12 (the board schematic has a typo – it is not P2.22) can be used to read the state of the pushbutton. If the button is pressed, will we read a '0' value at the pin.

Below are 2 pictures when the user pressess the button to pause or resume the game.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57875211-5e4d1380-77e0-11e9-8694-3d9221219e0b.PNG">
<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57875229-6efd8980-77e0-11e9-9578-ee5d50bcf89d.PNG">

### 3: Insert a Coin Display Screen
Before the user plays the game, the user needed to first insert a coin. This can be done by pressing a pushbutton, integrated on the board. The schematic below illustrates the pins and polarity of the pushbutton.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57878385-e84caa80-77e7-11e9-834d-43667475cbc9.PNG">
Based on this, we see that ** P2.11 ** can be used to read the state of the pushbutton. If the button is pressed, will we read a '0' value at the pin.
Once the button is pressed, the game will automatically begin.
A picture of the display screen is shown below.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57878555-47aaba80-77e8-11e9-8327-5a073531ad7a.PNG">

### 4: Frog touches the Lilly Pad
When the user susscessfully navigates the frog on 1 of the 5 lilly pads, the game will display the text shown below.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57878921-2e563e00-77e9-11e9-83f2-05f08a9e8a0a.PNG">

### 5: Frog touches the Obstacles
If the frog touches the obstacles(eg. Cars, Falls in River, Jumps in Shrubs, etc.), the user will lose a life, and the game will display the text shown below.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57879228-eedc2180-77e9-11e9-8dd7-01c244ce92b2.PNG">

### 6: Enging the game if the User loses all lifes
If the user loses all available lifes to navigate the frog to the 5 lilly pads, the game stopes, and the game will display the text shown below.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57879393-5e521100-77ea-11e9-902d-58182d57bd64.PNG">

### 7: Enging the game if the User navigates the frog to all 5 Lilly Pads
If the user navigates the frog to the 5 lilly pads, the game stopes, and the game will display the text shown below.

<img width="300" alt="Capture" src="https://user-images.githubusercontent.com/40522456/57879567-cbfe3d00-77ea-11e9-9645-42883f3832b5.PNG">

## Video of the Frogger Game
A full video of the Frogger Game using LPC1768 Microntroller Board can be viewed here:                        https://www.youtube.com/watch?v=c1cYdSDzkRU&feature=youtu.be

## Future Work
* Create actual sprites(eg. cars, trucks, logs, and turtles) that look similar to the real objects in the Frogger game.
* Displaying Scores whenever the frog moves towards the top of the screen.
* Moving the cars, logs, and turtles smoother.

# Thank You
## Email: osamaafz@buffalo.edu / osama.afzal96@gmail.com
## Linkedin - https://www.linkedin.com/in/osamaabaali/
