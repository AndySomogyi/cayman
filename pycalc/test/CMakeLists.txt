set(SRC
    test.cc
    )

add_executable(pycalc_test ${SRC})

target_link_libraries (pycalc_test LINK_PUBLIC pycalc)

