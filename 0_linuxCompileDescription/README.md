1) 전처리 단계

소스 파일(file.c)에 gcc를 동작시키면 가장 먼저 전처리기인 cpp가 동작한다. cpp는 소스 파일의 #include와 #define과 같은 #으로 시작되는 전처리기 부분을 처리 한다. 즉, 필요한 헤더 파일을 삽입하고 실행 문장의 매크로를 상수로 변환한다. 소스 파일 file.c가 전처리기를 거치면 file.i라는 이름의 파일이 생성되지만 디스크에는 저장되지 않는다.

2) 컴파일 단계

컴파일러가 전처리된 파일(file.i)로부터 어셈블리어로 된 파일(file.s)을 생성한다. 그런데 일반적으로 다음 단계인 어셈블 단계를 바로 실행하므로 file.s 파일은 디스크에 저장되지 않는다.

3) 어셈블 단계

이 단계에서는 어셈블리어로 된 파일(file.s)을 기계가 직접 이해할 수 있는 기계어로 된 오브젝트 파일(file.o)로 변환한다.

4) 링크 단계

오브젝트 파일(file.o)은 printf, scanf와 같은 라이브러리 함수에 해당하는 코드가 없기 때문에 실행될 수 없다. 또한 여러 파일로 이루어진 프로그램의 경우에도 파일 간에 연결이 이루어지지 않아 실행될 수 없는데, 이러한 라이브러리 함수와 오브젝트파일들을 연결해 실행 파일을 생성하는 단계가 링크 단계이다.
그리고 컴파일을 할 때는 각 단계별로 옵션을 사용해 얼마나 진행되었는지 그 상황을 볼 수 있게 수동으로 제어할 수 있는데, 이에 대한 자세한 내용은 gcc 옵션에서 다룬다.


-c 옵션은 전처리, 컴파일, 어셈블까지 실행하여 오브젝트 파일(.o)을 생성한다.
example ) gcc -c sourcefileName 
 -> completed making Objectfile 'sourcefileName.o'
 ** note : not linking !!

 -o 옵션은 C 소스 코드를 컴파일 할 때 생성되는 출력 파일 이름을 지정하는 옵션
 example ) gcc -o sourcefileName sourcefileName.c
  -> completed making executable file 'sourcefileName'

함께 컴파일 하는 방법
1)  
gcc main.c hi.c -o test

2)  
	a) 어셈블까지 실행하여 오브젝트 파일(.o)을 생성
	   gcc -c hi.c 
	   gcc -c main.c
	   -> then, maked 'main.o' 'hi.o' object file.

	b) linking
		gcc main.o hi.o -o test