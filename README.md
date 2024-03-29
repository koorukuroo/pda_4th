가설: 코테 문제를 좋은 cpu를 사용하면 연산속도가 빨라져서 좀더 빠르게 풀수 있지 않을까?

코테 문제:
## N-Queen
```python
import sys
input=sys.stdin.readline

n=12
graph=[0]*n
cnt=0
def queen(x):
    for i in range(x):
        if graph[x]==graph[i] or abs(graph[x]-graph[i])==abs(x-i):
            return False
    return True

def dfs(x):
    global cnt
    if x==n:
        cnt+=1
        return
    for i in range(n):
        graph[x]=i
        if queen(x):
            dfs(x+1)
    return cnt
dfs(0)
print(cnt)


```
일반으로 돌렸을때?
4.151427 sec







## t2 계열

### t2 micro

1. cpu사용량

![image](https://github.com/lemonticsoul/git22/assets/127959482/7c124143-e588-44dc-9141-cfea7cc15d0d)



### t2.small

1. cpu사용량

![image](https://github.com/lemonticsoul/git22/assets/127959482/6cf412b9-5f1d-4057-a9e7-c147550f80f5)


## t3계열

### t3 micro

1.cpu 사용


![image](https://github.com/lemonticsoul/git22/assets/127959482/2c121b4e-5d2f-4cf6-abba-23fc48bf0e4c)


### T3.large

1.cpu 사용


![image](https://github.com/lemonticsoul/git22/assets/127959482/2fe79c61-9e27-48a0-8919-5874dacb6c63)







## t4계열

### t4g micro

1.cpu 사용

![image](https://github.com/lemonticsoul/git22/assets/127959482/356e9839-ac1e-4110-ae2c-675a5adbdbfe)


### t4g large

1.cpu 사용

![image](https://github.com/lemonticsoul/git22/assets/127959482/fd3b5349-e582-4961-936e-422ad6406a65)




## C계열

### C4 2xlarge

1.cpu 사용

![image](https://github.com/lemonticsoul/git22/assets/127959482/5a1258aa-8289-46d6-962f-1f73d2e18829)



### c5.4xlarge

1.cpu 사용

![image](https://github.com/lemonticsoul/git22/assets/127959482/07a3168a-b983-41b9-84c3-3983730efd16)

![image](https://github.com/koorukuroo/pda_4th/assets/127959482/3e3251d9-8c33-4a53-8091-87b2ab07e315)


### 결론

cpu성능이 좋아질수록 t에서 유의미한 속도차이를 느끼지 못했고,
심지어 cpu성능이 좋아질수록 코테 속도가 조금 느린다고 생각했다.(이건 좀 튄 표지인거같다.)

그래서 C를 이용하였고 이를 통해 코테 시간 을 줄였는데 똑같은 유의미한 차이가 생겨서

C5으로 바꾸었더니 코테 시간이 확 줄어들었던것을 확인하였다.
![image](https://github.com/lemonticsoul/git22/assets/127959482/36eea0d7-7528-4a4a-a3d4-e2127a7d0593)


### 도전

결론에서 뭔가 찝찝해서 n-queen을 10번 반복하고 
t3.large 랑 c4.large 두개만 시간이 남아 비교를 해보았다.

T3 large real 2m4.209s user 2m4.180s sys 0m0.012s

C4 large real 1m47.739s user 1m47.725s sys 0m0.008s

