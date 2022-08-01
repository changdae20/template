################## OPENCV #####################
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})
###############################################

################# PROTOBUF #################
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})
############################################

################## fmt #################
find_package(fmt REQUIRED)
########################################

add_subdirectory(protobuf)

SET(UTIL
    util.hpp
    util.cpp
)

SET(PROTOBUF_LIB
    protobuf
)

add_library(${PROJECT_NAME}
    ${UTIL}
)

link_directories(${PROJECT_NAME})

add_executable(main
	${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROTOBUF_SRC_FILES}
    ${UTIL}
)

target_link_libraries(main
    ${OpenCV_LIBS}
    ${PROTOBUF_LIB}
    ${PROTOBUF_LIBRARIES}
    fmt::fmt
)



###################################################################################################
# - library targets -------------------------------------------------------------------------------

file(GLOB OPENCV_DLL_FILES
	"${OpenCV_INCLUDE_DIRS}/../x64/vc15/bin/*.dll"
)

file(COPY ${OPENCV_DLL_FILES} DESTINATION "./")

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${OpenCV_LIBS}
    ${PROTOBUF_LIB}
    ${UTIL}
    ${PROTOBUF_LIBRARIES}
    fmt::fmt
)