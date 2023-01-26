#include <bits/stdc++.h>
using namespace std;
#include "main.h"
int main() {
	using namespace Basic;
	using namespace Player;
	cout<<"本游戏由HelloWorld制作，喜欢的话到Github给个Star吧"<<endl;
	int nump=getInt("请输入玩家人数(2-10)：",2,10);
	cout<<"请依次输入玩家名称，一行一个："<<endl;
	for(int i=0;i<nump;i++) {
		string s;
		getline(cin,s);
		initPlayer(players[i],s);
	}
	auto manghe=[&](int i){
		cout<<players[i].name;
		int t=rand(0,3);
		cout<<"获得了"<<blindbox[t]<<"加成10";
		openbox(players[i],t);
		cout<<endl;
	};
	while(1) {
		cout<<"开盲盒："<<endl;
		for(int i=0;i<nump;i++) {
			manghe(i);
			PlayerInfo &t=players[i];
			showPlayer(t);
		}
		system("pause");
//		system("cls");
		cout<<endl<<endl;
		cout<<"开始攻击"<<endl;
		for(int i=0;i<nump;i++) {
			int t=rand(0,nump);
			while(t==i) {
				t=rand(0,nump);
			}
			cout<<players[i].name<<"向"<<players[t].name<<"发起了攻击"<<endl;
			showPlayer(players[i]);
			showPlayer(players[t]);
			cout<<players[i].name<<"的攻击力为"<<players[i].attack<<endl;
			cout<<players[t].name<<"的防御力为"<<players[t].defense<<endl;
			cout<<"造成了"<<max(0,players[i].attack-players[t].defense)<<"点伤害"<<endl;
			gongji(players[i],players[t]);
		}
		system("pause");
//		system("cls");
		cout<<endl<<endl;
	}
	return 0;
}
