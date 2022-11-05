#include "./inc/op.h"

int main(){
	int i,retval = 0;
	FILE *fp;
	fp = fopen("./result.txt","w");

	int cha[Test_len] = {11,23,141,16,15};
	int out[Test_len];
	op(cha,out);
	for(i = 0; i < Test_len; i++){
		fprintf(fp, "%d ",out[i]);
	}

	fclose(fp);

	FILE *fp_result;
	fp_result = fopen("../target_result.txt","r");
	int *bench_out = (int*)(malloc)(sizeof(int) * Test_len);
	for(i = 0; i < Test_len; i++){
		fscanf(fp_result,"%d",&bench_out[i]);
	}
	for(i = 0; i < Test_len; i++){
		retval += bench_out[i] - out[i];
	}
//	retval = system("diff --brief -w result.dat result.golden.dat");
	if(retval != 0){
		printf("Test failed !!!!\n");
		retval = 1;
	}else{
		printf("Test passed !\n");
	}
	fclose(fp_result);
	return retval;
}
