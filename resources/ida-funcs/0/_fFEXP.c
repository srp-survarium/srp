int __usercall _fFEXP@<eax>(int a1@<ebp>, double a2@<st0>)
{
  double v2; // st7

  *(_BYTE *)(a1 - 144) = -2;
  v2 = a2 * 1.442695040888963407;
  _ffexpm1();
  if ( (*(_BYTE *)(a1 - 159) & 1) != 0 && _adjust_fdiv == 1 )
    _safe_fdivr(1.442695040888963407 + 1.0, v2);
  return _rttospop();
}
