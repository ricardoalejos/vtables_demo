#!/usr/bin/env bash

export VTABLES_ROOT=$(readlink -f $(dirname ${BASH_SOURCE[0]}))
export VTABLES_SOURCE=${VTABLES_ROOT}/source
export VTABLES_OUTPUT=${VTABLES_ROOT}/out
export VTABLES_BUILD=${VTABLES_OUTPUT}/build
export LD_LIBRARY_PATH=${VTABLES_OUTPUT}/lib:${LD_LIBRARY_PATH}

alias vtables_configure="cmake -S ${VTABLES_SOURCE} -B ${VTABLES_BUILD} -DCMAKE_INSTALL_PREFIX=${VTABLES_OUTPUT}"
alias vtables_test="make -C ${VTABLES_BUILD} test"
alias vtables_build="make -C ${VTABLES_BUILD} install"
alias vtables_clean="rm -rf out"
