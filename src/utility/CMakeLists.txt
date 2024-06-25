project(utility)

aux_source_directory(. DIR_SRC)

add_library(${PROJECT_NAME} STATIC ${DIR_SRC})
