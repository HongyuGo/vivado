#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../inc/matrix.h"
#include "../inc/params.h"
#include "../inc/function.h"
#include <math.h>
#include <ap_cint.h>

#define Test_len 10
#define File_Test_len (Test_len + 1)

void op(MATRIX_TYPE ChannelBits[Test_len], MATRIX_TYPE output[Test_len + 10]);
