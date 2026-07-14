# NumPy 이미지 밝기 분석 및 필터 프로그램

## 1. 프로젝트 소개

이 프로젝트는 Python의 **NumPy**와 **Pillow** 라이브러리를 활용하여 이미지의 밝기와 색상 정보를 분석하고, 여러 가지 필터를 적용하는 콘솔 프로그램입니다.

이미지를 NumPy의 3차원 배열로 변환한 뒤 배열 연산을 이용하여 이미지 전체의 밝기와 RGB 평균값을 계산합니다. 또한 흑백, 색상 반전, 밝기 증가, 밝기 감소 필터를 적용하고 결과 이미지를 새로운 파일로 저장할 수 있습니다.

### 주요 기능

* 이미지 파일 불러오기
* 이미지의 가로·세로 크기 확인
* RGB 색상별 평균값 계산
* 이미지 전체 평균 밝기 계산
* 어두운 이미지, 보통 이미지, 밝은 이미지 판정
* 흑백 필터 적용
* 색상 반전 필터 적용
* 이미지 밝게 만들기
* 이미지 어둡게 만들기
* 필터가 적용된 이미지 저장
* 잘못된 파일이나 입력에 대한 오류 처리

---

## 2. 프로젝트 실행 환경

이 프로젝트는 다음 환경을 기준으로 작성되었습니다.

* Python 3.13
* NumPy 2.5.1
* Pillow 12.3.0

### 사용된 라이브러리

#### NumPy

NumPy는 이미지의 픽셀을 다차원 배열로 변환하고 계산하는 데 사용됩니다.

이 프로젝트에서는 다음 기능을 사용합니다.

* `np.array()` : Pillow 이미지를 NumPy 배열로 변환
* `np.mean()` : RGB 평균과 전체 밝기 계산
* `np.stack()` : 흑백 배열을 RGB 형태로 변환
* `np.clip()` : 픽셀값을 0부터 255 사이로 제한
* `astype()` : 배열의 자료형 변환

#### Pillow

Pillow는 이미지 파일을 불러오고 저장하는 데 사용됩니다.

이 프로젝트에서는 다음 기능을 사용합니다.

* `Image.open()` : 이미지 파일 열기
* `convert("RGB")` : 이미지를 RGB 형식으로 변환
* `Image.fromarray()` : NumPy 배열을 Pillow 이미지로 변환
* `save()` : 변환된 이미지 저장

코드에서는 다음과 같이 불러옵니다.

```python
from PIL import Image
import numpy as np
```

Pillow는 설치할 때는 `Pillow`라는 이름을 사용하지만, 코드에서는 `PIL`이라는 이름으로 불러옵니다.

---

## 3. 프로젝트 폴더 구성

프로젝트 폴더는 다음과 같이 구성합니다.

```text
과제2(사용자 지정)
├── main.py
├── README.md
├── requirements.txt
└── 이미지.jpg (jpg 권장)
```

각 파일의 역할은 다음과 같습니다.

* `main.py` : 이미지 분석 및 필터 프로그램 코드
* `README.md` : 프로젝트 설명 문서
* `requirements.txt` : 프로젝트에서 사용하는 라이브러리와 버전 정보
* `이미지.jpg` : 분석에 사용할 이미지

프로그램 실행 후에는 필터가 적용된 결과 이미지가 추가됩니다.

```text
numpy_image_project
├── main.py
├── README.md
├── requirements.txt
├── 이미지.jpg
└── 색상 반전 이미지.jpg
└── 흑백 이미지.jpg
```

---

## 4. 가상환경을 사용하는 이유

이 프로젝트의 라이브러리는 반드시 **가상환경에서 설치하는 것을 권장합니다.**

가상환경은 프로젝트마다 독립된 Python 실행 환경을 만들어 줍니다.

가상환경을 사용하면 다음과 같은 장점이 있습니다.

