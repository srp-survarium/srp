int __cdecl bn_cmp_part_words(char *a, char *b, int cl, int dl)
{
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  char *v7; // edx
  char *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  bool v11; // cf
  int v13; // ecx
  char *i; // eax
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
        for ( i = &b[4 * v13]; ; i -= 4 )
        {
          v15 = *(_DWORD *)&i[a - b];
          v11 = *(_DWORD *)i < v15;
          if ( *(_DWORD *)i != v15 )
            break;
          if ( --v13 < 0 )
            return 0;
        }
      }
      return v11 ? 1 : -1;
    }
    v8 = &a[4 * dl + 4 * v5];
    while ( !*(_DWORD *)v8 )
    {
      --v4;
      v8 -= 4;
      if ( v4 <= 0 )
        goto LABEL_9;
    }
    return 1;
  }
  else
  {
    v6 = dl;
    v7 = &b[4 * (v5 - dl)];
    while ( !*(_DWORD *)v7 )
    {
      ++v6;
      v7 -= 4;
      if ( v6 >= 0 )
        goto LABEL_5;
    }
    return -1;
  }
}
