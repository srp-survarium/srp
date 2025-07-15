int __cdecl BN_cmp(const bignum_st *a, const bignum_st *b)
{
  int neg; // eax
  int result; // eax
  int v4; // ebp
  int top; // ecx
  int v6; // edx
  int v7; // edx
  unsigned int *i; // ecx
  unsigned int v9; // esi

  if ( !a )
    return b != 0;
  if ( !b )
    return -1;
  neg = a->neg;
  if ( neg != b->neg )
    return 2 * (neg == 0) - 1;
  if ( neg )
  {
    result = -1;
    v4 = 1;
  }
  else
  {
    result = 1;
    v4 = -1;
  }
  top = a->top;
  v6 = b->top;
  if ( top <= v6 )
  {
    if ( top >= v6 )
    {
      v7 = top - 1;
      if ( top - 1 < 0 )
      {
        return 0;
      }
      else
      {
        for ( i = &b->d[v7]; ; --i )
        {
          v9 = *(unsigned int *)((char *)i + (char *)a->d - (char *)b->d);
          if ( v9 > *i )
            break;
          if ( v9 < *i )
            return v4;
          if ( --v7 < 0 )
            return 0;
        }
      }
    }
    else
    {
      return v4;
    }
  }
  return result;
}
