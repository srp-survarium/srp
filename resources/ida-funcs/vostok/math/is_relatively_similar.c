BOOL __usercall vostok::math::is_relatively_similar@<eax>(float a1@<xmm0>, float a2@<xmm2>)
{
  int v2; // xmm1_4
  bool v3; // cc

  v2 = LODWORD(a1) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(a1) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(a2) & 0x7FFFFFFF) )
    v2 = LODWORD(a2) & 0x7FFFFFFF;
  if ( *(float *)&v2 == 0.0 )
    v3 = fabs(a1 - a2) >= 0.0000099999997;
  else
    v3 = (float)(fabs(a1 - a2) / *(float *)&v2) >= 0.0000099999997;
  return !v3;
}
