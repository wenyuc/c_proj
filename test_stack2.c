
int add(int a, int b) {
    return a+b;
}

int main(int argc, char **argv) {
    int i=(int)(*argv[1]);
    int j=(int)(*argv[2]);
    int sum=add(i,j);
    argc--;
    return sum*argc;
}
