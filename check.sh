#!/bin/bash

set -e

if [ -z "$1" ] ; then
  QUESTIONS=$(ls hw2q*)
else
  QUESTIONS=$1
fi

./allbuild.sh > /dev/null

WRONGS=""

for Q in $QUESTIONS ; do
  EXEC="$Q/build/$Q"
  OUTPUT=$($EXEC < "$Q/input.txt")
  EXPECTED=$(cat "$Q/expected-output.txt")
  if [ "$OUTPUT" != "$EXPECTED" ] ; then
    WRONGS="$Q $WRONGS"
    echo "$Q: expected" >&2
    echo
    echo "$EXPECTED"
    echo
    echo "$Q: actual"
    echo
    echo "$OUTPUT"
    echo
  fi
done

if [ -n "$WRONGS" ] ; then
  echo "wrong: $WRONGS" >&2
  exit 1
fi
