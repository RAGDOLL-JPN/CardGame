#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

// カードの種類
enum CardType {
    
    Clubs = 0,
    Diamods,
    Hearts,
    Spades
};

// カード
struct Card {
    
    int number;
    CardType type;
};

// カードを表示する位置
struct PosIndex {
    
    int x;  // カードのx座標
    int y;  // カードのy座標
};

class HelloWorld : public cocos2d::Layer {

protected:
    std::vector<Card> _cards;    // カード情報
    
    void initCards();                       // カードを初期化する
    Card getCard();                         // カードを取得する
    void createCard(PosIndex posIndex);     // カードを作成する
    void showInitCards();                   // ゲーム開始時にカードを10枚表示する
    void initGame();                        // ゲームを初期化する
public:
    // HelloWorldクラスのシーンを作成する
    static cocos2d::Scene* createScene();
    
    // 初期化処理を行う
    virtual bool init();
    
    // create関数作成マクロ
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__