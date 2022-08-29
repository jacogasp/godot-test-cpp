mkdir -p  dist/.cmake
cd dist/.cmake
cmake ../.. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -j4
