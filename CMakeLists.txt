cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(Deep-Q-Network)

#find_package(Torch REQUIRED)
#find_package(OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")


add_executable(main main.cpp)
#target_link_libraries(main "${TORCH_LIBRARIES}")
#target_link_libraries( main ${OpenCV_LIBS} )
set_property(TARGET main PROPERTY CXX_STANDARD 17)
