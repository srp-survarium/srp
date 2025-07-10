vostok::math::float4x4 *__cdecl vostok::math::transpose(
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *other)
{
  vostok::math::float4x4 *v2; // eax
  vostok::math::float4_pod v3; // [esp+0h] [ebp-10h]

  v2 = result;
  v3.x = other->i.x;
  v3.y = other->j.x;
  v3.z = other->k.x;
  v3.w = other->c.x;
  result->i = v3;
  v3.x = other->i.y;
  v3.y = other->j.y;
  v3.z = other->k.y;
  v3.w = other->c.y;
  result->j = v3;
  v3.x = other->i.z;
  v3.y = other->j.z;
  v3.z = other->k.z;
  v3.w = other->c.z;
  result->k = v3;
  v3.x = other->i.w;
  v3.y = other->j.w;
  v3.z = other->k.w;
  v3.w = other->c.w;
  result->c = v3;
  return v2;
}
