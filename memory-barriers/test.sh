
declare -i counter=0

((counter=counter+1))
echo $counter

if [ $counter = 1 ]; then
    echo "YES"
fi
