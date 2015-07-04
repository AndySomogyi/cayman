set(SRC
    test.cc
    ca_run.cc
    ca_test1.cpp
    )

add_executable(pycalc_test ${SRC})

target_link_libraries (pycalc_test LINK_PUBLIC pycalc)

