#include <iostream>
#include "QLog.h"
#include "fileHandler.h"

int main(int argc, char **argv)
{
    QLog ql("Main", true);
    FileHandler fh(argv[1], std::ios::out);

    fh.write("Hello %s\n\tAgain\n", "World");

    ql.log(D, "Hello\t%d\t%d", D, 12);
    ql.log(W, "Hello\t%d\t%d", W, 13);
    ql.log(I, "Hello\t%d\t%d", I, 14);
    ql.log(E, "Hello\t%d\t%d", E, 15);
    ql.log(F, "Hello\t%d\t%d", F, 16);

    ql.log("Hello world\n%s:%f", "Test", 4.43);

    return 0;
}