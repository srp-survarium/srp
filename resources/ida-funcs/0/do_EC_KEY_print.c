int __cdecl do_EC_KEY_print(bio_st *bp, int off, int ktype)
{
  const env_md_st *x; // ecx
  unsigned int v4; // edi
  const engine_st *v5; // esi
  unsigned __int8 *v6; // ebp
  bignum_st *v7; // ebx
  int v8; // eax
  const ec_point_st *v9; // edi
  const ecdh_method *conv_form; // eax
  const bignum_st *v11; // eax
  int v12; // kr04_4
  const bignum_st *v13; // eax
  const bignum_st *v14; // esi
  unsigned int v15; // eax
  const char *v16; // edi
  bignum_st *v17; // eax
  int v18; // eax
  int v19; // esi
  __int16 reason; // [esp+10h] [ebp-14h]
  bignum_st *a; // [esp+14h] [ebp-10h]
  ec_group_st *group; // [esp+18h] [ebp-Ch]
  bignum_ctx *ctx; // [esp+1Ch] [ebp-8h]

  v4 = 0;
  v5 = (const engine_st *)x;
  v6 = 0;
  v7 = 0;
  reason = 32;
  a = 0;
  ctx = 0;
  if ( !x || (group = (ec_group_st *)EVP_CIPHER_block_size(x)) == 0 )
  {
    reason = 67;
LABEL_31:
    ERR_put_error(0x10u, 221, reason, ".\\crypto\\ec\\ec_ameth.c", 510);
    goto LABEL_32;
  }
  ctx = BN_CTX_new();
  if ( ctx )
  {
    v8 = ktype;
    if ( ktype > 0 )
    {
      v9 = (const ec_point_st *)EC_KEY_get0_public_key(v5);
      conv_form = EC_KEY_get_conv_form(v5);
      v11 = EC_POINT_point2bn(group, v9, (point_conversion_form_t)conv_form, 0, ctx);
      v7 = (bignum_st *)v11;
      if ( !v11 )
      {
        ERR_put_error(0x10u, 221, 16, ".\\crypto\\ec\\ec_ameth.c", 510);
        goto LABEL_32;
      }
      v12 = BN_num_bits(v11) + 7;
      v8 = ktype;
      v4 = v12 / 8;
    }
    if ( v8 == 2 )
    {
      v13 = (const bignum_st *)EC_KEY_get0_private_key((const ssl_st *)v5);
      v14 = v13;
      if ( v13 )
      {
        v15 = (BN_num_bits(v13) + 7) / 8;
        if ( v15 > v4 )
          v4 = v15;
      }
    }
    else
    {
      v14 = 0;
      if ( v8 <= 0 )
      {
LABEL_16:
        if ( v8 == 2 )
        {
          v16 = "Private-Key";
        }
        else
        {
          v16 = "Public-Key";
          if ( v8 != 1 )
            v16 = "ECDSA-Parameters";
        }
        if ( BIO_indent(bp, off, 128) )
        {
          v17 = BN_new();
          a = v17;
          if ( v17 )
          {
            if ( EC_GROUP_get_order(group, v17, 0) )
            {
              v18 = BN_num_bits(a);
              if ( (int)BIO_printf(bp, "%s: (%d bit)\n", v16, v18) > 0
                && (!v14 || ASN1_bn_print(bp, "priv:", v14, v6, off))
                && (!v7 || ASN1_bn_print(bp, "pub: ", v7, v6, off))
                && ECPKParameters_print(bp, group, off) )
              {
                v19 = 1;
                goto LABEL_33;
              }
            }
          }
        }
        goto LABEL_31;
      }
    }
    v6 = (unsigned __int8 *)CRYPTO_malloc(v4 + 10, ".\\crypto\\ec\\ec_ameth.c", 477);
    if ( !v6 )
      goto LABEL_4;
    v8 = ktype;
    goto LABEL_16;
  }
LABEL_4:
  ERR_put_error(0x10u, 221, 65, ".\\crypto\\ec\\ec_ameth.c", 510);
LABEL_32:
  v19 = 0;
LABEL_33:
  if ( v7 )
    BN_free(v7);
  if ( a )
    BN_free(a);
  if ( ctx )
    BN_CTX_free(ctx);
  if ( v6 )
    CRYPTO_free(v6);
  return v19;
}
