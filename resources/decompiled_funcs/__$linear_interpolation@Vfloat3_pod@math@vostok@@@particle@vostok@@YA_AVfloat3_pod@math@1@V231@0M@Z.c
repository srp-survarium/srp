vostok::math::float3_pod *__cdecl vostok::particle::linear_interpolation<vostok::math::float3_pod>(
        vostok::math::float3_pod *result,
        vostok::math::float3_pod a,
        vostok::math::float3_pod b,
        float alpha)
{
  vostok::math::float3 *v4; // esi
  vostok::math::float3 *v5; // eax
  vostok::math::float3 v7; // [esp+4h] [ebp-34h] BYREF
  vostok::math::float3 v8; // [esp+10h] [ebp-28h] BYREF
  float value; // [esp+1Ch] [ebp-1Ch] BYREF
  vostok::math::float3 v10; // [esp+20h] [ebp-18h] BYREF
  vostok::math::float3_pod v11; // [esp+2Ch] [ebp-Ch]

  value = *(float *)&clear_value - alpha;
  v4 = vostok::math::operator*(&b, &v10, &alpha);
  v5 = vostok::math::operator*(&a, &v8, &value);
  v11 = vostok::math::operator+(v4, v5, &v7)->vostok::math::float3_pod;
  *result = v11;
  return result;
}
