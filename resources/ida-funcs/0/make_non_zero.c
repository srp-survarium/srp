int __usercall make_non_zero@<xmm0>(int result@<xmm0>)
{
  if ( COERCE_FLOAT(result & 0x7FFFFFFF) < 0.0000099999997 )
    return LODWORD(s_bm_current_air_resistance);
  return result;
}
