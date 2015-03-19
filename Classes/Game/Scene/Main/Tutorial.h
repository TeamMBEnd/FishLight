#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "cocos2d.h"
USING_NS_CC;

class Player;

namespace Scenes{

	/*-----------------------------------------------------
	チュートリアル画面生成用クラス
	　ファイル名	Tutorial.h
	 作成者		小林　大峰
	 ------------------------------------------------------*/
	class Tutorial{
	public:
		/*----------------------------------------
			チュートリアル画面を作成
			・枠を作り、アニメーション用の
			　画像は子Nodeに追加
			
			return Sprite* チュートリアル画面
		----------------------------------------*/
		Sprite* createWindow();

		void update(Layer* layer, Player* player);

	};
}
#endif