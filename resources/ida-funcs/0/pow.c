double __cdecl pow(double X, double Y)
{
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns )
  {
    v2 = _mm_getcsr() & 0x1F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      JUMPOUT(0x667DA9);
  }
  JUMPOUT(0x665724);
}
