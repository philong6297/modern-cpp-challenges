# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/static_string
    REF boost-1.79.0
    SHA512 bd94db596a4a8e4cdd1aca52fe75dbe46cd1242e67edee5f5fe236d39cb3368db7268ce9de6be5686da5fa19105c82616a3569b27c5c2e9974db9d18df73a8a7
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})