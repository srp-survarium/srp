float __usercall invert@<xmm0>(float a1@<xmm1>)
{
  if ( COERCE_FLOAT(LODWORD(a1) & 0x7FFFFFFF) >= 0.0000099999997 )
    return s_bm_current_air_resistance / a1;
  else
    return 0.0;
}
