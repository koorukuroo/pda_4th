# 환경
저희 조는 vcpu, 코어 수, 인스턴스 패밀리, 네트워크 전송속도 등을 비교 분석하였습니다.

# 지표
지표는 다음과 같습니다.
|지표|
|------|
|코드 실행 속도|
|네트워크 속도 차이|

# 인스턴스 유형
![image](https://github.com/koorukuroo/pda_4th/assets/83682424/1743f02f-125c-4a43-b832-c4c94147011f)

## t3.small <-> t3a.small
항상 작업은 AMD CPU를 사용해야 한다고 들어왔었기 때문에 이런 간단한 작업에서도
유의미한 차이가 날까 궁금하여 테스트를 진행하였고 실제로 CPU 제조사에 따른 성능차이가 있음을 확인하였습니다.

|종류|실행시간|
|------|---|
|t3a.small|40.04|
|t3.small|50.06|

<img width="585" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/5e4ea516-d69d-4cde-8049-794e747f93d6">

## t2.small <-> t3.small

T3의 장점이 T2에 비교하여 네트워크 속도가 향상되었기 때문에 아나콘다 파일을 얼마나 빠르게
다운로드 받는지 테스트하였고 실제로 속도 향상이 된 것을 확인할 수 있었습니다.

|종류|네트워크 속도|
|------|---|
|t2.small|6.73|
|t3.small|4.81|
<img width="620" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/aeaaf019-3f06-4119-8e77-ce04d432f230">


## t3.micro <-> t3.xlarge

t3.micro보다 t3.xlarge의 스펙이 다방면으로 높아
코드 실행속도가 많이 차이 날 것이라 생각했고 테스트를 한 결과
코어수가 두배차이 나는 만큼 실행속도도 약 두배차이가 나는 것을 확인하였습니다.

|종류|실행시간|
|------|---|
|t3.micro|52.07|
|t3.xlarge|26.03|

<img width="610" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/41c37443-1c31-459f-804a-d3472ee87cca">


## c4.large <-> m4.large <-> t3.large 

인스턴스 패밀리의 차이를 알아보기 위해 각 c,t,m을 비교하였는데
범용적인 m이 제일 느렸고
범용적이지만 터보기능을 지원하는 t3.large와
컴퓨팅 능력에 특화되어 있는 c4.large의 속도가 비슷한 것을 확인하였습니다.

|종류|실행시간|
|------|---|
|c4.large|48.02|
|t3.large|46.04|
|m4.large|62.05|

<img width="635" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/cb7fefb4-62e7-4f2b-a0b9-beaedda06781">

