void __thiscall vostok::collision::box_geometry_instance::enumerate_primitives(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::enumerate_primitives_callback_vtbl *v2; // edi
  vostok::math::float4x4 *v3; // eax
  __int64 v4; // [esp+4h] [ebp-5Ch]
  const vostok::math::float4x4 *v5; // [esp+Ch] [ebp-54h]
  int v6; // [esp+10h] [ebp-50h] BYREF
  __int64 v7; // [esp+14h] [ebp-4Ch]
  const vostok::math::float4x4 *v8; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 v9; // [esp+20h] [ebp-40h] BYREF

  v2 = cb->__vftable;
  v5 = clear_value;
  LODWORD(v4) = clear_value;
  HIDWORD(v4) = clear_value;
  v6 = 1;
  v7 = v4;
  v8 = clear_value;
  v3 = vostok::math::float4x4::identity(&v9);
  v2->enumerate(cb, v3, (const vostok::collision::primitive *)&v6);
}
