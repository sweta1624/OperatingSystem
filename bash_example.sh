//bash script
//Write a menu driven bash script to perform the following. a. Check if a number is a Composite 
number b. Check if a number is an Automorphic number c. Check if a number is an Abundant 
number.

#!/bin/bash
# Function to check if a number is composite
composite() {
 n=$1
 i=2
 flag=0
 while [ $i -lt $n ]
 do
 if [ $((n%i)) -eq 0 ]
 then
 flag=1
 fi
 i=$((i+1))
 done
 if [ $flag -eq 1 ]
 then
 echo "$n is a composite number"
 else
 echo "$n is not a composite number"
 fi
}
# Function to check if a number is automorphic
automorphic() {
 n=$1
 square=$((n*n))
 if [ $((square%10)) -eq $n ]
 then
 echo "$n is an automorphic number"
 else
 echo "$n is not an automorphic number"
 fi
}
# Function to check if a number is abundant
abundant() {
 n=$1
 i=1
 sum=0
 while [ $i -lt $n ]
 do
 if [ $((n%i)) -eq 0 ]
 then
 sum=$((sum+i))
 fi
 i=$((i+1))
 done
 if [ $sum -gt $n ]
 then
 echo "$n is an abundant number"
 else
 echo "$n is not an abundant number"
 fi
}
# Menu
echo "Menu"
echo "1. Check if a number is a Composite number"
echo "2. Check if a number is an Automorphic number"
echo "3. Check if a number is an Abundant number"
echo "4. Quit"
# Loop to get user input and perform the desired operation
while :
do
 read -p "Enter your choice: " choice
 case $choice in
 1)
 read -p "Enter the number: " n
 composite $n
 ;;
 2)
 read -p "Enter the number: " n
 automorphic $n
 ;;
 3)
 read -p "Enter the number: " n
 abundant $n
 ;;
 4)
 exit
 ;;
 *)
 echo "Invalid choice"
 ;;
 esac
done


