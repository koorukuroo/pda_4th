# 김예진, 김주은, 김현아  
<br>

## 사용한 코드
```python
import math
import time
start = time.time()
math.factorial(100000)
n=12
ans = 0
row = [0] * n
def is_promising(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False
    return True
def n_queens(x):
    global ans
    if x == n:
        ans += 1
        return
    else:
        for i in range(n):
            # [x, i]에 퀸을 놓겠다.
            row[x] = i
            if is_promising(x):
                n_queens(x+1)
n_queens(0)
print("ans : ",ans)
end = time.time()
print(f"{end - start:.5f} sec")
```
<br>

## 결과 
|             	| X86(Ubuntu)      	| ARM(Ubuntu)      	| ARM(Amazone Linux) 	|
|-------------	|----------	|----------	|------------	|
| t4g.small   	|          	| 11.46922 	| 13.66932   	|
| t3.small    	| 14.88069 	|          	|            	|
|	|	|	||
| t4g.large   	|          	| 11.43830 	| 14.04990   	|
| t3.large    	| 12.17113 	|          	|            	|
|	|	|	||
| m6g.large   	|          	| 11.41954 	| 13.60144   	|
| m5.large    	| 11.20361 	|          	|            	|
|	|	|	||
| c6g.large   	|          	| 11.42115 	| 13.59670   	|
| c5.large    	| 9.66747  	|          	|            	|
|	|	|	||
| c6g.2xlarge 	|          	| 11.46003 	| 13.60561   	|
| c5.2xlarge  	| 9.69850  	|          	|            	|
<br>


## 인스턴스 유형 비교
### X86
![image](https://github.com/koorukuroo/pda_4th/assets/92364973/fac04d1b-ec07-412d-9fb9-cd7ea5e4ad24)
### ARM
![image (5)](https://github.com/koorukuroo/pda_4th/assets/92364973/62703b5d-7ff7-4f01-9e2a-e9852e72257f)  
<br><br>

## cpu 지표

|  X86(Ubuntu)    	| ![image (2)](https://github.com/koorukuroo/pda_4th/assets/92364973/158bfc33-7c8c-4795-adda-cae6b47abcbb) 	|
|--------------------	|----------------------------------------------------------------------------------------------------------	|
| **ARM(Ubuntu)**                	| ![arm](https://github.com/koorukuroo/pda_4th/assets/92364973/bcd9cda3-1a4b-4acc-ad63-de5a34cad20c)       	|
| **ARM(Amazone Linux)** 	| ![image (3)](https://github.com/koorukuroo/pda_4th/assets/92364973/a63ae31a-4f77-454e-8c58-46c6d2008254) 	|
<br>

## 특이사항
1. 왜 ARM Ubuntu에서 t4g.large에서 cpu사용량이 급격하게 증가했는가?
   -> small보다 cpu사용량이 줄었어야 하는 것 아닌가? <br>
이유 : 
<br>

## 결론
1. ARM 사용 시, Linux보다 Ubuntu의 속도가 더 빠르다.  
  -> 우분투는 널리 사용되는 개발자 및 사용자 커뮤니티가 활발하고, 이로인해 더 빠른 버그 수정 및 업데이트가 제공되어 성능 향상과 안정성을 기져오는 것 같다. <br>

2. 같은 Ubuntu 사용 시, 비슷한 인스턴스 유형을 사용할 때, X86에서 크게 변화가 된 것을 확인할 수 있다.  
  -> Window 운영체제는 더 많은 시스템 리소스를 요구해서 성능의 변화에 민감하지만, Ubuntu와 같은 Linux 기반 시스템은 일반적으로 더 적은 리소스를 사용해서 Ubuntu가 AWS 인스턴스에서 더 일관된 성능을 제공하는 것 같다.<br>

3. 인스턴스의 크기는 성능변화에 크게 영향을 미치지 않고, 인스턴스 family와 세대가 영향을 미치는 것을 알 수 있다. <br>

