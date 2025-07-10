int __usercall vostok::render::calc_pattern@<eax>(
        const vostok::math::float2 *begin@<ecx>,
        const vostok::math::float2 *end@<eax>)
{
  float v2; // xmm0_4

  LODWORD(v2) = COERCE_UNSIGNED_INT(end->y - begin->y) & _mask__AbsFloat_;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(end->x - begin->x) & _mask__AbsFloat_) > v2 )
    LODWORD(v2) = COERCE_UNSIGNED_INT(end->x - begin->x) & _mask__AbsFloat_;
  return (int)(float)((float)((float)(v2 * 0.125) - (float)(int)(float)(v2 * 0.125)) * 8.0);
}
