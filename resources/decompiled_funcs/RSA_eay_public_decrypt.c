int __cdecl RSA_eay_public_decrypt(int flen, unsigned __int8 *from, unsigned __int8 *to, rsa_st *rsa, int padding)
{
  bignum_ctx *v7; // eax
  bignum_ctx *v8; // ebp
  bignum_st *v9; // ebx
  int v10; // esi
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // [esp+4h] [ebp-8h]
  bignum_st *r; // [esp+8h] [ebp-4h]
  unsigned __int8 *toa; // [esp+1Ch] [ebp+10h]

  v15 = -1;
  if ( BN_num_bits(rsa->n) > 0x4000 )
  {
    ERR_put_error(4u, 103, 105, ".\\crypto\\rsa\\rsa_eay.c", 644);
    return -1;
  }
  if ( BN_ucmp(rsa->n, rsa->e) <= 0 )
  {
    ERR_put_error(4u, 103, 101, ".\\crypto\\rsa\\rsa_eay.c", 650);
    return -1;
  }
  if ( BN_num_bits(rsa->n) > 3072 && BN_num_bits(rsa->e) > 64 )
  {
    ERR_put_error(4u, 103, 101, ".\\crypto\\rsa\\rsa_eay.c", 659);
    return -1;
  }
  v7 = BN_CTX_new();
  v8 = v7;
  if ( v7 )
  {
    BN_CTX_start(v7);
    v9 = BN_CTX_get(v8);
    r = BN_CTX_get(v8);
    v10 = (BN_num_bits(rsa->n) + 7) / 8;
    v11 = (unsigned __int8 *)CRYPTO_malloc(v10, ".\\crypto\\rsa\\rsa_eay.c", 669);
    toa = v11;
    if ( v9 && r && v11 )
    {
      if ( flen <= v10 )
      {
        if ( BN_bin2bn(from, flen, v9) )
        {
          if ( BN_ucmp(v9, rsa->n) < 0 )
          {
            if ( ((rsa->flags & 2) == 0 || BN_MONT_CTX_set_locked(&rsa->_method_mod_n, 9, rsa->n, v8))
              && rsa->meth->bn_mod_exp(r, v9, rsa->e, rsa->n, v8, rsa->_method_mod_n)
              && (padding != 5 || (*(_BYTE *)r->d & 0xF) == 0xC || BN_sub(r, rsa->n, r)) )
            {
              v12 = toa;
              v13 = BN_bn2bin(r, toa);
              switch ( padding )
              {
                case 1:
                  v14 = RSA_padding_check_PKCS1_type_1(to, v10, toa, v13, v10);
                  break;
                case 3:
                  v14 = RSA_padding_check_none(to, v10, toa, v13, v10);
                  break;
                case 5:
                  v14 = RSA_padding_check_X931(to, v10, toa, v13, v10);
                  break;
                default:
                  ERR_put_error(4u, 103, 118, ".\\crypto\\rsa\\rsa_eay.c", 717);
                  goto err_108;
              }
              v15 = v14;
              if ( v14 < 0 )
                ERR_put_error(4u, 103, 114, ".\\crypto\\rsa\\rsa_eay.c", 721);
              goto err_108;
            }
          }
          else
          {
            ERR_put_error(4u, 103, 132, ".\\crypto\\rsa\\rsa_eay.c", 688);
          }
        }
      }
      else
      {
        ERR_put_error(4u, 103, 108, ".\\crypto\\rsa\\rsa_eay.c", 680);
      }
    }
    else
    {
      ERR_put_error(4u, 103, 65, ".\\crypto\\rsa\\rsa_eay.c", 672);
    }
    v12 = toa;
err_108:
    BN_CTX_end(v8);
    BN_CTX_free(v8);
    if ( v12 )
    {
      OPENSSL_cleanse(v12, v10);
      CRYPTO_free(v12);
    }
  }
  return v15;
}
