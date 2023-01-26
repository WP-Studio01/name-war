#ifndef MAIN_H_
#define MAIN_H_

const string blindbox[3] = {"blood","defense","attack"};
namespace Basic {
	inline int rand(int a,int b) {
		return (::rand() % (b-a) + a);
	}
	int getInt(string s,int minn,int maxn) {
		int a;
		do {
			cout<<s;
			cin>>a;
		} while(a<minn || a>maxn);
		cin.get();
		return a;
	}
	void wait(int ms) {
		int ltime=clock();
		while(clock()-ltime>=ms);
	}
}
namespace Player {
	/*
	struct BuffInfo {
		string name;
		string type;
		int rate;
	};
	*/
	struct PlayerInfo {
		string name;
		int blood;
		int defense;
		int attack;
//		vector<BuffInfo> attackbuff;
	};
	void initPlayer(PlayerInfo &p,string name) {
		p.name=name;
		p.blood=100;
		p.defense=0;
		p.attack=5;
	}
	void openbox(PlayerInfo &p,int t) {
		switch(t) {
			case 0: {
				p.blood+=10;
				break;
			}
			case 1: {
				p.defense+=10;
				break;
			}
			case 2: {
				p.attack+=10;
				break;
			}
		}
	}
	void gongji(PlayerInfo &me,PlayerInfo &that) {
		that.blood-=max(0,me.attack-that.defense);
	}
	void showPlayer(PlayerInfo &t) {
		cout<<t.name<<"的目前状况是：血量"<<t.blood<<"，防御"<<t.defense<<"，攻击"<<t.attack<<endl;
	}
}
Player::PlayerInfo players[10];

#endif
