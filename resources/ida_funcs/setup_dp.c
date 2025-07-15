void __usercall setup_dp(DIST_POINT_st *dp@<esi>, x509_st *x)
{
  asn1_string_st *reasons; // eax
  int v3; // edi
  char *v4; // eax
  X509_name_st *issuer_name; // eax

  reasons = dp->reasons;
  if ( reasons )
  {
    if ( reasons->length > 0 )
      dp->dp_reasons = *reasons->data;
    if ( reasons->length > 1 )
      dp->dp_reasons |= reasons->data[1] << 8;
    dp->dp_reasons &= 0x807Fu;
  }
  else
  {
    dp->dp_reasons = 32895;
  }
  if ( dp->distpoint && dp->distpoint->type == 1 )
  {
    v3 = 0;
    if ( sk_num(&dp->CRLissuer->stack) <= 0 )
      goto LABEL_15;
    while ( 1 )
    {
      v4 = sk_value(&dp->CRLissuer->stack, v3);
      if ( *(_DWORD *)v4 == 4 )
        break;
      if ( ++v3 >= sk_num(&dp->CRLissuer->stack) )
        goto LABEL_15;
    }
    issuer_name = (X509_name_st *)*((_DWORD *)v4 + 1);
    if ( !issuer_name )
LABEL_15:
      issuer_name = X509_get_issuer_name(x);
    DIST_POINT_set_dpname(dp->distpoint, issuer_name);
  }
}
