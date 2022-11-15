#include "../inc/op.h"
#define KWinLen 1
void op(MATRIX_TYPE ChannelBits[Test_len], MATRIX_TYPE output[Test_len + 10])
{
	int i;
	MATRIX_TYPE test_data[Test_len];
    MATRIX_TYPE gpr_target[5] ={1, 2,2,2, 1};

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
    		MATRIX_TYPE tempInputPad[1][Test_len + 1];
    		//memory_row_tempInputPad = &memory_data_tempInputPad[0][0];
    		tempInputPad[0][0] = 0.0;
    		for(i = 0; i < Test_len; i++){
    			tempInputPad[0][i + 1] = test_data[i];
    		}

    		//生成codedwords一维数组
    		//MATRIX_TYPE *memory_row_codedwords;
    		MATRIX_TYPE codewords[1][Test_len + 1];
    		codewords[0][0] = 0.0;
    		for(i = 0; i < Test_len + 1; i++){
    			codewords[0][i] = tempInputPad[0][i];
    		}
    		int codedlen = Test_len + 1;

    		MATRIX_TYPE ak[1][2 + Test_len];
    		for(i = 0; i < KWinLen; i++){
    			ak[0][i] = 0.0;
    		}
    		for(i = KWinLen; i < codedlen + KWinLen; i++){
    			ak[0][i] = codewords[0][i - KWinLen];
    		}
    		M_nummul(1,Test_len + 2,ak,2.0);
    		M_numsub(1,Test_len + 2,ak,1.0);


    		MATRIX_TYPE dk[1][Test_len + 1];
    		M_Transition(1,Test_len + 1,ak,dk);
    		M_nummul(1,Test_len + 1,dk,0.5);


    		//user_data[1].data = &memory_row_tempInputPad[0];
    		//Matrix_gen(1,Test_len + 1,)
    	    for(i = 0; i < File_Test_len; i++){
    	    	output[i] = dk[0][i];
    	    }
    	}
    }

}
