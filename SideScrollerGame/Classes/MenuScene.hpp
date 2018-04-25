//
//  Menu.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/24/18.
//

#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
class MenuScene : public cocos2d::Layer {
    
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(MenuScene);
    void buttonOneCallback(Ref* sender);
    void onMenuCloseCallback(Ref* sender);
    void onQuit(cocos2d::CCObject* pSender);
private:
    cocos2d::Sprite* sprite,*sprite2;
    cocos2d::Label* label;
    bool spritePaused = false;
    cocos2d::Vector<Node*> pausedNodes;
};
#endif /* MenuScene_hpp */
