int __cdecl dsa_priv_decode(evp_pkey_st *pkey, pkcs8_priv_key_info_st *p8)
{
  bignum_ctx *v2; // edi
  dsa_st *v3; // esi
  asn1_string_st *v4; // ebx
  stack_st *p_stack; // ebp
  stack_st_ASN1_TYPE *v6; // eax
  char *v7; // eax
  asn1_string_st *v8; // eax
  bignum_st *v9; // eax
  bignum_st *v10; // eax
  int v12; // [esp-4h] [ebp-34h]
  unsigned __int8 *pk; // [esp+10h] [ebp-20h] BYREF
  int ppklen; // [esp+14h] [ebp-1Ch] BYREF
  int v15; // [esp+18h] [ebp-18h] BYREF
  bignum_pool_item *current; // [esp+1Ch] [ebp-14h] BYREF
  bignum_ctx *ctx; // [esp+20h] [ebp-10h]
  X509_algor_st *pa; // [esp+24h] [ebp-Ch] BYREF
  asn1_string_st **v19; // [esp+28h] [ebp-8h] BYREF
  unsigned __int8 *dmax; // [esp+2Ch] [ebp-4h] BYREF

  v2 = (bignum_ctx *)p8;
  v3 = 0;
  v4 = 0;
  ctx = 0;
  p_stack = 0;
  if ( !PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, &pa, p8) )
    return 0;
  X509_ALGOR_get0(0, &v15, (char **)&current, pa);
  if ( *pk == 48 )
  {
    v6 = d2i_ASN1_SEQUENCE_ANY(0, &pk, (const unsigned __int8 *)ppklen);
    p_stack = &v6->stack;
    if ( !v6 || sk_num(&v6->stack) != 2 )
      goto decerr;
    v2 = (bignum_ctx *)sk_value(p_stack, 0);
    v7 = sk_value(p_stack, 1);
    if ( v2->pool.head == (bignum_pool_item *)16 )
    {
      p8->broken = 2;
      current = v2->pool.current;
    }
    else
    {
      if ( v15 != 16 )
        goto decerr;
      p8->broken = 3;
    }
    if ( *(_DWORD *)v7 == 2 )
    {
      v4 = (asn1_string_st *)*((_DWORD *)v7 + 1);
      goto LABEL_15;
    }
decerr:
    ERR_put_error((int)v4, 0xAu, 115, 114, ".\\crypto\\dsa\\dsa_ameth.c", 293);
LABEL_26:
    BN_CTX_free(ctx);
    if ( v4 )
      ASN1_INTEGER_free(v4);
    sk_pop_free(p_stack, (void (__cdecl *)(void *))ASN1_TYPE_free);
    DSA_free((int)v2, (int)v4, v3);
    return 0;
  }
  v19 = (asn1_string_st **)pk;
  v8 = d2i_ASN1_INTEGER(0, &pk, (const unsigned __int8 *)ppklen);
  v4 = v8;
  if ( !v8 )
    goto decerr;
  if ( v8->type == 258 )
  {
    p8->broken = 4;
    ASN1_INTEGER_free(v8);
    v4 = d2i_ASN1_UINTEGER((int)v4, 0, &v19, (const unsigned __int8 *)ppklen);
    if ( !v4 )
      goto decerr;
  }
  if ( v15 != 16 )
    goto decerr;
LABEL_15:
  dmax = (unsigned __int8 *)current->vals[0].dmax;
  v3 = d2i_DSAparams(0, &dmax, (const unsigned __int8 **)current->vals[0].d);
  if ( !v3 )
    goto decerr;
  v9 = ASN1_INTEGER_to_BN((int)v4, v4, 0);
  v3->priv_key = v9;
  if ( !v9 )
  {
    v12 = 262;
LABEL_25:
    ERR_put_error((int)v4, 0xAu, 115, 109, ".\\crypto\\dsa\\dsa_ameth.c", v12);
    goto LABEL_26;
  }
  v10 = BN_new((int)v4);
  v3->pub_key = v10;
  if ( !v10 )
  {
    ERR_put_error((int)v4, 0xAu, 115, 65, ".\\crypto\\dsa\\dsa_ameth.c", 268);
    goto LABEL_26;
  }
  v2 = BN_CTX_new();
  ctx = v2;
  if ( !v2 )
  {
    ERR_put_error((int)v4, 0xAu, 115, 65, ".\\crypto\\dsa\\dsa_ameth.c", 273);
    goto LABEL_26;
  }
  if ( !BN_mod_exp(v3->pub_key, v3->g, v3->priv_key, v3->p, v2) )
  {
    v12 = 279;
    goto LABEL_25;
  }
  EVP_PKEY_assign(pkey, (void *)0x74, (char *)v3);
  BN_CTX_free(v2);
  if ( p_stack )
    sk_pop_free(p_stack, (void (__cdecl *)(void *))ASN1_TYPE_free);
  else
    ASN1_INTEGER_free(v4);
  return 1;
}
