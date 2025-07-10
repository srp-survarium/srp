vostok::math::float4_pod *__cdecl vostok::math::linear_interpolation<vostok::math::float4_pod>(
        vostok::math::float4_pod *result,
        vostok::math::float4_pod a,
        vostok::math::float4_pod b,
        float alpha)
{
  vostok::math::float4_pod *v4; // eax

  v4 = result;
  b.x = (float)(a.x * (float)(*(float *)&clear_value - alpha)) + (float)(b.x * alpha);
  b.y = (float)(a.y * (float)(*(float *)&clear_value - alpha)) + (float)(b.y * alpha);
  *(_QWORD *)&b.elements[2] = __PAIR64__(
                                (float)(a.w * (float)(*(float *)&clear_value - alpha)) + (float)(b.w * alpha),
                                (float)(a.z * (float)(*(float *)&clear_value - alpha)) + (float)(b.z * alpha));
  *result = b;
  return v4;
}
