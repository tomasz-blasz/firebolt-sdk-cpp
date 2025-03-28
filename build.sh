#!/bin/bash
set -e
usage()
{
   echo "options:"
   echo "    -t target sdk: core, manage, discovery"
   echo "    -p sdk path"
   echo "    -s sysroot path"
   echo "    -c clear build"
   echo "    -l enable static build"
   echo "    -i enable interactive application"
   echo "    -u disable unit tests (to allow testing with the transport)"
   echo "    -h : help"
   echo
   echo "Thunder's sysroot can be set via environment: SYSROOT_PATH"
   echo
   echo "usage: "
   echo "    ./build.sh -t <core | manage | discovery > [-p .] [-s THUNDER/install]"
}

SdkPath="."
SysrootPath=${SYSROOT_PATH}
ClearBuild="N"
EnableStaticLib="OFF"
EnableInteractiveApp="OFF"
EnableUnitTests="ON"
SdkTarget=
while getopts t:p:s:clbiuh flag
do
    case "${flag}" in
        t) SdkTarget="${OPTARG}";;
        p) SdkPath="${OPTARG}";;
        s) SysrootPath="${OPTARG}";;
        c) ClearBuild="Y";;
        l) EnableStaticLib="ON";;
        i) EnableInteractiveApp="ON";;
        u) EnableUnitTests="OFF";;
        h) usage && exit 1;;
    esac
done

case ${SdkTarget} in
core | manage | discovery);;
*)
    echo "Wrong SDK provided: '${SdkTarget}'"
    usage
    exit 1;;
esac

BuildDir="${SdkPath}/build/${SdkTarget}"

if [ "${ClearBuild}" == "Y" ];
then
    rm -rf ${BuildDir}
fi

rm -f ${BuildDir}/src/libFireboltSDK.so*
cmake -B${BuildDir} -S${SdkPath} \
  -DSDK_TARGET=${SdkTarget} \
  -DSYSROOT_PATH=${SysrootPath} \
  -DHIDE_NON_EXTERNAL_SYMBOLS=OFF \
  -DFIREBOLT_ENABLE_STATIC_LIB=${EnableStaticLib} \
  -DENABLE_INTERACTIVE_APP=${EnableInteractiveApp} \
  -DENABLE_UNIT_TESTS=${EnableUnitTests} \
  -DCMAKE_PREFIX_PATH="${CMAKE_PREFIX_PATH}" \
|| exit 1

cmake --build ${BuildDir} || exit 1
if [ -f "${BuildDir}/src/libFireboltSDK.so" ];
then
    cmake --install ${BuildDir} --prefix ${BuildDir}/Firebolt/usr || exit 1
fi
