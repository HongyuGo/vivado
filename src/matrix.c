#include "../inc/matrix.h"

//MATRIX_TYPE** GetMemory(int row, int col£¬)
//{
//	    MATRIX_TYPE ** data = NULL;
//	    MATRIX_TYPE *row_memory[row];
//	    int size = row * col;
//	    MATRIX_TYPE row_col_memory[row][col];
//	    row_memory[0] = &row_col_memory[row][0]
//	    for(int i = 0; i < row; i++){
//	    	row_memory[i] = &row_col_memory[i * col];
//	    }
//	    data = &row_memory[0];
//	    return data;
//}
/*Generate Zeros _matrix*/
//Matrix* M_Zeros(int row, int column) {
//	Matrix temp_get;
//    Matrix* Zero_mat = &temp_get;
//    int ii,jj;
//    Zero_mat->column = column;
//    Zero_mat->row = row;
//    MATRIX_TYPE** ppp = GetMemory(row,column);
//    //GET_MEMORY(ppp, row, column);
////    GetMemory(row,column);
//
//    for (ii = 0; ii <row; ii++) {
//        for(jj = 0; jj < column; jj++){
//           ppp[ii][jj] = 0;
//        }
//    }
//    Zero_mat->data = ppp;
//    return Zero_mat;
//}

//MATRIX_TYPE** GetMemory(int row, int col){
////#ifdef NO_SYNTH
////    MATRIX_TYPE ** data = NULL;
////    data = (MATRIX_TYPE **)malloc(sizeof(MATRIX_TYPE*) * row);
////    for(int i = 0; i < row; i++){
////        data[i] = (MATRIX_TYPE*)malloc(sizeof(MATRIX_TYPE) * col);
////    }
////#else
////    MATRIX_TYPE ** data = NULL;
////    MATRIX_TYPE *row_memory[row];
////    int size = row * col;
////    MATRIX_TYPE row_col_memory[row * col];
////    for(int i = 0; i < row; i++){
////    	row_memory[i] = &row_col_memory[i * col];
////    }
////    data = &row_memory[0];
////#endif
////    return data;
////	double **a = NULL;
////	double *b[row];
////	double c[row * col];
////	for(int i = 0 ; i < row; i++)
////	{
////		b[i] = &c[i * col];
////	}
////	a = &b[0];
////	return a;
//}
/* Generate Matrix Struct */
void Matrix_gen(int row, int column, MATRIX_TYPE data[row * column], Matrix *_mat,MATRIX_TYPE **memory){
//    Matrix* _mat = (Matrix*)malloc(sizeof(Matrix));
//    if (_mat == NULL) return 0;
    int i,j;
    _mat->row = row;
    _mat->column = column;
    for (i = 0; i < row; i++) {
        for(j = 0; j < column; j++){
            *(*(memory+i)+j) = data[i*row + j];
        }
    }
}
#if 0
/* Copy Mtrix(gen new one)*/
Matrix* Matrix_copy(Matrix* _mat_sourse) {
    int row = _mat_sourse->row;
    int col = _mat_sourse->column;
    int size = row * col;
    MATRIX_TYPE *data = (MATRIX_TYPE*)malloc(sizeof(MATRIX_TYPE) * size);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            data[i * row + j] = _mat_sourse->data[i][j];
        }
    }
    Matrix* _mat_copy = Matrix_gen(_mat_sourse->row, _mat_sourse->column, data);
    free(data);
    return _mat_copy;
}
/* Free Memory*/
int M_free(Matrix* _mat) {
    for(int i = 0; i < _mat->row; i++){
        free(_mat->data[i]);
    }
    free(_mat->data);
    //(_DETAILED_ >= 3) ? printf(">>Matrix_%x has been freed.\n", _mat) : 0;
    free(_mat);
    return 0;
}
/* Add & Sub*/
Matrix* M_add_sub(MATRIX_TYPE scale_mat_subed, Matrix* _mat_subed, MATRIX_TYPE scale_mat_minus, Matrix* _mat_minus) {
    Matrix* _mat_result = NULL;
    if ((_mat_subed->column == _mat_minus->column) && (_mat_subed->row == _mat_minus->row)) {
        _mat_result = Matrix_copy(_mat_subed);
        for(int i = 0; i < _mat_subed->row; i++){
            for(int j = 0; j < _mat_subed->column; j++){
                _mat_result->data[i][j] = (_mat_result->data[i][j]) * scale_mat_subed - (_mat_minus->data[i][j]) * scale_mat_minus;
            }
        }
    } 
    return _mat_result;
}
/*Cut_out_part_of_Matrix*/
Matrix* M_Cut(Matrix* _mat, int row_head, int row_tail, int column_head, int column_tail) {
    Matrix* mat_result = NULL;
    if (row_tail < 0) {
        if (row_tail == _END_) {
            row_tail = _mat->row;
        }
    }

    if (row_head < 0) {
        if (row_head == _END_) {
            row_head = _mat->row;
        }
    }

    if (column_tail < 0) {
        if (column_tail == _END_) {
            column_tail = _mat->column;
        }
    }

    if (column_head < 0) {
        if (column_head == _END_) {
            column_head = _mat->column;
        }
    }

    if ((row_tail > _mat->row) || (column_tail > _mat->column)) {

    } else {
        if ((row_head > row_tail) || (column_head > column_tail)) {

        } else {
            row_head = row_head - 1;
            column_head = column_head - 1;
            mat_result = (Matrix*)malloc(sizeof(Matrix));
            mat_result->row = row_tail - row_head;
            mat_result->column = column_tail - column_head;
            mat_result->data = GetMemory(mat_result->row,mat_result->column);
            int i, j;
            for (i = 0; i < (row_tail - row_head); i++) {
                for (j = 0; j < (column_tail - column_head); j++) {
                    mat_result->data[i][j] = _mat->data[i+row_head][j+column_head];
                }
            }
        }
    }
    return mat_result;
}
/*Full*/
Matrix* M_full(Matrix* _mat, int row_up, int row_down, int column_left, int column_right, MATRIX_TYPE full_data) {
    Matrix* mat_result = NULL;
    mat_result = (Matrix*)malloc(sizeof(Matrix));
    mat_result->row = (_mat->row + row_up + row_down);
    mat_result->column = (_mat->column + column_left + column_right);
    mat_result->data = GetMemory(mat_result->row,mat_result->column);
    int i, j;
    for (i = 0; i < mat_result->row; i++) {
        for (j = 0; j < mat_result->column; j++) {
            if ((i >= row_up) && (i < (row_up + _mat->row))) {
                if ((j >= column_left) && (j < (column_left + _mat->column))) {
                    mat_result->data[i][j] = _mat->data[i -row_up][j - column_left];
                } else {
                    mat_result->data[i][j] = full_data;
                }
            } else {
                mat_result->data[i][j] = full_data;
            }
        }
    }
    return mat_result;
}

