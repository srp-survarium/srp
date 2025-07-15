vostok::math::float3 *__userpurge vostok::math::curve_line_ranged_xyz_float::evaluate@<eax>(
        vostok::math::curve_line_ranged_xyz_float *this@<ecx>,
        int a2@<edi>,
        float a3@<xmm0>,
        vostok::math::float3 *result,
        float time,
        const vostok::math::float3 *default_value,
        unsigned int time_type,
        unsigned int seed)
{
  vostok::math::curve_line_ranged_base::evaluate(
    (vostok::math::curve_line_ranged_base *)a2,
    time_type,
    time,
    default_value->x,
    *(vostok::math::enum_evaluate_type *)(a2 + 192),
    range_time_type);
  vostok::math::curve_line_ranged_base::evaluate(
    (vostok::math::curve_line_ranged_base *)(a2 + 64),
    time_type,
    time,
    default_value->y,
    *(vostok::math::enum_evaluate_type *)(a2 + 192),
    range_time_type);
  vostok::math::curve_line_ranged_base::evaluate(
    (vostok::math::curve_line_ranged_base *)(a2 + 128),
    time_type,
    time,
    default_value->z,
    *(vostok::math::enum_evaluate_type *)(a2 + 192),
    range_time_type);
  result->x = a3;
  result->y = a3;
  result->z = a3;
  return result;
}
