//
//  KeyboardScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/20/18.
//

#ifndef KeyboardScene_hpp
#define KeyboardScene_hpp

#pragma once
#include <stdio.h>

class KeyboardScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene *createScene();
    virtual bool init();
    
    //Cocos is only event-driven; no polling can be done. This is a workaround.
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);
    
    CREATE_FUNC(KeyboardScene);
    
private:
    static std::map<cocos2d::EventKeyboard::KeyCode,
    std::chrono::high_resolution_clock::time_point> keys;
    cocos2d::Label * label;
public:
    virtual void update(float delta) override;
    
};

#endif /* KeyboardScene_hpp */
