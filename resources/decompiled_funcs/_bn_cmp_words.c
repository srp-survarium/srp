int __cdecl bn_cmp_words(char *a, char *b, int n)
{
  unsigned int v3; // esi
  unsigned int v4; // ecx
  bool v5; // cf
  int v7; // ecx
  const unsigned int *i; // eax
  unsigned int v9; // edx

  v3 = *(_DWORD *)&b[4 * n - 4];
  v4 = *(_DWORD *)&a[4 * n - 4];
  v5 = v3 < v4;
  if ( v3 != v4 )
    return v5 ? 1 : -1;
  v7 = n - 2;
  if ( n - 2 >= 0 )
  {
    for ( i = (const unsigned int *)&b[4 * v7]; ; --i )
    {
      v9 = *(const unsigned int *)((char *)i + a - b);
      v5 = *i < v9;
      if ( *i != v9 )
        break;
      if ( --v7 < 0 )
        return 0;
    }
    return v5 ? 1 : -1;
  }
  return 0;
}
