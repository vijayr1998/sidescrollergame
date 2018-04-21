//
//  MouseScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/20/18.
//

#ifndef MouseScene_hpp
#define MouseScene_hpp

#pragma once
#include <stdio.h>
#include "cocos2d.h"

class MouseScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene *createScene();
    virtual bool init();
    CREATE_FUNC(MouseScene);
};

#endif /* MouseScene_hpp */
