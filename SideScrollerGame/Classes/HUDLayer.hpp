//
//  HUDLayer.hpp
//  SideScrollerGame
//
//  Created by Vijay Raveendran on 5/2/18.
//

#ifndef HUDLayer_hpp
#define HUDLayer_hpp

#include <stdio.h>
using namespace cocos2d;

class HUDLayer : public cocos2d::Layer
{
private:
    Label *_label;
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HUDLayer);
    
    void numCollectedChanged (int numCollected);
};

#endif /* HUDLayer_hpp */
