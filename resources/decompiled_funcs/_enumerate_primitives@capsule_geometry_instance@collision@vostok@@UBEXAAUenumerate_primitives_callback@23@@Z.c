void __thiscall vostok::collision::capsule_geometry_instance::enumerate_primitives(
        vostok::collision::capsule_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  float m_radius; // xmm1_4
  vostok::collision::enumerate_primitives_callback_vtbl *v3; // edi
  vostok::math::float4x4 *v4; // eax
  _DWORD v5[4]; // [esp+0h] [ebp-50h] BYREF
  vostok::math::float4x4 v6; // [esp+10h] [ebp-40h] BYREF

  m_radius = this->m_radius;
  v3 = cb->__vftable;
  v5[1] = LODWORD(this->m_half_length);
  v5[0] = 3;
  *(float *)&v5[2] = m_radius;
  v5[3] = 0;
  v4 = vostok::math::float4x4::identity(&v6);
  v3->enumerate(cb, v4, (const vostok::collision::primitive *)v5);
}
