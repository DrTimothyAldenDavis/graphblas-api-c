/*
 * This file is part of the GraphBLAS Tutorial materials,
 * Copyright (c) 2018 Carnegie Mellon University and Intel Corporation.
 * All Rights Reserved
 *
 * THIS SOFTWARE IS PROVIDED "AS IS," WITH NO WARRANTIES WHATSOEVER. CARNEGIE
 * MELLON UNIVERSITY AND INTEL CORPORATION EXPRESSLY DISCLAIMS TO THE FULLEST
 * EXTENT PERMITTED BY LAW ALL EXPRESS, IMPLIED, AND STATUTORY WARRANTIES,
 * INCLUDING, WITHOUT LIMITATION, THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF PROPRIETARY RIGHTS.
 *
 * Released under a BSD (SEI)-style license, please see LICENSE.txt for
 * full terms.
 *
 * DM18-xxx
 *
 * Authors: Scott McMillan, Timothy G. Mattson
 */

/**
 * @file matvecTransIter.c
 *
 * @brief Code to hop to neighbors of a set of vertices iteratively
 *
 */

#include <stdio.h>
#include <GraphBLAS.h>
#include "tutorial_utils.h"

//****************************************************************************
int main(int argc, char** argv)
{
    GrB_Index const NUM_NODES = 7;
    GrB_Index const NUM_EDGES = 12;
    GrB_Index row_indices[] = {0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 6, 6};
    GrB_Index col_indices[] = {1, 3, 4, 6, 5, 0, 2, 5, 2, 2, 3, 4};
    bool values[] = {true, true, true, true, true, true,
                     true, true, true, true, true, true};

    // Initialize a GraphBLAS context
    GrB_init(GrB_BLOCKING);

    GrB_Matrix graph;
    GrB_Matrix_new(&graph, GrB_BOOL, NUM_NODES, NUM_NODES);
    GrB_Matrix_build(graph, row_indices, col_indices, (bool*)values, NUM_EDGES,
                     GrB_LOR);

    pretty_print_matrix_BOOL(graph, "GRAPH");

    // Build a vector to select a source node and another
    // vector to hold the mxv result.
    GrB_Index const SRC_NODE = 6;
    GrB_Vector frontier;
    GrB_Vector_new(&frontier, GrB_BOOL, NUM_NODES);
    GrB_Vector_setElement(frontier, true, SRC_NODE);

    // Build the transpose (INP0) descriptor
    GrB_Descriptor desc_t0;
    GrB_Descriptor_new(&desc_t0);
    GrB_Descriptor_set(desc_t0, GrB_INP0, GrB_TRAN);

    pretty_print_vector_BOOL(frontier, "Source vector");

    // traverse to neighbors of a frontier iteratively starting with SRC_NODE
    for (unsigned int iter = 0; iter < 15; ++iter)
    {
        GrB_mxv(frontier, GrB_NULL, GrB_NULL,
                GxB_LOR_LAND_BOOL, graph, frontier, desc_t0);
        pretty_print_vector_BOOL(frontier, "Frontier");
    }

    // Cleanup
    GrB_free(&graph);
    GrB_free(&frontier);
    GrB_free(&desc_t0);
    GrB_finalize();
}
