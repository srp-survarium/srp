BOOL __usercall crl_revoked_issuer_match@<eax>(
        X509_crl_st *crl@<ecx>,
        X509_name_st *nm@<edx>,
        x509_revoked_st *rev@<edi>)
{
  stack_st_GENERAL_NAME *issuer; // eax
  X509_name_st *v4; // ebx
  int v6; // esi
  char *v7; // eax

  issuer = rev->issuer;
  v4 = nm;
  if ( issuer )
  {
    if ( !nm )
      v4 = crl->crl->issuer;
    v6 = 0;
    if ( sk_num(&issuer->stack) <= 0 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v7 = sk_value(&rev->issuer->stack, v6);
        if ( *(_DWORD *)v7 == 4 && !X509_NAME_cmp(v4, *((X509_name_st **)v7 + 1)) )
          break;
        if ( ++v6 >= sk_num(&rev->issuer->stack) )
          return 0;
      }
      return 1;
    }
  }
  else
  {
    return !nm || X509_NAME_cmp(nm, crl->crl->issuer) == 0;
  }
}
