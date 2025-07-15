int __cdecl bn_cmp_words(char *a, char *b, int n)
{
  unsigned int v3; // esi
  unsigned int v4; // ecx
  bool v5; // cf
  int v7; // ecx
  char *i; // eax
  unsigned int v9; // edx

  v3 = *(_DWORD *)&b[4 * n - 4];
  v4 = *(_DWORD *)&a[4 * n - 4];
  v5 = v3 < v4;
  if ( v3 != v4 )
    return v5 ? 1 : -1;
  v7 = n - 2;
  if ( n - 2 >= 0 )
  {
    for ( i = &b[4 * v7]; ; i -= 4 )
    {
      v9 = *(_DWORD *)&i[a - b];
      v5 = *(_DWORD *)i < v9;
      if ( *(_DWORD *)i != v9 )
        break;
      if ( --v7 < 0 )
        return 0;
    }
    return v5 ? 1 : -1;
  }
  return 0;
}
