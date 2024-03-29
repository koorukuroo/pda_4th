# EC2 성능 비교
## 비교인스턴스
![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/9ef91b52-febf-4140-886c-2c27c75c640d)
<br/>
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
|m6g.large||61.80887|
|c6g.large||61.61022|
|r6g.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/baa3f6b0-8fa2-4a09-bbbb-0faf41a5f463)|61.58268|
|i3.large|![image](https://github.com/jiyeon5/jiyeon5/assets/49721857/baa3f6b0-8fa2-4a09-bbbb-0faf41a5f463)|61.58268|

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
