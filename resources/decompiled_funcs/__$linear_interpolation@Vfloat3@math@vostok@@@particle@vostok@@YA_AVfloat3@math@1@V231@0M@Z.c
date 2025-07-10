vostok::math::float3 *__cdecl vostok::particle::linear_interpolation<vostok::math::float3>(
        vostok::math::float3 *result,
        vostok::math::float3 a,
        vostok::math::float3 b,
        float alpha)
{
  vostok::math::float3 *v4; // esi
  vostok::math::float3 *v5; // eax
  vostok::math::float3 v7; // [esp+4h] [ebp-1Ch] BYREF
  float value; // [esp+10h] [ebp-10h] BYREF
  vostok::math::float3 v9; // [esp+14h] [ebp-Ch] BYREF

  value = *(float *)&clear_value - alpha;
  v4 = vostok::math::operator*(&b, &v9, &alpha);
  v5 = vostok::math::operator*(&a, &v7, &value);
  vostok::math::operator+(v4, v5, result);
  return result;
}
