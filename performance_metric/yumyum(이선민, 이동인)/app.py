import os
import sys
import urllib.request
import time
import json

client_id = "f5GkBUJvh5eqGn4rMJeV"
client_secret = "OGv3UTtMkV"
encText = urllib.parse.quote("성수 맛집")
url = "https://openapi.naver.com/v1/search/blog?query=" + encText + "&display=100" # JSON 결과

start_crawl = time.time() # 시작 시간 기록

request = urllib.request.Request(url)
request.add_header("X-Naver-Client-Id",client_id)
request.add_header("X-Naver-Client-Secret",client_secret)
response = urllib.request.urlopen(request)
rescode = response.getcode()
if(rescode==200):
    response_body = response.read()
    json_data = json.loads(response_body.decode('utf-8'))
    items = json_data['items'] 
    for item in items:
      print(f"Blog 제목: {item['title']}\nBlog 링크: {item['link']}")
    # 크롤링 끝
    end_crawl = time.time() # 시작 시간 기록
    # 파일로 저장
    start_write = time.time()

    file_path = "./crawling_results.txt"
    with open(file_path, "w", encoding="utf-8") as file:
        for item in items:
            file.write(f"Blog 제목: {item['title']}\nBlog 링크: {item['link']}\n\n")

    # 파일 저장 종료 시간 기록
    end_write = time.time()
    print_time = end_write - start_write
    print(f"파일 출력 시간: {print_time}")

    # 총 수행 시간 계산
    crawl_time = end_crawl - start_crawl
    print(f"네이버 API response 받는 시간: {crawl_time}")

else:
    print("Error Code:" + rescode)