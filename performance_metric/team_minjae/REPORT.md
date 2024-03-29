## 테스트 환경
* Anaconda를 설치하여 파이썬 코드를 서버에서 실행시켰습니다.
* os는 ubuntu를 사용했습니다.
* 인스턴스 유형은 t2.micro와 t2.medium를 사용
* AMI는 amd64입니다.
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
|유형|t2.micro(초)|t2.medium(초)|c5.large|m5.large|
|-------|-------|-----|----|---|
|크롤링|19.5328|19.7202|16.4189|16.9833|
|for문|119.37|111.98|43.99|51.17|

## 이슈
1. 크롤링을 실행하였을 때 t2.medium이 t2.mircro보다 20배 느리게 나오는 문제
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




