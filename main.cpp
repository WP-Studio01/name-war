#include <bits/stdc++.h>
using namespace std;
#include "main.h"
int main() {
	using namespace Basic;
	using namespace Player;
	cout<<"����Ϸ��HelloWorld������ϲ���Ļ���Github����Star��"<<endl;
	int nump=getInt("�������������(2-10)��",2,10);
	cout<<"����������������ƣ�һ��һ����"<<endl;
	for(int i=0;i<nump;i++) {
		string s;
		getline(cin,s);
		initPlayer(players[i],s);
	}
	auto manghe=[&](int i){
		cout<<players[i].name;
		int t=rand(0,3);
		cout<<"�����"<<blindbox[t]<<"�ӳ�10";
		openbox(players[i],t);
		cout<<endl;
	};
	while(1) {
		cout<<"��ä�У�"<<endl;
		for(int i=0;i<nump;i++) {
			manghe(i);
			PlayerInfo &t=players[i];
			showPlayer(t);
		}
		system("pause");
//		system("cls");
		cout<<endl<<endl;
		cout<<"��ʼ����"<<endl;
		for(int i=0;i<nump;i++) {
			int t=rand(0,nump);
			while(t==i) {
				t=rand(0,nump);
			}
			cout<<players[i].name<<"��"<<players[t].name<<"�����˹���"<<endl;
			showPlayer(players[i]);
			showPlayer(players[t]);
			cout<<players[i].name<<"�Ĺ�����Ϊ"<<players[i].attack<<endl;
			cout<<players[t].name<<"�ķ�����Ϊ"<<players[t].defense<<endl;
			cout<<"�����"<<max(0,players[i].attack-players[t].defense)<<"���˺�"<<endl;
			gongji(players[i],players[t]);
		}
		system("pause");
//		system("cls");
		cout<<endl<<endl;
	}
	return 0;
}
