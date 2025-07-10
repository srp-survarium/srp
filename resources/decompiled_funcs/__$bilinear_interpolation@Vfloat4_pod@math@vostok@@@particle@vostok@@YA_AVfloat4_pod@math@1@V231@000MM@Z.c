vostok::math::float4_pod *__cdecl vostok::particle::bilinear_interpolation<vostok::math::float4_pod>(
        vostok::math::float4_pod *result,
        vostok::math::float4_pod a0,
        vostok::math::float4_pod b0,
        vostok::math::float4_pod a1,
        vostok::math::float4_pod b1,
        float alpha0,
        float alpha1)
{
  vostok::math::float4_pod v8; // [esp+4h] [ebp-90h] BYREF
  vostok::math::float4_pod v9; // [esp+14h] [ebp-80h]
  vostok::math::float4_pod v10; // [esp+24h] [ebp-70h] BYREF
  vostok::math::float4_pod v11; // [esp+34h] [ebp-60h]
  vostok::math::float4_pod v12; // [esp+44h] [ebp-50h] BYREF
  vostok::math::float4_pod v13; // [esp+54h] [ebp-40h]
  vostok::math::float4_pod resulta; // [esp+64h] [ebp-30h]
  vostok::math::float4_pod upper_result; // [esp+74h] [ebp-20h]
  vostok::math::float4_pod lower_result; // [esp+84h] [ebp-10h]

  v13 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(&v12, a0, b0, alpha0);
  upper_result = v13;
  v11 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(&v10, a1, b1, alpha0);
  lower_result = v11;
  v9 = *vostok::particle::linear_interpolation<vostok::math::float4_pod>(&v8, upper_result, v11, alpha1);
  resulta.y = v9.y;
  *(_QWORD *)&resulta.elements[2] = *(_QWORD *)&v9.elements[2];
  result->x = v9.x;
  result->y = resulta.y;
  *(_QWORD *)&result->elements[2] = *(_QWORD *)&resulta.elements[2];
  return result;
}
