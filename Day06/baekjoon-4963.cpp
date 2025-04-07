#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int w, h;
bool visited[50][50];
int current_map[50][50];
// 방향 배열 (상, 우상, 우, 우하, 하, 좌하, 좌, 좌상) - 8방향 
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

// DFS 함수
void dfs(int x, int y, int island_exist){
    visited[x][y] = true;
    
    // 8방향 탐색으로 수정
    for(int i=0; i<8; i++){
    	int nx = x+dx[i];
    	int ny = y+dy[i];

    	// 맵 범위 내에 있고, 방문하지 않았으며, 높이가 기준 이상인 경우
    	if (nx>=0 && nx <h && ny>=0 && ny < w && visited[nx][ny] == false && current_map[nx][ny] == island_exist){
    		dfs(nx, ny, island_exist);
    	}
    }    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
    	cin >> w >> h;
    	if(w==0 && h==0){
    		break;
    	}
    	// 현재 지도를 저장할 2차원 배열
    	
    	for (int i=0; i<h; i++){
    		for(int j=0; j<w; j++){
    			cin >> current_map[i][j];
    		}
    	}
    	// 방문 여부 확인을 위한 배열
    	fill(&visited[0][0], &visited[0][0] + 50*50, false);

    	int island_count=0;
    	// 모든 지역에 대해 dfs 수행
    	for(int i=0; i<h; i++){
    		for(int j=0; j<w; j++){
    			if(!visited[i][j] && current_map[i][j]==1){
    				dfs(i,j,1);
    				island_count +=1;
    			}
    		}
    	}
    	cout << island_count<<'\n';  
    }
	return 0;
}