void __thiscall vostok::collision::sphere_geometry_instance::enumerate_primitives(
        vostok::collision::sphere_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  float _X; // xmm3_4
  void (__thiscall *enumerate)(vostok::collision::enumerate_primitives_callback *, const vostok::math::float4x4 *, const vostok::collision::primitive *); // eax
  _DWORD v5[4]; // [esp+4h] [ebp-10h] BYREF

  _X = (float)((float)(this->m_matrix.i.z * this->m_matrix.i.z) + (float)(this->m_matrix.i.x * this->m_matrix.i.x))
     + (float)(this->m_matrix.i.y * this->m_matrix.i.y);
  v5[0] = 0;
  *(float *)&v5[1] = sqrtf(_X);
  enumerate = cb->enumerate;
  v5[2] = 0;
  v5[3] = 0;
  enumerate(cb, transform, (const vostok::collision::primitive *)v5);
}
