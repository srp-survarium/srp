int __cdecl bn_cmp_part_words(char *a, char *b, int cl, int dl)
{
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  const unsigned int *v7; // edx
  const unsigned int *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  bool v11; // cf
  int v13; // ecx
  const unsigned int *i; // eax
  unsigned int v15; // edx

  v4 = dl;
  v5 = cl - 1;
  if ( dl >= 0 )
  {
LABEL_5:
    if ( dl <= 0 )
    {
LABEL_9:
      v9 = *(_DWORD *)&a[4 * cl - 4];
      v10 = *(_DWORD *)&b[4 * cl - 4];
      v11 = v10 < v9;
      if ( v10 == v9 )
      {
        v13 = cl - 2;
        if ( cl - 2 < 0 )
          return 0;
        for ( i = (const unsigned int *)&b[4 * v13]; ; --i )
        {
          v15 = *(const unsigned int *)((char *)i + a - b);
          v11 = *i < v15;
          if ( *i != v15 )
            break;
          if ( --v13 < 0 )
            return 0;
        }
      }
      return v11 ? 1 : -1;
    }
    v8 = (const unsigned int *)&a[4 * dl + 4 * v5];
    while ( !*v8 )
    {
      --v4;
      --v8;
      if ( v4 <= 0 )
        goto LABEL_9;
    }
    return 1;
  }
  else
  {
    v6 = dl;
    v7 = (const unsigned int *)&b[4 * (v5 - dl)];
    while ( !*v7 )
    {
      ++v6;
      --v7;
      if ( v6 >= 0 )
        goto LABEL_5;
    }
    return -1;
  }
}
