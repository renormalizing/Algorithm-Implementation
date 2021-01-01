
for((i=1;i<100;++i));do
    echo $i
    ./gen $i > int
    ./a < int > out1
    ./ans < int > out2
    diff -w out1 out2 || break
done
