BEGIN {
FS="."
OFS=" : "
}
{
a = " LeetcodeSolved/$1.md"
print $1,$a
}
END{}
