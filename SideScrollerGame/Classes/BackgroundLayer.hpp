//
//  BackgroundLayer.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/30/18.
//

#ifndef BackgroundLayer_hpp
#define BackgroundLayer_hpp

#include <stdio.h>
#include "cocos2d.h"

class BackgroundLayer: public cocos2d::Layer
{
public:
    static cocos2d::Scene* scene();
    virtual bool init() override;
    CREATE_FUNC(BackgroundLayer);
private:
    cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char *format, int count);
    static std::map<cocos2d::EventKeyboard::KeyCode,
    std::chrono::high_resolution_clock::time_point> keys;
    cocos2d::TMXTiledMap *background;
};
#endif /* BackgroundLayer_hpp */
