cmake_minimum_required(VERSION 3.9)
project(GameRPG C)

set(CMAKE_C_STANDARD 99)

add_executable(GameRPG main.c Player.h Player.c Move.c Random.c Monster.c Monster.h Fight.c Fight.h Move.h Random.h HeroMagic.c HeroMagic.h MonsterMagic.c MonsterMagic.h)