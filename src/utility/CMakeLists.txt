project(Value)

aux_source_directory(. DIR_SRC)

add_library(${PROJECT_NAME} SHARED ${DIR_SRC})
