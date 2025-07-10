int __cdecl sub_52D9F0(int a1, _BYTE *a2)
{
  int v3; // [esp+0h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 496);
  while ( *a2 )
    v3 = (unsigned __int8)*a2++ ^ (1000003 * v3);
  return v3;
}
