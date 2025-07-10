void __thiscall vostok::collision::cylinder_geometry_instance::enumerate_primitives(
        vostok::collision::cylinder_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  long double v3; // st7
  vostok::collision::enumerate_primitives_callback_vtbl *v4; // edi
  vostok::math::float4x4 *v5; // eax
  float v6; // [esp+Ch] [ebp-58h]
  _DWORD v7[4]; // [esp+14h] [ebp-50h] BYREF
  vostok::math::float4x4 v8; // [esp+24h] [ebp-40h] BYREF

  v6 = sqrtf(
         (float)((float)(this->m_matrix.j.y * this->m_matrix.j.y) + (float)(this->m_matrix.j.z * this->m_matrix.j.z))
       + (float)(this->m_matrix.j.x * this->m_matrix.j.x));
  v3 = sqrtf(
         (float)((float)(this->m_matrix.i.y * this->m_matrix.i.y) + (float)(this->m_matrix.i.z * this->m_matrix.i.z))
       + (float)(this->m_matrix.i.x * this->m_matrix.i.x));
  *(float *)&v7[1] = v6;
  v4 = cb->__vftable;
  *(float *)&v7[2] = v3;
  v7[0] = 2;
  v7[3] = 0;
  v5 = vostok::math::float4x4::identity(&v8);
  v4->enumerate(cb, v5, (const vostok::collision::primitive *)v7);
}
