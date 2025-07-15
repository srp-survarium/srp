int __cdecl sub_374A50(bio_st *b)
{
  int (__cdecl *callback)(bio_st *, int, const char *, int, int, int); // edx
  _DWORD *v3; // eax
  const char *v4; // esi
  int v5; // edi
  int v6; // ecx
  int result; // eax
  int v8; // ecx
  signed int v9; // ebp
  int (__cdecl *i)(bio_st *, int, const char *, int, int, int); // esi
  int v11; // edi
  unsigned int v12; // ecx
  char *j; // esi
  int v14; // edi
  unsigned int v15; // ecx
  bio_st *ba; // [esp+14h] [ebp+4h]

  callback = b->callback;
  v3 = (_DWORD *)*((_DWORD *)callback + 17);
  v4 = 0;
  v5 = 0;
  for ( ba = (bio_st *)callback; v3; v3 = (_DWORD *)v3[9] )
  {
    if ( !*v3 )
    {
      v6 = v3[2];
      v4 += v6 * v3[3];
      v5 += v6 * v3[1];
    }
  }
  for ( result = *((_DWORD *)callback + 18); result; result = *(_DWORD *)(result + 36) )
  {
    if ( !*(_DWORD *)result )
    {
      v8 = *(_DWORD *)(result + 8);
      v4 += 128 * v8 * *(_DWORD *)(result + 12);
      v5 += (v8 * *(_DWORD *)(result + 4)) << 7;
    }
  }
  if ( (int)v4 > 0 )
  {
    result = jpeg_mem_available(b, v4, v5);
    if ( result < v5 )
    {
      result /= (int)v4;
      v9 = result;
      if ( result <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( i = ba[1].callback; i; i = (int (__cdecl *)(bio_st *, int, const char *, int, int, int))*((_DWORD *)i + 9) )
    {
      if ( !*(_DWORD *)i )
      {
        v11 = *((_DWORD *)i + 1);
        v12 = *((_DWORD *)i + 3);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          *((_DWORD *)i + 4) = v9 * v12;
          jpeg_open_backing_store(b);
          *((_BYTE *)i + 34) = 1;
        }
        else
        {
          *((_DWORD *)i + 4) = v11;
        }
        *(_DWORD *)i = sub_374810(b, 1u, *((_DWORD *)i + 2), *((_DWORD *)i + 4));
        result = 0;
        *((_DWORD *)i + 5) = ba[1].shutdown;
        *((_DWORD *)i + 6) = 0;
        *((_DWORD *)i + 7) = 0;
        *((_BYTE *)i + 33) = 0;
      }
    }
    for ( j = ba[1].cb_arg; j; j = (char *)*((_DWORD *)j + 9) )
    {
      if ( !*(_DWORD *)j )
      {
        v14 = *((_DWORD *)j + 1);
        v15 = *((_DWORD *)j + 3);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          *((_DWORD *)j + 4) = v9 * v15;
          jpeg_open_backing_store(b);
          j[34] = 1;
        }
        else
        {
          *((_DWORD *)j + 4) = v14;
        }
        *(_DWORD *)j = sub_3748C0(b, 1u, *((_DWORD *)j + 2), *((_DWORD *)j + 4));
        result = 0;
        *((_DWORD *)j + 5) = ba[1].shutdown;
        *((_DWORD *)j + 6) = 0;
        *((_DWORD *)j + 7) = 0;
        j[33] = 0;
      }
    }
  }
  return result;
}
