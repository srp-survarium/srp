void __thiscall vostok::collision::cylinder_geometry_instance::enumerate_primitives(
        vostok::collision::cylinder_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  long double v4; // st7
  vostok::collision::enumerate_primitives_callback_vtbl *v5; // eax
  void (__thiscall *enumerate)(vostok::collision::enumerate_primitives_callback *, const vostok::math::float4x4 *, const vostok::collision::primitive *); // eax
  float v7; // [esp+8h] [ebp-18h]
  _DWORD v8[4]; // [esp+10h] [ebp-10h] BYREF

  v7 = sqrtf(
         (float)((float)(this->m_matrix.j.y * this->m_matrix.j.y) + (float)(this->m_matrix.j.z * this->m_matrix.j.z))
       + (float)(this->m_matrix.j.x * this->m_matrix.j.x));
  v4 = sqrtf(
         (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y) + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
       + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  *(float *)&v8[1] = v7;
  v5 = cb->__vftable;
  *(float *)&v8[2] = v4;
  enumerate = v5->enumerate;
  v8[0] = 2;
  v8[3] = 0;
  enumerate(cb, transform, (const vostok::collision::primitive *)v8);
}
