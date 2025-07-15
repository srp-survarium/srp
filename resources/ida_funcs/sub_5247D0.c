_DWORD *__cdecl sub_5247D0(int a1, int a2, _BYTE *a3, int a4)
{
  _DWORD *v5; // [esp+8h] [ebp-4h]

  if ( a2 )
  {
    v5 = (_DWORD *)(*(int (__cdecl **)(int))a2)(500);
    if ( v5 )
    {
      v5[3] = *(_DWORD *)a2;
      v5[4] = *(_DWORD *)(a2 + 4);
      v5[5] = *(_DWORD *)(a2 + 8);
    }
  }
  else
  {
    v5 = malloc(0x1F4u);
    if ( v5 )
    {
      v5[3] = malloc;
      v5[4] = realloc;
      v5[5] = free;
    }
  }
  if ( !v5 )
    return 0;
  v5[2] = 0;
  v5[8] = 0;
  v5[95] = 16;
  v5[98] = ((int (__cdecl *)(int))v5[3])(16 * v5[95]);
  if ( !v5[98] )
  {
    ((void (__cdecl *)(_DWORD *))v5[5])(v5);
    return 0;
  }
  v5[11] = ((int (__cdecl *)(int))v5[3])(1024);
  if ( !v5[11] )
  {
    ((void (__cdecl *)(_DWORD))v5[5])(v5[98]);
    ((void (__cdecl *)(_DWORD *))v5[5])(v5);
    return 0;
  }
  v5[12] = v5[11] + 1024;
  if ( a4 )
  {
    v5[89] = a4;
  }
  else
  {
    v5[89] = sub_52D360(v5 + 3);
    if ( !v5[89] )
    {
      ((void (__cdecl *)(_DWORD))v5[5])(v5[11]);
      ((void (__cdecl *)(_DWORD))v5[5])(v5[98]);
      ((void (__cdecl *)(_DWORD *))v5[5])(v5);
      return 0;
    }
  }
  v5[94] = 0;
  v5[92] = 0;
  v5[76] = 0;
  v5[117] = 0;
  v5[116] = 0;
  v5[31] = 0;
  v5[62] = 0;
  *((_BYTE *)v5 + 472) = 33;
  *((_BYTE *)v5 + 236) = 0;
  *((_BYTE *)v5 + 237) = 0;
  v5[99] = 0;
  v5[100] = 0;
  *((_BYTE *)v5 + 404) = 0;
  sub_52DB40(v5 + 104, v5 + 3);
  sub_52DB40(v5 + 110, v5 + 3);
  sub_524AE0((int)v5, a1);
  if ( !a1 || v5[58] )
  {
    if ( a3 )
    {
      *((_BYTE *)v5 + 236) = 1;
      v5[57] = XmlGetUtf8InternalEncodingNS();
      *((_BYTE *)v5 + 472) = *a3;
    }
    else
    {
      v5[57] = XmlGetUtf8InternalEncoding();
    }
    return v5;
  }
  else
  {
    XML_ParserFree(v5);
    return 0;
  }
}
