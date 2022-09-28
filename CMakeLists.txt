CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(Wavez)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(wavez
	src/album.cpp
	src/artist.cpp
	src/main.cpp
	src/PasswordManager.cpp
	src/review.cpp
	src/song.cpp
	src/user.cpp
	src/UsernameManager.cpp
	src/wavez.cpp
)

ADD_EXECUTABLE(test
	tests/unit_test.cpp
	src/album.cpp
	src/artist.cpp
	src/PasswordManager.cpp
	src/review.cpp
	src/song.cpp
	src/user.cpp
	src/UsernameManager.cpp
	src/wavez.cpp
    )


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
