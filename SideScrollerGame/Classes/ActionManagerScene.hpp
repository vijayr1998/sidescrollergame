//
//  ActionManagerScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/21/18.
//

#ifndef ActionManagerScene_hpp
#define ActionManagerScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class ActionManagerScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(ActionManagerScene);
    void callOnce();
    
private:
    cocos2d::Sprite* sprite,*sprite2;
    cocos2d::Label* label;
    bool spritePaused = false;
    cocos2d::Vector<Node*> pausedNodes;
};
#endif /* ActionManagerScene_hpp */
