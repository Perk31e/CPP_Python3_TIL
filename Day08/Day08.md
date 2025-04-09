# 도전할 문제 **백준 9996**

## **백준 9996** (https://www.acmicpc.net/problem/9996) 도전

## 문제 - 백준 9996

1. 와일드카드로 \* 이 주어진다.
2. - 양옆에 문자 혹은 문자열이 주어진다.
3. 예시 입력으로 주어진 문자열이 \* 양옆의 문자 혹은 문자열과 동일하게 시작하고 끝나는가?

## 접근 방식

### 첫 번째 도전(baekjoon-9996.cpp, baekjoon-9996.py)

- 의 양옆을 리스트 슬라이싱을 활용하여 나눴다. 그걸 front, back으로 저장했다.
  예시 입력에서 front, back 각각이 예시 입력의 앞부분, 뒷부분과 일치하는지 비교했다.

## 배운 점

리스트에서 특정 값을 찾을때: 리스트는 문자열 처럼 find() 가 없다 대신에 index()를 사용해야 한다.
index()는 찾을려는 값이 없을때, ValueError가 등장한다.

```
def find_index_safely(lst, value):
    try:
        return lst.index(value)  # 값을 찾으면 인덱스 반환
    except ValueError:
        return -1  # 값이 없으면 -1 반환 (또는 다른 특별한 값/None 등)

# 사용 예시
my_list = [10, 20, 30, 40, 50]
result = find_index_safely(my_list, 30)
if result != -1:
    print(f"값의 인덱스: {result}")
else:
    print("값을 찾을 수 없습니다")
```

in 연산자: 특정 값이 컬렉션에 존재하는지 여부(True/False)만 확인합니다.

```
if "apple" in fruits:
    print("사과가 있습니다")
```

enumerate(): 반복 가능한 객체를 순회하면서 각 요소의 인덱스와 값을 함께 제공합니다.

```
for i, fruit in enumerate(fruits):
    print(f"{i}: {fruit}")
```

enumerate()는 in 연산자를 직접 사용하지는 않지만, 두 기능을 함께 사용하는 패턴이 일반적입니다.
예를 들어:

```
search_value = "apple"
if search_value in fruits:  # 먼저 존재 여부 확인
    for i, fruit in enumerate(fruits):  # 그 다음 위치 찾기
        if fruit == search_value:
            print(f"사과는 인덱스 {i}에 있습니다")
            break
```
