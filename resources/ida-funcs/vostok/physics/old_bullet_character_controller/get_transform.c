btTransform *__userpurge vostok::physics::old_bullet_character_controller::get_transform@<eax>(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        btTransform *a2@<eax>,
        btTransform *result)
{
  unsigned __int64 v3; // [esp+14h] [ebp-Ch]

  a2->m_basis.m_el[0] = result[2].m_origin;
  a2->m_basis.m_el[1] = result[3].m_basis.m_el[0];
  a2->m_basis.m_el[2] = result[3].m_basis.m_el[1];
  a2->m_origin = result[3].m_basis.m_el[2];
  *(float *)&v3 = a2->m_origin.mVec128.m128_f32[1] - result[1].m_origin.mVec128.m128_f32[1];
  *((float *)&v3 + 1) = a2->m_origin.mVec128.m128_f32[2] - result[1].m_origin.mVec128.m128_f32[2];
  a2->m_origin.mVec128.m128_f32[0] = a2->m_origin.mVec128.m128_f32[0] - result[1].m_origin.mVec128.m128_f32[0];
  *(unsigned __int64 *)((char *)a2->m_origin.mVec128.m128_u64 + 4) = v3;
  a2->m_origin.mVec128.m128_i32[3] = 0;
  return a2;
}
