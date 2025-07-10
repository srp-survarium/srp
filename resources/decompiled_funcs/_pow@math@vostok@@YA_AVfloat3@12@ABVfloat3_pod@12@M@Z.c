vostok::math::float3 *__usercall vostok::math::pow@<eax>(
        const vostok::math::float3_pod *object@<edi>,
        float *a2@<esi>,
        float power)
{
  *a2 = powf(object->x, power);
  a2[1] = powf(object->y, power);
  a2[2] = powf(object->z, power);
  return (vostok::math::float3 *)a2;
}
