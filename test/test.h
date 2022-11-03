#ifndef _TEST_INCLUDE_H_
#define _TEST_INCLUDE_H_

#include <iostream>

#include "rawbuffer.h"

struct mystruct0 {
    int xx;
    short yy;
    int zz;
};

std::ostream& operator<< (std::ostream &ost, const mystruct0& rhs) {
    ost << "xx=" << rhs.xx << "  " << "yy=" << rhs.yy << "  " << "zz=" << rhs.zz;
    return ost;
}

DEF_PACKET_BEGIN(test_type)
    ADD_FIELD_REQUIRED(int, a)

    ADD_FIELD_REQUIRED(double, b)

    ADD_FIELD_REQUIRED(mystruct0, c)

    ADD_FIELD_ARRAY_REQUIRED(int, d, 10)

    ADD_FIELD_ARRAY_REQUIRED(double, e, 10)

    ADD_FIELD_ARRAY_REQUIRED(mystruct0, f, 10)

    ADD_FIELD(int, aa)

    ADD_FIELD(double, bb)

    ADD_FIELD(mystruct0, cc)

    ADD_FIELD_ARRAY(int, ee, 10)

DEF_PACKET_END 

#endif // _TEST_INCLUDE_H_