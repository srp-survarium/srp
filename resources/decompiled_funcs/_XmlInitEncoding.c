int __cdecl XmlInitEncoding(int a1, _DWORD *a2, int a3)
{
  int v4; // [esp+0h] [ebp-4h]

  v4 = sub_540610(a3);
  if ( v4 == -1 )
    return 0;
  *(_BYTE *)(a1 + 73) = v4;
  *(_DWORD *)a1 = sub_540700;
  *(_DWORD *)(a1 + 4) = sub_540A30;
  *(_DWORD *)(a1 + 52) = sub_5405F0;
  *(_DWORD *)(a1 + 76) = a2;
  *a2 = a1;
  return 1;
}
