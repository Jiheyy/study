#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


/*
빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 
빨간 구슬을 구멍을 통해 빼내는 게임이다.

파란 구슬이 구멍에 들어가면 안 된다.
중력을 이용해서 이리 저리 굴려야 한다. 
왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기

공은 동시에 움직인다. 
빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다.

기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.


최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오. (BFS)
*/

struct TURN {
	int by, bx, ry, rx; // 위치
	int sec;
};


// y, x
int n, m, answer;
int blank_y, blank_x;

vector <string> arr;

/*
TURN set_turn(vector <string> arr, int sec) {

	TURN res;
	res.sec = sec;

	for(int i=0; i<arr.size(); i++)
		for(int j=0; j<arr[0].size(); j++) {
			if(arr[i][j] == 'R') {
				res.ry = i;
				res.rx = j;
			}
			else if(arr[i][j] == 'B') {
				res.by = i;
				res.bx = j;
			}

			else if(arr[i][j] != '#' && arr[i][j] != '.') {
				res.blank_y = i;
				res.blank_x = j;
			}
		}
	return res;
}
*/
// 왼쪽으로 기울이기
TURN left(TURN turn) {
	vector <string> arr = turn.arr;
	bool game_end = false;

	for(int i=1; i<arr.size()-1; i++) {
		for(int j=1; j<arr[0].size()-1; j++) {
			int move = 0;

			if(arr[i][j] != 'R' & arr[i][j] != 'B')
				continue;

			while(true) {
				move++;

				if(i == turn.blank_y && j+move == turn.blank_x) {	
					move--;
					game_end = true;
					break;
				}

				if (arr[i][j-move] != '.') {
					move--;
					break;
				}
			}
			if(move > 0) {
				arr[i][j-move] = arr[i][j];
				arr[i][j] = '.';
			}
		}
	}

	TURN next_turn = set_turn(arr, turn.sec+1);

	if(game_end) {
		next_turn.last = true;
	}

	return next_turn;
}


// 아래로 기울이기 // gravity
TURN down(TURN turn) {

	vector <string> arr = turn.arr;
	bool game_end = false;

	for(int i=1; i<arr[0].size()-1; i++) {
		for(int j=arr.size()-2; j>0; j--) {
			
			if(arr[i][j] != 'R' & arr[i][j] != 'B')
				continue;

			int move = 0;
			while(true) {
				move++;

				// game end
				if(i == turn.blank_y && j+move == turn.blank_x) {	
					move--;
					game_end = true;
					break;
				}

				if (arr[i+move][j] != '.') {
					move--;
					break;
				}
			}

			if(move > 0) {
				arr[i+move][j] = arr[i][j];
				arr[i][j] = '.';
			}
		}
	}

	TURN next_turn = set_turn(arr, turn.sec+1);
	if(game_end) {
		next_turn.last = true;
	}
	return next_turn;
}


TURN up(TURN turn) {
	
	vector <string> arr = turn.arr;
	bool game_end = false;

	for(int i=1; i<arr[0].size()-1; i++) {
		for(int j=1; j<arr.size()-1; j++) {
			int move = 0;

			if(arr[i][j] != 'R' & arr[i][j] != 'B')
				continue;

			while(true) {
				move++;
				// game end
				if(i == turn.blank_y && j+move == turn.blank_x) {	
					move--;
					game_end = true;
					break;
				}
				if (arr[i-move][j] != '.') {
					move--;
					break;
				}
			}
			if(move > 0) {
				arr[i-move][j] = arr[i][j];
				arr[i][j] = '.';
			}
		}
	}

	TURN next_turn = set_turn(arr, turn.sec+1);
	if(game_end) {
		next_turn.last = true;
	}
	return next_turn;
}


TURN right(TURN turn) {

	vector <string> arr = turn.arr;
	bool game_end = false;

	for(int i=1; i<arr.size()-1; i++) {
		for(int j=1; j<arr[0].size()-1; j++) {
			int move = 0;

			if(arr[i][j] != 'R' && arr[i][j] != 'B')
				continue;

			while(true) {
				move++;
				// game end
				if(i == turn.blank_y && j+move == turn.blank_x) {	
					move--;
					game_end = true;
					break;
				}
				

				if (arr[i][j+move] != '.') {
					move--;
					break;
				}
			}
			if(move > 0) {
				arr[i][j+move] = arr[i][j];
				arr[i][j] = '.';
			}
		}
	}

	TURN next_turn = set_turn(arr, turn.sec+1);

	if(game_end) {
		next_turn.last = true;
	}

	return next_turn;
}



// check wheather game is continue or not
bool success_checker(TURN turn) {
	// game end
	if (turn.blank_y == turn.by && turn.blank_x == turn.bx)
		return false;

	// it can be continue
	return true;
}



void BFS() {

	queue <TURN> q;
	TURN game = set_turn(arr, 0);
	q.push(game);

	while(!q.empty()) {
		TURN cur = q.front();
		q.pop();

		if(cur.last == true) {
			answer = cur.sec;
			return;
		}
		printf("--------------\n");
		for(int i=0; i<cur.arr.size(); i++) {
			for(int j=0; j<cur.arr[0].size(); j++)
				printf("%c ", cur.arr[i][j]);
			printf("\n");
		}
		

		// check 
		if (cur.blank_y == cur.ry && cur.blank_x == cur.rx) {
			answer = cur.sec;
			return;
		}

		if(cur.sec > 10) {
			answer = -1;
			return;
		}
		
		TURN next_turn;

		//왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기
		
		next_turn = left(cur);
		if (success_checker(next_turn))
			q.push(next_turn);
		
		next_turn = right(cur);
		if (success_checker(next_turn))
			q.push(next_turn);
		
		
		next_turn = up(cur);
		if (success_checker(next_turn))
			q.push(next_turn);

		next_turn = down(cur);
		if (success_checker(next_turn))
			q.push(next_turn);
		
	}

}


int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++) {
		string tmp = "";
		cin >> tmp;
		arr.push_back(tmp);
	}

	BFS();

	printf("%d\n",answer);

	return 0;
}