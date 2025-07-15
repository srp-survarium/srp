char *__cdecl BN_bn2dec(const bignum_st *a)
{
  int v1; // eax
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ebp
  _DWORD *v5; // edi
  char *v6; // ebx
  bignum_st *v7; // eax
  char *v8; // esi
  int v9; // edx
  _DWORD *v10; // edi
  int v11; // edx
  bignum_st *v13; // [esp+10h] [ebp-Ch]
  _DWORD *v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v15 = 0;
  v13 = 0;
  v1 = BN_num_bits(a);
  v2 = 3 * v1 / 1000;
  v3 = (int)((unsigned __int64)(5153960757LL * v1) >> 32) >> 2;
  v4 = (v3 >> 31) + v3 + v2 + 2;
  v5 = CRYPTO_malloc(4 * (v4 / 9) + 4, ".\\crypto\\bn\\bn_print.c", 118);
  v14 = v5;
  v6 = (char *)CRYPTO_malloc(v4 + 3, ".\\crypto\\bn\\bn_print.c", 119);
  if ( v6 && v5 )
  {
    v7 = BN_dup(a);
    v13 = v7;
    if ( v7 )
    {
      v8 = v6;
      if ( v7->top )
      {
        if ( v7->neg )
        {
          *v6 = 45;
          v8 = v6 + 1;
        }
        if ( v7->top )
        {
          while ( 1 )
          {
            *v5++ = BN_div_word(v7, 0x3B9ACA00u);
            if ( !v13->top )
              break;
            v7 = v13;
          }
        }
        v9 = *(v5 - 1);
        v10 = v5 - 1;
        BIO_snprintf(v8, (unsigned int)&v6[v4 - (_DWORD)v8 + 3], "%u", v9);
        for ( ; *v8; ++v8 )
          ;
        while ( v10 != v14 )
        {
          v11 = *--v10;
          BIO_snprintf(v8, (unsigned int)&v6[v4 - (_DWORD)v8 + 3], "%09u", v11);
          for ( ; *v8; ++v8 )
            ;
        }
        v5 = v14;
        v15 = 1;
      }
      else
      {
        *v6 = 48;
        v6[1] = 0;
        v15 = 1;
      }
    }
  }
  else
  {
    ERR_put_error(3u, 104, 65, ".\\crypto\\bn\\bn_print.c", 122);
  }
  if ( v5 )
    CRYPTO_free(v5);
  if ( v13 )
    BN_free(v13);
  if ( v15 || !v6 )
    return v6;
  CRYPTO_free(v6);
  return 0;
}
