from PIL import Image
import numpy as np

# 이미지 파일을 불러와 RGB 형식으로 변환하는 함수
def load_image():
    file_name = input("분석할 이미지 파일 이름: ")
    try:
        return Image.open(file_name).convert("RGB")
    except FileNotFoundError:
        print("ERROR: 이미지 파일을 찾을 수 없습니다.")
    except OSError:
        print("ERROR: 지원하지 않거나 손상된 이미지입니다.")
    return None

# 이미지의 크기, RGB 평균값, 전체 밝기를 분석하는 함수
def analyze_image(image):
    # Pillow 이미지를 NumPy 배열로 변환
    pixels = np.array(image)
    # 이미지 배열의 세로, 가로, 색상 채널 수 저장
    height, width, channels = pixels.shape
    # RGB 채널별 평균값과 전체 픽셀 평균 밝기 계산
    rgb_mean = np.mean(pixels, axis=(0, 1))
    brightness = np.mean(pixels)
    print("\n[이미지 분석 결과]")
    print(f"크기: {width} x {height}px")
    print(f"색상 채널 수: {channels}")
    print(f"빨간색 평균: {rgb_mean[0]:.2f}")
    print(f"초록색 평균: {rgb_mean[1]:.2f}")
    print(f"파란색 평균: {rgb_mean[2]:.2f}")
    print(f"전체 평균 밝기: {brightness:.2f}")
    # 평균 밝기에 따라 이미지 밝기 판정
    if brightness < 85:
        print("밝기 판정: 어두운 이미지")
    elif brightness < 170:
        print("밝기 판정: 보통 밝기의 이미지")
    else:
        print("밝기 판정: 밝은 이미지")
    return pixels

# 사용자가 선택한 필터를 이미지에 적용하는 함수
def apply_filter(pixels):
    print("\n[필터 선택]")
    print("1. 흑백")
    print("2. 색상 반전")
    print("3. 밝게")
    print("4. 어둡게")
    choice = input("번호 입력: ")
    if choice == "1":
        # RGB 평균값을 이용해 흑백 이미지 생성
        gray = np.mean(pixels, axis=2)
        result = np.stack((gray, gray, gray), axis=2)
        filter_name = "grayscale"
    elif choice == "2":
        # 각 픽셀값을 255에서 빼서 색상 반전
        result = 255 - pixels
        filter_name = "inverted"
    elif choice == "3":
        # 모든 픽셀값에 50을 더해 이미지를 밝게 변환
        result = pixels.astype(np.int16) + 50
        filter_name = "bright"
    elif choice == "4":
        # 모든 픽셀값에서 50을 빼 이미지를 어둡게 변환
        result = pixels.astype(np.int16) - 50
        filter_name = "dark"
    else:
        print("ERROR: 1~4 중에서 입력하세요.")
        return None, None
    # 픽셀값을 0~255 범위로 제한하고 이미지 자료형으로 변환
    result = np.clip(result, 0, 255)
    result = result.astype(np.uint8)
    return result, filter_name

# 필터가 적용된 이미지를 파일로 저장하는 함수
def save_image(result, filter_name):
    default_name = f"result_{filter_name}.png"
    output_name = input(f"저장 파일 이름(Enter: {default_name}): ")
    # 파일 이름을 입력하지 않으면 기본 이름 사용
    if output_name == "":
        output_name = default_name
    try:
        # NumPy 배열을 이미지로 변환한 후 저장
        Image.fromarray(result).save(output_name)
        print(f"완료: {output_name} 파일로 저장했습니다.")
    except OSError:
        print("ERROR: 이미지를 저장할 수 없습니다.")

# 프로그램의 전체 실행 순서를 관리하는 함수
def main():
    print("=== NumPy 이미지 분석 및 필터 프로그램 ===")
    image = load_image()
    # 이미지를 불러오지 못하면 프로그램 종료
    if image is None:
        return
    pixels = analyze_image(image)
    result, filter_name = apply_filter(pixels)
    # 필터 선택이 잘못되면 프로그램 종료
    if result is None:
        return
    save_image(result, filter_name)
main()