* 다른 프로젝트의 라이브러리와 충돌하지 않습니다.
* 프로젝트마다 서로 다른 라이브러리 버전을 사용할 수 있습니다.
* 프로젝트에 필요한 라이브러리만 관리할 수 있습니다.
* `requirements.txt`를 이용해 동일한 환경을 다시 만들기 쉽습니다.
* 컴퓨터 전체 Python 환경이 복잡해지는 것을 방지할 수 있습니다.

예를 들어 A 프로젝트에서 NumPy 2.5.1을 사용하고 B 프로젝트에서 다른 버전을 사용하더라도, 각 프로젝트의 가상환경이 분리되어 있으면 서로 영향을 주지 않습니다.

---

## 5. 가상환경 생성 방법

### 5.1 프로젝트 폴더 열기

VS Code를 실행하고 다음 순서로 프로젝트 폴더를 엽니다.

```text
파일 → 폴더 열기 → 과제2(본인이 만든 폴더) 선택
```

VS Code에서 다음 메뉴를 선택해 터미널을 엽니다.

```text
터미널 → 새 터미널
```

터미널의 현재 위치가 프로젝트 폴더인지 확인합니다.

```powershell
PS C:\Users\사용자이름\Desktop\과제2>
```

다른 폴더가 표시된다면 `cd` 명령어로 이동합니다.

```powershell
cd "C:\Users\사용자이름\Desktop\과제2"
```

경로에 공백이나 한글이 포함되어 있을 수 있으므로 전체 경로를 큰따옴표로 묶는 것이 안전합니다.

---

### 5.2 가상환경 생성

프로젝트 폴더의 터미널에서 다음 명령어를 실행합니다.

```powershell
python -m venv .venv
```

`python` 명령어가 실행되지 않는 경우 다음 명령어를 사용합니다.

```powershell
py -m venv .venv
```

명령어가 정상적으로 실행되면 프로젝트 폴더 안에 `.venv` 폴더가 만들어집니다.

```text
numpy_image_project
├── .venv
├── main.py
├── README.md
└── 이미지.jpg
```

`.venv` 폴더에는 이 프로젝트에서 사용할 Python 실행 파일과 라이브러리가 저장됩니다.

---

### 5.3 가상환경 활성화

가상환경이 정상적으로 활성화되면 터미널 앞부분에 `(.venv)`가 표시됩니다.

```powershell
(.venv) PS C:\Users\사용자이름\Desktop\과제2>
```

앞에 `(.venv)`가 표시되는지 반드시 확인한 뒤 라이브러리를 설치해야 합니다.

---

## 6. 라이브러리 설치

터미널 앞에 `(.venv)`가 표시된 상태에서 다음 명령어를 실행합니다.

```powershell
python -m pip install numpy==2.5.1 Pillow==12.3.0
```

또는 다음 명령어를 사용할 수 있습니다.

```powershell
pip install numpy==2.5.1 Pillow==12.3.0
```

권장하는 방법은 현재 가상환경의 Python을 확실하게 사용하도록 다음 형식을 사용하는 것입니다.

```powershell
python -m pip install numpy==2.5.1 Pillow==12.3.0
```

### 설치 확인

다음 명령어를 실행합니다.

```powershell
python -c "import numpy; import PIL; print('설치 완료')"
```

다음과 같이 출력되면 정상적으로 설치된 것입니다.

```text
설치 완료
```

설치된 버전을 확인하려면 다음 명령어를 사용합니다.

```powershell
python -c "import numpy; import PIL; print('NumPy:', numpy.__version__); print('Pillow:', PIL.__version__)"
```

출력 예시는 다음과 같습니다.

```text
NumPy: 2.5.1
Pillow: 12.3.0
```

---

## 7. 코드 구조

프로그램은 기능에 따라 다음 다섯 개의 함수로 구성되어 있습니다.

```text
main()
 ├── load_image()
 ├── analyze_image()
 ├── apply_filter()
 └── save_image()
```

---

### 7.1 `load_image()` 함수

```python
def load_image():
```

사용자로부터 이미지 파일 이름을 입력받고 Pillow를 이용해 이미지를 불러오는 함수입니다.

