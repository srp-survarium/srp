int __cdecl X509_check_issued(x509_st *issuer, x509_st *subject)
{
  X509_name_st *subject_name; // eax
  int result; // eax
  X509_name_st *issuer_name; // [esp-4h] [ebp-Ch]

  issuer_name = X509_get_issuer_name(subject);
  subject_name = X509_get_subject_name(issuer);
  if ( X509_NAME_cmp(subject_name, issuer_name) )
    return 29;
  x509v3_cache_extensions(issuer);
  x509v3_cache_extensions(subject);
  if ( !subject->akid || (result = X509_check_akid(issuer, subject->akid)) == 0 )
  {
    if ( (subject->ex_flags & 0x400) != 0 )
    {
      if ( (issuer->ex_flags & 2) != 0 && SLOBYTE(issuer->ex_kusage) >= 0 )
        return 39;
    }
    else if ( (issuer->ex_flags & 2) != 0 && (issuer->ex_kusage & 4) == 0 )
    {
      return 32;
    }
    return 0;
  }
  return result;
}