/*Matrix Multiply*/
Matrix* M_nummul(Matrix* _mat, double _num) {
    MATRIX_TYPE** data = _mat->data;
    int i, j;
    for (i = 0; i < _mat->row; i++) {
        for(j = 0; j < _mat->column; j++){
            data[i][j] = data[i][j] * _num;
        }
    }
    return _mat;
}
/*Matrix sub*/
Matrix* M_numsub(Matrix* _mat, MATRIX_TYPE _num) {
    MATRIX_TYPE** data = _mat->data;
    int i, j; 
    for (i = 0; i < _mat->row; i++) {
        for(j = 0; j < _mat->column; j++){
            data[i][j] = data[i][j] - _num;
        }
    }
    return _mat;
}
/*Generation of transition matrix*/
Matrix* M_Transition(Matrix* _mat) {
    if (_mat == NULL) {
        return NULL;
    }
    if (_mat->column < 2) {
        return NULL;
    }
    Matrix* _mat_result = NULL;
    int row = _mat->row,col = _mat->column,i,j;
    MATRIX_TYPE** _data = GetMemory(row,col);
    for (i = 0; i < row; i++) {
        for(j = 0; j < col - 1; j++){
            _data[i][j] = _mat->data[i][j + 1] - _mat->data[i][j];
        }
    }
    _mat_result = (Matrix*)malloc(sizeof(Matrix));
    _mat_result->row = row;
    _mat_result->column = col - 1;
    _mat_result->data = _data;
    return _mat_result;
}
/*Find min value in a MATRIX_TYPE[*]*/
MATRIX_TYPE M_Min_value(MATRIX_TYPE *data, int size) {
    MATRIX_TYPE Val_min = data[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        if (data[i] <= Val_min) {
            Val_min = data[i];
        }
    }
    return Val_min;
}
/*Find max value in a MATRIX_TYPE[*]*/
MATRIX_TYPE M_Max_value(MATRIX_TYPE *data, int size) {
    MATRIX_TYPE Val_max = data[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        if (data[i] >= Val_max) {
            Val_max = data[i];
        }
    }
    return Val_max;
}
/*Assign a value to a position of the matrix*/
void M_value_one(Matrix *_mat, int row , int col,MATRIX_TYPE value){
    int _m_row = _mat->row;
    int _m_column = _mat->column;
    if(row <= 0 || row > _m_row || col <= 0 || col > _m_column){
        return;
    }
    _mat->data[row - 1][col - 1] = value;
}
/*Get a value to a position of the matrix*/
MATRIX_TYPE M_get_one(Matrix *_mat, int row, int col){
    int _m_row = _mat->row;
    int _m_column = _mat->column;
    if(row <= 0 || row > _m_row || col <= 0 || col > _m_column){
        return 0.0;
    }
    return _mat->data[row - 1][col - 1];
}
/*Transpose*/
Matrix *M_T(Matrix *_mat_source) {
    Matrix *_mat = (Matrix *) malloc(sizeof(Matrix));
    _mat->column = _mat_source->row;
    _mat->row = _mat_source->column;
    MATRIX_TYPE **data = GetMemory(_mat->row,_mat->column);
    _mat->data = data;
    int i, j;
    for (i = 0; i < (_mat->row); i++) {
        for (j = 0; j < _mat->column; j++) {
            data[i][j] = _mat_source->data[j][i];
        }
    }
    return _mat;
}
/*Matrix Multiply*/
Matrix *M_mul(Matrix *_mat_left, Matrix *_mat_right) {
    Matrix *_mat_result = NULL;
    if (_mat_left->column != _mat_right->row) {
    } else {
        _mat_result = (Matrix *) malloc(sizeof(Matrix));
        int row = _mat_left->row;
        int mid = _mat_left->column;
        int column = _mat_right->column;
        int i, j, k;
        MATRIX_TYPE **_data = GetMemory(row,column);
        MATRIX_TYPE temp = 0;
        /*Ergodic*/
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                /*Caculate Element*/
                temp = 0;
                for (k = 0; k < mid; k++) {
                    temp += (_mat_left->data[i][k]) * (_mat_right->data[k][j]);
                }
                _data[i][j] = temp;
            }
        }
        _mat_result->row = row;
        _mat_result->column = column;
        _mat_result->data = _data;
    }
    return _mat_result;
}
/*Matrix inverse*/
Matrix *M_Inverse(Matrix *_mat){
	int i,j;
    MATRIX_TYPE **TempA = _mat->data;
    Matrix *_mat_result = (Matrix*)malloc(sizeof(Matrix));
    MATRIX_TYPE **B = GetMemory(_mat->row,_mat->column);
    for(i = 0; i < _mat->row; i++){
        for(j = 0; j < _mat->column; j++){
            B[i][j] = 0.0;
        }
    }
	int c,m = _mat->row;
	double temp;
	double **A;

	/* Copying the input matrix TempA into matrix A */
	A = (double**)malloc(m*sizeof(double));
	for(i=0;i<m;i++)
	{
		A[i] = (double*)malloc(m*sizeof(double));
	}

	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			A[i][j] = TempA[i][j];
		}
	}

	/* Creating the identity matrix B */
	/* Memory for Matrix B should already be allocated and initialized to 0 */
	for(i=0;i<m;i++)
	{
			B[i][i] = 1;
	} 

	/*** Performing Gaussian elimination on A ***/

	for(c=0;c<m;c++)
	{/* loop over all columns of A */

		/*
		If diagnol element of column c is 0, then interchange row c with any other row
		so that diagnol element of column c is non-zero.
		*/
		if(A[c][c] == 0)
		{
			for(i=0;i<m;i++)
			{
				if(A[i][c] != 0)
				{
					/** Interchange row i and row c **/
					for(j=0;j<m;j++)
					{
						temp = A[i][j];
						A[i][j] = A[c][j];
						A[c][j] = temp;
						/* Do the same operation for B */
						temp = B[i][j];
						B[i][j] = B[c][j];
						B[c][j] = temp;
					}
					break;
				}
			}
		}

		/*
		Making the diagnol element of column c, A[c][c] 1 by dividing
		all the elements of row c, i.e. A[c][0 1 ... m-1] by A[c][c].
		*/
		if(A[c][c] != 1)
		{
			temp = A[c][c];
			for(j=0;j<m;j++)
			{
				A[c][j] = A[c][j]/temp;
				/* Do the same operation on the matrix B */
				B[c][j] = B[c][j]/temp;
			}
		}

		for(i=0;i<m;i++)
		{/* loop over all rows of A */

			/*
			Making all elements of column c as zero, except for the diagnol element,
			which is 1 at this point.
			*/
			if(i!=c)
			{
				temp = A[i][c];
				for(j=0;j<m;j++)
				{
					A[i][j] = A[i][j] - temp*A[c][j];
					B[i][j] = B[i][j] - temp*B[c][j];
				}
			}
		}/* loop over all rows of A */

	}/* loop over all columns of A */
	
	for(i=0;i<m;i++)
	{
		free(A[i]);
	}
	free(A);
    _mat_result->row = _mat->row;
    _mat_result->column = _mat->column;
    _mat_result->data = B;
    return _mat_result;
}
#endif
