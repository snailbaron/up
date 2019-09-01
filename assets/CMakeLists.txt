include(GNUInstallDirs)

configure_file(
    fonts/clear-sans/ClearSans-Regular.ttf
    ${CMAKE_BINARY_DIR}/data/ClearSans-Regular.ttf
    COPYONLY)
