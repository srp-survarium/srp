vostok::math::float4 *__usercall vostok::math::pow@<eax>(const vostok::math::float4_pod *object@<edi>, float *a2@<esi>)
{
  *a2 = powf(object->x, 2.2);
  a2[1] = powf(object->y, 2.2);
  a2[2] = powf(object->z, 2.2);
  a2[3] = powf(object->w, 2.2);
  return (vostok::math::float4 *)a2;
}
