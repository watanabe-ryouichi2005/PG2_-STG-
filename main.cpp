#include <Novice.h>
#include "Enemy.h"
#include"Player.h"
#include"Bullet.h"
const char kWindowTitle[] = "GC1D_ワタナベ_リョウイチ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	
	Player* player = new Player;

	Enemy* enemy = new Enemy;
	enemy->initalize();
	
	enum Scene 
	{title,game,gg,gc

	};
	Scene scene = game;
	 

	// ウィンドウの×  ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene)
		{
		case title:
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffff00ff, kFillModeSolid);
			if (keys[DIK_RETURN]) {
				scene = game;

			}


			break;
		case game:
			
			enemy->Update();
			
			player->Update(keys,preKeys);
		





			enemy->Draw();
			 
			player->Draw();
			break;
		case gg:


			break;
		case gc:


			break;
		default:
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	delete player,enemy;
	
	return 0;
}
