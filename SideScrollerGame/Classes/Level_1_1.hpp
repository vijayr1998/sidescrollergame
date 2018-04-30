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
    virtual bool init() override;
    CREATE_FUNC(Level_1_1);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
    void setViewPointCenter(cocos2d::Point position);
    virtual void update(float delta) override;
    
private:
    cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char *format, int count);
    static std::map<cocos2d::EventKeyboard::KeyCode,
    std::chrono::high_resolution_clock::time_point> keys;
    cocos2d::TMXTiledMap *background;
};
#endif /* Level_1_1_hpp */
