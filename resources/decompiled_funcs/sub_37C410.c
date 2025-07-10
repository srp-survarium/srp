void __cdecl sub_37C410(_DWORD *a1, char a2)
{
  bool v3; // zf
  int v4; // edi
  int v5; // ebp
  unsigned int v6; // ebp
  int i; // esi
  int v8; // [esp+Ch] [ebp+4h]

  v3 = a1[19] == 0;
  v4 = a1[110];
  v8 = *(_DWORD *)(v4 + 24);
  if ( !v3 )
    a1[19] = 2;
  if ( a2 )
  {
    *(_DWORD *)(v4 + 4) = sub_37B310;
    *(_DWORD *)(v4 + 8) = sub_37C3E0;
    *(_BYTE *)(v4 + 28) = 1;
  }
  else
  {
    if ( a1[19] == 2 )
      *(_DWORD *)(v4 + 4) = sub_37C080;
    else
      *(_DWORD *)(v4 + 4) = sub_37BFC0;
    *(_DWORD *)(v4 + 8) = Scaleform::Render::JPEG::JPEGRwSource::TermSource;
    v5 = a1[28];
    if ( v5 < 1 )
    {
      *(_DWORD *)(*a1 + 20) = 58;
      *(_DWORD *)(*a1 + 24) = 1;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    if ( v5 > 256 )
    {
      *(_DWORD *)(*a1 + 20) = 59;
      *(_DWORD *)(*a1 + 24) = 256;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    if ( a1[19] == 2 )
    {
      v6 = 6 * (a1[23] + 2);
      if ( !*(_DWORD *)(v4 + 32) )
        *(_DWORD *)(v4 + 32) = (*(int (__cdecl **)(_DWORD *, int, unsigned int))(a1[1] + 4))(a1, 1, v6);
      memset(*(_DWORD *)(v4 + 32), 0, v6);
      if ( !*(_DWORD *)(v4 + 40) )
        sub_37C340((int)a1);
      *(_BYTE *)(v4 + 36) = 0;
    }
  }
  if ( *(_BYTE *)(v4 + 28) )
  {
    for ( i = 0; i < 32; ++i )
      memset(*(_DWORD *)(v8 + 4 * i), 0, 0x1000u);
    *(_BYTE *)(v4 + 28) = 0;
  }
}
