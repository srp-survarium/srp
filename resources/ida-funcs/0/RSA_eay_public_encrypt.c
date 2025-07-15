int __usercall RSA_eay_public_encrypt@<eax>(
        int a1@<ebx>,
        int flen,
        unsigned __int8 *from,
        unsigned __int8 *to,
        bignum_st *rsa,
        int padding)
{
  bignum_ctx *v8; // eax
  bignum_ctx *v9; // ebx
  int v10; // esi
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // ebp
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  bignum_pool_item *a; // [esp+4h] [ebp-8h]
  int v17; // [esp+8h] [ebp-4h]
  bignum_pool_item *ret; // [esp+1Ch] [ebp+10h]

  v17 = -1;
  if ( BN_num_bits((const bignum_st *)rsa->flags) > 0x4000 )
  {
    ERR_put_error(a1, 4u, 104, 105, ".\\crypto\\rsa\\rsa_eay.c", 163);
    return -1;
  }
  if ( BN_ucmp((const bignum_st *)rsa->flags, (const bignum_st *)rsa[1].d) <= 0 )
  {
    ERR_put_error(a1, 4u, 104, 101, ".\\crypto\\rsa\\rsa_eay.c", 169);
    return -1;
  }
  if ( BN_num_bits((const bignum_st *)rsa->flags) > 3072 && BN_num_bits((const bignum_st *)rsa[1].d) > 64 )
  {
    ERR_put_error(a1, 4u, 104, 101, ".\\crypto\\rsa\\rsa_eay.c", 178);
    return -1;
  }
  v8 = BN_CTX_new();
  v9 = v8;
  if ( v8 )
  {
    BN_CTX_start(v8);
    ret = BN_CTX_get(v9);
    a = BN_CTX_get(v9);
    v10 = (BN_num_bits((const bignum_st *)rsa->flags) + 7) / 8;
    v11 = (unsigned __int8 *)CRYPTO_malloc(v10, ".\\crypto\\rsa\\rsa_eay.c", 188);
    v12 = v11;
    if ( ret && a && v11 )
    {
      switch ( padding )
      {
        case 1:
          v13 = RSA_padding_add_PKCS1_type_2(v11, v10, from, flen);
          goto LABEL_18;
        case 2:
          v13 = RSA_padding_add_SSLv23(v11, v10, from, flen);
          goto LABEL_18;
        case 3:
          v13 = RSA_padding_add_none(v11, v10, from, flen);
          goto LABEL_18;
        case 4:
          v13 = RSA_padding_add_PKCS1_OAEP(v11, v10, from, flen, 0, 0);
LABEL_18:
          if ( v13 > 0 && BN_bin2bn(v12, v10, ret->vals) )
          {
            if ( BN_ucmp(ret->vals, (const bignum_st *)rsa->flags) < 0 )
            {
              if ( (((int)rsa[3].d & 2) == 0
                 || BN_MONT_CTX_set_locked(
                      (int)rsa,
                      (bn_mont_ctx_st **)&rsa[3].top,
                      9,
                      (const bignum_st *)rsa->flags,
                      v9))
                && (*(int (__cdecl **)(bignum_pool_item *, bignum_pool_item *, unsigned int *, int, bignum_ctx *, int))(rsa->dmax + 24))(
                     a,
                     ret,
                     rsa[1].d,
                     rsa->flags,
                     v9,
                     rsa[3].top) )
              {
                v14 = BN_num_bits(a->vals);
                v15 = v10 - BN_bn2bin(a->vals, &to[v10 - (v14 + 7) / 8]);
                if ( v15 > 0 )
                  memset((int)to, 0, v15);
                v17 = v10;
              }
            }
            else
            {
              ERR_put_error((int)v9, 4u, 104, 132, ".\\crypto\\rsa\\rsa_eay.c", 222);
            }
          }
          break;
        default:
          ERR_put_error((int)v9, 4u, 104, 118, ".\\crypto\\rsa\\rsa_eay.c", 212);
          break;
      }
    }
    else
    {
      ERR_put_error((int)v9, 4u, 104, 65, ".\\crypto\\rsa\\rsa_eay.c", 191);
    }
    BN_CTX_end(v9);
    BN_CTX_free(v9);
    if ( v12 )
    {
      OPENSSL_cleanse(v12, v10);
      CRYPTO_free(v12);
    }
  }
  return v17;
}
