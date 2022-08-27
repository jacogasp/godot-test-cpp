#!/bin/bash
platform=$1
arch=$2
build_type=$3

default_build_type="Debug"
default_arch="x64"
available_platforms="macos windows"
available_archs="x64 arm64"
available_build_types="Debug Release"

if [[ -z $platform ]]; then
  echo "You must enter a platform."
  exit
fi

if [[ -z $build_type ]]; then
  build_type=$default_build_type
fi

function exists_in_list() {
  LIST=$1
  DELIMITER=$2
  VALUE=$3
  LIST_WHITESPACES=$(echo "$LIST" | tr "$DELIMITER" " ")
  for x in $LIST_WHITESPACES; do
    if [ "$x" = "$VALUE" ]; then
      return 0
    fi
  done
  return 1
}

if [[ -z $arch ]]; then
  arch=$default_arch
fi

if ! exists_in_list "${available_platforms}" " " "${platform}"; then
  echo "${platform} is not a valid platform."
  exit
fi

if ! exists_in_list "${available_archs}" " " ${arch}; then
  echo "${arch} is not a valid architercure."
  exit
fi

if ! exists_in_list "${available_build_types}" " " ${build_type}; then
  echo "${build_type} is not a valid build_type."
  exit
fi

echo "Building for platform=${platform}, arch=${arch}, build_type=${build_type}"

build_dir="dist/${platform}/${arch}/${build_type}"
mkdir -p "$build_dir" &&
cd "$build_dir"

cmake ../../../.. -DCMAKE_BUILD_TYPE=${build_type}
cmake --build . -j4
