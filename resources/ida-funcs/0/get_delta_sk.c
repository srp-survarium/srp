void __cdecl get_delta_sk(x509_store_ctx_st *ctx, X509_crl_st **dcrl, int *pscore, stack_st_X509_CRL *crls)
{
  X509_crl_st *base; // ecx
  X509_crl_st *v5; // esi
  int v6; // edi
  X509_crl_st *v7; // ebx
  X509_VERIFY_PARAM_st *param; // eax
  __int64 *p_check_time; // esi
  const asn1_string_st *nextUpdate; // eax
  int v11; // eax

  v5 = base;
  if ( (ctx->param->flags & 0x2000) != 0 && ((base->flags | ctx->current_cert->ex_flags) & 0x1000) != 0 )
  {
    v6 = 0;
    if ( sk_num(&crls->stack) <= 0 )
    {
LABEL_6:
      *dcrl = 0;
    }
    else
    {
      while ( 1 )
      {
        v7 = (X509_crl_st *)sk_value(&crls->stack, v6);
        if ( check_delta_base(v7, v5) )
          break;
        if ( ++v6 >= sk_num(&crls->stack) )
          goto LABEL_6;
      }
      param = ctx->param;
      if ( (param->flags & 2) != 0 )
        p_check_time = &param->check_time;
      else
        p_check_time = 0;
      if ( X509_cmp_time(v7->crl->lastUpdate, p_check_time) < 0 )
      {
        nextUpdate = v7->crl->nextUpdate;
        if ( !nextUpdate
          || (v11 = X509_cmp_time(nextUpdate, p_check_time)) != 0 && (v11 >= 0 || (ctx->current_crl_score & 2) != 0) )
        {
          *pscore |= 2u;
        }
      }
      CRYPTO_add_lock(&v7->references, 1, 6, ".\\crypto\\x509\\x509_vfy.c", 964);
      *dcrl = v7;
    }
  }
}
