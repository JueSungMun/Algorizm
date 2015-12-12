#include "MY_HEADER.h"
#ifdef MOSAIC
/*
	파일 이름 : [JO] Mosaic.cpp
	작성자 : 주성문
	목적 : 정보올림피아드 알고리즘 문제 1219번 모자이크 문제 해결
	       입력으로 주어진 벽면에 잘못 칠해진 부분을 표시할 색종이의 크기 출력
	사용방식 : 빌드시 main함수 부분을 선택하기 위하여 MY_HEADER.h 필요
	오류처리 : 입력값의 범위 체크 필요
			   도화지 행, 열의 개수 1,000,000 이하
			   사용할 색종이 100장 이하
			   잘못칠해진 칸의 개수 : 1,000개 이하
	주의사항 : [색종이 조건 - 1. 사용되는 색종이는 모두 크기가 같고 정사각형 모양
							  2. 색종이의 크기는 한변의 길이를 나타내며, 원하는 크기의 색종이는 모두 구할 수 있다.
							  3. 모든 색종이는 반드시 도화지의 밑변에 맞추어 붙인다. 이 때 색종이를 겹쳐서 붙일 수 있다.
	입출력 예시 : [입력 형식]
				  첫째 줄 - 도화지 위의 행의 개수와 열의 개수를 나타내는 자연수 (1,000,000 이하)
				  둘째 줄 - 사용할 색종이의 장수를 나타내는 자연수 (100이하)
				  셋째 줄 - 도화지에 잘못 칠해진 칸의 개수를 나타내는 자연수 (1,000이하)
				  넷째 줄 ~ 마지막 줄 - 잘못 칠해진 칸의 위치가 한줄에 하나씩 주어진다.
				  [출력형식]
				  첫째 줄에 주어진 장수의 색종이를 사용하여 잘못 칠해진 칸을 모두 가릴 수 있는 가장 작은 색종이의 크기 출력
				  ex) 4 14
					  4
					  9
					  1 2
					  2 1
					  2 3
					  1 6
					  3 5
					  1 10
					  3 6
					  1 12
					  2 13
				 ===> 출력 3
	이력 사항 : 
	*/

#endif