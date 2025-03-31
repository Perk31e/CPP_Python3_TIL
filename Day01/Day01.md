# 도전할 문제 **백준 1929** // **LeetCode 347**

## **백준 1929** (https://www.acmicpc.net/problem/1929) 도전

## 문제 - 백준 1929

범위를 지정하면 그 사이에 존재하는 소수를 구하라

## 접근 방식

### 첫 번째 도전 (baekjoon-1929.cpp)

**소수** = 나눠떨어지는 게 1과 나 자신 외에 존재하지 않는다.  
**(결과: 시간 초과)**

### 두 번째 도전 (baekjoon-1929.cpp, baekjoon-1929-re.py)

**소수** = 제곱근 한 값까지만 확인하면 된다.  
=> 2부터 제곱근 값까지 순차적으로 나눠 떨어지는 게 있는지 확인한다.  
**(결과: 성공)**

## 배운 점

1. **개행**  
   C++에서는 `endl`을 사용하지 말고 `\n`을 활용하자.  
   => `endl`은 시간 초과 요인이 될 수 있음.  
   예: `cout << '\n';`

2. **제곱근**
   - C++: `cmath` 라이브러리를 추가하고 `sqrt(값)`으로 계산.
   - Python: `math` 라이브러리를 추가하고 `math.sqrt(값)`으로 계산.

## **(보너스) LeetCode 347** (https://leetcode.com/problems/top-k-frequent-elements/) 도전

## 문제 - (보너스) LeetCode 347

정수 배열 `nums`와 정수 `k`가 주어졌을 때, 배열에서 가장 빈도수가 높은 `k`개의 요소를 반환하라.  
(단, 반환 순서는 상관없으며, 답은 고유함이 보장된다.)

## 접근 방식

### 첫 번째 도전 (leet-347.cpp)

**unordered_map** 자료형을 활용하여 키, 값을 넣고 정렬을 위해 **unordered_map**에 저장한 내용을 **vector<pair<int, int>>**로 변환하고 정렬을 거쳐서 빈도수 높은 순으로 `k`개 만큼 반환한다.

1. 빈도수 계산: **unordered_map**을 사용하여 각 요소의 빈도수를 계산한다.

```cpp
unordered_map<int, int> count;
for (int value: nums){
   cout[value]++;
}
```

2. 정렬을 위한 변환: 빈도수를 기준으로 정렬하기 위해 **unordered_map**의 내용을 **vector<pair<int, int>>**로 변환합니다. 이때 **빈도수를 첫 번째 요소에 배치하여 정렬 시 빈도수 기준**으로 정렬되도록 합니다.

```cpp
vector<pair<int, int>> freq_vec;
for (auto& pair : count){
   freq_vec.push_back(pair.second, pair.first); // {빈도수, 요소}
}
```

3. 내림차순 정렬: **greater<>()** 함수 객체를 사용하여 빈도수 기준 내림차순으로 정렬합니다.

```cpp
sort(freq_vec.begin(), freq_vec.end(), greater<>());
```

4. 결과 출력: 정렬된 벡터에서 상위 k개의 요소만 결과 벡터에 추가합니다.

```cpp
vector<int>result;
for(int i=0; i<k; i++){
   result.push_back(freq_vec[i].second);
}
return result;
```

### 두 번째 도전 (leet-347.py)

**Dictionary** 자료형을 사용하여 배열의 각 요소 빈도수를 계산하고, 빈도수를 기준으로 키를 정렬하여 상위 `k`개를 반환한다.

1. `count` 딕셔너리에 각 요소의 빈도수를 저장.
2. `sorted()` 함수와 `key=count.get`을 사용해 빈도수 기준 내림차순 정렬
3. 상위 `k`개의 키를 반환
   **(결과: 성공)**

### 세 번째 도전 (leet-347-Counter.py)

**Collections** 라이브러리의 **Counter** 객체를 사용하여 빈도수를 계산하고, **most_common** 메서드로 상위 `k`개의 요소를 바로 추출한다.

1. `Counter()`로 빈도수 계산.
2. `most_common()` 로 상위 k개의 (키, 빈도수) 튜플로 반환.
3. 리스트 컴프리헨션으로 키만 추출
   **(결과: 성공)**

## 배운 점

1. **unordered_map**
   C++에서 파이썬의 딕셔너리와 유사한 해시 테이블 자료구조
   키-값 쌍을 저장하며, 평균 **O(1)** 시간복잡도를 가지며 요소 접근/삽입/삭제 가능 **(따라서, 키/값 형태는 pair보다는 unordered_map 사용 권장)**
   요소 빈도수 계산 등에 효율적으로 사용 가능
   예:
   ```cpp
   unordered_map<int, int> count;**
   ```
2. **pair**
   두 가지 데이터를 하나의 단위로 저장할 수 있는 자료 구조
   **pair<자료형 1, 자료형 2> 변수명;** 형태로 선언
   **first**와 **second** 멤버를 통해 각 요소에 접근
   벡터 등의 컨테이너와 함께 사용하여 여러 쌍의 데이터 관리 가능
   예:

   ```cpp
   vector<pair<int, int>> freq_vec;
   ```

3. **greater<>()와 sort 함수**
   C++ **sort()** 함수는 기본적으로 **첫 번째 인자**를 기준으로 오름차순 정렬 **(다른 순번의 인자를 기준으로 정렬하려면 따로 함수 정의해야 한다.)**
   greater<>() 함수 객체를 사용하면 내림차순으로 정렬 가능
   예:
   ```cpp
   sort(freq_vec.begin(), freq_vec.end(), greater<>());
   ```
   **pair**를 정렬할 때 기본적으로 **first** 요소를 기준으로 정렬하므로, 빈도수를 **first**에 저장하면 빈도수 기준으로 정렬 가능

3-1. **나는 greater<>() 쓰기 싫다?**

```cpp
sort(vec.begin(), vec.end(), greater<>());
```

대신에

```cpp
sort(vec.rbegin(), vec.rend());
```

사용할 수 있다.

4. **Counter의 저장방식**
   `Counter`는 `collections` 모듈의 클래스. 원래 리스트를 입력받아 각 요소의 빈도수를 키-값 쌍으로 저장.
   **변환 과정**:
   원래 리스트: `[1, 1, 1, 2, 2, 3]`.
   `Counter(nums)` 적용: `Counter({1: 3, 2: 2, 3: 1})`.
   **저장 형태**: 딕셔너리와 유사한 객체(`Counter({요소: 빈도수})`).
   **특징**: 딕셔너리처럼 키로 값을 조회 가능하며, 빈도수 작업에 최적화됨.

5. **most_common()의 저장 방식**:
   `Counter.most_common(k)`는 `Counter` 객체에서 빈도수 기준 내림차순으로 상위 k개의 `(요소, 빈도수)` 튜플 리스트를 반환.
   **변환 과정**:
   원래 리스트: `[1, 1, 1, 2, 2, 3]`.
   `Counter(nums)`: `Counter({1: 3, 2: 2, 3: 1})`.
   `most_common(2)` 적용: `[(1, 3), (2, 2)]`.
   **저장 형태**: 리스트 안에 튜플.
   **동작**: 내부적으로 빈도수를 정렬하고 상위 k개만 잘라서 제공.
