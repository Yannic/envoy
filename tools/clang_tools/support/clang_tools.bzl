def clang_tools_cc_binary(name, copts = [], tags = [], **kwargs):
    native.cc_binary(
        name = name,
        copts = copts + [
            "-fno-exceptions",
            "-fno-rtti",
        ],
        tags = tags + ["manual"],
        **kwargs
    )

def clang_tools_cc_library(name, **kwargs):
    native.cc_library(
        name = name,
        **kwargs
    )

def clang_tools_cc_test(name, deps = [], **kwargs):
    native.cc_test(
        name = name,
        deps = deps + ["@com_google_googletest//:gtest_main"],
        **kwargs
    )
