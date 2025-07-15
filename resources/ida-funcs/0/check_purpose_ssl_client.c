int __cdecl check_purpose_ssl_client(const x509_purpose_st *xp, const x509_st *x, int ca)
{
  unsigned int ex_flags; // eax

  ex_flags = x->ex_flags;
  if ( (ex_flags & 4) != 0 && (x->ex_xkusage & 2) == 0 )
    return 0;
  if ( ca )
    return check_ssl_ca(x);
  return ((ex_flags & 2) == 0 || (x->ex_kusage & 0x80) != 0) && ((ex_flags & 8) == 0 || (x->ex_nscert & 0x80) != 0);
}
