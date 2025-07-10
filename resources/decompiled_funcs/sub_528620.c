int __cdecl sub_528620(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // [esp+0h] [ebp-4h]

  v5 = sub_528150(a1);
  if ( v5 )
    return v5;
  *(_DWORD *)(a1 + 280) = sub_528670;
  return sub_528670(a1, a2, a3, a4);
}
