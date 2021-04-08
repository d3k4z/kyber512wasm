
//
//  PQCgenKAT_kem.c
//
//  Created by Bassham, Lawrence E (Fed) on 8/29/17.
//  Copyright © 2017 Bassham, Lawrence E (Fed). All rights reserved.
//
//  this script is edited by Deso
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rng.h"
#include "api.h"
#include <emscripten/emscripten.h>

#define	MAX_MARKER_LEN		50
#define KAT_SUCCESS          0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_DATA_ERROR      -3
#define KAT_CRYPTO_FAILURE  -4

int		FindMarker(FILE *infile, const char *marker);
int		ReadHex(FILE *infile, unsigned char *A, int Length, char *str);
void	fprintBstr(FILE *fp, char *S, unsigned char *A, unsigned long long L);

char                fn_req[32], fn_rsp[32];
FILE                *fp_req, *fp_rsp;
unsigned char       seed[48];
unsigned char       entropy_input[48];
unsigned char       ct[CRYPTO_CIPHERTEXTBYTES], ss[CRYPTO_BYTES], ss1[CRYPTO_BYTES];
int                 count;
int                 done;
unsigned char       pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
int                 ret_val;

int
main()
{
printf("\n");
printf("  |￣￣￣￣￣￣￣￣￣|\n");
printf("  | pqcrypto wasm?!  |\n");
printf("  |＿＿＿＿＿＿＿＿＿|\n");
printf("  (\\__/)|| \n");
printf("  (•ㅅ•)|| \n");
printf("  /,  .\\づ by d3k4z\n");
printf("\n");
}

#ifdef __cplusplus
extern "C" {
#endif

// int crypto_kem_keypair(unsigned char *pk, unsigned char *sk);

// int crypto_kem_enc(unsigned char *ct, unsigned char *ss, const unsigned char *pk);

// int crypto_kem_dec(unsigned char *ss, const unsigned char *ct, const unsigned char *sk);


// Encrypt

// Decrypt

// Priv / Pub keygen


void EMSCRIPTEN_KEEPALIVE crypto_keypair() {

    printf("if you see this a function is called\n");
    crypto_kem_keypair(pk, sk);
}

#ifdef __cplusplus
}
#endif