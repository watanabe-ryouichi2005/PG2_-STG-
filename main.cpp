#include <Novice.h>
#include "Enemy.h"
#include"Player.h"
#include"Bullet.h"
const char kWindowTitle[] = "GC1D_ワタナベ_リョウイチ";

int Collision(Tranceform obje1, Tranceform obje2, int obje1radius_, int obje2radius) {
	if (obje1.x - obje1radius_ <= obje2.x + obje2radius && obje2.x <= obje1.x + obje1radius_ &&
		obje1.y - obje1radius_ <= obje2.y + obje2radius && obje2.y <= obje1.y + obje1radius_)
	{
		return 1;
	}
	return 0;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player;
	//Bullet* bullet = new Bullet;
	Enemy* enemy = new Enemy;
	//Enemy* enemy_ = new Enemy;
	enemy->initalize();
	//enemy->SetisAlive(0);
	//enemy->Settimer(0);
	//enemy->Settimer(100);
	Scene scene = title;


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
			player->Setpos({ 500,550 });
			enemy->Setpos({ 640,150 });
			enemy->SetHp(3);
			player->tmpisshot = 0;
			player->bullet->Setballet(player->tmpisshot);
			
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffff00ff, kFillModeSolid);
			if (keys[DIK_RETURN]) {
				scene = game;

			}
			Novice::ScreenPrintf(0, 0, "PushToEnter");

			break;
		case game:

			if (Collision(enemy->Getpos(), player->bullet->Getpos(), enemy->Getradius(), player->bullet->Getradius())) {
				enemy->SetisAlive(0);
			}
				enemy->OnCollision(scene);
			if (Collision(enemy->Getpos(), player->Getpos(), enemy->Getradius(), player->Getradius())) {
				scene = go;


			}
			/*if (enemy->SetHp(0)) {
				scene = gc;
			}*/



			/*if( Collision ) {

				scene = gg;

				}*/


			enemy->Update();

			player->Update(keys, preKeys);




			enemy->Draw();

			player->Draw();
			//Novice::ScreenPrintf(0, 0, "timerHp%d", enemy->SetHp(3));
			Novice::ScreenPrintf(0, 50, "isAlive%d", enemy->GetisAlive());
			break;
		case go:
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, RED, kFillModeSolid);
			Novice::ScreenPrintf(0, 0, "PushToEnter");
			if (keys[DIK_RETURN]) {
				scene = title;


			}
			break;
		case gc:
			Novice::ScreenPrintf(0, 0, "PushToEnter");
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLUE, kFillModeSolid);
			if (keys[DIK_RETURN]) {
				scene = title;
				

			}


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
	delete player, enemy;

	return 0;
}
