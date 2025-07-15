unsigned int __cdecl BN_mod_word(const bignum_st *a, unsigned int w)
{
  unsigned __int64 v2; // rax
  int v3; // esi
  unsigned int *v4; // edi

  LODWORD(v2) = 0;
  if ( w )
  {
    v3 = a->top - 1;
    if ( v3 >= 0 )
    {
      v4 = &a->d[v3];
      do
      {
        v2 = __PAIR64__(v2, *v4) % w;
        --v3;
        --v4;
      }
      while ( v3 >= 0 );
    }
  }
  else
  {
    LODWORD(v2) = -1;
  }
  return v2;
}
