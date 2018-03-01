//
//  dft.h
//  photon
//
//  Copyright (C) 2018 Rue Yokaze
//  Distributed under the MIT License.
//
#include <math.h>
#include <stddef.h>

namespace photon
{
    template <class T, class C = T>
    void dft(const T* input_real, const T* input_imag, T* output_real, T* output_imag, size_t size)
    {
        const C unit = 2 * static_cast<C>(M_PI) / static_cast<C>(size);
        for (size_t o = 0; o < size; ++o)
        {
            T real = 0, imag = 0;
            for (size_t i = 0; i < size; ++i)
            {
                const C c = cos(unit * i * o);
                const C s = sin(unit * i * o);
                real += input_real[i] * c + input_imag[i] * s;
                imag += -input_real[i] * s + input_imag[i] * c;
            }
            *output_real++ = real;
            *output_imag++ = imag;
        }
    }
}
