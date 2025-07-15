int __usercall get_crl_delta@<eax>(x509_store_ctx_st *ctx@<esi>, X509_crl_st **pcrl, X509_crl_st **pdcrl, x509_st *x)
{
  X509_name_st *issuer_name; // eax
  X509_name_st *v5; // edi
  stack_st_X509_CRL *v6; // edi
  X509_crl_st *v7; // eax
  int v8; // ecx
  unsigned int v9; // edx
  X509_crl_st *v10; // edx
  stack_st_X509_CRL *crls; // [esp-8h] [ebp-24h]
  X509_crl_st *pcrla; // [esp+8h] [ebp-14h] BYREF
  x509_st *pissuer; // [esp+Ch] [ebp-10h] BYREF
  int pscore; // [esp+10h] [ebp-Ch] BYREF
  unsigned int preasons; // [esp+14h] [ebp-8h] BYREF
  X509_crl_st *pdcrla; // [esp+18h] [ebp-4h] BYREF

  pissuer = 0;
  pscore = 0;
  pcrla = 0;
  pdcrla = 0;
  issuer_name = X509_get_issuer_name(x);
  crls = ctx->crls;
  v5 = issuer_name;
  preasons = ctx->current_reasons;
  if ( !get_crl_sk(ctx, &pcrla, &pdcrla, &pissuer, &pscore, &preasons, crls) )
  {
    v6 = ctx->lookup_crls(ctx, v5);
    if ( !v6 )
    {
      v7 = pcrla;
      if ( pcrla )
        goto LABEL_6;
    }
    get_crl_sk(ctx, &pcrla, &pdcrla, &pissuer, &pscore, &preasons, v6);
    sk_pop_free(&v6->stack, (void (__cdecl *)(void *))X509_CRL_free);
  }
  v7 = pcrla;
  if ( pcrla )
  {
LABEL_6:
    v8 = pscore;
    ctx->current_issuer = pissuer;
    v9 = preasons;
    ctx->current_crl_score = v8;
    ctx->current_reasons = v9;
    v10 = pdcrla;
    *pcrl = v7;
    *pdcrl = v10;
    return 1;
  }
  return 0;
}
