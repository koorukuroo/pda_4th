# EC2 성능 비교
## 비교인스턴스
1. t4g 패밀리에서 크기별로 차이 비교
![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/9ef91b52-febf-4140-886c-2c27c75c640d)
<br/>
2. 같은 large이지만 패밀리가 다른 인스턴스 유형 차이 비교
![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/82942ba6-8f32-4003-8457-646f8d13690c)

## 결과

|EC2|CPU사용시간, 가용메모리|실행시간|
|------|---|---|
|t4g.micro|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/007a7ff6-2551-48c2-9786-b1a0e04efc91)|61.46846|
|t4g.small|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/2ec4b926-b45c-41f6-8a48-8a303068319c)|61.80887|
|t4g.medium|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/e4720cad-18bb-435a-86b0-d0a2c411ba41)|61.61022|
|t4g.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/baa3f6b0-8fa2-4a09-bbbb-0faf41a5f463)|61.58268|
|t4g.xlarge|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/68ab90cd-038a-431a-8bf0-be889783bdcf)|61.66919|

|EC2|CPU사용시간, 가용메모리|실행시간|
|------|---|---|
|t4g.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/baa3f6b0-8fa2-4a09-bbbb-0faf41a5f463)|61.58268|
|m6g.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/955adcef-a7b4-444d-b0d3-f214a6a00ef2)|61.48954|
|c6g.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/0092f639-2328-435a-a764-4bf59f162722)|61.54917|
|r6g.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/07f4ea09-a32d-48f9-bf46-6a0997b28888)|61.56287|
|i3.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/776d423c-4c26-4b2f-9547-8582680f909a)|60.00059|

## 사용코드
```python
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

# CSV 파일에 기록할 헤더
fieldnames = ['Iteration', 'CPU', 'Memory']

# CSV 파일 열기 및 헤더 쓰기
with open('performance_data.csv', mode='w', newline='') as file:
    writer = csv.DictWriter(file, fieldnames=fieldnames)
    writer.writeheader()

    # 작업 시작 시간 기록
    start_time = time.time()

    # Fibonacci 계산 및 CPU, 메모리 사용량 측정
    for i in range(40):
        # Fibonacci 계산
        fibonacci_result = fibonacci(i)

        # CPU 사용량 측정
        cpu_per = psutil.cpu_times(percpu=False)
        cpu_percent = cpu_per.user
        print(f'Iteration: {i}, CPU Usage: {cpu_percent}')

        # 메모리 사용량 측정
        memory = psutil.virtual_memory()
        memory_avail = round(memory.available / 1024 ** 3, 3)
        print(f'Iteration: {i}, Available Memory: {memory_avail}GB')

        # CSV 파일에 기록
        writer.writerow({'Iteration': i+1, 'CPU': cpu_percent, 'Memory': memory_avail})

    # 작업 종료 시간 기록
    end_time = time.time()

# 실행 시간 계산 및 출력
execution_time = end_time - start_time
print(f"실행 시간: {execution_time:.5f} 초")
```

## 결론
ec2 인스턴스 크기가 커져도 별로 유의미한 실행속도의 차이를 얻지 못했습니다.  
또한, cpu가 2배로 커졌음에도 코드 실행속도 차이는 크게 차이 나지 않았습니다.  
c가 컴퓨팅 성능이 빠르다고하여 기대를 하였지만 실험결과에는 유의미 하지 않았습니다.  
### => 하나의 실행파일만 돌고, 멀티태스킹을 진행하지 않아 cpu의 성능차이를 크게 느끼지 못했다고 생각이 듭니다. 추후 멀티 태스킹을 활용한 복잡한 시스템을 설계하고 재실험하는 것이 필요합니다.