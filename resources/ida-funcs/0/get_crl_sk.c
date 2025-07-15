BOOL __cdecl get_crl_sk(
        x509_store_ctx_st *ctx,
        X509_crl_st **pcrl,
        X509_crl_st **pdcrl,
        x509_st **pissuer,
        int *pscore,
        unsigned int *preasons,
        stack_st_X509_CRL *crls)
{
  x509_st *current_cert; // edx
  int v8; // esi
  X509_crl_st *v9; // ebx
  int v10; // ebp
  char *v11; // edi
  signed int crl_score; // eax
  x509_st *v13; // edx
  unsigned int v14; // eax
  x509_st *v16; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v17; // [esp+10h] [ebp-10h] BYREF
  x509_st *v18; // [esp+14h] [ebp-Ch]
  unsigned int v19; // [esp+18h] [ebp-8h]
  x509_st *v20; // [esp+1Ch] [ebp-4h]

  current_cert = ctx->current_cert;
  v8 = *pscore;
  v9 = 0;
  v19 = 0;
  v20 = current_cert;
  v16 = 0;
  v18 = 0;
  v10 = 0;
  if ( sk_num(&crls->stack) > 0 )
  {
    do
    {
      v11 = sk_value(&crls->stack, v10);
      v17 = *preasons;
      crl_score = get_crl_score(ctx, (X509_crl_st *)v11, &v16, &v17, v20);
      if ( crl_score > v8 )
      {
        v9 = (X509_crl_st *)v11;
        v18 = v16;
        v8 = crl_score;
        v19 = v17;
      }
      ++v10;
    }
    while ( v10 < sk_num(&crls->stack) );
    if ( v9 )
    {
      if ( *pcrl )
        X509_CRL_free(*pcrl);
      v13 = v18;
      v14 = v19;
      *pcrl = v9;
      *pissuer = v13;
      *pscore = v8;
      *preasons = v14;
      CRYPTO_add_lock(&v9->references, 1, 6, ".\\crypto\\x509\\x509_vfy.c", 857);
      if ( *pdcrl )
      {
        X509_CRL_free(*pdcrl);
        *pdcrl = 0;
      }
      get_delta_sk(ctx, (stack_st_X509_ATTRIBUTE **)pdcrl, pscore, crls);
    }
  }
  return v8 >= 448;
}
