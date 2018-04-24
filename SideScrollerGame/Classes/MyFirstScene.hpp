//
//  MyFirstScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/22/18.
//
//  This will be the menu!
//

#ifndef MyFirstScene_hpp
#define MyFirstScene_hpp

#include <stdio.h>
#include "cocos2d.h"


class MyFirstScene : public cocos2d::Layer {
    
    public:
    
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(MyFirstScene);
    void callOnce();
    
private:
    cocos2d::Sprite* sprite,*sprite2;
    cocos2d::Label* label;
    bool spritePaused = false;
    cocos2d::Vector<Node*> pausedNodes;
};
#endif /* MyFirstScene_hpp */
