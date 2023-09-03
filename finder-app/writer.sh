if [ $# -lt 2 ]
then
    echo "ERORR: Number of arguments should be 2"
    echo "The first argument should be full path to a file"
    echo "The second argument should be the text string which will be written within this file"
    exit 1
fi
writefile="$1"
writestr="$2"
if [ -z writefile ]
then
    echo "Write file argument cannot be empty"
fi
dir_name=$(dirname "$writefile")
mkdir -p $dir_name
echo "$writestr" > "$writefile"
exit 0