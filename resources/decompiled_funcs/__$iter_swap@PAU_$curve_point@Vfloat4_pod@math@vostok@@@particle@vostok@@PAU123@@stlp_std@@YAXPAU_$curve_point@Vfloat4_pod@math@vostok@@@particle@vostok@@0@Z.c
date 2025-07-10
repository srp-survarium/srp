void __cdecl stlp_std::iter_swap<vostok::particle::curve_point<vostok::math::float4_pod> *,vostok::particle::curve_point<vostok::math::float4_pod> *>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__i1,
        vostok::particle::curve_point<vostok::math::float4_pod> *__i2)
{
  _BYTE v2[72]; // [esp+10h] [ebp-50h] BYREF

  qmemcpy(v2, __i1, sizeof(v2));
  qmemcpy(__i1, __i2, sizeof(vostok::particle::curve_point<vostok::math::float4_pod>));
  qmemcpy(__i2, v2, sizeof(vostok::particle::curve_point<vostok::math::float4_pod>));
}
