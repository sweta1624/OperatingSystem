//to print a pattern
#!/bin/bash
for ((i=1; i<=5; i++))
do
 for ((j=i; j<=5; j++))
 do
 echo -n " "
 done
 for ((j=1; j<=i; j++))
 do
 echo -n "$((i+j-1))"
 done
 for ((j=1; j<i; j++))
 do
 echo -n "$((2*i-j-1))"
 done
 echo ""
done
