unsigned int __usercall crldp_check_crlissuer@<eax>(DIST_POINT_st *dp@<edi>, X509_crl_st *crl, unsigned int crl_score)
{
  stack_st_GENERAL_NAME *CRLissuer; // eax
  X509_name_st *issuer; // ebx
  int v6; // esi
  char *v7; // eax

  CRLissuer = dp->CRLissuer;
  issuer = crl->crl->issuer;
  if ( !CRLissuer )
    return (crl_score >> 5) & 1;
  v6 = 0;
  if ( sk_num(&CRLissuer->stack) <= 0 )
    return 0;
  while ( 1 )
  {
    v7 = sk_value(&dp->CRLissuer->stack, v6);
    if ( *(_DWORD *)v7 == 4 && !X509_NAME_cmp(*((X509_name_st **)v7 + 1), issuer) )
      break;
    if ( ++v6 >= sk_num(&dp->CRLissuer->stack) )
      return 0;
  }
  return 1;
}
