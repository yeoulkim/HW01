#include <iostream>
using namespace std;

// 함수 선언
int calculateSum(int arr[], int size)
{
    int sum = 0;   //  변수 초기화
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];  // 배열의 각 요소를 합산
    }
    return sum;   // 합계 반환
}

double calculateAverage(int arr[], int size)
{
    int sum = calculateSum(arr, size);  // calculateSum 함수를 호출하여 합계 계산
    return static_cast<double>(sum) / size;   // double로 형변환 후 평균 계산하여 반환
}


int main() 
{ 
    const int SIZE = 5;      // 배열의 크기를 5로 고정
    int numarr[SIZE] = {};   // 크기가 5인 정수형 배열 선언 및 초기화

    cout << "숫자 5개를 입력하세요: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> numarr[i];  // 사용자로부터 숫자 입력 받기
    }

    // 합계, 평균 계산하기
    int sum = calculateSum(numarr, SIZE);
    double average = calculateAverage(numarr, SIZE);

    // 결과 출력하기
    cout << "합계: " << sum << endl;
    cout << "평균: " << average << endl;

    return 0;

}