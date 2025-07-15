int __usercall X509_check_purpose@<eax>(int a1@<edi>, int a2@<ebx>, x509_st *x, int id, int ca)
{
  int result; // eax
  char *v6; // eax

  if ( (x->ex_flags & 0x100) == 0 )
  {
    CRYPTO_lock(a1, a2, 9, 3, ".\\crypto\\x509v3\\v3_purp.c", 114);
    x509v3_cache_extensions(x);
    CRYPTO_lock(a1, a2, 10, 3, ".\\crypto\\x509v3\\v3_purp.c", 116);
  }
  if ( id == -1 )
    return 1;
  result = X509_PURPOSE_get_by_id(a1, id);
  if ( result != -1 )
  {
    if ( result >= 0 )
    {
      if ( result >= 9 )
      {
        v6 = sk_value(&xptable->stack, result - 9);
        return (*((int (__cdecl **)(char *, x509_st *, int))v6 + 3))(v6, x, ca);
      }
      else
      {
        return xstandard[result].check_purpose(&xstandard[result], x, ca);
      }
    }
    else
    {
      return MEMORY[0xC](0, x, ca);
    }
  }
  return result;
}
