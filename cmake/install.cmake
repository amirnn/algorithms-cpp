# install.cmake
# look at: https://cmake.org/cmake/help/latest/guide/importing-exporting/index.html

set(DSA_EXPORT_TARGET_NAME "${ARTIFACT_NAME_DSA}-targets")

# Specify module search paths
target_include_directories(
        ${ARTIFACT_NAME_DSA}
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/modules/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

install(TARGETS ${ARTIFACT_NAME_DSA}
        EXPORT ${DSA_EXPORT_TARGET_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILE_SET all_modules DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/modules
)

# export for build tree (without installation)
export(EXPORT ${DSA_EXPORT_TARGET_NAME}
        FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/dsa/dsa-targets.cmake"
        NAMESPACE dsa::
)

# install headers
#message(STATUS "Installing headers to: ${CMAKE_INSTALL_INCLUDEDIR}")
#install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/modules/include" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# export install
install(EXPORT ${DSA_EXPORT_TARGET_NAME}
        FILE "dsa-targets.cmake"
        NAMESPACE dsa::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dsa
)

# configure file
include(CMakePackageConfigHelpers)
configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/${ARTIFACT_NAME_DSA}-config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/${ARTIFACT_NAME_DSA}-config.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dsa
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/${ARTIFACT_NAME_DSA}-config.cmake"
#        "${CMAKE_CURRENT_BINARY_DIR}/${ARTIFACT_NAME_DSA}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dsa
)