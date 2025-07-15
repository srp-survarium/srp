void __usercall vostok::math::half3::half3(
        vostok::math::half3 *this@<esi>,
        const vostok::math::float3 *copy@<edi>,
        vostok::math::half *a3@<ecx>)
{
  vostok::math::half *v3; // ecx
  vostok::math::half *v4; // ecx
  __int16 v5; // [esp+0h] [ebp-2h] BYREF

  v5 = HIWORD(a3);
  this->x.data = *vostok::math::half::half(a3, &v5, LODWORD(copy->x));
  this->y.data = *vostok::math::half::half(v3, &v5, LODWORD(copy->y));
  this->z.data = *vostok::math::half::half(v4, &v5, LODWORD(copy->z));
}
