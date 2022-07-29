#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;

struct parameter//変数をまとめたクラス
{
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//問題の番号
    int stage = 0;//出題した問題の数
    string answer;//問題の答え
    int point = 0;//獲得ポイント
    int score = 0;//総合得点
};

parameter status;

void game()//問題を出題する関数
{
    cout << "\n第" << status.stage + 1 << "問\n";

    switch (status.vec[status.stage])
    {
    case 1:
        cout << "「あいうえお(aiueo)」\n";
        status.answer = "aiueo";
        break;
    case 2:
        cout << "「東京都立大学(toukyoutoritudaigaku)」\n";
        status.answer = "toukyoutoritudaigaku";
        break;
    case 3:
        cout << "「システムデザイン学部(sisutemudezainngakubu)」\n";
        status.answer = "sisutemudezainngakubu";
        break;
    case 4:
        cout << "「墾田永年私財法(konndenneinennsizaihou)」\n";
        status.answer = "konndenneinennsizaihou";
        break;
    case 5:
        cout << "「モンゴリアンデスワーム(monngorianndesuwa-mu)」\n";
        status.answer = "monngorianndesuwa-mu";
        break;
    case 6:
        cout << "「セミの抜け殻(seminonukegara)」\n";
        status.answer = "seminonukegara";
        break;
    case 7:
        cout << "「エビフライのしっぽ(ebihurainosippo)」\n";
        status.answer = "ebihurainosippo";
        break;
    case 8:
        cout << "「塩レモン(sioremonn)」\n";
        status.answer = "sioremonn";
        break;
    case 9:
        cout << "「カルピスの原液(karupisunogenneki)」\n";
        status.answer = "karupisunogenneki";
        break;
    case 10:
        cout << "「油取り紙(aburatorigami)」\n";
        status.answer = "aburatorigami";
        break;
    default:
        break;
    }

    cout << "\nアルファベットでタイピングしてEnterを押してくださいワン。\n";

    auto tp2 = chrono::system_clock::now();
    auto duration2 = tp2.time_since_epoch();
    auto ms2 = chrono::duration_cast<chrono::milliseconds>(duration2).count();//問題開始時間

    string input;
    cin >> input;

    auto tp3 = chrono::system_clock::now();
    auto duration3 = tp3.time_since_epoch();
    auto ms3 = chrono::duration_cast<chrono::milliseconds>(duration3).count();//問題終了時間

    status.point = 1000000/(ms3-ms2);//問題開始時間と終了時間の差が小さいほど得点が上がる

    if (input == status.answer)
    {
        status.score += status.point;
        cout << "\n正解だワン！！！　" << status.point << "ポイント獲得だワン。 Score:" << status.score << "\n";
    }
    else
    {
        cout << "不正解ですワン…　0ポイント獲得ですワン。 Score:" << status.score << "\n";
    }

    status.stage++;

    if (status.stage <= 4)//５問出題するまで出題し続ける
    {
        game();
    }
    else
    {
        cout << "\n　　　　,-'''ﾞ￣”￣”`'',, \n　　 ／　　　　　　　 ヾ, /⌒)\n　／　　i　 ●　 　●　i /　/ﾞ\n/ﾞ　　　l ´　(　_▼_)｀ﾉ　/　";
        cout << "総合得点：" << status.score << "\n";
        cout << "丶,＿,,/丶_　  |∪|　　 ,ノ　　　 ";
        if (status.score >= 1000)
        {
            cout << "評価：A\n　_　/ ＿_,　  ヽノ 　/　　　";
            cout << "(最高評価ですワン…)\n";
        }
        else if (status.score >= 700)
        {
            cout << "評価：B\n　_　/ ＿_,　  ヽノ 　/　　　";
            cout << "(Aランクまであと" << 1000 - status.score << "ポイントですワン…)\n";
        }
        else if (status.score >= 400)
        {
            cout << "評価：C\n　_　/ ＿_,　  ヽノ 　/　　　";
            cout << "(Bランクまであと" << 700 - status.score << "ポイントですワン…)\n";
        }
        else
        {
            cout << "評価：D\n　_　/ ＿_,　  ヽノ 　/　　　";
            cout << "(Cランクまであと" << 400 - status.score << "ポイントですワン…)\n";
        }
        cout << "（　(＿＿,）　　　　 /\n";
    }
}

void startscene()//ゲームを始めるための関数
{
    cout << "タイピングゲーム\n    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n   |全５問。早く打つほど高得点だワン。　　　　　|\n   |「s」を入力してEnterを押すと開始しますワン。|\n    ━━ ｖ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n　　　　　　　　 ＿＿＿＿\n　　　　　　　／　　　　　　＼\n　　　　　　/●　　●　　　　 ＼\n　　　　 ／　　　　　　　　 Y　Y| \n　　　　| ▼　　　　　　　　|　 | | \n　　　　|_人＿　　 　　　　 ＼／” ＼．\n　　　　　＼＿　　　　　　　”　　　　＼\n　　　　　　　　|”　　　””　　 　　　＼\n　　　　　　　　|　　　　　　　　　　　　　＼\n　　　　　　　　|　　　　　　　　　　　　　　 ｜ \n　　　　　　　　＼　　|　　　　　　　　　　　　 ｜ \n　　　　　　　　　 |＼　|　　　　　/　　　　　　　｜ \n　　　　　　　　　｜　＼|　　　　/　/　　　　　　　| \n　　　　　　　　　｜　｜/|　　　|　 |　　　　　　　　| \n　　　　　　　　　｜　｜|｜　　|　　|　　　　　　　　|＿／￣￣/ \n　　　　　　　　／　　 | ＼|　　|　　 ＼　　　　　　|＼＿＿_／\n　　　　　　　（（（__|　（（（__|-（（￣￣　　　_／\n";
    string title;
    cin >> title;
    if (title == "s")
    {
        game();
    }
}

int main()
{
    auto tp = chrono::system_clock::now();
    auto duration = tp.time_since_epoch();
    auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count();
    mt19937 get_rand_mt(ms);//問題をシャッフルするためのランダム要素
    shuffle(status.vec.begin(), status.vec.end(), get_rand_mt);//ここで出題する問題をシャッフルする
    startscene();
}
