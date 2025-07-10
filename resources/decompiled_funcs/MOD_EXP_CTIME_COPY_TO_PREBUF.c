int __usercall MOD_EXP_CTIME_COPY_TO_PREBUF@<eax>(
        bignum_st *b@<esi>,
        int top@<ecx>,
        unsigned __int8 *buf,
        int idx,
        int width)
{
  int result; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edi
  unsigned __int8 *v9; // edx
  int v10; // ecx
  unsigned int *v11; // edx

  if ( top > b->dmax )
    result = (int)bn_expand2(b, (unsigned int *)top);
  else
    result = (int)b;
  if ( result )
  {
    for ( result = 1; b->top < top; ++b->top )
      b->d[b->top] = 0;
    v7 = 0;
    v8 = 4 * top;
    if ( v8 )
    {
      v9 = &buf[idx];
      do
      {
        *v9 = *((_BYTE *)b->d + v7++);
        v9 += width;
      }
      while ( v7 < v8 );
    }
    v10 = b->top;
    if ( v10 > 0 )
    {
      v11 = &b->d[v10 - 1];
      do
      {
        if ( *v11-- )
          break;
        --v10;
      }
      while ( v10 > 0 );
      b->top = v10;
    }
  }
  return result;
}
