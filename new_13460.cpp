#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


struct TURN {
	int by, bx, ry, rx; // 위치
	int sec;
	int game_end = 0; // 0 continue 1 win 2 lose
};


// y, x
int n, m, answer;
int blank_y, blank_x;

vector <string> arr;


// 왼쪽으로 기울이기
TURN up(TURN turn) {
	int cur_by = turn.by;
	int cur_bx = turn.bx;
	int cur_ry = turn.ry;
	int cur_rx = turn.rx;


	bool b_success = false;
	bool r_success = false;
	int move = 0;

	// do blue first
	if(cur_by < cur_ry) {
		// move blue
		while(true) {
			move++;

			if(cur_by - move == blank_y && cur_bx == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by-move][cur_bx] != '.') {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.by = cur_by - move;
		}

		move = 0;
		// move red
		while(true) {
			move++;

			if(cur_ry - move == blank_y && cur_rx == blank_x) {
				r_success = 1; // win
				break;
			}

			if(arr[cur_ry - move][cur_rx] != '.') {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.ry = cur_ry - move;
		}

	}
	else {
		// move red
		while(true) {
			move++;

			if(cur_ry - move == blank_y && cur_rx == blank_x) {
				r_success = 1; // win
				break;
			}

			if(arr[cur_ry - move][cur_rx] != '.') {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.ry = cur_ry - move;
		}

		// move blue
		move  = 0;
		while(true) {
			move++;

			if(cur_by - move == blank_y && cur_bx == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by-move][cur_bx] != '.') {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.by = cur_by - move;
		}

	}

	if(b_success) 
		turn.game_end = 2;

	else if(r_success) 
		turn.game_end = 1;
	
	else
		turn.game_end = 0;

	turn.sec++;
	return turn;
}

TURN down(TURN turn) {
	int cur_by = turn.by;
	int cur_bx = turn.bx;
	int cur_ry = turn.ry;
	int cur_rx = turn.rx;
	turn.sec++;

	bool b_success = false;
	bool r_success = false;
	int move = 0;

	// do blue first
	if(cur_by > cur_ry) {
		// move blue
		while(true) {
			move++;

			if(cur_by + move == blank_y && cur_bx == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by+move][cur_bx] != '.' ) {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.by = cur_by + move;
			if(b_success) {
				turn.game_end = 2;
				return turn;
			}

		}

		move = 0;
		// move red
		while(true) {
			move++;

			if(cur_ry + move == blank_y && cur_rx == blank_x) {
	 			r_success = true; // win
				break;
			}

			if(arr[cur_ry +move][cur_rx] != '.') {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.ry = cur_ry + move;
			if(r_success) {
				turn.game_end = 1;
				return turn;
			}

		}
	}
	else {
		// move red
		while(true) {
			move++;

			if(cur_ry + move == blank_y && cur_rx == blank_x) {
	 			r_success = true; // win
				break;
			}

			if(arr[cur_ry +move][cur_rx] != '.') {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.ry = cur_ry + move;
		}
		move = 0;
		// move blue
		while(true) {
			move++;

			if(cur_by + move == blank_y && cur_bx == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by+move][cur_bx] != '.' ) {
				move--;
				break;
			}
		}
		if(move > 0) {
			turn.by = cur_by + move;
			if(b_success) {
				turn.game_end = 2;
				return turn;
			}
		}
	}

	if(b_success) 
		turn.game_end = 2;

	else if(r_success) 
		turn.game_end = 1;
	
	else
		turn.game_end = 0;


	return turn;
}


// 왼쪽으로 기울이기
TURN left(TURN turn) {
	int cur_by = turn.by;
	int cur_bx = turn.bx;
	int cur_ry = turn.ry;
	int cur_rx = turn.rx;
	turn.sec++;

	bool b_success = false;
	bool r_success = false;
	int r_move = 0;
	int b_move = 0;

	// do blue first
	if(cur_bx < cur_rx)  {
		// move blue
		while(true) {
			b_move++;

			if(cur_by==blank_y && cur_bx - b_move == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by][cur_bx-b_move] != '.') {
				b_move--;
				break;
			}
		}
		if(b_move > 0) {
			turn.bx = cur_bx - b_move;
			if(b_success) {
				turn.game_end = 2;
				return turn;
			}
		}

		r_move = 0;
		while(true) {
			r_move++;

			if(cur_ry == blank_y && cur_rx - r_move == blank_x) {
				r_success= true; // win
				break;
			}

			if(arr[cur_ry][cur_rx-r_move] != '.') {
				r_move--;
				break;
			}
		}
		if(r_move > 0) {
			turn.rx = cur_rx - r_move;
		}

	}
	else {
		while(true) {
			r_move++;

			if(cur_ry == blank_y && cur_rx - r_move == blank_x) {
				r_success= true; // win
				break;
			}

			if(arr[cur_ry][cur_rx-r_move] != '.') {
				r_move--;
				break;
			}
		}
		if(r_move > 0) {
			turn.rx = cur_rx - r_move;
			if(r_success) {
				turn.game_end = 1;
				return turn;
			}
		}
		int b_move = 0;
		while(true) {
			b_move++;

			if(cur_by==blank_y && cur_bx - b_move == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by][cur_bx-b_move] != '.') {
				b_move--;
				break;
			}
		}
		if(b_move > 0) {
			turn.bx = cur_bx - b_move;
		}


	}
	//printf("%d %d %d %d\n", b_success, b_move, r_success, r_move);
	if (b_success && r_success) {
		if(r_move < b_move){
			turn.game_end = 1;
		}
		else 
			turn.game_end = 2;
	}

	else if(b_success) 
		turn.game_end = 2;

	else if(r_success) 
		turn.game_end = 1;
	
	else
		turn.game_end = 0;

	


	return turn;
}



// 오른쪽으로 기울이기
TURN right(TURN turn) {
	int cur_by = turn.by;
	int cur_bx = turn.bx;
	int cur_ry = turn.ry;
	int cur_rx = turn.rx;

	bool b_success = false;
	bool r_success = false;
	int b_move = 0;

	//printf("Blank %d %d\n", blank_x, blank_y);

	if(cur_bx > cur_ry) {

		// move blue
		while(true) {
			b_move++;

			if(cur_by==blank_y && cur_bx + b_move == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by][cur_bx+b_move] != '.') {
				b_move--;
				break;
			}
		}
		if(b_move > 0) {
			turn.bx = cur_bx + b_move;
		}

		// red
		int r_move = 0;
		while(true) {
			r_move++;

			if(cur_ry == blank_y && cur_rx + r_move == blank_x) {
				r_success = true; // win
				break;
			}

			if(arr[cur_ry][cur_rx+r_move] != '.') {
				r_move--;
				break;
			}
		}
		if(r_move > 0) {
			turn.rx = cur_rx + r_move;
		}
	}
	else {
		// red
		int r_move = 0;
		while(true) {
			r_move++;

			if(cur_ry == blank_y && cur_rx + r_move == blank_x) {
				r_success = true; // win
				break;
			}

			if(arr[cur_ry][cur_rx+r_move] != '.') {
				r_move--;
				break;
			}
		}
		if(r_move > 0) {
			turn.rx = cur_rx + r_move;
		}
		int b_move = 0;
		// move blue
		while(true) {
			b_move++;

			if(cur_by==blank_y && cur_bx + b_move == blank_x) {
				b_success = true; // lose
				break;
			}

			if(arr[cur_by][cur_bx+b_move] != '.') {
				b_move--;
				break;
			}
		}
		if(b_move > 0) {
			turn.bx = cur_bx + b_move;
		}

	}
	
	//printf("R: %d %d\n", turn.rx, turn.ry);
	//printf("r: %d b: %d\n", r_move, b_move);
	
	if(b_success) 
		turn.game_end = 2;

	else if(r_success) 
		turn.game_end = 1;
	
	else
		turn.game_end = 0;


	turn.sec++;

	return turn;
}




