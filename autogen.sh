# autogen.sh --
#
# Run this in the top source directory to rebuild the infrastructure.

set -xe

autoreconf --warnings=all --install --verbose
# --force

### end of file
