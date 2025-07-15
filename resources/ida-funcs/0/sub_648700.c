int __cdecl sub_648700(int (__stdcall **a1)(int))
{
  int v2; // [esp+0h] [ebp-4h]
  int v3; // [esp+0h] [ebp-4h]

  if ( !(*a1)(188) )
    return 0;
  sub_648EE0(a1 + 20, a1);
  sub_648EE0(a1 + 26, a1);
  sub_648E30(a1, a1);
  sub_648E30(a1 + 5, a1);
  sub_648E30(a1 + 10, a1);
  sub_648E30(a1 + 15, a1);
  *(_BYTE *)(v2 + 131) = 0;
  sub_648E30(a1 + 33, a1);
  *(_DWORD *)(v3 + 152) = 0;
  *(_DWORD *)(v3 + 156) = 0;
  *(_BYTE *)(v3 + 160) = 0;
  *(_DWORD *)(v3 + 184) = 0;
  *(_DWORD *)(v3 + 164) = 0;
  *(_DWORD *)(v3 + 180) = 0;
  *(_DWORD *)(v3 + 172) = 0;
  *(_DWORD *)(v3 + 176) = 0;
  *(_DWORD *)(v3 + 168) = 0;
  *(_BYTE *)(v3 + 128) = 1;
  *(_BYTE *)(v3 + 129) = 0;
  *(_BYTE *)(v3 + 130) = 0;
  return v3;
}
