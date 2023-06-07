#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 编译器对数组和指针的优化
 * 访问数组的元素时，C语言允许数组操作符（[]）和指针两种形式。然而使用C指针使得编译的优化工作更难。
 * 如果没有细致的分析，编译器可以认为指针可以指向任何内存单元，比如*p和*q可以指向相同的内存位置，
 * 然而x[0]和x[2]却是代表不同的内存位置。这样使用指针容易引起 别名
 * 问题：同一个内存位置可以以多种方式访问。通过减少 别名 ，使得编译的优化工作更加容易进行。
 * */

#define N 1000000000

typedef struct {
    float x, y, z, w;
} vertex;

typedef struct {
    float m[4][4];
} matrix;

void display_res(float *res)
{
    int i;

    for (i = 0; i < 4; i++)
        printf("%.2f ", res[i]);
    printf("\n");
}

//xform_pointer和xform_array分别被函数t_xform_pointer和t_xform_array测试性能
void xform_pointer(float *res, const float *v, const float *m, int numverts) {
    float dp;
    int i;
    const vertex *vv = (vertex *) v;

    for (i = 0; i < numverts; i++) {
        dp =  vv->x * *m++;
        dp += vv->y * *m++;
        dp += vv->z * *m++;
        dp += vv->w * *m++;
        *res++ = dp;

        dp =  vv->x * *m++;
        dp += vv->y * *m++;
        dp += vv->z * *m++;
        dp += vv->w * *m++;
        *res++ = dp;

        dp =  vv->x * *m++;
        dp += vv->y * *m++;
        dp += vv->z * *m++;
        dp += vv->w * *m++;
        *res++ = dp;

        dp =  vv->x * *m++;
        dp += vv->y * *m++;
        dp += vv->z * *m++;
        dp += vv->w * *m++;
        *res++ = dp;

        ++vv;
        m -= 16;
    }
    //display_res(res-4);
}

void xform_array(float *res, const float *v, const float *m, int numverts)
{
    int i;
    const vertex *vv = (vertex *)v;
    const matrix *mm = (matrix *)m;
    vertex *rr = (vertex *)res;

    for (i = 0; i < numverts; i++) {
        rr->x = vv->x * mm->m[0][0] + vv->y * mm->m[0][1] +
            vv->z * mm->m[0][2] + vv->w * mm->m[0][3];

        rr->y = vv->x * mm->m[1][0] + vv->y * mm->m[1][1] +
            vv->z * mm->m[1][2] + vv->w * mm->m[1][3];

        rr->z = vv->x * mm->m[2][0] + vv->y * mm->m[2][1] +
            vv->z * mm->m[2][2] + vv->w * mm->m[2][3];

        rr->w = vv->x * mm->m[3][0] + vv->y * mm->m[3][1] +
            vv->z * mm->m[3][2] + vv->w * mm->m[3][3];
    }
    //display_res(res);
}

//输入一个一维浮点数组v，和一个二维浮点数组m，将v和m中的每一行按行序相乘然后求和存到一个一维数组res中
void t_xform_array(float *res, const float *v, const float *m, int numverts)
{
    int i;
    clock_t begin, end;
    double time_spent;

    for (i = 0; i < 4; i++)
        *(res + i) = 0;

    time_spent = 0.0;
    begin = clock();
    for (i = 0; i < N; i++)
        xform_array(res, v, m, numverts);
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("array spent: %f\n", time_spent);
}

void t_xform_pointer(float *res, const float *v, const float *m, int numverts)
{
    int i;
    clock_t begin, end;
    double time_spent;

    for (i = 0; i < 4; i++)
        *(res + i) = 0;

    time_spent = 0.0;
    begin = clock();
    for (i = 0; i < N; i++)
        xform_pointer(res, v, m, numverts);
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("pointer spent: %f\n", time_spent);
}

int main(int argc, char *argv[])
{
    int i;
    float *res = (float*)malloc(4 * sizeof(float));
    float *m = (float*)malloc( 16 * sizeof(float));
    float *v = (float*)malloc(  4 * sizeof(float));


    for (i = 0; i < 4; i++)
        *(v + i) = i + 0.5;
    for (i = 0; i < 16;i++)
        *(m + i) = i + 0.5;

    t_xform_array(res, v, m, 1);
    t_xform_pointer(res, v, m, 1);

    return 0;
}

// 数组和指针在O2优化时性能差距是很小的，然而对于clang这样的编译器来说数组优化提升可以有37%，
// 这个数字是很大的。所以工程上的做法可以是编写指针和数组两套实现，
// 然后在具体的编译器下测试它们的性能。
// 这里也可以说clang O2对于指针性能优化应该还可以做的更好，
// 因为clang O2的array方式时间少很多，指令数上也可以看到clang对于指针别名问题可以说比较糟糕，
// 优化后指令数 反而比O0更多。可以比较、理解clang O2的二进制和gcc O2的二进制有何区别，
// 然后修改clang编译器相关的优化阶段。而gcc的O2对pointer的优化还稍微优一点，从这个方面说，gcc优秀。