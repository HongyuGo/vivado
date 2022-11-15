#include "./inc/op.h"
int main(){
	int i,retval = 0;
	FILE *fp;
	fp = fopen("./result.txt","w");

	MATRIX_TYPE cha[Test_len] = {1,0,1,1,1,1,0,0,1,0};
	MATRIX_TYPE out[Test_len + 10];
	op(cha,out);
	for(i = 0; i < File_Test_len; i++){
		fprintf(fp, "%lf ",out[i]);
	}

	fclose(fp);

	FILE *fp_result;
	fp_result = fopen("../target_result.txt","r");
	MATRIX_TYPE *bench_out = (MATRIX_TYPE*)(malloc)(sizeof(MATRIX_TYPE) * (File_Test_len));
	for(i = 0; i < File_Test_len; i++){
		fscanf(fp_result,"%lf",&bench_out[i]);
	}
	for(i = 0; i < File_Test_len; i++){
		retval += abs(bench_out[i] - out[i]);
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
