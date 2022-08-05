# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/ublas
    REF boost-1.79.0
    SHA512 080ccf36bef22c72620f595b41e7bcaf9e900335ba662d5c605b03b710ce2ca0b64c9666b970331a2ecab870c3f8f14705defe7d7de57821b0f070a74ee89606
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})
