#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <array>
#include <cctype>
#include <string>

using namespace std;

template <size_t N>
void print(std::array<int, N>& arr) {
	for (auto ele : arr)
		std::cout << ele << ", ";
}

class A {
public:
	A() { cout << "HI A" << endl; }
	virtual ~A() { cout << "BYE A" << endl; }
};

class B : public A {
public:
	B() { cout << "HI B" << endl; };
	virtual ~B() { cout << "BYE B" << endl; }
};

int changeMoney(int N) {
	int count = 0;

	array<int, 4> moneyList = { 500, 100, 50, 10 };

	for (auto money : moneyList) {
		count += N / money;
		N %= money;
	}

	return count;
}

int bigNumRule() {
	// 동빈북 2번
	// 배열의 크기 N, 숫자가 더해지는 횟수 M, K를 초과하여 더해질 수 없는 것
	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;
	cin.ignore();

	vector<int> InArr;

	while (N > 0)
	{
		int i;
		cin >> i;
		InArr.push_back(i);

		--N;
	}

	sort(InArr.begin(), InArr.end());
	int ArrSize = InArr.size();
	int largest1 = InArr[ArrSize - 1];
	int largest2 = InArr[ArrSize - 2];

	int times = (M / (K + 1)) * K;
	times += M % (K + 1);

	int sum = 0;

	sum += times * largest1;
	sum += largest2 * (M - times);

	return sum;
}

void NumCardGame() {
	int n, m, result;

	// N, M을 공백을 기준으로 구분하여 입력 받기
	cin >> n >> m;

	// 한 줄씩 입력 받아 확인하기
	for (int i = 0; i < n; i++) {
		// 현재 줄에서 '가장 작은 수' 찾기
		int min_value = 10001;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);
		}
		// '가장 작은 수'들 중에서 가장 큰 수 찾기
		result = max(result, min_value);
	}

	cout << result << '\n'; // 최종 답안 출력
}

void UntilGetOne(int N = 0, int K = 0) {
	int MinCount{ 0 };

	while (N != 1) {
		if (N % K == 0) {
			N /= K;
		}
		else {
			--N;
		}
		++MinCount;
	}
	cout << MinCount << endl;
}

void FindDest(int N, vector<string> Route) {
	vector<vector<int>> map (N * N);

	int x{1}, y{1};

	
    for(auto point : Route) {
        if(point == "R" && y != N) {
			++y;
        }
		else if (point == "U" && x != 1) {
			--x;
		}
		else if (point == "D" && x != N) {
			++x;
		}
		else if (point == "L" && y != 1) {
			--y;
		}
    }

	cout << x << " " << y;

}

bool clockcheck(int h, int m, int s) {
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
		return true;
	return false;    
}

void clockmain() {
	int h, cnt=0;
    cin >> h;
	for(int i = 0; i<=h ; ++i) {
	    for(int j =0; j<60;++j) {
	        for(int k = 0 ;k<60;++k) {
				if (clockcheck(i, j, k)) ++cnt;
	        }
	    }
	}

	cout << cnt;
}

void ChessKnight() {
	vector<int> x = {-2, -1, 1, 2, -2 ,-1, 1, 2};
	vector<int> y = {1, 2, 2, 1, -1, -2, -2, -1};

	string pos;
	cin >> pos;

	vector<char> col = { 'a','b','c','d','e','f','g','h' };

	int colomn = 0;
	int row = pos[1] - '0';

	for (int i = 0; i < col.size(); ++i) {
	    if(pos[0] == col.at(i)) {
			colomn = i + 1;
	    }
	}

	int movement{ 0 };

	for (int i = 0; i < 8; ++i) {
		int nextRow = row + x[i];
		int nextCol = colomn + y[i];
		if(1 <= nextRow && 8 >= nextRow && 1 <= nextCol && 8>=nextCol) {
			++movement;
		}
	}


    cout << movement;
}

int main() {

	// Greed done
	/*int i = 5;
	vector<string> s = {"R","R","R","U","D","D"};
	FindDest(i, s);*/
	
	//clockmain();

	

	ChessKnight();


	return 0;
}
