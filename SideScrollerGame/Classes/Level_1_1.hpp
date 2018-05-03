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
#include "HUDLayer.hpp"
#include "BackgroundLayer.hpp"

class Level_1_1 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(Level_1_1);
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
    virtual void update(float delta) override;
    void setPlayerPosition(cocos2d::Point position);
    cocos2d::Point tileCoord(cocos2d::Point pt);
    
private:
    cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char *format, int count);
    static std::map<cocos2d::EventKeyboard::KeyCode,
    std::chrono::high_resolution_clock::time_point> keys;
    cocos2d::TMXTiledMap *background;
    cocos2d::Sequence *jump;
    int xMovement;
    int yMovement;
    cocos2d::Sprite *sprite;
    HUDLayer *_hud;
    int _numCollected;
    cocos2d::TMXLayer *_coin_layer1;
    cocos2d::TMXLayer *_coin_layer2;
};

#endif /* Level_1_1_hpp */
