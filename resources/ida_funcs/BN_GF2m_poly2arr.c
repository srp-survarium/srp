int __cdecl BN_GF2m_poly2arr(const bignum_st *a, int *p, int max)
{
  const bignum_st *v3; // ebx
  int top; // ecx
  int result; // eax
  int v6; // esi
  int v7; // edi
  unsigned int v8; // ecx
  int i; // edx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx

  v3 = a;
  top = a->top;
  result = 0;
  if ( top )
  {
    v6 = top - 1;
    if ( top - 1 >= 0 )
    {
      v7 = 32 * v6 - 2;
      do
      {
        if ( v3->d[v6] )
        {
          v8 = 0x80000000;
          for ( i = 31; i >= 0; i -= 4 )
          {
            if ( (v8 & v3->d[v6]) != 0 )
            {
              if ( result < max )
              {
                p[result] = v7 + i + 2;
                v3 = a;
              }
              ++result;
            }
            v10 = v8 >> 1;
            if ( (v10 & v3->d[v6]) != 0 )
            {
              if ( result < max )
              {
                p[result] = v7 + i + 1;
                v3 = a;
              }
              ++result;
            }
            v11 = v10 >> 1;
            if ( (v11 & v3->d[v6]) != 0 )
            {
              if ( result < max )
              {
                p[result] = v7 + i;
                v3 = a;
              }
              ++result;
            }
            v12 = v11 >> 1;
            if ( (v12 & v3->d[v6]) != 0 )
            {
              if ( result < max )
              {
                p[result] = v7 + i - 1;
                v3 = a;
              }
              ++result;
            }
            v8 = v12 >> 1;
          }
        }
        --v6;
        v7 -= 32;
      }
      while ( v6 >= 0 );
    }
    if ( result < max )
      p[result++] = -1;
  }
  return result;
}
