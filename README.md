# Kiwi-App

[Kiwi 형태소 분석기](https://github.com/bab2min/Kiwi)를 사용한 샘플 프로그램

## 프로젝트 빌드
```
$ mkdir build && cd build
$ cmake ..
$ make
$ cd ..
$ ./kiwi-analyzer
```

## 프로젝트 구조
```
├── CMakeLists.txt
├── include             
│   └── kiwi              # Kiwi 헤더 파일
├── lib                   # Kiwi static 라이브러리
├── model                 # KiwiBuilder 실행 시 로드하는 학습된 형태소 분석기 모델
└── src
```

## 실행 결과
```
$ ./build/kiwi-analyzer
이것/NP + 은/JX + 먹이/NNG + 이/VCP + 다/EF + ./SF
kiwi-analyzer(80057,0x115de4e00) malloc: *** error for object 0x20000044600: pointer being freed was not allocated
kiwi-analyzer(80057,0x115de4e00) malloc: *** set a breakpoint in malloc_error_break to debug
[1]    80057 abort      ./build/kiwi-analyzer
```

프로그램 종료 시 `pointer being freed was not allocated` 에러 발생
