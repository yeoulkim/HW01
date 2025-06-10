#include <iostream>
using namespace std;

// 매개변수(파라미터)로 배열을 받는 함수 선언
void printArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;  // 출력 후 줄바꿈
}

// 합계를 반환하는 함수
int getSum(int numbers[], int size)
{
    int sum = 0;  // 합계를 담을 변수 선언 및 초기화

    // 배열을 돌면서 합계 구하기
    for (int i = 0; i < size; i++)  // 배열의 크기만큼 반복
    {
        sum += numbers[i];  // 배열의 각 요소를 합산
    }

    return sum;  // 합계 반환
}

// 평균을 반환하는 함수
double getAverage(int numbers[], int size)
{
    // 평균 == 총합 / 개수
    // 정수 / 정수 == 정수 -> 하나를 실수형으로 형변환
    return getSum(numbers, size) / static_cast<double>(size);
    // return static_cast<double>)(getSum(numbers, size)) / size;
}

// 버블정렬 함수 (오름차순)
void sortAsc(int numbers[], int size)
{   
    // 뒤에가 정렬되면 마지막 회전에서 가장 앞 숫자는 이미 제일 작은 수라 정렬 안 해도 됨
    for (int i = 0; i < size - 1; i++)   // i는 행 회전
    {
        for (int j = 0; j < size - 1 - i; j++)  // j는 열 회전
        {
            if (numbers[j] > numbers[j + 1])
            {
                // Swap
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

// 버블 정렬 함수 (내림차순)
void sortDesc(int numbers[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (numbers[j] < numbers[j + 1])
            {
                // Swap
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // 사용자로부터 정수 5개를 입력받아 배열에 저장
    const int SIZE = 5;  // 배열의 크기를 5로 고정
    int numbers[SIZE] = {};  // 배열 생성 및 초기화

    int sortChoice = 0;

    // 5번 돌면서 사용자에게 정수값을 입력 받음
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << "번째 숫자 입력: ";
        cin >> numbers[i];
    }

    printArray(numbers, SIZE);  // 함수에 배열의 주소와 배열의 크기를 매개변수로 넘김
    
    cout << "총합: " << getSum(numbers, SIZE) << endl;
    cout << "평균: " << getAverage(numbers, SIZE) << endl;

    cout << "오름차순: 1번, 내림차순: 2번";
    cin >> sortChoice;

    if (sortChoice == 1)
    {
        sortAsc(numbers, SIZE);     // sortAsc()는 정렬만 수행, return 값 없음
    }
    else if (sortChoice == 2)
    {
        sortDesc(numbers, SIZE);
    }
    else
    {
        cout << "1번, 2번 중에 선택하세요." << endl;
    }
   
    // 정렬 함수들은 정렬만 수행, return 값 없음 
    // 여기서 출력
    printArray(numbers, SIZE);  
   
    return 0;

}