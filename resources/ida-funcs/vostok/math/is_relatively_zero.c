bool __cdecl vostok::math::is_relatively_zero(float bigger_value, float smaller_value)
{
  int v2; // xmm1_4

  v2 = LODWORD(bigger_value) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(smaller_value) & 0x7FFFFFFF) > COERCE_FLOAT(LODWORD(bigger_value) & 0x7FFFFFFF) )
    return 0;
  if ( *(float *)&v2 == 0.0 )
    return 1;
  return (float)(COERCE_FLOAT(LODWORD(smaller_value) & 0x7FFFFFFF) / *(float *)&v2) < 0.0000001;
}
