int __cdecl sub_643860(int a1, int a2)
{
  int v2; // eax
  int inited; // eax
  _DWORD v5[256]; // [esp+8h] [ebp-418h] BYREF
  int v6; // [esp+408h] [ebp-18h]
  int v7; // [esp+40Ch] [ebp-14h]
  void (__cdecl *v8)(int); // [esp+410h] [ebp-10h]
  int i; // [esp+41Ch] [ebp-4h]

  if ( !*(_DWORD *)(a1 + 124) )
    return 18;
  for ( i = 0; i < 256; ++i )
    v5[i] = -1;
  v7 = 0;
  v6 = 0;
  v8 = 0;
  if ( !(*(int (__cdecl **)(_DWORD, int, _DWORD *))(a1 + 124))(*(_DWORD *)(a1 + 248), a2, v5) )
  {
LABEL_15:
    if ( v8 )
      v8(v6);
    return 18;
  }
  v2 = XmlSizeOfUnknownEncoding();
  *(_DWORD *)(a1 + 240) = (*(int (__cdecl **)(int))(a1 + 12))(v2);
  if ( *(_DWORD *)(a1 + 240) )
  {
    if ( *(_BYTE *)(a1 + 236) )
      inited = XmlInitUnknownEncodingNS(*(_DWORD *)(a1 + 240), (int)v5, v7, v6);
    else
      inited = XmlInitUnknownEncoding(*(_DWORD *)(a1 + 240), (int)v5, v7, v6);
    if ( inited )
    {
      *(_DWORD *)(a1 + 244) = v6;
      *(_DWORD *)(a1 + 252) = v8;
      *(_DWORD *)(a1 + 144) = inited;
      return 0;
    }
    goto LABEL_15;
  }
  if ( v8 )
    v8(v6);
  return 1;
}
