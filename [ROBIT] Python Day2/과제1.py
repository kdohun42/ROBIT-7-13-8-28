#과제1 | CSV 성적 관리 프로그램

import csv
import json

try:
    with open(r"C:\Users\PC User\Desktop\[ROBIT] Python Day2\students.csv", newline="",encoding="utf-8") as file:
    
        reader = csv.reader(file)
        header = next(reader) # 필수 기능 1 - 첫 행을 header로 건너뛴다

        clean_students = [] # 유효 행 저장할 리스트

        for row in reader: 
            name = row[0]
            score = (row[1])
        
            try:
                int_score = int(score) 
            # 숫자 변환이 되지 않을 때 ValueError (문자열인 것을 정수형으로 변환 시킬 때)
            except ValueError:
                print(f"{score} -> 숫자 변환에 실패했습니다.")
                continue 
            # 필수 기능 2 - score을 int로 바꾸고 0~100 범위를 검사한다.
            if int_score < 0 or int_score > 100:
                print(f"{int_score} -> 허용 범위를 초과했습니다.")
                continue
            # 필수 기능 3 - 오류 행은 이유를 출력하고 다음 행을 계속 처리한다.
            # 필수 기능 4 - 유효 행은 clean_students.cvs로 저장한다.
            clean_students.append([name, int_score]) # 모든 과정을 통과한 행들만 리스트에 저장

    with open(r"C:\Users\PC User\Desktop\[ROBIT] Python Day2\clean_students.csv", "w", newline="", encoding="utf-8") as file:

            writer = csv.writer(file) #writer 사용
            writer.writerow(["name", "score"])
            writer.writerows(clean_students)

    scores = []

    for student in clean_students:
        scores.append(student[1])

    num_of_stu = len(scores) #인원수

    if num_of_stu > 0:
        average = sum(scores) / num_of_stu #평균
        highest = max(scores) #최고점
    else:
        average = 0
        highest = 0

    summary = {
        "number_of_student": num_of_stu,
        "average": average,
        "highest": highest
    }
    # 필수 기능 5 - 인원수, 평균, 최고점을 summart.json으로 저장한다.
    with open(r"C:\Users\PC User\Desktop\[ROBIT] Python Day2\summary.json", "w", encoding="utf-8") as file:
        json.dump(summary, file, ensure_ascii=False, indent=4)

except FileNotFoundError: #파일 인식되지 않을 때 FileNotFoundError 처리
    print("파일을 찾을 수 없습니다.")
