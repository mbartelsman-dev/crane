function(snake_case UNSAFE_STRING OUT_VARIABLE)
    set(TEMP ${UNSAFE_STRING})
    string(REGEX REPLACE "[<>:/ \\ \| \. \? \*]" "_" TEMP ${TEMP})
    string(TOLOWER "${TEMP}" TEMP)
    set(${OUT_VARIABLE} ${TEMP} PARENT_SCOPE)
endfunction()

function(set_project_names PROJECT_NAME)
    string(REPLACE "." ";" COMPONENTS ${PROJECT_NAME})
    list(GET COMPONENTS 0 ROOT_NAME)
    list(GET COMPONENTS 1 MODULE_NAME)
    set(PROJECT_NAMESPACE  ${ROOT_NAME}::${MODULE_NAME})
    snake_case("${ROOT_NAME}_${MODULE_NAME}" PROJECT_FILE_NAME)
    string(TOUPPER ${PROJECT_FILE_NAME} PROJECT_MACRO_NAME)

    set(ROOT_NAME           ${ROOT_NAME} PARENT_SCOPE)
    set(MODULE_NAME         ${MODULE_NAME} PARENT_SCOPE)
    set(PROJECT_NAMESPACE   ${PROJECT_NAMESPACE} PARENT_SCOPE)
    set(PROJECT_FILE_NAME   ${PROJECT_FILE_NAME} PARENT_SCOPE)
    set(PROJECT_MACRO_NAME   ${PROJECT_MACRO_NAME} PARENT_SCOPE)
endfunction()

function(add_git_library libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
    target_compile_options(${libName} PRIVATE "-w")
endfunction()