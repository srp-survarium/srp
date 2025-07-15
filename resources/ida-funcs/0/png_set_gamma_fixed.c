void __cdecl png_set_gamma_fixed(int a1, int a2, int a3)
{
  int v3; // [esp+Ch] [ebp+Ch]

  if ( a1 )
  {
    v3 = sub_466960(a1, a2, 1);
    *(_DWORD *)(a1 + 376) = sub_466960(a1, a3, 0);
    *(_DWORD *)(a1 + 380) = v3;
  }
}
