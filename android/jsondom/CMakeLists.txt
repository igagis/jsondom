cmake_minimum_required(VERSION 3.4.1)
set(name jsondom)
file(GLOB_RECURSE srcs "../../src/*.cpp")
include (${ANDROID_GRADLE_NATIVE_BUNDLE_PLUGIN_MK})
add_library(
        ${name}
        STATIC
        ${srcs}
    )
target_link_libraries(
        ${name}
        android log ${ANDROID_GRADLE_NATIVE_MODULES}
    )