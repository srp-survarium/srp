int __cdecl png_user_version_check(int a1, char *a2)
{
  int v2; // esi
  int v4; // esi
  int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax
  _BYTE *header_ver; // eax
  unsigned int v10; // [esp+4h] [ebp-8Ch]
  _BYTE v11[128]; // [esp+8h] [ebp-88h] BYREF
  int v12; // [esp+8Ch] [ebp-4h]

  if ( a2 )
  {
    v12 = 0;
    do
    {
      v2 = a2[v12];
      if ( v2 != *(char *)(png_get_header_ver(0) + v12) )
        *(_DWORD *)(a1 + 112) |= (unsigned int)&loc_20000;
    }
    while ( *(char *)(png_get_header_ver(0) + v12++) );
  }
  else
  {
    *(_DWORD *)(a1 + 112) |= (unsigned int)&loc_20000;
  }
  if ( ((unsigned int)&loc_20000 & *(_DWORD *)(a1 + 112)) == 0 )
    return 1;
  if ( a2 )
  {
    v4 = *a2;
    if ( v4 == *(char *)png_get_header_ver(0) )
    {
      if ( *a2 != 49 || (v5 = a2[2], v5 == *(char *)(png_get_header_ver(0) + 2)) )
      {
        if ( *a2 != 48 || a2[2] >= 57 )
          return 1;
      }
    }
  }
  v6 = png_safecat((int)v11, 0x80u, 0, "Application built with libpng-");
  v7 = png_safecat((int)v11, 0x80u, v6, a2);
  v10 = png_safecat((int)v11, 0x80u, v7, " but running with ");
  header_ver = (_BYTE *)png_get_header_ver(0);
  png_safecat((int)v11, 0x80u, v10, header_ver);
  png_warning(a1, v11);
  return 0;
}
