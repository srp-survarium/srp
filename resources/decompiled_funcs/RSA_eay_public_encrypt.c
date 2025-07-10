int __cdecl RSA_eay_public_encrypt(int flen, unsigned __int8 *from, unsigned __int8 *to, bignum_st *rsa, int padding)
{
  bignum_ctx *v7; // eax
  bignum_ctx *v8; // ebx
  int v9; // esi
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ebp
  int v12; // eax
  int v13; // eax
  signed int v14; // ecx
  bignum_st *a; // [esp+4h] [ebp-8h]
  int v16; // [esp+8h] [ebp-4h]
  bignum_st *ret; // [esp+1Ch] [ebp+10h]

  v16 = -1;
  if ( BN_num_bits((const bignum_st *)rsa->flags) > 0x4000 )
  {
    ERR_put_error(4u, 104, 105, ".\\crypto\\rsa\\rsa_eay.c", 163);
    return -1;
  }
  if ( BN_ucmp((const bignum_st *)rsa->flags, (const bignum_st *)rsa[1].d) <= 0 )
  {
    ERR_put_error(4u, 104, 101, ".\\crypto\\rsa\\rsa_eay.c", 169);
    return -1;
  }
  if ( BN_num_bits((const bignum_st *)rsa->flags) > 3072 && BN_num_bits((const bignum_st *)rsa[1].d) > 64 )
  {
    ERR_put_error(4u, 104, 101, ".\\crypto\\rsa\\rsa_eay.c", 178);
    return -1;
  }
  v7 = BN_CTX_new();
  v8 = v7;
  if ( v7 )
  {
    BN_CTX_start(v7);
    ret = BN_CTX_get(v8);
    a = BN_CTX_get(v8);
    v9 = (BN_num_bits((const bignum_st *)rsa->flags) + 7) / 8;
    v10 = (unsigned __int8 *)CRYPTO_malloc(v9, ".\\crypto\\rsa\\rsa_eay.c", 188);
    v11 = v10;
    if ( ret && a && v10 )
    {
      switch ( padding )
      {
        case 1:
          v12 = RSA_padding_add_PKCS1_type_2(v10, v9, from, flen);
          goto LABEL_18;
        case 2:
          v12 = RSA_padding_add_SSLv23(v10, v9, from, flen);
          goto LABEL_18;
        case 3:
          v12 = RSA_padding_add_none(v10, v9, from, flen);
          goto LABEL_18;
        case 4:
          v12 = RSA_padding_add_PKCS1_OAEP(v10, v9, from, flen, 0, 0);
LABEL_18:
          if ( v12 > 0 && BN_bin2bn(v11, v9, ret) )
          {
            if ( BN_ucmp(ret, (const bignum_st *)rsa->flags) < 0 )
            {
              if ( (((int)rsa[3].d & 2) == 0
                 || BN_MONT_CTX_set_locked((bn_mont_ctx_st **)&rsa[3].top, 9, (const bignum_st *)rsa->flags, v8))
                && (*(int (__cdecl **)(bignum_st *, bignum_st *, unsigned int *, int, bignum_ctx *, int))(rsa->dmax + 24))(
                     a,
                     ret,
                     rsa[1].d,
                     rsa->flags,
                     v8,
                     rsa[3].top) )
              {
                v13 = BN_num_bits(a);
                v14 = v9 - BN_bn2bin(a, &to[v9 - (v13 + 7) / 8]);
                if ( v14 > 0 )
                  memset((int)to, 0, v14);
                v16 = v9;
              }
            }
            else
            {
              ERR_put_error(4u, 104, 132, ".\\crypto\\rsa\\rsa_eay.c", 222);
            }
          }
          break;
        default:
          ERR_put_error(4u, 104, 118, ".\\crypto\\rsa\\rsa_eay.c", 212);
          break;
      }
    }
    else
    {
      ERR_put_error(4u, 104, 65, ".\\crypto\\rsa\\rsa_eay.c", 191);
    }
    BN_CTX_end(v8);
    BN_CTX_free(v8);
    if ( v11 )
    {
      OPENSSL_cleanse(v11, v9);
      CRYPTO_free(v11);
    }
  }
  return v16;
}
