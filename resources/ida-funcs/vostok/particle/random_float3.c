vostok::math::float3 *__usercall vostok::particle::random_float3@<eax>(
        const vostok::math::float3 *max_value@<edi>,
        vostok::math::float3 *a2@<esi>,
        const vostok::math::float3 *min_value)
{
  double v4; // st7
  vostok::math::float3 *result; // eax
  float v6; // [esp+Ch] [ebp-4h]
  float v7; // [esp+18h] [ebp+8h]

  v7 = vostok::particle::random_float(min_value->x, max_value->x);
  v6 = vostok::particle::random_float(min_value->y, max_value->y);
  v4 = vostok::particle::random_float(min_value->z, max_value->z);
  a2->x = v7;
  result = a2;
  a2->y = v6;
  a2->z = v4;
  return result;
}
