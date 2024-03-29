## EC2 인스턴스 4개에 동일한 코드를 실행하고 실행 시간 및 CPU 사용량을 비교 분석
- CPU 개수 : 2개로 통일
- 인스턴스 유형 : large로 통일

### 비교 대상
**M5.large vs M6g.large vs C6g.large vs R6g.large**

***

### 실습 코드1
원주율 근사치를 위한 단계 개수인 num_steps 만큼 반복하여 pi 값을 계산해주는 코드
```python
import time
def calculate_pi(num_steps):
    step = 1.0 / num_steps
    sum = 0.0
    for i in range(num_steps):
        x = (i + 0.5) * step
        sum = sum + 4.0 / (1.0 + x * x)
    return step * sum
num_steps = 10000000  # 적절한 숫자로 변경하여 성능을 테스트하세요
start_time = time.time()
pi = calculate_pi(num_steps)
end_time = time.time()
print("계산된 원주율 값:", pi)
print("소요된 시간(초):", end_time - start_time)
```

### 결과1
**1. ubuntu x86 M5.large**
- 2CPU 8GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/98f28bfb-1d58-4fe2-a121-e7e000bba68d)

**2. ubuntu arm M6g.large**
- 2CPU 8GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/9c3772a5-4cad-4aef-9228-6c1c1164dcbd)

**3. ubuntu arm R6g.large**
- 2CPU 16GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/4dbed9cb-2e69-4e90-b6f1-a425bbdff68b)

**4. ubuntu arm C6g.large**
- 2CPU 4GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/13b95da5-8203-462c-95e1-64b92a810cdd)

**결과 :** M5 인스턴스의 실행이 M6g, C6g, R6g 인스턴스에 비해 빠른 결과를 보여주었다.

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/4a91043d-c16e-49de-86c6-3c984bb53c7d)

---

### 실습 코드2
```python
import numpy as np
import time

# 많은 계산을 수행하여 CPU를 사용하는 작업
def high_cpu_workload():
    a = np.random.rand(1000, 1000)
    b = np.random.rand(1000, 1000)
    for _ in range(1000):
        np.dot(a, b)

# 높은 CPU 사용량 작업 실행 및 시간 측정
start_time = time.time()
high_cpu_workload()
end_time = time.time()

elapsed_time = end_time - start_time
print(f"높은 CPU 사용량 작업 소요 시간(초): {elapsed_time:.2f}")
```

### 결과2
**1. ubuntu x86 M5.large**
- 2CPU 8GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/c87d9abc-50a7-4b13-bd86-6e4110c731ed)

**2. ubuntu arm M6g.large**
- 2CPU 8GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/760f68c8-e2d4-4051-95f4-8f82112fcfa6)

**3. ubuntu arm R6g.large**
- 2CPU 16GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/2a244978-df7c-4c83-ade7-ae3be710e7d1)

**4. ubuntu arm C6g.large**
- 2CPU 4GiB

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/0b72c477-dc9a-4580-bfbe-55ecb510fe07)

**결과 :** 1번 실습과 마찬가지로 M5 인스턴스의 실행이 M6g, C6g, R6g 인스턴스에 비해 빠른 결과를 보여주었다.

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/ae1051a8-4c33-4189-8cb3-402f343eeef6)
---

### 실습 코드3
프로 디지털 아카데미 4기 수강생들의 깃허브 페이지에 접속하여 내용 중에 존재하는 유튜브, 인스타그램, 링크드인 등의 주소를 정리하는 코드

### 결과3
CPU 사용률을 비교해보았다.

**1. ubuntu x86 M5.large**
- 2CPU 8GiB

![스크린샷 2024-03-29 125233](https://github.com/koorukuroo/pda_4th/assets/116863184/75b30afb-0a20-4c17-87dd-1fa51cd9b012)

**2. ubuntu arm M6g.large**
- 2CPU 8GiB

![스크린샷 2024-03-29 125208](https://github.com/koorukuroo/pda_4th/assets/116863184/2ed8f043-0e97-4d8a-a8bf-be8ddc2c65e4)

**3. ubuntu arm R6g.large**
- 2CPU 16GiB

![스크린샷 2024-03-29 125343](https://github.com/koorukuroo/pda_4th/assets/116863184/d6bfe484-841a-4e50-8331-97c572a21d43)

**4. ubuntu arm C6g.large**
- 2CPU 4GiB

![스크린샷 2024-03-29 125448](https://github.com/koorukuroo/pda_4th/assets/116863184/d158c11d-2d0c-49f7-9648-145efc840925)

**결과 :** M5 인스턴스의 CPU 사용률이 M6g, C6g, R6g 인스턴스에 비해 적은 결과를 보여주었다.

![image](https://github.com/koorukuroo/pda_4th/assets/116863184/bed157a1-db3b-4b49-9453-7f5714ab784f)
