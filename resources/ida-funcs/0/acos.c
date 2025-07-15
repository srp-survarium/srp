double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x2AD8B8);
  }
  JUMPOUT(0x29D17F);
}
