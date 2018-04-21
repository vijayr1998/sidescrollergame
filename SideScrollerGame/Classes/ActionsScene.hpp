//
//  ActionsScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/20/18.
//

#ifndef ActionsScene_hpp
#define ActionsScene_hpp
#pragma once
#include <stdio.h>

#include "cocos2d.h"

class ActionsScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool initWithColor();
    CREATE_FUNC(ActionsScene);
    
    //void update(float) override;
    
private:
    cocos2d::Sprite* sprite;
};
#endif /* ActionsScene_hpp */