주요 기능은 다음과 같습니다.

* 이미지 파일 이름 입력
* `Image.open()`으로 이미지 열기
* `convert("RGB")`로 RGB 형식 변환
* 존재하지 않는 파일에 대한 오류 처리
* 손상되었거나 지원되지 않는 파일에 대한 오류 처리

이미지를 RGB 형식으로 변환하는 이유는 흑백 이미지, RGB 이미지, 투명도가 있는 RGBA 이미지 등 서로 다른 형식을 모두 동일한 3채널 구조로 처리하기 위해서입니다.

이미지를 정상적으로 불러오면 Pillow 이미지 객체를 반환합니다.

```python
return Image.open(file_name).convert("RGB")
```

파일을 불러오지 못하면 `None`을 반환합니다.

---

### 7.2 `analyze_image()` 함수

```python
def analyze_image(image):
```

Pillow 이미지를 NumPy 배열로 변환하고 이미지 정보를 분석하는 함수입니다.

이미지는 다음 명령어를 통해 NumPy 배열로 변환됩니다.

```python
pixels = np.array(image)
```

일반적인 RGB 이미지 배열은 다음과 같은 구조를 가집니다.

```text
(세로 크기, 가로 크기, 색상 채널 수)
```

예를 들어 가로 1920픽셀, 세로 1080픽셀의 RGB 이미지는 다음 형태입니다.

```text
(1080, 1920, 3)
```

배열의 크기는 다음과 같이 분리합니다.

```python
height, width, channels = pixels.shape
```

RGB 색상별 평균은 다음 코드로 계산합니다.

```python
rgb_mean = np.mean(pixels, axis=(0, 1))
```

결과에는 빨간색, 초록색, 파란색의 평균값이 저장됩니다.

```python
rgb_mean[0]  # 빨간색 평균
rgb_mean[1]  # 초록색 평균
rgb_mean[2]  # 파란색 평균
```

이미지 전체의 평균 밝기는 다음과 같이 계산합니다.

```python
brightness = np.mean(pixels)
```

계산된 밝기에 따라 이미지를 세 단계로 분류합니다.

```text
0 이상 85 미만      : 어두운 이미지
85 이상 170 미만    : 보통 밝기의 이미지
170 이상 255 이하   : 밝은 이미지
```

분석을 마치면 이미지의 NumPy 배열인 `pixels`를 반환합니다.

---

### 7.3 `apply_filter()` 함수

```python
def apply_filter(pixels):
```

사용자가 선택한 필터를 이미지 배열에 적용하는 함수입니다.

사용할 수 있는 필터는 다음 네 가지입니다.

```text
1. 흑백
2. 색상 반전
3. 밝게
4. 어둡게
```

#### 흑백 필터

각 픽셀의 RGB 평균을 계산합니다.

```python
gray = np.mean(pixels, axis=2)
```

계산된 흑백값을 R, G, B 채널에 동일하게 넣습니다.

```python
result = np.stack((gray, gray, gray), axis=2)
```

예를 들어 다음 픽셀은

```text
[120, 180, 60]
```

평균값인 120을 이용해 다음과 같이 변환됩니다.

```text
[120, 120, 120]
```

#### 색상 반전 필터

각 픽셀값을 255에서 뺍니다.

```python
result = 255 - pixels
```

검은색은 흰색이 되고 흰색은 검은색이 됩니다.

```text
[0, 0, 0] → [255, 255, 255]
```

#### 밝게 만들기

모든 픽셀값에 50을 더합니다.

```python
result = pixels.astype(np.int16) + 50
```

계산 전에 자료형을 `int16`으로 변환하여 255를 넘는 값을 안전하게 계산합니다.

#### 어둡게 만들기

모든 픽셀값에서 50을 뺍니다.

```python
result = pixels.astype(np.int16) - 50
```

자료형을 `int16`으로 바꾸기 때문에 계산 과정에서 음수가 발생해도 안전하게 처리할 수 있습니다.

#### 픽셀 범위 제한

