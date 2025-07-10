vostok::math::float4_pod *__cdecl vostok::particle::linear_interpolation<vostok::math::float4_pod>(
        vostok::math::float4_pod *result,
        vostok::math::float4_pod a,
        vostok::math::float4_pod b,
        float alpha)
{
  vostok::math::float4 *v4; // eax
  vostok::math::float4 *v6; // [esp-4h] [ebp-48h]
  vostok::math::float4 v7; // [esp+0h] [ebp-44h] BYREF
  vostok::math::float4 v8; // [esp+10h] [ebp-34h] BYREF
  float value; // [esp+20h] [ebp-24h] BYREF
  vostok::math::float4 v10; // [esp+24h] [ebp-20h] BYREF
  vostok::math::float4 v11; // [esp+34h] [ebp-10h]

  value = *(float *)&clear_value - alpha;
  v6 = vostok::math::operator*(&b, &v10, &alpha);
  v4 = vostok::math::operator*(&a, &v8, &value);
  v11 = *vostok::math::operator+(&v7, v4, v6);
  *result = v11.vostok::math::float4_pod;
  return result;
}
