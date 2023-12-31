/*
 * Created by Aleksey Cheusov <vle@gmx.net>
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining
 * a copy of the software and accompanying documentation covered by this license
 * (the “Software”) to use, reproduce, display, distribute, execute, and transmit
 * the Software, and to prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must be
 * included in all copies of the Software, in whole or in part, and all derivative
 * works of the Software, unless such copies or derivative works are solely in
 * the form of machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 * A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER
 * LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <string>
#include <iostream>
#include <cstdint>

///////////////////////////////////////
// user-defined settings
struct mytype {
    char _[8];
};

#ifndef PUSH_OP
# define PUSH_OP push_front
#endif // PUSH_OP

///////////////////////////////////////
// main code
static mytype value;

static void usage() {
    std::cerr << "usage: bench_SOMETHING ITEM_COUNT ITERATION_COUNT\n";
    exit(1);
}

int main(int argc, char **argv);
int main(int argc, char **argv)
{
    --argc;
    ++argv;
    if (argc != 2) {
        usage();
    }

    int item_count = std::stoi(argv[0]);
    int iteration_count = std::stoi(argv[1]);

    typedef LIST_TYPE list_type;
    list_type lists[iteration_count];
    for (int j = 0; j < iteration_count; ++j) {
        list_type &list = lists[j];
        for (int i = 0; i < item_count; ++i) {
                list.PUSH_OP(value);
        }
    }

    return 0;
}
