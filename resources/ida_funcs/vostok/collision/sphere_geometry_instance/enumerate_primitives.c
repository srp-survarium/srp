void __thiscall vostok::collision::sphere_geometry_instance::enumerate_primitives(
        vostok::collision::sphere_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  float _X; // xmm3_4
  vostok::collision::enumerate_primitives_callback_vtbl *v3; // edi
  vostok::math::float4x4 *v4; // eax
  _DWORD v5[4]; // [esp+Ch] [ebp-50h] BYREF
  vostok::math::float4x4 v6; // [esp+1Ch] [ebp-40h] BYREF

  _X = (float)((float)(this->m_matrix.i.z * this->m_matrix.i.z) + (float)(this->m_matrix.i.x * this->m_matrix.i.x))
     + (float)(this->m_matrix.i.y * this->m_matrix.i.y);
  v5[0] = 0;
  *(float *)&v5[1] = sqrtf(_X);
  v3 = cb->__vftable;
  v5[2] = 0;
  v5[3] = 0;
  v4 = vostok::math::float4x4::identity(&v6);
  v3->enumerate(cb, v4, (const vostok::collision::primitive *)v5);
}


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
