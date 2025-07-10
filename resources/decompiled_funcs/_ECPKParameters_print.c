int __cdecl ECPKParameters_print(bio_st *bp, ssl_st *x, int off)
{
  unsigned __int8 *v3; // ebp
  bignum_ctx *v4; // edi
  unsigned int shutdown; // eax
  const char *v6; // eax
  const ssl_st *v7; // eax
  int curve_GF2m; // eax
  const ec_point_st *v9; // esi
  const bignum_st *v10; // edi
  unsigned int v11; // esi
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  const char *v17; // eax
  unsigned int basis_type; // ebx
  const char *v19; // eax
  int v20; // eax
  int v21; // eax
  __int16 reason; // [esp+10h] [ebp-34h]
  bignum_st *a; // [esp+14h] [ebp-30h]
  bignum_st *v25; // [esp+18h] [ebp-2Ch]
  bignum_st *num; // [esp+1Ch] [ebp-28h]
  bignum_st *v27; // [esp+20h] [ebp-24h]
  bignum_st *order; // [esp+24h] [ebp-20h]
  bignum_st *cofactor; // [esp+28h] [ebp-1Ch]
  int v30; // [esp+2Ch] [ebp-18h]
  int len; // [esp+30h] [ebp-14h]
  bignum_ctx *ctx; // [esp+34h] [ebp-10h]
  unsigned int n; // [esp+38h] [ebp-Ch]
  point_conversion_form_t point_conversion_form; // [esp+3Ch] [ebp-8h]
  unsigned __int8 *buf; // [esp+40h] [ebp-4h]

  v3 = 0;
  v30 = 0;
  reason = 32;
  ctx = 0;
  num = 0;
  a = 0;
  v25 = 0;
  v27 = 0;
  order = 0;
  cofactor = 0;
  len = 0;
  if ( !x )
  {
    ERR_put_error(0x10u, 149, 67, ".\\crypto\\ec\\eck_prn.c", 335);
    goto LABEL_62;
  }
  v4 = BN_CTX_new();
  ctx = v4;
  if ( !v4 )
    goto LABEL_60;
  if ( SSL_state(x) )
  {
    if ( BIO_indent(bp, off, 128) )
    {
      shutdown = SSL_get_shutdown(x);
      if ( shutdown )
      {
        v6 = OBJ_nid2sn(shutdown);
        if ( (int)BIO_printf(bp, "ASN1 OID: %s", v6) > 0 && (int)BIO_printf(bp, "\n") > 0 )
        {
          v30 = 1;
          goto LABEL_62;
        }
      }
    }
    goto LABEL_61;
  }
  v7 = (const ssl_st *)EVP_CIPHER_CTX_cipher(x);
  n = EVP_CIPHER_CTX_cipher(v7);
  num = BN_new();
  if ( !num )
    goto LABEL_60;
  a = BN_new();
  if ( !a )
    goto LABEL_60;
  v25 = BN_new();
  if ( !v25 )
    goto LABEL_60;
  order = BN_new();
  if ( !order )
    goto LABEL_60;
  cofactor = BN_new();
  if ( !cofactor )
    goto LABEL_60;
  if ( n == 407 )
    curve_GF2m = EC_GROUP_get_curve_GF2m((const ec_group_st *)x);
  else
    curve_GF2m = EC_GROUP_get_curve_GFp((const ec_group_st *)x);
  if ( !curve_GF2m
    || (v9 = (const ec_point_st *)EVP_CIPHER_block_size((const env_md_st *)x)) == 0
    || !EC_GROUP_get_order((const ec_group_st *)x, order)
    || !EC_GROUP_get_cofactor((const ec_group_st *)x, cofactor)
    || (point_conversion_form = EC_GROUP_get_point_conversion_form((const ec_group_st *)x),
        v10 = EC_POINT_point2bn((const ec_group_st *)x, v9, point_conversion_form, 0, v4),
        (v27 = (bignum_st *)v10) == 0) )
  {
    ERR_put_error(0x10u, 149, 16, ".\\crypto\\ec\\eck_prn.c", 335);
    goto LABEL_62;
  }
  v11 = (BN_num_bits(num) + 7) / 8;
  v12 = (BN_num_bits(a) + 7) / 8;
  if ( v11 < v12 )
    v11 = v12;
  v13 = (BN_num_bits(v25) + 7) / 8;
  if ( v11 < v13 )
    v11 = v13;
  v14 = (BN_num_bits(v10) + 7) / 8;
  if ( v11 < v14 )
    v11 = v14;
  v15 = (BN_num_bits(order) + 7) / 8;
  if ( v11 < v15 )
    v11 = v15;
  v16 = (BN_num_bits(cofactor) + 7) / 8;
  if ( v11 < v16 )
    v11 = v16;
  buf = EC_GROUP_get0_seed((const ec_group_st *)x);
  if ( buf )
    len = EVP_MD_block_size((const env_md_st *)x);
  v3 = (unsigned __int8 *)CRYPTO_malloc(v11 + 10, ".\\crypto\\ec\\eck_prn.c", 265);
  if ( v3 )
  {
    if ( !BIO_indent(bp, off, 128) )
      goto LABEL_61;
    v17 = OBJ_nid2sn(n);
    if ( (int)BIO_printf(bp, "Field Type: %s\n", v17) <= 0 )
      goto LABEL_61;
    if ( n == 407 )
    {
      basis_type = EC_GROUP_get_basis_type(x);
      if ( !basis_type )
        goto LABEL_61;
      if ( !BIO_indent(bp, off, 128) )
        goto LABEL_61;
      v19 = OBJ_nid2sn(basis_type);
      if ( (int)BIO_printf(bp, "Basis Type: %s\n", v19) <= 0 )
        goto LABEL_61;
      v20 = ASN1_bn_print(bp, "Polynomial:", num, v3, off);
    }
    else
    {
      v20 = ASN1_bn_print(bp, "Prime:", num, v3, off);
    }
    if ( v20 && ASN1_bn_print(bp, "A:   ", a, v3, off) && ASN1_bn_print(bp, "B:   ", v25, v3, off) )
    {
      if ( point_conversion_form == POINT_CONVERSION_COMPRESSED )
        v21 = ASN1_bn_print(bp, gen_compressed, v10, v3, off);
      else
        v21 = point_conversion_form == POINT_CONVERSION_UNCOMPRESSED
            ? ASN1_bn_print(bp, gen_uncompressed, v10, v3, off)
            : ASN1_bn_print(bp, gen_hybrid, v10, v3, off);
      if ( v21
        && ASN1_bn_print(bp, "Order: ", order, v3, off)
        && ASN1_bn_print(bp, "Cofactor: ", cofactor, v3, off)
        && (!buf || print_bin(bp, "Seed:", buf, len, off)) )
      {
        v30 = 1;
        goto LABEL_62;
      }
    }
  }
  else
  {
LABEL_60:
    reason = 65;
  }
LABEL_61:
  ERR_put_error(0x10u, 149, reason, ".\\crypto\\ec\\eck_prn.c", 335);
LABEL_62:
  if ( num )
    BN_free(num);
  if ( a )
    BN_free(a);
  if ( v25 )
    BN_free(v25);
  if ( v27 )
    BN_free(v27);
  if ( order )
    BN_free(order);
  if ( cofactor )
    BN_free(cofactor);
  if ( ctx )
    BN_CTX_free(ctx);
  if ( v3 )
    CRYPTO_free(v3);
  return v30;
}
