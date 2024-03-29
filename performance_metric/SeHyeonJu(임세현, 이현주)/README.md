#### CPU 개수 : 2개로 통일

### AMI
**이름 ubuntu_아키텍쳐_instance**

#### 태그
- instance_type
- cpu_architecture

### 비교 대상
#### M5.large vs M6g.large vs C6g.large vs R6g.large

### 실습 코드1
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
1. ubuntu x86 M5.large
- 2CPU 8GiB

계산된 원주율 값: 3.141592653589731  
소요된 시간(초): 0.8935410976409912

2. ubuntu arm M6g.large
- 2CPU 8GiB

계산된 원주율 값: 3.141592653589731  
소요된 시간(초): 1.7081754207611084

3. ubuntu arm R6g.large
- 2CPU 16GiB

계산된 원주율 값: 3.141592653589731  
소요된 시간(초): 1.7010509967803955

4. ubuntu arm C6g.large
- 2CPU 4GiB

계산된 원주율 값: 3.141592653589731  
소요된 시간(초): 1.7010509967803955

**결과 :** M5 인스턴스의 실행이 M6g, C6g, R6g 인스턴스에 비해 빠른 결과를 보여주었다.


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

### 결과

