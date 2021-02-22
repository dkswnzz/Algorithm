﻿//  Copyright © 2021 안주형. All rights reserved.
//  백트래킹
//  https://www.acmicpc.net/problem/15664
//  BOJ15664 N과 M(10)

#include <iostream>
#include <vector>
#include <algorithm>
#define max 9

using namespace std;

int N, M;
int arr[max];
bool visitied[max];
vector<int>v;

void dfs(int num, int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		int check = -1;
		for (int i = num; i <= N; i++) {
			if (!visitied[i] && v[i - 1] != check) {
				visitied[i] = true;
				check = v[i - 1];
				arr[start] = v[i - 1];
				dfs(i, start+1);
				visitied[i] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	dfs(1, 0);
}