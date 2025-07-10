void __thiscall vostok::collision::capsule_geometry_instance::enumerate_primitives(
        vostok::collision::capsule_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  float m_radius; // xmm1_4
  void (__thiscall *enumerate)(vostok::collision::enumerate_primitives_callback *, const vostok::math::float4x4 *, const vostok::collision::primitive *); // eax
  _DWORD v5[4]; // [esp+0h] [ebp-10h] BYREF

  m_radius = this->m_radius;
  enumerate = cb->enumerate;
  v5[1] = LODWORD(this->m_half_length);
  v5[0] = 3;
  *(float *)&v5[2] = m_radius;
  v5[3] = 0;
  enumerate(cb, transform, (const vostok::collision::primitive *)v5);
}
