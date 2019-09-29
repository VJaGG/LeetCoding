#include<iostream>
#include<vector>
using namespace std;

//递归实现与非递归，递归时间复杂度随着n的变化增长率是2^n
//想一下转换的过程
int Fibonacci1(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	vector<int> array(n+1);
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i <=n; i++) {
		array[i] = array[i - 1] + array[i - 2];
	}
	return array[n];
}
int Fibobacci2(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int first = 0, second = 1, result;
	for (int i = 2; i <= n; i++) {
		result = first + second;
		first = second;
		second = result;
	}
	return result;
		

}
int Fibonacci(int n) {
	//递归实现的
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int num = Fibonacci(n - 1) + Fibonacci(n - 2);
	return num;
}

int main() {
	int num;
	cout << "please enter the num: ";
	cin >> num;
	int result = Fibobacci2(num);
	cout << result<<endl;
	system("pause");
	return 0;


}
