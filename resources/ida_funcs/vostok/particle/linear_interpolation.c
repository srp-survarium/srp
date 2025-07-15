double __cdecl vostok::particle::linear_interpolation<float>(float a, float b, float alpha)
{
  return (1.0 - alpha) * a + b * alpha;
}


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
