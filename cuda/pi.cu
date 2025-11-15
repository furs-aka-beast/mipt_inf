#include <cuda.h>
#include <stdio.h>
#include <iostream>
#define THREAD_SIZE 5
__global__ void pi_kern(float *res, float *resx)
{
    int n = threadIdx.x + blockIdx.x * blockDim.x;
    float x0 = n * 1.f / (blockDim.x * gridDim.x); // Начало отрезка интегрирования
    float y0 = sqrtf(1 - x0 * x0), yx0 = x0 * y0;
    float dx = 1.f / (1.f * blockDim.x * gridDim.x *
                      THREAD_SIZE); // Шаг интегрирования
    float s = 0;                    // Значение интеграла по отрезку, данному текущему треду
    float sx = 0;
    float x1, y1, yx1;
    for (int i = 0; i < THREAD_SIZE; ++i)
    {
        x1 = x0 + dx;
        y1 = sqrtf(1 - x1 * x1);
        yx1 = x1 * y1;
        s += (y0 + y1) * dx / 2.f; // Площадь трапеции
        sx += (yx0 + yx1) * dx / 2.f;
        x0 = x1;
        y0 = y1;
        yx0 = yx1;
    }

    res[n] = s; // Запись результата в глобальную память
    resx[n] = sx;
}
int main()
{
    float *res_d;
    float *resx_d;
    float sol;
    cudaMalloc(&res_d, 64 * 64 * sizeof(float));
    cudaMalloc(&resx_d, 64 * 64 * sizeof(float));
    pi_kern<<<dim3(64), dim3(64)>>>(res_d, resx_d);
    float res[64 * 64], resx[64 * 64];
    cudaMemcpy(res, res_d, 64 * 64 * sizeof(float), cudaMemcpyDeviceToHost);
    cudaMemcpy(resx, resx_d, 64 * 64 * sizeof(float), cudaMemcpyDeviceToHost);

    float s = 0, sx = 0;
    for (int i = 0; i < 64 * 64; i++)
    {
        s += res[i];
        sx += resx[i];
    }
    sol = sx / s;
    printf("%f", sol);
}
