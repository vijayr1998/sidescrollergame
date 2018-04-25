#  A running log of my progress 

## Progress so far 

1. Learning how to use the cocos2d-x library to build a simple side scrolling game. 
2. I have learned how to use sprites, images that will be my main character. 
3. I have learned about scenes, which are distinct parts of my game. 
4. I have learned about actions, which I will use to simulate enemies. 
5. I have learned how to update in the background. 

## What I have to do

1. I still have to learn how to build levels, how to progress through a level, or how to use infinite scroll. 
2. I have to learn how to use gravity.
3. I have to learn how to do collisions to kill enemies. If no time, I will only code collecting items.
4. I have to decide how to implement my player character, and whether I can have different sprites for jump, crouch, and lateral movement. 


## Update 4/21: I understand how different levels work. 

### http://www.cocos2d-x.org/docs/cocos2d-x/en/basic_concepts/scene.html

### Reasonably confident I can implement all the features I want.  What I need to do is clean up all the example code I've been working with and start writing my own. I will have to create a new branch for the actual development of the game and go from there. 

## Update 4/24:

### Finished opening scene

1. Created two sprites that should jump together when enter is pressed.
2. Created a Name Label and text that prompts the user to press ENTER to continue.
3. Fixed an issue where only one of the sprites would jump.
4. Fixed the issue of the background image not filling the entire screen by intializing the image later instead of in the constructor. 
5. Upgraded the sprites to be drawn with many polygons to decrease load. 

### Next step is the menu scene, after I learn how to transition between scenes.

### Menu Scene Progress:

1. Had to call files MenuScene, "menu" was throwing ambiguous reference errror. 
2. Considering merging menu code into OpeningScene, no need for separate scene.

## Update 4/25:

1. Have to figure out how to transition screens. 
2. Have to figure out how to use new code, not deprecated code. 
3. Wrote code to transition from opening screen to menu screen.

### Menu Screen Progress:

1. Wrote and tested a quit button for my menu. Unfortunately, it is by using deprecated code.
2. Wrote "Start Game" and "Settings".
