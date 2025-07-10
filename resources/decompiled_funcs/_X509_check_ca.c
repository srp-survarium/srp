int __usercall X509_check_ca@<eax>(unsigned int a1@<edi>, x509_st *x)
{
  unsigned int ex_flags; // eax

  if ( (x->ex_flags & 0x100) == 0 )
  {
    CRYPTO_lock(a1, 9, 3, ".\\crypto\\x509v3\\v3_purp.c", 532);
    x509v3_cache_extensions(x);
    CRYPTO_lock(a1, 10, 3, ".\\crypto\\x509v3\\v3_purp.c", 534);
  }
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
