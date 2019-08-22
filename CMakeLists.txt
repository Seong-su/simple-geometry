cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)
    set(CompilerFlags
            CMAKE_CXX_FLAGS
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_C_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            )
    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()

include(CTest)
enable_testing()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(LBT_INFO_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/include/occt)
set(OCCT_LIB_DIR ${PROJECT_SOURCE_DIR}/lib/win64/vc14/occt)
#PowerShell: Get-ChildItem -Path C:\Users\MNS-LAPTOP-MSI\projects\lbt-info\lib\win64\vc14\lib\* -Include *.lib -Name
set(OCCT_LIBS TKBin TKBinL TKBinTObj TKBinXCAF TKBO TKBool TKBRep 
    TKCAF TKCDF TKD3DHost TKDCAF TKDFBrowser TKDraw TKernel 
    TKFeat TKFillet TKG2d TKG3d TKGeomAlgo TKGeomBase TKHLR 
    TKIGES TKIVtk TKIVtkDraw TKLCAF TKMath TKMesh TKMeshVS 
    TKOffset TKOpenGl TKPrim TKQADraw TKService TKShapeView 
    TKShHealing TKStd TKStdL TKSTEP TKSTEP209 TKSTEPAttr TKSTEPBase 
    TKSTL TKTInspector TKTInspectorAPI TKTObj TKTObjDRAW TKToolsDraw 
    TKTopAlgo TKTopTest TKTreeModel TKV3d TKVCAF TKView TKViewerTest 
    TKVInspector TKVRML TKXCAF TKXDEDRAW TKXDEIGES TKXDESTEP TKXMesh 
    TKXml TKXmlL TKXmlTObj TKXmlXCAF TKXSBase TKXSDRAW )
#set(TBB_LIB_DIR ${PROJECT_SOURCE_DIR}/lib/win64/vc14/tbb)
#set(TBB_LIBS tbb tbbmalloc tbbproxy )

include_directories(${LBT_INFO_INCLUDE_DIR})
link_directories(${OCCT_LIB_DIR})
link_libraries(${OCCT_LIBS})

add_subdirectory(src)
add_subdirectory(test)