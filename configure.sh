# configure.sh --
#

set -ex

prefix=/usr/local

../configure \
    --config-cache                              \
    --cache-file=../config.cache                \
    --prefix="${prefix}"                        \
    CFLAGS='-O3 -march=i686 -mtune=i686'        \
    "$@"

### end of file
