import requests
from bs4 import BeautifulSoup
from tqdm import tqdm
import time

# 각 사이트 별 크롤링 속도와 총 크롤링 속도를 표기하는 코드
# 각 웹사이트 URL 리스트
urls = [
    "https://yarkyungmin.github.io/YaRkyungmin/",
    "https://jiyeon5.github.io/jiyeon5/",
    "https://Leehyeonju0219.github.io/Leehyeonju0219",
    "https://Yoon-97.github.io/Yoon-97",
    "https://subsub97.github.io/subsub97/",
    "https://sdc05103.github.io/sdc05103/",
    "https://yangjinhyeok.github.io/YangJinHyeok",
    "https://yoonjaeuk.github.io/yoonjaeuk/",
    "https://github.com/Elandland",
    "https://yapyap2.github.io/yapyap2/",
    "https://hyuna333.github.io/hyuna333/",
    "https://narongkim.github.io/narongkim/",
    "https://soyalattee.github.io/soyalattee/",
    "https://limsehyeon.github.io/LimSeHyeon",
    "https://shinheeeul.github.io/ShinHeeEul/",
    "https://wpdbs1229.github.io/wpdbs1229/",
    "https://nahyeonnnn.github.io/Nahyeonnnn/",
    "https://kimriun.github.io/KimRiun/",
    "https://jueunkim429.github.io/Jueunkim429/",
    "https://janjinn.github.io/janjinn",
    "https://yarkyungmin.github.io/YaRkyungmin/",
    "https://lemonticsoul.github.io/lemonticsoul",
    "https://gariguri.github.io/gariguri/",
    "https://github.com/JangHoIk1",
    "https://do-yoongyo2.github.io/do-yoongyo2/",
    "https://kyeongseo90.github.io/kyeongseo90/",
    "https://chaeyeonhan.github.io/ChaeyeonHan/",
    "https://colde99.github.io/colde99/",
    "https://kmj-99.github.io/kmj-99/",
    "https://jody816.github.io/jody816/",
    "https://phoebe125.github.io/Phoebe125/",
    "https://Erlhon9.github.io/Erlhon9/",
    "https://sooyeon-kr.github.io/sooyeon-kr",
    "https://ijustwannabeme.github.io/ijustwannabeme/",
    "https://jiyoongrace.github.io/Jiyoongrace",
    "https://ymkdev.github.io/ymkdev/",
    "https://github.com/sktmdgus1212/sktmdgus1212/",
    "https://donginlee.github.io/donginLee/",
    "https://onek-2.github.io/OneK-2/",
    "https://wlsdk9803.github.io/wlsdk9803/",
    "https://jaein1.github.io/JaeIn1/"
]

# 각 웹사이트에서 유튜브, 인스타그램, 링크드인 주소를 정리하는 함수
def extract_social_media_links(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    social_media_links = {'YouTube': [], 'Instagram': [], 'LinkedIn': []}
    for link in soup.find_all('a', href=True):
        href = link['href']
        if 'youtube.com' in href:
            social_media_links['YouTube'].append(href)
        elif 'instagram.com' in href:
            social_media_links['Instagram'].append(href)
        elif 'linkedin.com' in href:
            social_media_links['LinkedIn'].append(href)
    return social_media_links

# 각 웹사이트에서 유튜브, 인스타그램, 링크드인 주소를 출력하고 총 처리 시간을 출력
total_execution_time = 0  # 전체 크롤링에 걸린 총 시간 초기화
for url in tqdm(urls):
    start_time = time.time()
    social_media_links = extract_social_media_links(url)
    for platform, links in social_media_links.items():
        if links:
            print("주소:", url)
            print(f"{platform}:")
            for link in links:
                print(f"- {link}")
    end_time = time.time()
    total_time = end_time - start_time
    total_execution_time += total_time  # 각 웹사이트의 처리 시간을 전체 시간에 더함
    print(f"처리 시간: {total_time:.2f} 초\n")

# 전체 크롤링에 걸린 총 시간 출력
print(f"전체 크롤링에 걸린 총 시간: {total_execution_time:.2f} 초")
