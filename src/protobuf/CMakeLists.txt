file(GLOB _all_proto_files  ${CMAKE_SOURCE_DIR}/protobuf/*.proto)
SET(_proto_gen_dir ${CMAKE_SOURCE_DIR}/src/protobuf)

foreach(__proto_file ${_all_proto_files})
    get_filename_component(__current_proto ${__proto_file} NAME)
    execute_process(COMMAND protoc -I=${CMAKE_SOURCE_DIR}/protobuf
            --cpp_out=${_proto_gen_dir}
            ${__current_proto})
endforeach(__proto_file)

file(GLOB PROTOBUF_SRC_FILES *.pb.*)
add_library(protobuf
    STATIC
    ${PROTOBUF_SRC_FILES}
)

target_link_libraries(protobuf
    ${PROTOBUF_LIB}
)