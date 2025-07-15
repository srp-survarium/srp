void __cdecl BN_free(bignum_st *a)
{
  int flags; // eax

  if ( a )
  {
    if ( a->d && (a->flags & 2) == 0 )
      CRYPTO_free(a->d);
    flags = a->flags;
    if ( (flags & 1) != 0 )
    {
      CRYPTO_free(a);
    }
    else
    {
      a->flags = flags | 0x8000;
      a->d = 0;
    }
  }
}
