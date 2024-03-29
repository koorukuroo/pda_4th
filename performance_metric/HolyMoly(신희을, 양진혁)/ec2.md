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
AMD를 사용하는 t3a.small과 인텔 cpu를 사용하는 t3.small을 비교 하였습니다.
|종류|실행시간|
|------|---|
|t3a.small|40.04|
|t3.small|50.06|

<img width="585" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/5e4ea516-d69d-4cde-8049-794e747f93d6">

## t2.small <-> t3.small
네트워크 성능의 차이가 있는 t2.small과 t3.small의 네트워크 속도를 비교하였습니다.

|종류|네트워크 속도|
|------|---|
|t2.small|6.73|
|t3.small|4.81|
<img width="620" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/aeaaf019-3f06-4119-8e77-ce04d432f230">

## t3.micro <-> t3.xlarge
vcpu와 코어 차이가 나는 t3.micro와 t3.xlarge의 컴퓨팅 능력을 비교하였습니다.

|종류|실행시간|
|------|---|
|t3.micro|52.07|
|t3.xlarge|26.03|

<img width="610" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/41c37443-1c31-459f-804a-d3472ee87cca">


## c4.large <-> m4.large <-> t3.large 
인스턴스 패밀리 차이를 알아보기 위해 c4.large, m4.large, t3.large를 비교하였습니다.
|종류|실행시간|
|------|---|
|c4.large|48.02|
|t3.large|46.04|
|m4.large|62.05|

<img width="635" alt="image" src="https://github.com/koorukuroo/pda_4th/assets/101380919/cb7fefb4-62e7-4f2b-a0b9-beaedda06781">

