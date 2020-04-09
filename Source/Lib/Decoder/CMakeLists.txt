#
# Copyright(c) 2019 Intel Corporation
# SPDX - License - Identifier: BSD - 2 - Clause - Patent
#
# Decoder Library directory CMakeLists.txt

# Shared Decoder Version
set(DEC_VERSION_MAJOR 0)
set(DEC_VERSION_MINOR 8)
set(DEC_VERSION_PATCH 1)
set(DEC_VERSION ${DEC_VERSION_MAJOR}.${DEC_VERSION_MINOR}.${DEC_VERSION_PATCH})

# Include Decoder Subdirectories
include_directories(${PROJECT_SOURCE_DIR}/Source/API/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSSE3/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE4_1/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX512/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Decoder/Codec/
    ${PROJECT_SOURCE_DIR}/third_party/fastfeat/)

link_directories(
     ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/C_DEFAULT/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSSE3/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_SSE4_1/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX2/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/ASM_AVX512/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Common/Codec/
    ${PROJECT_SOURCE_DIR}/Source/Lib/Decoder/Codec/
    ${PROJECT_SOURCE_DIR}/third_party/fastfeat/)

set(all_files
    Codec/EbDecBitReader.h
    Codec/EbDecBitstream.c
    Codec/EbDecBitstream.h
    Codec/EbDecBitstreamUnit.c
    Codec/EbDecBitstreamUnit.h
    Codec/EbDecBlock.h
    Codec/EbDecCdef.c
    Codec/EbDecCdef.h
    Codec/EbDecHandle.c
    Codec/EbDecHandle.h
    Codec/EbDecInterPrediction.c
    Codec/EbDecInterPrediction.h
    Codec/EbDecIntraPrediction.c
    Codec/EbDecIntraPrediction.h
    Codec/EbDecInverseQuantize.c
    Codec/EbDecInverseQuantize.h
    Codec/EbDecLF.c
    Codec/EbDecLF.h
    Codec/EbDecMemInit.c
    Codec/EbDecMemInit.h
    Codec/EbDecNbr.c
    Codec/EbDecNbr.h
    Codec/EbDecObmc.c
    Codec/EbDecObmc.h
    Codec/EbDecParseBlock.c
    Codec/EbDecParseFrame.c
    Codec/EbDecParseFrame.h
    Codec/EbDecParseHelper.c
    Codec/EbDecParseHelper.h
    Codec/EbDecParseInterBlock.c
    Codec/EbDecParseInterBlock.h
    Codec/EbDecParseObu.c
    Codec/EbDecParseObuUtil.h
    Codec/EbDecPicMgr.c
    Codec/EbDecPicMgr.h
    Codec/EbDecProcess.c
    Codec/EbDecProcess.h
    Codec/EbDecProcessBlock.c
    Codec/EbDecProcessBlock.h
    Codec/EbDecProcessFrame.c
    Codec/EbDecProcessFrame.h
    Codec/EbDecRestoration.c
    Codec/EbDecRestoration.h
    Codec/EbDecStruct.h
    Codec/EbDecSuperRes.c
    Codec/EbDecUtils.c
    Codec/EbDecUtils.h
    Codec/EbObuParse.h
    )

if(UNIX)
    if(NOT APPLE)
        find_library(M_LIB name m)
        if(M_LIB)
            list(APPEND PLATFORM_LIBS m)
        endif()
    endif()
    set(LIBS_PRIVATE "-lpthread -lm")
endif()

if(COVERAGE)
    if(CMAKE_C_COMPILER_ID MATCHES "GNU")
        set(LIBS_PRIVATE "-lgcov ${LIBS_PRIVATE}")
    else(CMAKE_C_COMPILER_ID MATCHES "Clang")
        set(LIBS_PRIVATE "--coverage ${LIBS_PRIVATE}")
    endif()
endif()

# Decoder Lib Source Files
add_library(SvtAv1Dec
    ${all_files}
    $<TARGET_OBJECTS:COMMON_CODEC>
    $<TARGET_OBJECTS:FASTFEAT>
    $<TARGET_OBJECTS:COMMON_C_DEFAULT>
    $<TARGET_OBJECTS:COMMON_ASM_SSE2>
    $<TARGET_OBJECTS:COMMON_ASM_SSSE3>
    $<TARGET_OBJECTS:COMMON_ASM_SSE4_1>
    $<TARGET_OBJECTS:COMMON_ASM_AVX2>
    $<TARGET_OBJECTS:COMMON_ASM_AVX512>)

set_target_properties(SvtAv1Dec PROPERTIES VERSION ${DEC_VERSION})
set_target_properties(SvtAv1Dec PROPERTIES SOVERSION ${DEC_VERSION_MAJOR})
target_link_libraries(SvtAv1Dec ${PLATFORM_LIBS})
install(TARGETS SvtAv1Dec DESTINATION "${CMAKE_INSTALL_LIBDIR}")

configure_file(pkg-config.pc.in ${CMAKE_BINARY_DIR}/SvtAv1Dec.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/SvtAv1Dec.pc DESTINATION "${CMAKE_INSTALL_FULL_LIBDIR}/pkgconfig")
