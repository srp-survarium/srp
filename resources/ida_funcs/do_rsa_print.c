int __usercall do_rsa_print@<eax>(const rsa_st *x@<edi>, bio_st *bp, int off, int priv)
{
  bignum_st *n; // eax
  unsigned int v5; // esi
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned __int8 *v15; // esi
  const char *v17; // eax
  const char *v18; // ebx
  int v19; // [esp+Ch] [ebp-4h]

  n = x->n;
  v5 = 0;
  v6 = 0;
  v19 = 0;
  if ( n )
  {
    v7 = (BN_num_bits(n) + 7) / 8;
    if ( v7 )
      v5 = v7;
  }
  if ( x->e )
  {
    v8 = (BN_num_bits(x->e) + 7) / 8;
    if ( v5 < v8 )
      v5 = v8;
  }
  if ( priv )
  {
    if ( x->d )
    {
      v9 = (BN_num_bits(x->d) + 7) / 8;
      if ( v5 < v9 )
        v5 = v9;
    }
    if ( x->p )
    {
      v10 = (BN_num_bits(x->p) + 7) / 8;
      if ( v5 < v10 )
        v5 = v10;
    }
    if ( x->q )
    {
      v11 = (BN_num_bits(x->q) + 7) / 8;
      if ( v5 < v11 )
        v5 = v11;
    }
    if ( x->dmp1 )
    {
      v12 = (BN_num_bits(x->dmp1) + 7) / 8;
      if ( v5 < v12 )
        v5 = v12;
    }
    if ( x->dmq1 )
    {
      v13 = (BN_num_bits(x->dmq1) + 7) / 8;
      if ( v5 < v13 )
        v5 = v13;
    }
    if ( x->iqmp )
    {
      v14 = (BN_num_bits(x->iqmp) + 7) / 8;
      if ( v5 < v14 )
        v5 = v14;
    }
  }
  v15 = (unsigned __int8 *)CRYPTO_malloc(v5 + 10, ".\\crypto\\rsa\\rsa_ameth.c", 204);
  if ( !v15 )
  {
    ERR_put_error(4u, 146, 65, ".\\crypto\\rsa\\rsa_ameth.c", 207);
    return 0;
  }
  if ( x->n )
    v6 = BN_num_bits(x->n);
  if ( BIO_indent(bp, off, 128) )
  {
    if ( priv && x->d )
    {
      if ( (int)BIO_printf(bp, "Private-Key: (%d bit)\n", v6) > 0 )
      {
        v17 = "modulus:";
        v18 = "publicExponent:";
LABEL_37:
        if ( ASN1_bn_print(bp, v17, x->n, v15, off)
          && ASN1_bn_print(bp, v18, x->e, v15, off)
          && (!priv
           || ASN1_bn_print(bp, "privateExponent:", x->d, v15, off)
           && ASN1_bn_print(bp, "prime1:", x->p, v15, off)
           && ASN1_bn_print(bp, "prime2:", x->q, v15, off)
           && ASN1_bn_print(bp, "exponent1:", x->dmp1, v15, off)
           && ASN1_bn_print(bp, "exponent2:", x->dmq1, v15, off)
           && ASN1_bn_print(bp, "coefficient:", x->iqmp, v15, off)) )
        {
          v19 = 1;
        }
      }
    }
    else if ( (int)BIO_printf(bp, "Public-Key: (%d bit)\n", v6) > 0 )
    {
      v17 = "Modulus:";
      v18 = "Exponent:";
      goto LABEL_37;
    }
  }
  CRYPTO_free(v15);
  return v19;
}
