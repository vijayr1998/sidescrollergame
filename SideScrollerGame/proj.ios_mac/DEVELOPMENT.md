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
4. Did code cleanup. 

### Menu Screen Progress:

1. Wrote and tested a quit button for my menu. Unfortunately, it is by using deprecated code.
2. Wrote "Start Game" and "Settings".
3. Tried writing a new class in MenuScene.cpp for the About Me Page, but it isn't working. I will probably have to create new files for that. :(

### To-do: 

1. Figure out how I will write levels!

## Update 4/26: 

### Level 1 Progress: 

1.  Started working on actual levels for the game. 
2. Going to learn how to use sprite sheets so I can efficiently create the levels and player character. 
3. Created a sprite sheet for batch drawing sprites using TexturePacker.
4. Got files from: http://kenney.nl/assets/platformer-art-deluxe and https://raventale.itch.io/nature-tile-set
5. Running into problems creating the animation because I don't know how to call each file for walking. 
6. Properly created animation and found batch file. 
7. Created the movement. Have to figure out to make movement on key holds, not just indivdual presses. 

## Update 4/27:

### Level 1 Progress:

1.  Trying to adapt KeyboardScene code to Level 1-1.
2. Trying to fix direction sprite faces when going left or right. 
3. Have to start loading in floors and platforms. 
4. The tilemap loader is not finding the tilemap I created. 
5. Got level to load, but it isn't appearing in game. 
6. Got tilemap to appear, but it isn't correct size and is anchored to player sprite instead of being still, so the bg moves with the character, which is bad. 
7. Did a temp fix of size by scaling it 1.25x, but tileset is exact res of screen, so this shouldn't have been a problem. 
8. Still have to write in jump and duck, and move on key hold as well as press.

### Apps Used:

1. TexturePack
2. Tiled

## Update 4/28:

### Issues:

1. Background anchoring.
2. Key polling. 
3. Bg sizing. 

### Progress:

1. None apparently.

## Update 4/30:

1.  Might have to give up on having multiple scenes once we go off the screen. I cannot seem to fix the issue of the background moving with the sprite.
2. I am going to implement infinite parallax and have an extremely long background. 
