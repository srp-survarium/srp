int __usercall check_ssl_ca@<eax>(const x509_st *x@<esi>)
{
  unsigned int ex_flags; // eax
  int result; // eax
  unsigned int ex_nscert; // ecx

  ex_flags = x->ex_flags;
  if ( (ex_flags & 2) != 0 && (x->ex_kusage & 4) == 0 )
    return 0;
  if ( (ex_flags & 1) != 0 )
    return (ex_flags & 0x10) != 0;
  if ( (ex_flags & 0x60) == 0x60 )
    return 3;
  if ( (x->ex_flags & 2) != 0 )
    return 4;
  if ( (ex_flags & 8) == 0 )
    return 0;
  ex_nscert = x->ex_nscert;
  if ( (ex_nscert & 7) == 0 )
    return 0;
  result = 5;
  if ( (ex_nscert & 4) == 0 )
    return 0;
  return result;
}
