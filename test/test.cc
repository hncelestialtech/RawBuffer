#include "test.h"
#include "string.h"

using namespace rawbuf;

#define OUTPUT_TEST(x) std::cout <<"Line " RAW_BUF_STRING(__LINE__) ": " RAW_BUF_STRING(x) << std::endl; x; std::cout << std::endl

void test_rawapi()
{
    struct timespec begin{}, end{};
    int ar[10] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    int ar1[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0
    };

    double dar[10] = {
        3.14, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    int ar2[20] = {
        1, 2, 3, 1, 2, 4, 2, 4, 6, 2, 
        1, 3, 4, 5, 6, 7, 8, 4, 2, 3
    };

    struct mystruct0 m1 = {
        .xx = 1,
        .yy = 2,
        .zz = 3
    };
    struct mystruct0 mar[10] = {m1};

    clock_gettime(CLOCK_REALTIME, &begin);
    struct rawbuf_builder<test_type> instance;
    instance->a(1);
    instance->b(3.14);
    auto pinstance = instance();
    pinstance->c()->xx = 1;
    pinstance->c()->yy = 2;
    pinstance->c()->zz = 3;
    
    memcpy(pinstance->d(), ar, sizeof(ar));
    instance->d(ar1, 10);
    instance->e(dar, 10);
    instance->f(mar, 10);
    instance->aa(4);
    instance->bb(3.14);
    instance->cc(m1);
    instance->ee(ar2, 20);

    clock_gettime(CLOCK_REALTIME, &end);
    uint64_t duration = (end.tv_sec * 1000000000 + end.tv_nsec) - (begin.tv_sec * 1000000000 + begin.tv_nsec);
    
    OUTPUT_TEST(instance()->output(std::cout));
    
    std::cout<<"duration "<<duration<<" ns"<<std::endl;
}

int main() {
    test_rawapi();
}