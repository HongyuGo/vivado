#ifndef _PARAMS_H_
#define _PARAMS_H_

//#define NO_SYNTH

#define maxErrs (100)
#define maxBits (1e10)
#define lamda (0.405)
#define NA (0.65)
#define t0 (0.86 * (lamda) / (NA))
#define T (1)
#define TL (0.102)
#define S ((t0) / (TL))
#define SectorLength (14)
#define delta (0.1)
#define edge_width (((fir_length)-1) / 2)
#define sigma_jitter ((0.01) * (TL))
#define KWinLen 1

#define _END_ -1
#define _HEAD_ 1
#define _DETAILED_ 2
#define _ROW_    1
#define _COLUMN_ 0

#define MATRIX_TYPE double
#define TRANS_TYPE  double



extern int SNR;
extern char constraint;
extern char method;
#endif
