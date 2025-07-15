int __cdecl BN_ucmp(const bignum_st *a, const bignum_st *b)
{
  int top; // ecx
  int result; // eax
  int v4; // eax
  unsigned int *d; // edx
  unsigned int *v6; // ecx
  char *v7; // edi
  unsigned int v8; // edx

  top = a->top;
  result = top - b->top;
  if ( !result )
  {
    v4 = top - 1;
    d = b->d;
    if ( top - 1 < 0 )
    {
      return 0;
    }
    else
    {
      v6 = &d[v4];
      v7 = (char *)((char *)a->d - (char *)d);
      while ( 1 )
      {
        v8 = *(unsigned int *)((char *)v6 + (_DWORD)v7);
        if ( *v6 != v8 )
          break;
        --v4;
        --v6;
        if ( v4 < 0 )
          return 0;
      }
      return *v6 < v8 ? 1 : -1;
    }
  }
  return result;
}
