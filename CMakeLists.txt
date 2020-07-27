cmake_minimum_required(VERSION 3.0)

project(OrbiSim VERSION 1.0) # set the project name

# configure_file(OrbiSimConfig.h.in OrbiSimConfig.h)

# target_include_directories(OrbiSim PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

include_directories()

# include files
include_directories( ./include ./src)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics audio)

include_directories(${SFML_INCLUDE_DIR}
                    ${EIGEN_INCLUDE_DIR}
)

# add the executable
add_executable("${PROJECT_NAME}" ./src/main.cpp ./src/celestial_body.cpp) 

target_link_libraries("${PROJECT_NAME}"
    sfml-system
    sfml-window
    sfml-graphics 
    sfml-audio
    # sfml-network
    # imgui
    # imgui-sfml
    Eigen3::Eigen
    )

# add_dependencies("${PROJECT_NAME}"
#     imgui
#     imgui-sfml
# )

# install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin 
# install(FILES "main.cpp" DESTINATION src)           #${CMAKE_INSTALL_PREFIX}/bin 