int __usercall RSA_eay_public_decrypt@<eax>(
        int a1@<ebx>,
        int flen,
        unsigned __int8 *from,
        unsigned __int8 *to,
        rsa_st *rsa,
        int padding)
{
  bignum_ctx *v8; // eax
  bignum_ctx *v9; // ebp
  bignum_pool_item *v10; // ebx
  int v11; // esi
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // [esp+4h] [ebp-8h]
  bignum_pool_item *r; // [esp+8h] [ebp-4h]
  unsigned __int8 *toa; // [esp+1Ch] [ebp+10h]

  v16 = -1;
  if ( BN_num_bits(rsa->n) > 0x4000 )
  {
    ERR_put_error(a1, 4u, 103, 105, ".\\crypto\\rsa\\rsa_eay.c", 644);
    return -1;
  }
  if ( BN_ucmp(rsa->n, rsa->e) <= 0 )
  {
    ERR_put_error(a1, 4u, 103, 101, ".\\crypto\\rsa\\rsa_eay.c", 650);
    return -1;
  }
  if ( BN_num_bits(rsa->n) > 3072 && BN_num_bits(rsa->e) > 64 )
  {
    ERR_put_error(a1, 4u, 103, 101, ".\\crypto\\rsa\\rsa_eay.c", 659);
    return -1;
  }
  v8 = BN_CTX_new();
  v9 = v8;
  if ( v8 )
  {
    BN_CTX_start(v8);
    v10 = BN_CTX_get(v9);
    r = BN_CTX_get(v9);
    v11 = (BN_num_bits(rsa->n) + 7) / 8;
    v12 = (unsigned __int8 *)CRYPTO_malloc(v11, ".\\crypto\\rsa\\rsa_eay.c", 669);
    toa = v12;
    if ( v10 && r && v12 )
    {
      if ( flen <= v11 )
      {
        if ( BN_bin2bn(from, flen, v10->vals) )
        {
          if ( BN_ucmp(v10->vals, rsa->n) < 0 )
          {
            if ( ((rsa->flags & 2) == 0 || BN_MONT_CTX_set_locked((int)rsa, &rsa->_method_mod_n, 9, rsa->n, v9))
              && rsa->meth->bn_mod_exp((bignum_st *)r, (const bignum_st *)v10, rsa->e, rsa->n, v9, rsa->_method_mod_n)
              && (padding != 5 || (*(_BYTE *)r->vals[0].d & 0xF) == 0xC || BN_sub(r->vals, rsa->n, r->vals)) )
            {
              v13 = toa;
              v14 = BN_bn2bin(r->vals, toa);
              switch ( padding )
              {
                case 1:
                  v15 = RSA_padding_check_PKCS1_type_1(to, v11, toa, v14, v11);
                  break;
                case 3:
                  v15 = RSA_padding_check_none(to, v11, toa, v14);
                  break;
                case 5:
                  v15 = RSA_padding_check_X931(to, v11, toa, v14, v11);
                  break;
                default:
                  ERR_put_error((int)r, 4u, 103, 118, ".\\crypto\\rsa\\rsa_eay.c", 717);
                  goto err_110;
              }
              v16 = v15;
              if ( v15 < 0 )
                ERR_put_error((int)r, 4u, 103, 114, ".\\crypto\\rsa\\rsa_eay.c", 721);
              goto err_110;
            }
          }
          else
          {
            ERR_put_error((int)v10, 4u, 103, 132, ".\\crypto\\rsa\\rsa_eay.c", 688);
          }
        }
      }
      else
      {
        ERR_put_error((int)v10, 4u, 103, 108, ".\\crypto\\rsa\\rsa_eay.c", 680);
      }
    }
    else
    {
      ERR_put_error((int)v10, 4u, 103, 65, ".\\crypto\\rsa\\rsa_eay.c", 672);
    }
    v13 = toa;
err_110:
    BN_CTX_end(v9);
    BN_CTX_free(v9);
    if ( v13 )
    {
      OPENSSL_cleanse(v13, v11);
      CRYPTO_free(v13);
    }
  }
  return v16;
}
