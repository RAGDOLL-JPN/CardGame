#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

//カードの種類
enum CardType
{
    Clubs = 0,
    Diamonds,
    Hearts,
    Spades
};

//カード
struct Card
{
    int number;
    CardType type;
};

//カードを表示する位置
struct PosIndex
{
    int x;
    int y;
};

class CardSprite : public cocos2d::Sprite
{
protected:
    std::string getFileName(CardType cardType);     // 表画像ファイル名取得
    void showNumber();                              // カードのマークと数字を表示
    
public:
    virtual bool init();                            // 初期化処理
    void onEnter() override;                        // 表示前処理
    CREATE_FUNC(CardSprite);                        // create関数作成マクロ
    
    CC_SYNTHESIZE(Card, _card, Card);               // カード情報
    CC_SYNTHESIZE(PosIndex, _posIndex, PosIndex);   // 表示位置
    
    void moveBackToInitPos();                       // 元の位置に移動する
    void moveToTrash();                             // カードを捨てる
    void moveToInitPos();                           // 最初の位置に移動する
};

class HelloWorld : public cocos2d::Layer
{
protected:
    std::vector<Card> _cards;                           // カード情報
    CardSprite* _firstCard;                             // 最初にタップされたカード
    
    void initCards();                                   // カードを初期化する
    Card getCard();                                     // カードを取得する
    void createCard(PosIndex posIndex);                 // カードを作成する
    void showInitCards();                               // ゲーム開始時にカードを10枚表示する
    void initGame();                                    // ゲームを初期化する
    CardSprite* getTouchCard(cocos2d::Touch *touch);    // タップされたカード取得
    void showButton();                                  // ボタンを表示する
    void initTrash();                                   // ゴミカードを初期化する
    void onTapButton(cocos2d::Ref* sender,
                     cocos2d::extension::Control::EventType controlEvent);    // ボタンがタップされたときに呼ばれる
    void showBackCards();                               // カードの山を表示する
    
public:
    //HelloWorldクラスのシーンを作成する
    static cocos2d::Scene* createScene();
    
    //初期化処理を行う
    virtual bool init();
    
    //create関数作成マクロ
    CREATE_FUNC(HelloWorld);
    
    // タップイベント
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif // __HELLOWORLD_SCENE_H__