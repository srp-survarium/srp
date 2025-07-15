int __cdecl do_dh_print(bio_st *bp, const dh_st *x, int indent, asn1_pctx_st *ctx)
{
  unsigned __int8 *v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  const char *v9; // ebx
  int v10; // eax
  int v11; // esi
  const bignum_st *num; // [esp+10h] [ebp-10h]
  const bignum_st *a; // [esp+14h] [ebp-Ch]
  int v15; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v15 = 0;
  if ( ctx == (asn1_pctx_st *)2 )
  {
    num = x->priv_key;
    a = x->pub_key;
  }
  else
  {
    num = 0;
    if ( (int)ctx <= 0 )
      a = 0;
    else
      a = x->pub_key;
  }
  if ( x->p && (v5 = (BN_num_bits(x->p) + 7) / 8) != 0 )
  {
    if ( x->g )
    {
      v6 = (BN_num_bits(x->g) + 7) / 8;
      if ( v5 < v6 )
        v5 = v6;
    }
    if ( a )
    {
      v7 = (BN_num_bits(a) + 7) / 8;
      if ( v5 < v7 )
        v5 = v7;
    }
    if ( num )
    {
      v8 = (BN_num_bits(num) + 7) / 8;
      if ( v5 < v8 )
        v5 = v8;
    }
    if ( ctx == (asn1_pctx_st *)2 )
    {
      v9 = "PKCS#3 DH Private-Key";
    }
    else
    {
      v9 = "PKCS#3 DH Public-Key";
      if ( ctx != (asn1_pctx_st *)1 )
        v9 = "PKCS#3 DH Parameters";
    }
    v4 = (unsigned __int8 *)CRYPTO_malloc(v5 + 10, ".\\crypto\\dh\\dh_ameth.c", 356);
    if ( v4 )
    {
      BIO_indent((int)v9, bp, indent, 128);
      v10 = BN_num_bits(x->p);
      if ( BIO_printf(bp, "%s: (%d bit)\n", v9, v10) > 0
        && (v11 = indent + 4, ASN1_bn_print(bp, "private-key:", num, v4, indent + 4))
        && ASN1_bn_print(bp, "public-key:", a, v4, v11)
        && (v9 = (const char *)x, ASN1_bn_print(bp, "prime:", x->p, v4, v11))
        && ASN1_bn_print(bp, "generator:", x->g, v4, v11)
        && (!x->length
         || (BIO_indent((int)x, bp, v11, 128), BIO_printf(bp, "recommended-private-length: %d bits\n", x->length) > 0)) )
      {
        v15 = 1;
      }
      else
      {
        ERR_put_error((int)v9, 5u, 100, 7, ".\\crypto\\dh\\dh_ameth.c", 385);
      }
    }
    else
    {
      ERR_put_error((int)v9, 5u, 100, 65, ".\\crypto\\dh\\dh_ameth.c", 385);
    }
  }
  else
  {
    ERR_put_error((int)x, 5u, 100, 67, ".\\crypto\\dh\\dh_ameth.c", 385);
  }
  if ( v4 )
    CRYPTO_free(v4);
  return v15;
}
