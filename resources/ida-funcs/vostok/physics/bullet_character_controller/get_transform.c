btTransform *__usercall vostok::physics::bullet_character_controller::get_transform@<eax>(
        vostok::physics::bullet_character_controller *this@<ecx>,
        btTransform *a2@<eax>,
        int a3@<edx>)
{
  _QWORD *v3; // ecx
  unsigned __int64 v4; // xmm0_8
  unsigned __int64 v5; // [esp+0h] [ebp-10h]
  unsigned __int64 v6; // [esp+8h] [ebp-8h]

  v3 = *(_QWORD **)(a3 + 136);
  a2->m_basis.m_el[0].mVec128.m128_u64[0] = v3[2];
  a2->m_basis.m_el[0].mVec128.m128_u64[1] = v3[3];
  v4 = v3[4];
  v3 += 2;
  a2->m_basis.m_el[1].mVec128.m128_u64[0] = v4;
  a2->m_basis.m_el[1].mVec128.m128_u64[1] = v3[3];
  a2->m_basis.m_el[2].mVec128.m128_u64[0] = v3[4];
  a2->m_basis.m_el[2].mVec128.m128_u64[1] = v3[5];
  a2->m_origin.mVec128.m128_u64[0] = v3[6];
  a2->m_origin.mVec128.m128_u64[1] = v3[7];
  *(float *)&v5 = a2->m_origin.mVec128.m128_f32[0] - *(float *)(a3 + 96);
  *((float *)&v5 + 1) = a2->m_origin.mVec128.m128_f32[1] - *(float *)(a3 + 100);
  *(float *)&v6 = a2->m_origin.mVec128.m128_f32[2] - *(float *)(a3 + 104);
  HIDWORD(v6) = 0;
  a2->m_origin.mVec128.m128_u64[0] = v5;
  a2->m_origin.mVec128.m128_u64[1] = v6;
  return a2;
}