필터를 적용한 뒤 픽셀값을 0부터 255 사이로 제한합니다.

```python
result = np.clip(result, 0, 255)
```

예를 들어 290은 255로, -20은 0으로 변경됩니다.

```text
290 → 255
-20 → 0
```

마지막으로 이미지에 적합한 `uint8` 자료형으로 변환합니다.

```python
result = result.astype(np.uint8)
```

---

### 7.4 `save_image()` 함수

```python
def save_image(result, filter_name):
```

필터가 적용된 NumPy 배열을 이미지 파일로 저장하는 함수입니다.

NumPy 배열은 다음 명령어로 Pillow 이미지 객체로 변환됩니다.

```python
Image.fromarray(result)
```

변환된 이미지는 `save()`를 이용해 저장합니다.

```python
Image.fromarray(result).save(output_name)
```

사용자가 저장 파일 이름을 입력하지 않고 Enter를 누르면 필터에 따라 기본 이름을 사용합니다.

```text
흑백 필터       : result_grayscale.png
색상 반전 필터  : result_inverted.png
밝게 만들기     : result_bright.png
어둡게 만들기   : result_dark.png
```

---

### 7.5 `main()` 함수

```python
def main():
```

프로그램의 전체 실행 순서를 관리하는 함수입니다.

실행 순서는 다음과 같습니다.

1. 프로그램 제목 출력
2. 이미지 파일 불러오기
3. 이미지 분석
4. 필터 선택
5. 필터 적용
6. 결과 이미지 저장

이미지를 불러오지 못하거나 잘못된 필터 번호를 입력하면 `return`을 이용해 프로그램을 종료합니다.

프로그램의 마지막 줄에서 `main()` 함수를 호출합니다.

```python
main()
```

---

## 8. 프로그램 실행 방법

### 8.1 프로젝트 폴더 준비

`main.py`와 분석할 이미지 파일을 같은 폴더에 넣습니다.

```text
과제2
├── main.py
├── 이미지.jpg
├── README.md
└── requirements.txt
```

---

### 8.2 가상환경 활성화

터미널 앞에 `(.venv)`가 표시되는지 확인합니다.

```powershell
(.venv) PS C:\Users\사용자이름\Desktop\numpy_image_project>
```

---

### 8.3 라이브러리 설치

아직 라이브러리를 설치하지 않았다면 다음 명령어를 실행합니다.

```powershell
python -m pip install -r requirements.txt
```

---

### 8.4 프로그램 실행

다음 둘 중 하나의 명령어를 입력합니다.

```powershell
python main.py
py main.py
```

---

### 8.5 이미지 파일 이름 입력

프로그램이 이미지 파일 이름을 요청하면 확장자까지 입력합니다.

```text
분석할 이미지 파일 이름: 이미지.jpg
```

이미지가 다른 폴더에 있다면 전체 경로를 입력할 수 있습니다.

```text
C:\Users\사용자이름\Pictures\이미지.jpg
```

---

### 9.6 이미지 분석 결과 확인

이미지를 정상적으로 불러오면 다음과 같은 분석 결과가 출력됩니다.

```text
[이미지 분석 결과]
크기: 1920 x 1080px
색상 채널 수: 3
빨간색 평균: 132.51
초록색 평균: 128.27
파란색 평균: 119.83
전체 평균 밝기: 126.87
밝기 판정: 보통 밝기의 이미지
```

---

### 9.7 필터 선택

적용할 필터의 번호를 입력합니다.

```text
[필터 선택]
1. 흑백
2. 색상 반전
3. 밝게
4. 어둡게
번호 입력: 1
```

---

### 9.8 결과 이미지 저장

저장할 파일 이름을 입력합니다.

```text
저장 파일 이름(Enter: result_grayscale.png):
```

아무것도 입력하지 않고 Enter를 누르면 기본 이름으로 저장됩니다.

```text
완료: result_grayscale.png 파일로 저장했습니다.
```

저장된 결과 파일은 프로젝트 폴더에서 확인할 수 있습니다.

---
