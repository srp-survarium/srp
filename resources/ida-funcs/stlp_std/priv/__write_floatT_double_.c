int __usercall stlp_std::priv::__write_floatT_double_@<eax>(
        stlp_std::priv::__basic_iostring<char> *buf@<ecx>,
        __int16 flags@<bx>,
        int precision,
        _CRT_DOUBLE x)
{
  int v4; // esi
  int *p_decpt; // eax
  int v7; // eax
  bool v8; // cc
  int *p_sign; // eax
  int sign; // [esp+1Ch] [ebp-164h] BYREF
  int decpt; // [esp+20h] [ebp-160h] BYREF
  double v13; // [esp+24h] [ebp-15Ch]
  char result[328]; // [esp+34h] [ebp-14Ch] BYREF

  v4 = precision;
  v13 = INFINITY;
  if ( x.x == INFINITY )
    return stlp_std::priv::__format_nan_or_inf_double_(buf, flags, x.x);
  v13 = INFINITY;
  if ( -INFINITY == x.x )
    return stlp_std::priv::__format_nan_or_inf_double_(buf, flags, x.x);
  if ( (flags & 0xC0) == 0x40 )
  {
    if ( x.x <= -1.0 || (v7 = 324, x.x >= 1.0) )
      v7 = 17;
    sign = v7;
    v8 = v7 < precision;
    p_sign = &sign;
    if ( !v8 )
      p_sign = &precision;
    _fcvt_s(result, 0x146u, x, *p_sign, &decpt, &sign);
  }
  else
  {
    decpt = 17;
    p_decpt = &decpt;
    if ( precision <= 17 )
      p_decpt = &precision;
    _ecvt_s(result, 0x146u, x, *p_decpt, &decpt, &sign);
  }
  return stlp_std::priv::__format_float(result, flags, v4, buf, decpt, sign, 0.0 == x.x);
}
