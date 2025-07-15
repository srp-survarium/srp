int __cdecl check_purpose_timestamp_sign(const x509_purpose_st *xp, x509_st *x, int ca)
{
  int result; // eax
  unsigned int ex_flags; // ecx
  unsigned int ex_kusage; // eax
  int ext_by_NID; // eax
  X509_extension_st *ext; // eax

  if ( ca )
    return check_ca(x);
  ex_flags = x->ex_flags;
  result = 0;
  if ( (ex_flags & 2) == 0 || (ex_kusage = x->ex_kusage, (ex_kusage & 0xFFFFFF3F) == 0) && (ex_kusage & 0xC0) != 0 )
  {
    if ( (ex_flags & 4) != 0 && x->ex_xkusage == 64 )
    {
      ext_by_NID = X509_get_ext_by_NID((stack_st_X509_ATTRIBUTE *)x, 126, 0);
      if ( ext_by_NID < 0 )
        return 1;
      ext = X509_get_ext(x, ext_by_NID);
      if ( X509_EXTENSION_get_critical(ext) )
        return 1;
    }
  }
  return result;
}
