vostok::math::float3 *__thiscall vostok::math::float3_pod::normalize_safe(
        vostok::math::float3_pod *this,
        const vostok::math::float3_pod *result_in_case_of_zero)
{
  float y; // xmm2_4
  float v4; // xmm3_4
  int v5; // xmm0_4
  int v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float x; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+Ch] [ebp-Ch]
  float length; // [esp+14h] [ebp-4h]

  x = this->x;
  length = sqrtf((float)((float)(this->y * this->y) + (float)(this->x * this->x)) + (float)(this->z * this->z));
  y = this->y;
  v4 = x;
  v5 = LODWORD(y) & 0x7FFFFFFF;
  v11 = LODWORD(x) & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(y) & 0x7FFFFFFF) <= COERCE_FLOAT(LODWORD(this->z) & 0x7FFFFFFF) )
    v5 = LODWORD(this->z) & 0x7FFFFFFF;
  if ( *(float *)&v11 > *(float *)&v5 )
    v5 = v11;
  v6 = v5 & 0x7FFFFFFF;
  if ( COERCE_FLOAT(LODWORD(length) & 0x7FFFFFFF) <= COERCE_FLOAT(v5 & 0x7FFFFFFF)
    && (*(float *)&v6 == 0.0 || (float)(COERCE_FLOAT(LODWORD(length) & 0x7FFFFFFF) / *(float *)&v6) < 0.0000001) )
  {
    *this = *result_in_case_of_zero;
    return (vostok::math::float3 *)this;
  }
  else
  {
    v7 = y * (float)(*(float *)&clear_value / length);
    v8 = this->z * (float)(*(float *)&clear_value / length);
    this->x = v4 * (float)(*(float *)&clear_value / length);
    this->y = v7;
    this->z = v8;
    return (vostok::math::float3 *)this;
  }
}
