## 테스트 환경
* Anaconda를 설치하여 파이썬 코드를 서버에서 실행시켰습니다.
* os는 ubuntu를 사용했습니다.
* 인스턴스 유형은 t2.micro와 t2.medium,c5.large,m5.large를 사용
* AMI는 amd64입니다.

## 코드
```python
# 크롤링
import time
from bs4 import BeautifulSoup
import urllib.request
import re
#User-Agent를 조작하는 경우(아이폰에서 사용하는 사파리 브라우져의 헤더)
hdr = {'User-agent':'Mozilla/5.0 (iPhone; CPU iPhone OS 10_3 like Mac OS X) AppleWebKit/603.1.23 (KHTML, like Gecko) Version/10.0 Mobile/14E5239e Safari/602.1'}
start = time.time() # 시작
for n in range(0,100):
        #클리앙의 중고장터 주소
        data ='https://www.clien.net/service/board/sold?&od=T31&po=' + str(n)
        #웹브라우져 헤더 추가
        req = urllib.request.Request(data, \
                                    headers = hdr)
        data = urllib.request.urlopen(req).read()
        page = data.decode('utf-8', 'ignore')
        soup = BeautifulSoup(page, 'html.parser')
        list = soup.find_all('span',
                attrs={'data-role':'list-title-text'})
        for item in list:
                try:
                        title = item.text.strip()
                        #print(title) # 클리앙 글 출력
                        if (re.search('아이패드', title)): # 아이패드에 관련된 글만 출력
                                print(title.strip())
                except:
                        pass
print(f"{time.time()-start:.4f} sec") # 종료와 함께 수행시간 출력
```  
```python
# for문
import time
def long_running_task():
    total = 0
    for i in range(1, 990000001):
        total += i
    return total
if __name__ == "__main__":
    start_time = time.time()
    result = long_running_task()
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Result: {result}")
    print(f"Execution Time: {execution_time:.2f} seconds")
```




## 성능 측정
* 크롤링 속도
* 코드 실행 시간
## 범위와 역할
* 김민중 팀원
  * t2.medium , c5.large 인스턴스를 사용
  * 크롤링에 해당하는 파이썬 코드 작성
* 이재인 팀원
  * t2.micro  , m5.large 인스턴스를 사용
  * for문을 사용한 파이썬 코드 문제 작성
## 결과 분석
|유형|t2.micro(초)|t2.medium(초)|c5.large(초)|m5.large(초)|
|-------|-------|-----|----|---|
|크롤링|19.5328|19.7202|16.4189|16.9833|
|for문|119.37|111.98|43.99|51.17|

## 이슈
1. 크롤링을 실행하였을 때 t2.medium이 t2.micro보다 20배 느리게 나오는 문제
   - 문제점 : 서로 다른 리전 설정(t2.medium:미국북부 , t2.micro:서울)
   - 해결 : 리전 동기화
2. for문을 실행할때 t2.medium이 t2.mircro보다 빨랐지만 크롤링에서는 비슷한 문제
   - 문제점 : t2.medium가 t2.micro보다 성능이 좋은데 왜 크롤링에서는 비슷한 지 의문
   - 해결 : t2.medium과 t2.micro의 세부사항을 찾아본 결과 network performance는 비슷하여서 크롤링에서는 큰 차이가 없었음
     - network performance가 더 좋은 c5.large,m5.large에서 크롤링을 했을때는 속도가 더 빨랐음

## 참고자료
<img width="952" alt="스크린샷 2024-03-29 오전 11 51 07" src="https://github.com/koorukuroo/pda_4th/assets/76093968/1bf72cc2-748a-44f5-8404-ba58f4b948cd">
<img width="955" alt="스크린샷 2024-03-29 오전 11 51 23" src="https://github.com/koorukuroo/pda_4th/assets/76093968/bb32b200-063a-4b29-a44a-f5d197517957">
<img width="942" alt="스크린샷 2024-03-29 오전 11 51 33" src="https://github.com/koorukuroo/pda_4th/assets/76093968/3a7fb98c-6202-4dbb-b879-59a731edfc6d">
<img width="943" alt="스크린샷 2024-03-29 오전 11 53 22" src="https://github.com/koorukuroo/pda_4th/assets/76093968/c21be26c-29a7-4cf1-b210-07b29f6977e2">




