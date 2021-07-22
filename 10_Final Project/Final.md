# Final Project

#### 2016116563 윤성한

# 가로등 시뮬레이터

![g1](./image\g1.PNG)

```
개별 프로젝트로 
가로등 시뮬레이터를 구현해보았습니다.

pc화면에는 가상의 태양이 빛을 내뿜고있으며 이 태양의 빛의 세기에 따라 조그만 led가 반응합니다.

밤이 되면 귀여운 LED가 하나둘 씩 켜집니다.
```

* 개요

```
빛의 세기에 따라 보드에 내장된 led가 차례대로 점등되며 가장 어두운 경우 최대 4개의 led가 발광합니다. 가상의 태양을 프로세싱 화면상에 구현하여 시뮬레이션을 해봅니다.
```

* 준비물

```
빛의 세기를 감지 할 수있는 광센서가 필요합니다.
```

![a1](./image\a1.jpg)

```
SIG와 PA1을 연결 해주면 끝입니다.
```

### 시뮬레이션 시작

* 밝을 경우

![g1](./image\g1.PNG)

```
낮인 만큼 태양이 크게 떠서 밝기가 강함을 표현해줍니다.
```

![g3](./image\g3.PNG)

```
하단에는 글자 출력.
```



* 어두운 경우

![g2](./image\g2.PNG)

```
밤이 되어 태양이 거의 사라져 안 보임을 표현합니다.
```

![g4](./image\g4.PNG)

```
역시 하단에는 상태를 출력해줍니다.
```



![g5](./image\g5.PNG)

```
프로세싱 내부에서는 얼마의 값이 들어왔는지 터미널 상에서 출력해줍니다.
```



![g6](./image\g6.PNG)

```
입력 받은 ADC값에 따라 LED 개수를 조절하는 코드입니다.
```

* 데모영상

  <video src="C:\Users\성한\Desktop\개별과제\image\demo1.mp4"></video>

<video src="C:\Users\성한\Desktop\개별과제\image\demo2.mp4"></video>

---

reference : STM32F Reference Manual, STM User Guide

https://blog.naver.com/PostView.nhn?blogId=roboholic84&logNo=221235680319

http://interactivedesign21.blogspot.com/2017/12/blog-post_10.html

https://kocoafab.cc/tutorial/view/90

https://processing.org/reference/map_.html

https://venusyu.tistory.com/18

https://ko.wikipedia.org/wiki/ASCII

https://designatedroom87.tistory.com/306?category=902512
