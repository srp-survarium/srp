unsigned int __usercall get_crl_score@<eax>(
        x509_store_ctx_st *ctx@<ecx>,
        X509_crl_st *crl@<edi>,
        x509_st **pissuer,
        unsigned int *preasons,
        x509_st *x)
{
  unsigned int v5; // ebp
  int idp_flags; // eax
  __int64 *p_check_time; // esi
  unsigned int result; // eax
  X509_name_st *issuer_name; // eax
  X509_VERIFY_PARAM_st *param; // eax
  asn1_string_st *nextUpdate; // eax
  int v13; // eax
  X509_name_st *issuer; // [esp-4h] [ebp-18h]
  unsigned int v15; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v16; // [esp+10h] [ebp-4h] BYREF

  v5 = *preasons;
  idp_flags = crl->idp_flags;
  p_check_time = 0;
  v15 = 0;
  if ( (idp_flags & 2) != 0 )
    return 0;
  if ( (ctx->param->flags & 0x1000) != 0 )
  {
    if ( (idp_flags & 0x40) != 0 )
    {
      if ( (~v5 & crl->idp_reasons) != 0 )
        goto LABEL_9;
    }
    else if ( !crl->base_crl_number )
    {
      goto LABEL_9;
    }
    return 0;
  }
  if ( (idp_flags & 0x60) != 0 )
    return 0;
LABEL_9:
  issuer = crl->crl->issuer;
  issuer_name = X509_get_issuer_name(x);
  if ( X509_NAME_cmp(issuer_name, issuer) )
  {
    if ( (crl->idp_flags & 0x20) == 0 )
      return 0;
  }
  else
  {
    v15 = 32;
  }
  if ( (crl->flags & 0x200) == 0 )
    v15 |= 0x100u;
  param = ctx->param;
  if ( (param->flags & 2) != 0 )
    p_check_time = &param->check_time;
  if ( X509_cmp_time(crl->crl->lastUpdate, p_check_time) < 0 )
  {
    nextUpdate = crl->crl->nextUpdate;
    if ( !nextUpdate
      || (v13 = X509_cmp_time(nextUpdate, p_check_time)) != 0 && (v13 >= 0 || (ctx->current_crl_score & 2) != 0) )
    {
      v15 |= 0x40u;
    }
  }
  crl_akid_check(ctx, crl, pissuer, (int *)&v15);
  if ( (v15 & 4) == 0 )
    return 0;
  if ( crl_crldp_check(x, crl, v15, &v16) )
  {
    if ( (~v5 & v16) == 0 )
      return 0;
    v5 |= v16;
    v15 |= 0x80u;
  }
  result = v15;
  *preasons = v5;
  return result;
}
