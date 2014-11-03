#include "HelloWorldScene.h"
#include <random>

#define CARD_NUM 13         // 1種類あたりのカード枚数
#define CARD_TYPE_NUM 4     // カードの種類

#define CARD_1_POS_X 200    // 1番のカード位置（x）
#define CARD_1_POS_Y 320    // 1番のカード位置（y）
#define CARD_DISTANCE_X 140 // カード間の距離（x方向）
#define CARD_DISTANCE_Y 200 // カード間の距離（y方向）

#define ZORDER_SHOW_CARD 1  // 表示しているカードのzオーダー

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // シーンを生成する
    auto scene = Scene::create();
    
    // HelloWorldクラスのレイヤーを生成する
    auto layer = HelloWorld::create();
    
    // シーンに対してレイヤーを追加する
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

bool HelloWorld::init()
{
    if (!Layer::init()) {
        return false;
        
    }
    
    // カードを表示する
    showInitCards();
    
    return true;
}


void HelloWorld::initCards()
{
    // ゲームカードのクリア
    _cards.clear();
    
    // 4種類　×　13枚分のループ
    for (int type = 0; type < CARD_NUM; type++) {
        for (int number = 1; number <= CARD_NUM; number++) {
        
            // カード情報の作成
            Card card;
            card.number = number;
            card.type = (CardType)type;
        
            // カードを追加する
            _cards.push_back(card);
        }

    }
}


Card HelloWorld::getCard()
{
    std::random_device rd;
    std::mt19937 rand = std::mt19937(rd());
    
    // インデックスをランダムに取得する
    int index = std::uniform_int_distribution<int>(0, (int)_cards.size() - 1)(rand);
    
    // カードの数値を取得する
    auto card = _cards[index];
    
    // 一時カードから削除する
    _cards.erase(_cards.begin() + index);
    
    return card;
}

void HelloWorld::createCard( PosIndex posIndex )
{
    // 新しいカードを作成する
    auto card = Sprite::create( "card_spades.png" );
    card->setPosition( CARD_1_POS_X + CARD_DISTANCE_X * posIndex.x, CARD_1_POS_Y + CARD_DISTANCE_Y * posIndex.y );
    addChild( card, ZORDER_SHOW_CARD );
}

void HelloWorld::showInitCards()
{
    for (int tag = 1; tag <= 10; tag++) {
        
        auto card = getChildByTag(tag);
        if (card) {
            
            // カードが残っている場合は、削除する
            card->removeFromParent();
        }
    }
    
    // ５列　×　2行分のループ
    for (int x = 0; x < 5; x++) {
        
        for (int y = 0; y < 2; y++) {
            
            PosIndex posIndex;
            posIndex.x = x;
            posIndex.y = y;
            
            // カードの生成
            createCard(posIndex);
        }
    }
}

void HelloWorld::initGame()
{
    // カードを初期化する
    initCards();
    
    // カードを表示する
    showInitCards();
}