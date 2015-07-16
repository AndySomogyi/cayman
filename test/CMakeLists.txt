set(SRC
    test.cc
    ca_run.cc
    ca_test1.cpp
    )

set(HEADERS
    cayman_test.h
    )

add_executable(cayman_test ${SRC} ${HEADERS})

target_link_libraries (cayman_test LINK_PUBLIC cayman)

