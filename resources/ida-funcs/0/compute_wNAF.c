char *__usercall compute_wNAF@<eax>(int w@<edi>, const bignum_st *scalar, unsigned int *ret_len)
{
  signed int v3; // ebx
  char *result; // eax
  int v5; // ebp
  unsigned int v6; // esi
  int v7; // ecx
  char v8; // al
  char *v9; // ecx
  int v10; // [esp-4h] [ebp-24h]
  char *str; // [esp+Ch] [ebp-14h]
  unsigned int v12; // [esp+10h] [ebp-10h]
  char v13; // [esp+14h] [ebp-Ch]

  v3 = (signed int)scalar;
  str = 0;
  v13 = 1;
  if ( !scalar->top )
  {
    result = (char *)CRYPTO_malloc(1, ".\\crypto\\ec\\ec_mult.c", 204);
    str = result;
    if ( result )
    {
      *result = 0;
      *ret_len = 1;
      return result;
    }
    ERR_put_error((int)scalar, 0x10u, 143, 65, ".\\crypto\\ec\\ec_mult.c", 207);
    goto LABEL_33;
  }
  if ( (unsigned int)(w - 1) > 6 )
  {
    v10 = 217;
    goto LABEL_32;
  }
  v5 = 1 << w;
  if ( scalar->neg )
    v13 = -1;
  if ( !scalar->d )
  {
    v10 = 231;
LABEL_32:
    ERR_put_error(v3, 0x10u, 143, 68, ".\\crypto\\ec\\ec_mult.c", v10);
    goto LABEL_33;
  }
  v12 = BN_num_bits(scalar);
  str = (char *)CRYPTO_malloc(v12 + 1, ".\\crypto\\ec\\ec_mult.c", 236);
  if ( !str )
  {
    ERR_put_error((int)scalar, 0x10u, 143, 65, ".\\crypto\\ec\\ec_mult.c", 241);
LABEL_33:
    CRYPTO_free(str);
    return 0;
  }
  v3 = (2 * (1 << w) - 1) & *scalar->d;
  v6 = 0;
  while ( v3 || v6 + w + 1 < v12 )
  {
    LOBYTE(v7) = 0;
    if ( (v3 & 1) != 0 )
    {
      v7 = v3;
      if ( (v3 & v5) != 0 )
      {
        v7 = v3 - 2 * v5;
        if ( v6 + w + 1 >= v12 )
          v7 = v3 & ((2 * v5 - 1) >> 1);
      }
      if ( v7 <= -v5 || v7 >= v5 || (v7 & 1) == 0 )
      {
        v10 = 279;
        goto LABEL_32;
      }
      v3 -= v7;
      if ( v3 && v3 != 2 * v5 && v3 != v5 )
      {
        v10 = 290;
        goto LABEL_32;
      }
    }
    v8 = v7 * v13;
    v9 = &str[v6 - w];
    ++v6;
    v9[w] = v8;
    v3 = v5 * BN_is_bit_set(scalar, v6 + w) + (v3 >> 1);
    if ( v3 > 2 * v5 )
    {
      v10 = 302;
      goto LABEL_32;
    }
  }
  if ( v6 > v12 + 1 )
  {
    v10 = 309;
    goto LABEL_32;
  }
  result = str;
  *ret_len = v6;
  return result;
}
