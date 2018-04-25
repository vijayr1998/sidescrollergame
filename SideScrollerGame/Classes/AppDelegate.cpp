#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GraphicsScene.hpp"
#include "TouchScene.hpp"
#include "MouseScene.hpp"
#include "KeyboardScene.hpp"
#include "ActionsScene.hpp"
#include "ActionManagerScene.hpp"
#include "OpeningScene.hpp"
#include "MenuScene.hpp"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

//Previous default window size
//static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);

/**
 * Default window size is too small for any reasonbly sized sprite.
 * 1080p offers enough real estate for me to work with.
 * However, I may change the aspect ratio to something less widescreen to make levels less long.
 * Changed to 2048x1536 as per https://www.codeandweb.com/blog/2015/12/15/animations-and-spritesheets-in-cocos2d-x
 * This is for simplicity using spritesheets
 */
//static cocos2d::Size designResolutionSize = cocos2d::Size(2048, 1536);
static cocos2d::Size designResolutionSize = cocos2d::Size(1680, 1030);
static cocos2d::Size smallResolutionSize = cocos2d::Size(512, 384);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    cocos2d::GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = cocos2d::Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = cocos2d::GLViewImpl::createWithRect("SideScrollerGame", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("SideScrollerGame");
#endif
        director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);
    
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
    
    register_all_packages();
    
    // create a scene. it's an autorelease object
    
    /**
    Displays the opening screen.
    auto scene = HelloWorld::createScene();
    
    Displays an image.
    auto scene2 = GraphicsScene::createScene();
    
    Gives info on where I clicked
    auto scene3 = TouchScene::createScene();
    
    A mouse Listener
    auto scene4 = MouseScene::createScene();
    
    A keyboard listener
    auto scene5 = KeyboardScene::createScene();
    
    Using actions to update, pause, etc.
    auto scene6 = ActionsScene::createScene();
    
    Using ActionManager to control actions:
    auto scene7 = ActionManagerScene::createScene();
    */
    
    //Starts game
    auto beginGame = OpeningScene::createScene();
    
    auto menuScreen = MenuScene::createScene();
    
    
    // run
    director->runWithScene(beginGame);
    //director->runWithScene(menuScreen);
    
    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    cocos2d::Director::getInstance()->stopAnimation();
    
#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    cocos2d::Director::getInstance()->startAnimation();
    
#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
