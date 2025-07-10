int __cdecl sub_510220(int *a1, int a2, char *first, unsigned int count, int a5, int a6, int *a7)
{
  BOOL v8; // [esp+0h] [ebp-2Ch]
  BOOL v9; // [esp+4h] [ebp-28h]
  BOOL v10; // [esp+8h] [ebp-24h]
  int v11; // [esp+Ch] [ebp-20h]
  int i; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]
  char *last; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+20h] [ebp-Ch]
  int v17; // [esp+24h] [ebp-8h]
  int v18; // [esp+28h] [ebp-4h] BYREF

  v18 = *a1;
  v15 = *a7;
  v17 = *a7;
  v16 = 0;
  if ( *(_BYTE *)v18 != 40 )
    goto LABEL_45;
  if ( *(_BYTE *)(v18 + 1) == 42 )
  {
    v18 += 2;
    goto LABEL_45;
  }
  if ( *(_BYTE *)(v18 + 1) != 63 )
  {
    ++*a7;
    if ( first || *a7 != count )
    {
      ++v18;
      goto LABEL_45;
    }
    return *a7;
  }
  switch ( *(_BYTE *)(v18 + 2) )
  {
    case '|':
      v18 += 3;
      v16 = 1;
      goto LABEL_45;
    case '#':
      for ( v18 += 3; *(_BYTE *)v18 && *(_BYTE *)v18 != 41; ++v18 )
        ;
LABEL_122:
      *a1 = v18;
      return -1;
    case '(':
      v18 += 2;
      if ( *(_BYTE *)(v18 + 1) != 63 )
      {
        while ( *(_BYTE *)v18 && *(_BYTE *)v18 != 41 )
          ++v18;
        if ( *(_BYTE *)v18 )
          ++v18;
      }
      goto LABEL_45;
  }
  v18 += 2;
  if ( *(_BYTE *)v18 == 80 )
    ++v18;
  if ( (*(_BYTE *)v18 != 60 || *(_BYTE *)(v18 + 1) == 33 || *(_BYTE *)(v18 + 1) == 61) && *(_BYTE *)v18 != 39 )
  {
LABEL_45:
    while ( (unsigned int)v18 < *(_DWORD *)(a2 + 28) )
    {
      if ( *(_BYTE *)v18 == 92 )
      {
        if ( !*(_BYTE *)++v18 )
          goto LABEL_122;
        if ( *(_BYTE *)v18 == 81 )
        {
          do
          {
            do
              ++v18;
            while ( *(_BYTE *)v18 && *(_BYTE *)v18 != 92 );
            if ( !*(_BYTE *)v18 )
              goto LABEL_122;
          }
          while ( *(_BYTE *)++v18 != 69 );
        }
      }
      else if ( *(_BYTE *)v18 == 91 )
      {
        for ( i = 0; ; i = 1 )
        {
          while ( *(_BYTE *)(v18 + 1) == 92 )
          {
            if ( *(_BYTE *)(v18 + 2) == 69 )
            {
              v18 += 2;
            }
            else
            {
              if ( strncmp((const char *)(v18 + 2), "Q\\E", 3u) )
                goto LABEL_65;
              v18 += 4;
            }
          }
          if ( i || *(_BYTE *)(v18 + 1) != 94 )
            break;
          ++v18;
        }
LABEL_65:
        if ( *(_BYTE *)(v18 + 1) == 93 && (*(_DWORD *)(a2 + 76) & 0x2000000) == 0 )
          ++v18;
LABEL_68:
        while ( *(_BYTE *)++v18 != 93 )
        {
          if ( !*(_BYTE *)v18 )
            return -1;
          if ( *(_BYTE *)v18 == 92 )
          {
            if ( !*(_BYTE *)++v18 )
              goto LABEL_122;
            if ( *(_BYTE *)v18 == 81 )
            {
              while ( 1 )
              {
                do
                  ++v18;
                while ( *(_BYTE *)v18 && *(_BYTE *)v18 != 92 );
                if ( !*(_BYTE *)v18 )
                  goto LABEL_122;
                if ( *(_BYTE *)++v18 == 69 )
                  goto LABEL_68;
              }
            }
          }
        }
      }
      else if ( a5 && *(_BYTE *)v18 == 35 )
      {
        ++v18;
        while ( *(_BYTE *)v18 )
        {
          if ( *(_DWORD *)(a2 + 96) )
          {
            v10 = (unsigned int)v18 < *(_DWORD *)(a2 + 28)
               && _pcre_is_newline(v18, *(_DWORD *)(a2 + 96), *(_DWORD *)(a2 + 28), a2 + 100, a6);
            v9 = v10;
          }
          else
          {
            v8 = v18 <= (unsigned int)(*(_DWORD *)(a2 + 28) - *(_DWORD *)(a2 + 100))
              && *(unsigned __int8 *)v18 == *(unsigned __int8 *)(a2 + 104)
              && (*(_DWORD *)(a2 + 100) == 1 || *(unsigned __int8 *)(v18 + 1) == *(unsigned __int8 *)(a2 + 105));
            v9 = v8;
          }
          if ( v9 )
          {
            v18 = v18 + *(_DWORD *)(a2 + 100) - 1;
            break;
          }
          ++v18;
          if ( a6 )
          {
            while ( (*(_BYTE *)v18 & 0xC0) == 0x80 )
              ++v18;
          }
        }
        if ( !*(_BYTE *)v18 )
          goto LABEL_122;
      }
      else if ( *(_BYTE *)v18 == 40 )
      {
        v11 = sub_510220((int)&v18, a2, first, count, a5, a6, (int)a7);
        if ( v11 > 0 )
          return v11;
        if ( !*(_BYTE *)v18 )
          goto LABEL_122;
      }
      else
      {
        if ( *(_BYTE *)v18 == 41 )
        {
          if ( v16 && *a7 < v17 )
            *a7 = v17;
          goto LABEL_122;
        }
        if ( *(_BYTE *)v18 == 124 && v16 )
        {
          if ( *a7 > v17 )
            v17 = *a7;
          *a7 = v15;
        }
      }
      ++v18;
    }
    goto LABEL_122;
  }
  ++*a7;
  if ( !first && *a7 == count )
    return *a7;
  v13 = *(unsigned __int8 *)v18++;
  if ( v13 == 60 )
    v13 = 62;
  last = (char *)v18;
  while ( *(unsigned __int8 *)v18 != v13 )
    ++v18;
  if ( !first || count != v18 - (_DWORD)last || strncmp(first, last, count) )
    goto LABEL_45;
  return *a7;
}
