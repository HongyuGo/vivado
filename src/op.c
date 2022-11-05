#include "../inc/op.h"

void op(int ChannelBits[Test_len], int output[Test_len])
{
	Matrix user_data[10];
	MATRIX_TYPE test_data[Test_len];

	MATRIX_TYPE *memory_row[2];
	MATRIX_TYPE memory_data[2][Test_len];
	memory_row[0] = &memory_data[0][0];
	memory_row[1] = &memory_data[1][0];


    MATRIX_TYPE gpr_target[5] ={1, 2,2,2, 1};
    //int gpr_length = sizeof(gpr_target)/sizeof(MATRIX_TYPE);
    int fir_length = 13;
    // int pr2_target[5] = {1,2,2,2,1};
    // int pr2_length = sizeof(pr2_target)/sizeof(int);
    int SNR_len = 1;
//    Matrix* BER1 = M_Zeros(2,2);
//    Matrix* BER2 = M_Zeros(SNR_len, 1);
//    Matrix* BER3 = M_Zeros(SNR_len, 1);
    for(int isnr = 1; isnr <= SNR_len; isnr++){
    	int numBits = 0;
    	int numErrs3 = 0;

    	if(numErrs3 < maxErrs && numBits < maxBits){
    		LOOP_getdata:for(int i = 0; i < Test_len; i++){
    			test_data[i] = ChannelBits[i];
    		}
    		user_data[0].data = &memory_row[0];
    		user_data[1].data = &memory_row[1];
//    		Matrix_gen(1,Test_len,test_data,&user_data[0]);
    		Matrix_gen(1,Test_len,test_data,&user_data[0],&memory_row[0]);
    		Matrix_gen(1,Test_len,test_data,&user_data[1],&memory_row[1]);
    	}
    }
    for(int kk = 0; kk < 3; kk++)
    {
    	for(int nn = 0; nn < 4; nn++){
    		int jjj = 9;
    	}
    }
    for(int i = 0; i < Test_len; i++){
    	output[i] = (int)user_data[0].data[0][i];
    }
}
