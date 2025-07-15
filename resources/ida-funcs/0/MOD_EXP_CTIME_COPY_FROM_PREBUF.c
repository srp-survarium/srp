bignum_st *__usercall MOD_EXP_CTIME_COPY_FROM_PREBUF@<eax>(
        bignum_st *b@<edi>,
        int top,
        unsigned __int8 *buf,
        int idx,
        int width)
{
  int v5; // ebp
  bignum_st *result; // eax
  unsigned int v7; // esi
  unsigned int v8; // eax
  unsigned __int8 *v9; // ecx
  unsigned __int8 v10; // bl
  unsigned int *v11; // esi

  v5 = top;
  if ( top > b->dmax )
    result = bn_expand2(b, top);
  else
    result = b;
  if ( result )
  {
    v7 = 4 * top;
    v8 = 0;
    if ( 4 * top )
    {
      v9 = &buf[idx];
      do
      {
        v10 = *v9;
        v9 += width;
        *((_BYTE *)b->d + v8++) = v10;
      }
      while ( v8 < v7 );
    }
    b->top = top;
    if ( top > 0 )
    {
      v11 = &b->d[v7 / 4 - 1];
      do
      {
        if ( *v11-- )
          break;
        --v5;
      }
      while ( v5 > 0 );
      b->top = v5;
    }
    return (bignum_st *)1;
  }
  return result;
}
