bignum_st *__usercall BN_dup@<eax>(int a1@<ebx>, const bignum_st *a)
{
  bignum_st *v3; // eax
  bignum_st *v4; // esi

  if ( !a )
    return 0;
  v3 = BN_new(a1);
  v4 = v3;
  if ( !v3 )
    return 0;
  if ( !BN_copy(v3, a) )
  {
    BN_free(v4);
    return 0;
  }
  return v4;
}
