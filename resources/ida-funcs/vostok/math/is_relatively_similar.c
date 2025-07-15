int __usercall vostok::math::is_relatively_similar@<eax>(float a1@<xmm0>, float a2@<xmm2>)
{
  int v2; // xmm1_4
  float v3; // xmm0_4
  int result; // eax
  bool v5; // cc

  v2 = LODWORD(a1) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(a1) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(a2) & 0x7FFFFFFF) )
    v2 = LODWORD(a2) & 0x7FFFFFFF;
  v3 = a1 - a2;
  result = 0;
  if ( *(float *)&v2 == 0.0 )
    v5 = COERCE_FLOAT(LODWORD(v3) & 0x7FFFFFFF) >= 0.0000099999997;
  else
    v5 = (float)(COERCE_FLOAT(LODWORD(v3) & 0x7FFFFFFF) / *(float *)&v2) >= 0.0000099999997;
  if ( !v5 )
    return 1;
  return result;
}
