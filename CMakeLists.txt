cmake_minimum_required(VERSION 3.31)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-fetch REQUIRED PATHS node_modules/cmake-fetch)

project(bare_addon C CXX)

fetch_package("github:holepunchto/libjstl#cdf1d21")

add_bare_module(bare_addon)

target_sources(
  ${bare_addon}
  PRIVATE
    binding.cc
)

target_link_libraries(
  ${bare_addon}
  PRIVATE
    jstl
)
