vostok::math::float3 *__usercall vostok::math::abs@<eax>(
        const vostok::math::float3 *object@<edx>,
        vostok::math::float3 *result@<eax>)
{
  int v2; // edx
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v3 = LODWORD(object->z) & 0x7FFFFFFF;
  v4 = LODWORD(object->y) & 0x7FFFFFFF;
  v2 = LODWORD(object->x) & 0x7FFFFFFF;
  LODWORD(result->y) = v4;
  LODWORD(result->x) = v2;
  LODWORD(result->z) = v3;
  return result;
}
