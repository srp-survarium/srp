int __cdecl sub_643560(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp+4h] [ebp-20h]
  int v9; // [esp+8h] [ebp-1Ch] BYREF
  int v10; // [esp+Ch] [ebp-18h]
  int v11; // [esp+10h] [ebp-14h] BYREF
  int v12; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+18h] [ebp-Ch] BYREF
  int v14; // [esp+1Ch] [ebp-8h] BYREF
  int v15; // [esp+20h] [ebp-4h]

  v14 = 0;
  v15 = 0;
  v9 = 0;
  v12 = 0;
  v10 = 0;
  v11 = -1;
  if ( *(_BYTE *)(a1 + 236) )
    v4 = XmlParseXmlDeclNS(
           a2,
           *(_DWORD *)(a1 + 144),
           a3,
           a4,
           a1 + 288,
           (int)&v12,
           (int)&v13,
           (int)&v14,
           (int)&v9,
           (int)&v11);
  else
    v4 = XmlParseXmlDecl(
           a2,
           *(_DWORD *)(a1 + 144),
           a3,
           a4,
           a1 + 288,
           (int)&v12,
           (int)&v13,
           (int)&v14,
           (int)&v9,
           (int)&v11);
  if ( !v4 )
  {
    if ( a2 )
      return 31;
    else
      return 30;
  }
  if ( !a2 && v11 == 1 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 356) + 130) = 1;
    if ( *(_DWORD *)(a1 + 492) == 1 )
      *(_DWORD *)(a1 + 492) = 0;
  }
  if ( *(_DWORD *)(a1 + 140) )
  {
    if ( v14 )
    {
      v6 = (*(int (__cdecl **)(_DWORD, int))(*(_DWORD *)(a1 + 144) + 32))(*(_DWORD *)(a1 + 144), v14);
      v15 = sub_6491A0(a1 + 440, *(_DWORD *)(a1 + 144), v14, v14 + v6);
      if ( !v15 )
        return 1;
      *(_DWORD *)(a1 + 456) = *(_DWORD *)(a1 + 452);
    }
    if ( v12 )
    {
      v10 = sub_6491A0(a1 + 440, *(_DWORD *)(a1 + 144), v12, v13 - *(_DWORD *)(*(_DWORD *)(a1 + 144) + 68));
      if ( !v10 )
        return 1;
    }
    (*(void (__cdecl **)(_DWORD, int, int, int))(a1 + 140))(*(_DWORD *)(a1 + 4), v10, v15, v11);
  }
  else if ( *(_DWORD *)(a1 + 80) )
  {
    sub_6475E0(a1, *(_DWORD *)(a1 + 144), a3, a4);
  }
  if ( *(_DWORD *)(a1 + 232) )
    goto LABEL_35;
  if ( v9 )
  {
    if ( *(_DWORD *)(v9 + 68) != *(_DWORD *)(*(_DWORD *)(a1 + 144) + 68) )
    {
      *(_DWORD *)(a1 + 288) = v14;
      return 19;
    }
    *(_DWORD *)(a1 + 144) = v9;
    goto LABEL_35;
  }
  if ( !v14 )
  {
LABEL_35:
    if ( v15 || v10 )
      sub_648F20(a1 + 440);
    return 0;
  }
  if ( !v15 )
  {
    v7 = (*(int (__cdecl **)(_DWORD, int))(*(_DWORD *)(a1 + 144) + 32))(*(_DWORD *)(a1 + 144), v14);
    v15 = sub_6491A0(a1 + 440, *(_DWORD *)(a1 + 144), v14, v14 + v7);
    if ( !v15 )
      return 1;
  }
  v8 = sub_643860(a1, v15);
  sub_648F20(a1 + 440);
  if ( v8 == 18 )
    *(_DWORD *)(a1 + 288) = v14;
  return v8;
}
