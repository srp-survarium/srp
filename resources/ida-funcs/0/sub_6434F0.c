int __cdecl sub_6434F0(int a1)
{
  int inited; // eax
  int v3; // [esp+4h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 232);
  if ( *(_BYTE *)(a1 + 236) )
    inited = XmlInitEncodingNS(a1 + 148, a1 + 144, v3);
  else
    inited = XmlInitEncoding(a1 + 148, a1 + 144, v3);
  if ( inited )
    return 0;
  else
    return sub_643860(a1, *(_DWORD *)(a1 + 232));
}
