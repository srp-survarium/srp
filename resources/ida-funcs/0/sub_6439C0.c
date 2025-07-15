int __cdecl sub_6439C0(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_6434F0(a1);
  if ( v5 )
    return v5;
  *(_DWORD *)(a1 + 280) = sub_643A10;
  return sub_643A10(a1, a2, a3, a4);
}
