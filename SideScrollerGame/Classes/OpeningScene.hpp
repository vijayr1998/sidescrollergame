//
//  OpeningScene.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 4/22/18.
//
//  This will be the menu!
//

#ifndef OpeningScene_hpp
#define OpeningScene_hpp

#include <stdio.h>
#include "cocos2d.h"


class OpeningScene : public cocos2d::Layer {
    
    public:
    
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(OpeningScene);
private:
    cocos2d::Sprite* sprite,*sprite2;
    cocos2d::Label* label;
    bool spritePaused = false;
    cocos2d::Vector<Node*> pausedNodes;
};
#endif /* OpeningScene_hpp */
