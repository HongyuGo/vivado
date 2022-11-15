#include "../inc/op.h"
#define KWinLen 1
void op(MATRIX_TYPE ChannelBits[Test_len], MATRIX_TYPE output[Test_len + 10])
{
	int i;
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

    for(int isnr = 1; isnr <= SNR_len; isnr++){
    	int numBits = 0;
    	int numErrs3 = 0;

    	if(numErrs3 < maxErrs && numBits < maxBits){
    		LOOP_getdata:for(int i = 0; i < Test_len; i++){
    			test_data[i] = ChannelBits[i];
    		}

    		//生成tempInputPad一维数组
    		//MATRIX_TYPE *memory_row_tempInputPad;
    		MATRIX_TYPE memory_data_tempInputPad[1][Test_len + 1];
    		//memory_row_tempInputPad = &memory_data_tempInputPad[0][0];
    		memory_data_tempInputPad[0][0] = 0.0;
    		for(i = 0; i < Test_len; i++){
    			memory_data_tempInputPad[0][i + 1] = test_data[i];
    		}

    		//生成codedwords一维数组
    		//MATRIX_TYPE *memory_row_codedwords;
    		MATRIX_TYPE memory_data_codewords[1][Test_len + 1];
    		memory_data_codewords[0][0] = 0.0;
    		for(i = 0; i < Test_len + 1; i++){
    			memory_data_codewords[0][i] = memory_data_tempInputPad[0][i];
    		}
    		int codedlen = Test_len + 1;
    		//int codeBitsLength = codedlen - 1;

    		//生成ak一维数组
    		//MATRIX_TYPE *memory_row_ak;
    		MATRIX_TYPE memory_data_ak[1][2 + Test_len];
    		//memory_row_ak = &memory_data_ak[0][0];
    		for(i = 0; i < KWinLen; i++){
    			memory_data_ak[0][i] = 0.0;
    		}
    		for(i = KWinLen; i < codedlen + KWinLen; i++){
    			memory_data_ak[0][i] = memory_data_codewords[0][i - KWinLen];
    		}
    		M_nummul(1,Test_len + 2,memory_data_ak,2.0);
    		M_numsub(1,Test_len + 2,memory_data_ak,1.0);


    		MATRIX_TYPE memory_data_dk[1][Test_len + 1];
    		M_Transition(1,Test_len + 1,memory_data_ak,memory_data_dk);
    		M_nummul(1,Test_len + 1,memory_data_dk,0.5);


    		//user_data[1].data = &memory_row_tempInputPad[0];
    		//Matrix_gen(1,Test_len + 1,)
    	    for(i = 0; i < File_Test_len; i++){
    	    	output[i] = memory_data_dk[0][i];
    	    }
    	}
    }

}
