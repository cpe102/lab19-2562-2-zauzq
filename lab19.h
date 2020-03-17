#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Unit{
		string name;
		string type;		
		int hp;
		int hpmax;
		int atk;
		int def;
		bool guard_on;		
	public:			
		void create(string);
		void showStatus();
		void newTurn();
		int attack(Unit &);
		int beAttacked(int);
		int heal();	
		void guard();
		bool isDead();	
};

void Unit::create(string t){ 
	if(t == "Hero"){
		type = "Hero";
		cout << "Please input your name: ";
		getline(cin,name);
		hpmax = rand()%20+90;
		atk = rand()%5+14;
		def = rand()%3+9;
	}else if(t == "Monster"){
		type = "Monster";
		name = "Monster";
		hpmax = rand()%20+200;
		atk = rand()%5+25;
		def = rand()%3+5;
	}
	hp = hpmax;
	guard_on = false;
}

void Unit::showStatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\tMonster" << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn(){
	guard_on = false;
}

//Write Function Member attack(), beAttacked(), heal(), guard() and isDead() here
int Unit::attack(Unit &target){
	return target.beAttacked(atk);
} 
int Unit:: beAttacked(int oppatk){
	int dmg = oppatk-def;
	if(guard_on == true){
		if(dmg<0) dmg = 0;
		hp = hp-dmg/3;
		return dmg/3;
		}else{
			if(dmg<0) dmg = 0;
			hp = hp-dmg;
			return dmg;
		}
	
	
}
int Unit:: heal(){
	int y=(rand()%20)+10;
	if(hp==hpmax){
		y=0;
		return y;
	}
	if(hp+y>=hpmax) {
		int i=hpmax-hp;
		hp=hpmax;
		return i;
	}else{
		hp=hp+y;
		return y;
	}

}
void Unit :: guard(){
	guard_on = true;
}
bool Unit :: isDead(){
	if(hp>0) return false;
	else return true;
}

void drawScene(char p_action,int p,char m_action,int m){
	cout << "                                                       \n";
	if(p_action == 'A'){
	cout << "                                       "<< -p <<"\n";
	}else{
	cout << "                                                       \n";	
	}	
	cout << "                                *               *      \n";
	cout << "                                *  ********  **      \n";
	cout << "                                **         **      \n";
	if(m_action == 'A'){
	cout << "                 " << setw(5) << -m << "           * *   * *       Attack!\n";
	}else if(m_action == 'G'){
	cout << "                                 * *   * *       Guard!\n";
	}else{
	cout << "                                 * *   * *       \n";	
	}
	cout << "                                  * *   * *        \n";
	cout << "                   *             *         *         \n";
	if(p_action == 'A'){
	cout << "        Attack!    *  *           *******          \n";		
	}else if(p_action == 'H'){
	cout << "      Heal! +" << setw(2) << p << "    *  *           *******          \n";
	}else if(p_action == 'G'){
	cout << "         Guard!    *  *           *******          \n";
	}else{
	cout << "                   *  *           *******          \n";	
	}
	cout << "                    *  *       *  *  *  *            \n";
	cout << "                  ***           **   *   *           \n";
	cout << "                    *                  *    *        \n";
	cout << "                   * *               **        *       \n";
	cout << "                  *   *                                \n";
	cout << "                                                       \n";
};


void playerWin(){	
	cout << "*******************************************************\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


void playerLose(){
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};