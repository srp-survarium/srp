bignum_st *__cdecl BN_dup(const bignum_st *a)
{
  bignum_st *v2; // eax
  bignum_st *v3; // esi

  if ( !a )
    return 0;
  v2 = BN_new();
  v3 = v2;
  if ( !v2 )
    return 0;
  if ( !BN_copy(v2, a) )
  {
    BN_free(v3);
    return 0;
  }
  return v3;
}
