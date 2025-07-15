bignum_st *__fastcall euclid(bignum_st *b, bignum_st *a)
{
  bignum_st *v2; // esi
  int top; // eax
  int v4; // ebx
  int v6; // eax
  bignum_st *v7; // eax

  v2 = b;
  top = b->top;
  v4 = 0;
  if ( !top )
    return a;
  do
  {
    if ( a->top > 0 && (*(_BYTE *)a->d & 1) != 0 )
    {
      if ( top > 0 && (*(_BYTE *)v2->d & 1) != 0 )
      {
        if ( !BN_sub(a, a, v2) )
          return 0;
LABEL_11:
        v6 = BN_rshift1(a, a);
      }
      else
      {
        v6 = BN_rshift1(v2, v2);
      }
      if ( !v6 )
        return 0;
      if ( BN_cmp(a, v2) < 0 )
      {
        v7 = a;
        a = v2;
        v2 = v7;
      }
      goto LABEL_18;
    }
    if ( top > 0 && (*(_BYTE *)v2->d & 1) != 0 )
      goto LABEL_11;
    if ( !BN_rshift1(a, a) || !BN_rshift1(v2, v2) )
      return 0;
    ++v4;
LABEL_18:
    top = v2->top;
  }
  while ( top );
  if ( v4 && !BN_lshift(a, a, v4) )
    return 0;
  return a;
}
