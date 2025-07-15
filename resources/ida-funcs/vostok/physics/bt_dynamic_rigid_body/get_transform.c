vostok::math::float4x4 *__thiscall vostok::physics::bt_dynamic_rigid_body::get_transform(
        vostok::physics::bt_dynamic_rigid_body *this,
        vostok::math::float4x4 *result)
{
  btTransform *p_m_worldTransform; // ebx
  vostok::math::float4x4 *v3; // eax
  int v4; // xmm0_4
  vostok::math::float4x4 *v5; // esi
  vostok::math::float4x4 *v6; // eax
  int v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  vostok::math::float4x4 v10; // [esp+Ch] [ebp-4Ch] BYREF
  _BYTE v11[12]; // [esp+4Ch] [ebp-Ch]

  p_m_worldTransform = &this->m_bt_body->m_worldTransform;
  v3 = vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v10);
  *(_QWORD *)v11 = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_u64[0];
  *(_DWORD *)&v11[8] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[2];
  v4 = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[0];
  v5 = v3;
  v6 = result;
  qmemcpy(result, v5, sizeof(vostok::math::float4x4));
  v7 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[2];
  *(_QWORD *)&result->i.x = *(_QWORD *)v11;
  result->i.z = *(float *)&v11[8];
  *(_DWORD *)v11 = v4;
  *(_DWORD *)&v11[4] = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[1];
  *(_DWORD *)&v11[8] = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[2];
  v8 = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_f32[0];
  *(_QWORD *)&result->lines[1].x = *(_QWORD *)v11;
  result->j.z = *(float *)&v11[8];
  *(float *)v11 = v8;
  *(_DWORD *)&v11[4] = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[1];
  *(_DWORD *)&v11[8] = v7 ^ _mask__NegFloat_;
  v9 = p_m_worldTransform->m_origin.mVec128.m128_f32[0];
  result->k.x = v8;
  *(_QWORD *)&result->lines[2].elements[1] = *(_QWORD *)&v11[4];
  *(float *)v11 = v9;
  *(_DWORD *)&v11[4] = p_m_worldTransform->m_origin.mVec128.m128_i32[1];
  *(_DWORD *)&v11[8] = p_m_worldTransform->m_origin.mVec128.m128_i32[2] ^ _mask__NegFloat_;
  result->c.x = v9;
  *(_QWORD *)&result->lines[3].elements[1] = *(_QWORD *)&v11[4];
  return v6;
}
