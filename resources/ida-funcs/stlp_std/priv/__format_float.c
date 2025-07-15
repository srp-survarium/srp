int __usercall stlp_std::priv::__format_float@<eax>(
        char *bp@<eax>,
        __int16 flags@<di>,
        int precision@<ecx>,
        stlp_std::priv::__basic_iostring<char> *buf,
        int decpt,
        unsigned int sign,
        bool is_zero)
{
  unsigned int v7; // edx
  int v8; // ebp
  int v10; // eax
  unsigned int v11; // edx

  v7 = sign;
  v8 = decpt;
  if ( (flags & 0xC0) == 0x40 )
    return stlp_std::priv::__format_float_fixed(buf, bp, decpt, sign, flags, precision);
  if ( (flags & 0xC0) == 0x80 )
    return stlp_std::priv::__format_float_scientific(buf, bp, decpt, sign, is_zero, flags, precision);
  if ( (flags & 0x400) != 0 )
  {
    if ( !precision )
      precision = 1;
  }
  else if ( precision <= 0 )
  {
    precision = (flags & 0x400) + 6;
  }
  if ( is_zero )
    v8 = 1;
  v10 = precision;
  if ( (flags & 0x400) == 0 )
  {
    v11 = strlen(bp);
    if ( v11 < precision )
      v10 = v11;
    for ( ; v10 >= 1; --v10 )
    {
      if ( bp[v10 - 1] != 48 )
        break;
    }
    v7 = sign;
  }
  if ( v8 < -3 || v8 > precision )
    return stlp_std::priv::__format_float_scientific(buf, bp, v8, v7, is_zero, flags, v10 - 1);
  else
    return stlp_std::priv::__format_float_fixed(buf, bp, v8, v7, flags, v10 - v8);
}
