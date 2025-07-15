bool __cdecl vostok::math::is_relatively_zero(float bigger_value, float smaller_value, float epsilon)
{
  int v3; // xmm1_4

  v3 = LODWORD(bigger_value) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(smaller_value) & 0x7FFFFFFF) > COERCE_FLOAT(LODWORD(bigger_value) & 0x7FFFFFFF) )
    return 0;
  if ( *(float *)&v3 == 0.0 )
    return 1;
  return epsilon > (float)(COERCE_FLOAT(LODWORD(smaller_value) & 0x7FFFFFFF) / *(float *)&v3);
}
