int __usercall crl_crldp_check@<eax>(
        x509_st *x@<ebx>,
        X509_crl_st *crl@<ecx>,
        unsigned int crl_score,
        unsigned int *preasons)
{
  int idp_flags; // eax
  int v7; // ebp
  DIST_POINT_st *v8; // edi
  ISSUING_DIST_POINT_st *idp; // esi

  idp_flags = crl->idp_flags;
  if ( (idp_flags & 0x10) != 0 )
    return 0;
  if ( (x->ex_flags & 0x10) != 0 )
  {
    if ( (idp_flags & 4) != 0 )
      return 0;
  }
  else if ( (idp_flags & 8) != 0 )
  {
    return 0;
  }
  *preasons = crl->idp_reasons;
  v7 = 0;
  if ( sk_num(&x->crldp->stack) <= 0 )
  {
LABEL_12:
    idp = crl->idp;
    if ( idp && idp->distpoint || (crl_score & 0x20) == 0 )
      return 0;
  }
  else
  {
    while ( 1 )
    {
      v8 = (DIST_POINT_st *)sk_value(&x->crldp->stack, v7);
      if ( crldp_check_crlissuer(v8, crl, crl_score) )
      {
        if ( !crl->idp || idp_check_dp(v8->distpoint) )
          break;
      }
      if ( ++v7 >= sk_num(&x->crldp->stack) )
        goto LABEL_12;
    }
    *preasons &= v8->dp_reasons;
  }
  return 1;
}
