/*
This file is part of mfaktc (mfakto).
Copyright (C) 2009 - 2013  Oliver Weihe (o.weihe@t-online.de)
                           Bertram Franz (bertramf@gmx.net)

mfaktc (mfakto) is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

mfaktc (mfakto) is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with mfaktc (mfakto).  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef mfakto_H_
#define mfakto_H_

#define NUM_KERNELS (sizeof(kernel_info)/sizeof(kernel_info[0]))
#define KERNEL_FILE "mfakto_Kernels.cl"
#define MAX_PRIMES_PER_THREAD	4224			// Primes up to 16M can be handled by this many "rows" of 256 primes (GPU sieving)

#ifdef __cplusplus
extern "C"
{
#endif

int init_CL(int num_streams, cl_int devicenumber);
int init_CLstreams(void);
int cleanup_CL(void);
void CL_test(cl_int devicenumber);
int tf_class_opencl(cl_ulong k_min, cl_ulong k_max, mystuff_t *mystuff, enum GPUKernels use_kernel);
void printArray(const char * Name, const cl_uint * Data, const cl_uint len, cl_uint hex);
cl_int run_calc_mod_inv(cl_uint numblocks, size_t localThreads, cl_event *run_event);
cl_int run_calc_bit_to_clear(cl_uint numblocks, size_t localThreads, cl_event *run_event, cl_ulong k_min);
cl_int run_cl_sieve(cl_uint numblocks, size_t localThreads, cl_event *run_event, cl_uint maxp);
int run_gs_kernel(cl_kernel kernel, cl_uint numblocks, cl_uint shared_mem_required, cl_uint shiftcount);
const char* ClErrorString( const cl_int errcode );

#ifdef __cplusplus
}
#endif

int run_kernel(cl_kernel l_kernel, cl_uint exp, int stream, cl_mem res);
int run_mod_kernel(cl_ulong hi, cl_ulong lo, cl_ulong q, cl_float qr, cl_ulong *res_hi, cl_ulong *res_lo);


#endif  /* #ifndef mfakto_H_ */
