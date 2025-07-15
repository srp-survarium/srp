int __cdecl ECPKParameters_print(bio_st *bp, ssl_st *x, int off)
{
  ssl_st *basis_type; // ebx
  unsigned __int8 *v4; // ebp
  bignum_ctx *v5; // edi
  unsigned int shutdown; // eax
  const char *v7; // eax
  const ssl_st *v8; // eax
  int curve_GF2m; // eax
  const ec_point_st *v10; // esi
  const bignum_st *v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  int v20; // eax
  int v21; // eax
  __int16 v23; // [esp+10h] [ebp-34h]
  bignum_st *num; // [esp+14h] [ebp-30h]
  bignum_st *v25; // [esp+18h] [ebp-2Ch]
  bignum_st *a; // [esp+1Ch] [ebp-28h]
  bignum_st *v27; // [esp+20h] [ebp-24h]
  bignum_st *v28; // [esp+24h] [ebp-20h]
  bignum_st *v29; // [esp+28h] [ebp-1Ch]
  int v30; // [esp+2Ch] [ebp-18h]
  unsigned int v31; // [esp+30h] [ebp-14h]
  bignum_ctx *ctx; // [esp+34h] [ebp-10h]
  unsigned int v33; // [esp+38h] [ebp-Ch]
  point_conversion_form_t point_conversion_form; // [esp+3Ch] [ebp-8h]
  const unsigned __int8 *v35; // [esp+40h] [ebp-4h]

  basis_type = x;
  v4 = 0;
  v30 = 0;
  v23 = 32;
  ctx = 0;
  a = 0;
  num = 0;
  v25 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v31 = 0;
  if ( !x )
  {
    ERR_put_error(0, 0x10u, 149, 67, ".\\crypto\\ec\\eck_prn.c", 335);
    goto LABEL_62;
  }
  v5 = BN_CTX_new((int)x);
  ctx = v5;
  if ( !v5 )
    goto LABEL_60;
  if ( SSL_state(x) )
  {
    if ( BIO_indent((int)x, bp, off, 128) )
    {
      shutdown = SSL_get_shutdown(x);
      if ( shutdown )
      {
        v7 = OBJ_nid2sn((int)x, shutdown);
        if ( BIO_printf(bp, "ASN1 OID: %s", v7) > 0 && BIO_printf(bp, "\n") > 0 )
        {
          v30 = 1;
          goto LABEL_62;
        }
      }
    }
    goto LABEL_61;
  }
  v8 = (const ssl_st *)EVP_CIPHER_CTX_cipher(x);
  v33 = EVP_CIPHER_CTX_cipher(v8);
  a = BN_new((int)x);
  if ( !a )
    goto LABEL_60;
  num = BN_new((int)x);
  if ( !num )
    goto LABEL_60;
  v25 = BN_new((int)x);
  if ( !v25 )
    goto LABEL_60;
  v28 = BN_new((int)x);
  if ( !v28 )
    goto LABEL_60;
  v29 = BN_new((int)x);
  if ( !v29 )
    goto LABEL_60;
  if ( v33 == 407 )
    curve_GF2m = EC_GROUP_get_curve_GF2m((int)x, (const ec_group_st *)x);
  else
    curve_GF2m = EC_GROUP_get_curve_GFp((int)x, (const ec_group_st *)x);
  if ( !curve_GF2m
    || (v10 = (const ec_point_st *)EVP_CIPHER_block_size((const env_md_st *)x)) == 0
    || !EC_GROUP_get_order((const ec_group_st *)x, v28)
    || !EC_GROUP_get_cofactor((const ec_group_st *)x, v29)
    || (point_conversion_form = EC_GROUP_get_point_conversion_form((const ec_group_st *)x),
        v11 = EC_POINT_point2bn((const ec_group_st *)x, v10, point_conversion_form, 0, v5),
        (v27 = (bignum_st *)v11) == 0) )
  {
    ERR_put_error((int)x, 0x10u, 149, 16, ".\\crypto\\ec\\eck_prn.c", 335);
    goto LABEL_62;
  }
  v12 = (BN_num_bits(a) + 7) / 8;
  v13 = (BN_num_bits(num) + 7) / 8;
  if ( v12 < v13 )
    v12 = v13;
  v14 = (BN_num_bits(v25) + 7) / 8;
  if ( v12 < v14 )
    v12 = v14;
  v15 = (BN_num_bits(v11) + 7) / 8;
  if ( v12 < v15 )
    v12 = v15;
  v16 = (BN_num_bits(v28) + 7) / 8;
  if ( v12 < v16 )
    v12 = v16;
  v17 = (BN_num_bits(v29) + 7) / 8;
  if ( v12 < v17 )
    v12 = v17;
  v35 = EC_GROUP_get0_seed((const ec_group_st *)x);
  if ( v35 )
    v31 = EVP_MD_block_size((const env_md_st *)x);
  v4 = (unsigned __int8 *)CRYPTO_malloc(v12 + 10, ".\\crypto\\ec\\eck_prn.c", 265);
  if ( v4 )
  {
    if ( !BIO_indent((int)x, bp, off, 128) )
      goto LABEL_61;
    v18 = OBJ_nid2sn((int)x, v33);
    if ( BIO_printf(bp, "Field Type: %s\n", v18) <= 0 )
      goto LABEL_61;
    if ( v33 == 407 )
    {
      basis_type = (ssl_st *)EC_GROUP_get_basis_type(x);
      if ( !basis_type )
        goto LABEL_61;
      if ( !BIO_indent((int)basis_type, bp, off, 128) )
        goto LABEL_61;
      v19 = OBJ_nid2sn((int)basis_type, (unsigned int)basis_type);
      if ( BIO_printf(bp, "Basis Type: %s\n", v19) <= 0 )
        goto LABEL_61;
      v20 = ASN1_bn_print(bp, "Polynomial:", a, v4, off);
    }
    else
    {
      v20 = ASN1_bn_print(bp, "Prime:", a, v4, off);
    }
    if ( v20 && ASN1_bn_print(bp, "A:   ", num, v4, off) && ASN1_bn_print(bp, "B:   ", v25, v4, off) )
    {
      if ( point_conversion_form == POINT_CONVERSION_COMPRESSED )
        v21 = ASN1_bn_print(bp, gen_compressed, v11, v4, off);
      else
        v21 = point_conversion_form == POINT_CONVERSION_UNCOMPRESSED
            ? ASN1_bn_print(bp, gen_uncompressed, v11, v4, off)
            : ASN1_bn_print(bp, gen_hybrid, v11, v4, off);
      if ( v21 )
      {
        if ( ASN1_bn_print(bp, "Order: ", v28, v4, off) )
        {
          if ( ASN1_bn_print(bp, "Cofactor: ", v29, v4, off) )
          {
            basis_type = (ssl_st *)v35;
            if ( !v35 || print_bin(bp, "Seed:", v35, v31, off) )
            {
              v30 = 1;
              goto LABEL_62;
            }
          }
        }
      }
    }
  }
  else
  {
LABEL_60:
    v23 = 65;
  }
LABEL_61:
  ERR_put_error((int)basis_type, 0x10u, 149, v23, ".\\crypto\\ec\\eck_prn.c", 335);
LABEL_62:
  if ( a )
    BN_free(a);
  if ( num )
    BN_free(num);
  if ( v25 )
    BN_free(v25);
  if ( v27 )
    BN_free(v27);
  if ( v28 )
    BN_free(v28);
  if ( v29 )
    BN_free(v29);
  if ( ctx )
    BN_CTX_free(ctx);
  if ( v4 )
    CRYPTO_free(v4);
  return v30;
}
