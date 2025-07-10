void __thiscall vostok::math::half3::half3(vostok::math::half3 *this, const vostok::math::float3 *copy)
{
  unsigned __int16 *v2; // eax
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  vostok::math::half v6; // [esp+2Eh] [ebp-6h] BYREF
  vostok::math::half v7; // [esp+30h] [ebp-4h] BYREF
  vostok::math::half v8; // [esp+32h] [ebp-2h] BYREF

  vostok::math::half::half(&v8, copy->x);
  this->x.data = *v2;
  vostok::math::half::half(&v7, copy->y);
  this->y.data = *v3;
  vostok::math::half::half(&v6, copy->z);
  this->z.data = *v4;
}
