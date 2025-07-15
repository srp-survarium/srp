vostok::math::float4 *__thiscall vostok::particle::curve_line_color::evaluate(
        vostok::particle::curve_line_color *this,
        vostok::math::float4 *result,
        float time,
        vostok::math::float4 default_value,
        vostok::particle::enum_evaluate_time_type time_type)
{
  vostok::math::float4 *v5; // eax
  vostok::math::float4 *v7; // eax
  float max_value; // [esp+4h] [ebp-194h]
  vostok::math::float4_pod v10; // [esp+158h] [ebp-40h] BYREF
  vostok::math::float4 v11; // [esp+168h] [ebp-30h]
  vostok::math::float4_pod v12; // [esp+178h] [ebp-20h] BYREF
  vostok::math::float4 v13; // [esp+188h] [ebp-10h]

  if ( this->m_evaluate_type == random_evaluate_type )
  {
    v11 = default_value;
    max_value = vostok::particle::random_float(this->curve_time_min, this->curve_time_max);
    v7 = (vostok::math::float4 *)vostok::particle::curve_line_points<vostok::math::float4_pod,1>::evaluate(
                                   this,
                                   &v10,
                                   max_value,
                                   default_value.vostok::math::float4_pod,
                                   range_time_type,
                                   0.0,
                                   0.0);
    vostok::math::float4::float4(v7, result);
  }
  else
  {
    v13 = default_value;
    v5 = (vostok::math::float4 *)vostok::particle::curve_line_points<vostok::math::float4_pod,1>::evaluate(
                                   this,
                                   &v12,
                                   time,
                                   default_value.vostok::math::float4_pod,
                                   time_type,
                                   0.0,
                                   0.0);
    vostok::math::float4::float4(v5, result);
  }
  return result;
}
