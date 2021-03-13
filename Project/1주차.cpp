#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> temp;
    //vector<int> temp;
    int length = progresses.size();

    //작업 완료일 구하기
    for (int i = 0; i < length; i++) {
        int sum = progresses[i];
        int count = 0;
        while (sum < 100) {
            sum += speeds[i];
            count++;
        }
        temp.push_back(count);
    }
    //작업 우선순위 구하기
    int count = 1;
    int max = temp[0];
    for (int i = 1; i < length; i++) {
        if (max < temp[i]) {
            answer.push_back(count);
            count = 1;
            max = temp[i];
        }
        else {
            count++;
        }
        if (i == length - 1) {
            answer.push_back(count);
        }
    }
}

int main() {
    vector<int> A = { 96,99,98,97 };
    vector<int> B = { 1,1,1,1 };
    vector<int> C = solution(A, B);
    for (int elem : C) {
        cout << elem << ' ';
    }

}