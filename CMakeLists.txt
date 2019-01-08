cmake_minimum_required(VERSION 3.12)
project(Project2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")



add_executable(Project2 main.cpp Server.h ClientHandler.h Solver.h MySerialServer.h MySerialServer.cpp CacheManager.h FileCacheManager.h StringReverser.h StringReverser.cpp MyTestClientHandler.h Searchable.h State.h Searcher.h BestFirstSearch.h PriorityQueue.h MyPriorityQueue.h)