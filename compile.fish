#!/usr/bin/fish

echo Radhey Shyam

# Check if the argument exists
if test (count $argv) -ne 1
  echo "Usage: ./compile <filename.cpp>"
  exit 1
end

# set filename to first argument
set filename $argv[1]

if not test -f $filename
  echo "File '$filename' does not exist."
  exit 1
end

# extract the filename without the .cpp extention to name it as the binary file
set executable (basename $filename .cpp)

g++ -o $executable $filename ./utils.cpp

if test $status -ne 0
  echo "Compilation of '$filename' failed with status $status"
  exit 1
end

./$executable

