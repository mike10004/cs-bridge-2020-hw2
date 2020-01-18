#!/bin/bash

set -e

if [ -z "$1" ] ; then
  QUESTIONS=$(ls -d hw2q*)
  #echo "QUESTIONS=$QUESTIONS" >&2
else
  QUESTIONS=$1
fi

./allbuild.sh > /dev/null

WRONGS=""
RIGHTS=""

for Q in $QUESTIONS ; do
  EXEC="$Q/build/$Q"
  INFILE="$Q/input.txt"
  EXPECTEDFILE="$Q/expected-output.txt"
  if [ ! -f "$EXPECTEDFILE" ] ; then
    echo "file missing: $EXPECTEDFILE" >&2
    exit 1
  fi
  if [ -f "$INFILE" ] ; then
    OUTPUT=$("$EXEC" < "$INFILE")
  else
    echo "$Q: no input file" >&2
    OUTPUT=$("$EXEC")
  fi
  EXPECTED=$(cat "$EXPECTEDFILE")
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
  else
    RIGHTS="$Q $RIGHTS"
  fi
done

if [ -n "$WRONGS" ] ; then
  echo "wrong: $WRONGS" >&2
  exit 1
else
  echo "gravy: $RIGHTS"
fi
