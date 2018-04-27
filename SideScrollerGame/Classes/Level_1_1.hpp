//
//  Level 1-1.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/26/18.
//

#ifndef Level_1_1_hpp
#define Level_1_1_hpp

#include <stdio.h>
#include "cocos2d.h"

class Level_1_1 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Level_1_1);
    
private:
    cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char *format, int count);
    
};
#endif /* Level_1_1_hpp */