void BFS() {

	queue <TURN> q;
	TURN game;

	game.sec = 0;
	for(int i=0; i<arr.size(); i++) 
		for(int j=0; j<arr[0].size(); j++) {
			if(arr[i][j] == 'B') {
				arr[i][j] ='.';
				game.by = i;
				game.bx = j;
				
			}
			else if(arr[i][j] == 'R') {
				arr[i][j] = '.';
				game.ry = i;
				game.rx = j;
			}
			else if(arr[i][j] != '#' && arr[i][j] != '.') {
				blank_y = i;
				blank_x = j;
			}
		}
	q.push(game);

	while(!q.empty()) {
		//printf("while");
		TURN cur = q.front();
		q.pop();

		if(cur.game_end == 1) {
			answer = cur.sec;
			return;
		}

		if(cur.sec >= 10) {
			answer = -1;
			return;
		}
		
		TURN next_turn;

		//왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기
		
		next_turn = left(cur);
		if (next_turn.game_end != 2)
			q.push(next_turn);
		
		next_turn = right(cur);
		if (next_turn.game_end != 2)
			q.push(next_turn);

		next_turn = up(cur);
		if (next_turn.game_end != 2)
			q.push(next_turn);

		next_turn = down(cur);
		if (next_turn.game_end != 2)
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