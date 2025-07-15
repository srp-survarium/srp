int __cdecl sub_52E310(int a1)
{
  int v2; // [esp+0h] [ebp-14h] BYREF
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h] BYREF

  v5 = *(_DWORD *)(a1 + 356);
  v3 = *(_DWORD *)(v5 + 168) + 20 * *(_DWORD *)(v5 + 176);
  v4 = (*(int (__cdecl **)(int))(a1 + 12))(v3);
  if ( !v4 )
    return 0;
  v2 = v4 + 20 * *(_DWORD *)(v5 + 176);
  v6 = v4 + 20;
  sub_52E3A0(a1, 0, v4, &v6, &v2);
  return v4;
}
