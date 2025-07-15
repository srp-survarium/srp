void __thiscall vostok::collision::truncated_sphere_geometry_instance::enumerate_primitives(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::enumerate_primitives_callback_vtbl *v2; // edi
  vostok::math::float4x4 *v3; // eax
  _DWORD v4[4]; // [esp+0h] [ebp-50h] BYREF
  vostok::math::float4x4 v5; // [esp+10h] [ebp-40h] BYREF

  v2 = cb->__vftable;
  v4[1] = LODWORD(this->m_radius);
  v4[0] = 0;
  v4[2] = 0;
  v4[3] = 0;
  v3 = vostok::math::float4x4::identity(&v5);
  v2->enumerate(cb, v3, (const vostok::collision::primitive *)v4);
}


void __thiscall vostok::collision::truncated_sphere_geometry_instance::enumerate_primitives(
        vostok::collision::truncated_sphere_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  void (__thiscall *enumerate)(vostok::collision::enumerate_primitives_callback *, const vostok::math::float4x4 *, const vostok::collision::primitive *); // eax
  _DWORD v4[4]; // [esp+0h] [ebp-10h] BYREF

  enumerate = cb->enumerate;
  v4[1] = LODWORD(this->m_radius);
  v4[0] = 0;
  v4[2] = 0;
  v4[3] = 0;
  enumerate(cb, transform, (const vostok::collision::primitive *)v4);
}
