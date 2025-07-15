void __usercall vostok::sound::atomic_half3::atomic_half3(vostok::sound::atomic_half3 *this@<ecx>, _WORD *a2@<esi>)
{
  vostok::math::half *v2; // ecx
  vostok::math::half *v3; // ecx
  __int16 v4; // [esp+0h] [ebp-2h] BYREF

  v4 = HIWORD(this);
  *a2 = *vostok::math::half::half((vostok::math::half *)this, &v4, 0);
  a2[1] = *vostok::math::half::half(v2, &v4, 0);
  a2[2] = *vostok::math::half::half(v3, &v4, 0);
}
