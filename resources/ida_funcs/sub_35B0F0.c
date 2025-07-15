BOOL __cdecl sub_35B0F0(int a1, int a2)
{
  int v4; // [esp+4h] [ebp-4h] BYREF

  return !png_muldiv(&v4, a1, a2, (int)&loc_186A0) || png_gamma_significant(v4);
}
