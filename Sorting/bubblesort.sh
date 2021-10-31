# Bubble Sort
echo "Enter number: "
read n
echo "Enter the elements: "
for(( i=0;i<n;i++ ))
do
  read a[i]
done

echo "Unsorted List is:"
echo -e "${a[@]} \t"

echo "Sorted List is: "
for(( i=0;i<n;i++ ))
do
  k=`expr $n-$i-1`
  for(( j=0;j<k;j++ ))
  do
    if [ ${a[j]} -gt ${a[$((j+1))]} ]
    then
      temp=${a[j]}
      a[$j]=${a[$((j+1))]}  
      a[$((j+1))]=$temp
    fi
  done
done

echo -e "${a[@]}"