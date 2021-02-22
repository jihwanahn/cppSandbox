#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <array>

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

int main() {

	// Greed done
	//asdf;

	return 0;
}
