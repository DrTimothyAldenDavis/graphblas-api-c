/*
 * Copyright (c) 2018 Carnegie Mellon University.
 * All Rights Reserved.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS," WITH NO WARRANTIES WHATSOEVER. CARNEGIE
 * MELLON UNIVERSITY EXPRESSLY DISCLAIMS TO THE FULLEST EXTENT PERMITTED BY LAW
 * ALL EXPRESS, IMPLIED, AND STATUTORY WARRANTIES, INCLUDING, WITHOUT
 * LIMITATION, THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, AND NON-INFRINGEMENT OF PROPRIETARY RIGHTS.
 *
 * This Program is distributed under a BSD license.  Please see LICENSE file or
 * permission@sei.cmu.edu for more information.  DM-0002659
 */

/**
 * @file algorithm_utils.h
 *
 * @brief Useful routines to use and test various algorithms.
 *
 * @todo Move implementation to a C file
 */

#ifndef ALGORITHM_UTILS_H
#define ALGORITHM_UTILS_H

#include <GraphBLAS.h>

//****************************************************************************
// pretty print a vector
void pretty_print_vector_BOOL(GrB_Vector vec, char const *label)
{
    GrB_Index N;
    GrB_Vector_size(&N, vec);

    bool val;
    GrB_Info ret_val;

    printf("Vector: %s =\n", label);

    printf("[");
    for (GrB_Index idx = 0; idx < N; ++idx)
    {
        ret_val = GrB_Vector_extractElement_BOOL(&val, vec, idx);
        if (GrB_SUCCESS == ret_val)
        {
            if (idx == 0)
            {
                printf("%3d", val);
            }
            else
            {
                printf(", %3d", val);
            }
        }
        else if (GrB_NO_VALUE == ret_val)
        {
            if (idx == 0)
            {
                printf("  -");
            }
            else
            {
                printf(",   -");
            }
        }
        else
        {
            if (idx == 0)
            {
                printf("  ERR");
            }
            else
            {
                printf(", ERR");
            }
        }
    }
    printf("]\n");

}

//****************************************************************************
// pretty print a vector
void pretty_print_vector_UINT64(GrB_Vector vec, char const *label)
{
    GrB_Index N;
    GrB_Vector_size(&N, vec);

    GrB_Index val;
    GrB_Info ret_val;

    printf("Vector: %s =\n", label);

    printf("[");
    for (GrB_Index idx = 0; idx < N; ++idx)
    {
        ret_val = GrB_Vector_extractElement_UINT64(&val, vec, idx);
        if (GrB_SUCCESS == ret_val)
        {
            if (idx == 0)
            {
                printf("%3ld", val);
            }
            else
            {
                printf(", %3ld", val);
            }
        }
        else if (GrB_NO_VALUE == ret_val)
        {
            if (idx == 0)
            {
                printf("  -");
            }
            else
            {
                printf(",   -");
            }
        }
        else
        {
            if (idx == 0)
            {
                printf("  ERR");
            }
            else
            {
                printf(", ERR");
            }
        }
    }
    printf("]\n");

}

//****************************************************************************
// pretty print a vector
void pretty_print_vector_FP64(GrB_Vector vec, char const *label)
{
    GrB_Index N;
    GrB_Vector_size(&N, vec);

    double val;
    GrB_Info ret_val;

    printf("Vector: %s =\n", label);

    printf("[");
    for (GrB_Index idx = 0; idx < N; ++idx)
    {
        ret_val = GrB_Vector_extractElement_FP64(&val, vec, idx);
        if (GrB_SUCCESS == ret_val)
        {
            if (idx == 0)
            {
                printf("%lf", val);
            }
            else
            {
                printf(", %lf", val);
            }
        }
        else if (GrB_NO_VALUE == ret_val)
        {
            if (idx == 0)
            {
                printf("  -");
            }
            else
            {
                printf(",   -");
            }
        }
        else
        {
            if (idx == 0)
            {
                printf("  ERR");
            }
            else
            {
                printf(", ERR");
            }
        }
    }
    printf("]\n");

}

//****************************************************************************
// pretty print a matrix
void pretty_print_matrix_BOOL(GrB_Matrix mat, char const *label)
{
    GrB_Index M,N;
    GrB_Matrix_nrows(&M, mat);
    GrB_Matrix_ncols(&N, mat);

    bool val;
    GrB_Info ret_val;

    printf("Matrix: %s =\n", label);
    for (GrB_Index row = 0; row < M; ++row)
    {
        printf("[");
        for (GrB_Index col = 0; col < N; ++col)
        {
            ret_val = GrB_Matrix_extractElement_BOOL(&val, mat, row, col);
            if (GrB_SUCCESS == ret_val)
            {
                if (col == 0)
                {
                    printf("%3d", val);
                }
                else
                {
                    printf(", %3d", val);
                }
            }
            else if (GrB_NO_VALUE == ret_val)
            {
                if (col == 0)
                {
                    printf("  -");
                }
                else
                {
                    printf(",   -");
                }
            }
            else
            {
                if (col == 0)
                {
                    printf("  ERR");
                }
                else
                {
                    printf(", ERR");
                }
            }
        }
        printf("]\n");
    }
}

//****************************************************************************
// pretty print a matrix
void pretty_print_matrix_UINT64(GrB_Matrix mat, char const *label)
{
    GrB_Index M,N;
    GrB_Matrix_nrows(&M, mat);
    GrB_Matrix_ncols(&N, mat);

    GrB_Index val;
    GrB_Info ret_val;

    printf("Matrix: %s =\n", label);
    for (GrB_Index row = 0; row < M; ++row)
    {
        printf("[");
        for (GrB_Index col = 0; col < N; ++col)
        {
            ret_val = GrB_Matrix_extractElement_UINT64(&val, mat, row, col);
            if (GrB_SUCCESS == ret_val)
            {
                if (col == 0)
                {
                    printf("%3ld", val);
                }
                else
                {
                    printf(", %3ld", val);
                }
            }
            else if (GrB_NO_VALUE == ret_val)
            {
                if (col == 0)
                {
                    printf("  -");
                }
                else
                {
                    printf(",   -");
                }
            }
            else
            {
                if (col == 0)
                {
                    printf("  ERR");
                }
                else
                {
                    printf(", ERR");
                }
            }
        }
        printf("]\n");
    }
}

//****************************************************************************
// pretty print a matrix
void pretty_print_matrix_FP64(GrB_Matrix mat, char const *label)
{
    GrB_Index M,N;
    GrB_Matrix_nrows(&M, mat);
    GrB_Matrix_ncols(&N, mat);

    double val;
    GrB_Info ret_val;

    printf("Matrix: %s =\n", label);
    for (GrB_Index row = 0; row < M; ++row)
    {
        printf("[");
        for (GrB_Index col = 0; col < N; ++col)
        {
            ret_val = GrB_Matrix_extractElement_FP64(&val, mat, row, col);
            if (GrB_SUCCESS == ret_val)
            {
                if (col == 0)
                {
                    printf("%3lf", val);
                }
                else
                {
                    printf(", %3lf", val);
                }
            }
            else if (GrB_NO_VALUE == ret_val)
            {
                if (col == 0)
                {
                    printf("  -");
                }
                else
                {
                    printf(",   -");
                }
            }
            else
            {
                if (col == 0)
                {
                    printf("  ERR");
                }
                else
                {
                    printf(", ERR");
                }
            }
        }
        printf("]\n");
    }
}

#endif
