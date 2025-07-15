int __usercall do_dsa_print@<eax>(bio_st *bp@<ebx>, const dsa_st *x@<ecx>, int off, int ptype)
{
  unsigned int v5; // esi
  bignum_st *priv_key; // ebp
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned __int8 *v13; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edi
  const bignum_st *a; // [esp+Ch] [ebp-8h]
  const char *v19; // [esp+1Ch] [ebp+8h]

  v5 = 0;
  if ( ptype == 2 )
  {
    priv_key = x->priv_key;
    a = x->pub_key;
  }
  else
  {
    priv_key = 0;
    if ( ptype <= 0 )
      a = 0;
    else
      a = x->pub_key;
  }
  if ( ptype == 2 )
  {
    v19 = "Private-Key";
  }
  else
  {
    v19 = "Public-Key";
    if ( ptype != 1 )
      v19 = "DSA-Parameters";
  }
  if ( x->p )
  {
    v8 = (BN_num_bits(x->p) + 7) / 8;
    if ( v8 )
      v5 = v8;
  }
  if ( x->q )
  {
    v9 = (BN_num_bits(x->q) + 7) / 8;
    if ( v5 < v9 )
      v5 = v9;
  }
  if ( x->g )
  {
    v10 = (BN_num_bits(x->g) + 7) / 8;
    if ( v5 < v10 )
      v5 = v10;
  }
  if ( priv_key )
  {
    v11 = (BN_num_bits(priv_key) + 7) / 8;
    if ( v5 < v11 )
      v5 = v11;
  }
  if ( a )
  {
    v12 = (BN_num_bits(a) + 7) / 8;
    if ( v5 < v12 )
      v5 = v12;
  }
  v13 = (unsigned __int8 *)CRYPTO_malloc(v5 + 10, ".\\crypto\\dsa\\dsa_ameth.c", 462);
  if ( v13 )
  {
    if ( priv_key
      && (!BIO_indent((int)bp, bp, off, 128)
       || (v15 = BN_num_bits(x->p), BIO_printf(bp, "%s: (%d bit)\n", v19, v15) <= 0))
      || !ASN1_bn_print(bp, "priv:", priv_key, v13, off)
      || !ASN1_bn_print(bp, "pub: ", a, v13, off)
      || !ASN1_bn_print(bp, "P:   ", x->p, v13, off)
      || !ASN1_bn_print(bp, "Q:   ", x->q, v13, off)
      || (v16 = ASN1_bn_print(bp, "G:   ", x->g, v13, off), v17 = 1, !v16) )
    {
      v17 = 0;
    }
    CRYPTO_free(v13);
    return v17;
  }
  else
  {
    ERR_put_error((int)bp, 0xAu, 104, 65, ".\\crypto\\dsa\\dsa_ameth.c", 465);
    return 0;
  }
}
