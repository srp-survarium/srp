unsigned int __usercall stlp_std::priv::__write_floatT_double_@<eax>(
        stlp_std::priv::__basic_iostring<char> *buf@<ecx>,
        __int16 flags@<bx>,
        int precision,
        long double x)
{
  int v4; // esi
  int *p_decpt; // eax
  int v7; // eax
  bool v8; // cc
  int *p_digits10; // eax
  int digits10; // [esp+1Ch] [ebp-164h] BYREF
  int decpt; // [esp+20h] [ebp-160h] BYREF
  double v13; // [esp+24h] [ebp-15Ch]
  char cvtbuf[328]; // [esp+34h] [ebp-14Ch] BYREF

  v4 = precision;
  v13 = INFINITY;
  if ( x == INFINITY )
    return stlp_std::priv::__format_nan_or_inf_double_(buf, flags, x);
  v13 = INFINITY;
  if ( -INFINITY == x )
    return stlp_std::priv::__format_nan_or_inf_double_(buf, flags, x);
  if ( (flags & 0xC0) == 0x40 )
  {
    if ( x <= -1.0 || (v7 = 324, x >= 1.0) )
      v7 = 17;
    digits10 = v7;
    v8 = v7 < precision;
    p_digits10 = &digits10;
    if ( !v8 )
      p_digits10 = &precision;
    _fcvt_s(cvtbuf, 0x146u, x, *p_digits10, &decpt, &digits10);
  }
  else
  {
    decpt = 17;
    p_decpt = &decpt;
    if ( precision <= 17 )
      p_decpt = &precision;
    _ecvt_s(cvtbuf, 0x146u, x, *p_decpt, &decpt, &digits10);
  }
  return stlp_std::priv::__format_float(cvtbuf, flags, v4, buf, decpt, digits10, 0.0 == x);
}
