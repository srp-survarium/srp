int __usercall check_ca@<eax>(const x509_st *x@<esi>)
{
  unsigned int ex_flags; // eax

  ex_flags = x->ex_flags;
  if ( (ex_flags & 2) != 0 && (x->ex_kusage & 4) == 0 )
    return 0;
  if ( (ex_flags & 1) != 0 )
    return ((unsigned __int8)ex_flags >> 4) & 1;
  if ( (ex_flags & 0x60) == 0x60 )
    return 3;
  if ( (x->ex_flags & 2) != 0 )
    return 4;
  if ( (ex_flags & 8) != 0 && (x->ex_nscert & 7) != 0 )
    return 5;
  else
    return 0;
}
