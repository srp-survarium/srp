int __cdecl check_purpose_ns_ssl_server(const x509_purpose_st *xp, const x509_st *x, int ca)
{
  unsigned int ex_flags; // eax
  unsigned int v5; // eax

  ex_flags = x->ex_flags;
  if ( (ex_flags & 4) != 0 && (x->ex_xkusage & 0x11) == 0 )
    return 0;
  if ( ca )
    return check_ssl_ca(x);
  return ((ex_flags & 8) == 0 || (x->ex_nscert & 0x40) != 0)
      && ((v5 = x->ex_flags & 2) == 0 || (x->ex_kusage & 0xA0) != 0)
      && (!v5 || (x->ex_kusage & 0x20) != 0);
}
