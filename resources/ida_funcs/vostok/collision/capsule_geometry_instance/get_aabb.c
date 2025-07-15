vostok::math::aabb *__thiscall vostok::collision::capsule_geometry_instance::get_aabb(
        vostok::collision::capsule_geometry_instance *this,
        vostok::math::aabb *result)
{
  float m_radius; // xmm6_4
  float m_half_length; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  vostok::math::aabb *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // edx
  float v10; // xmm3_4
  float v11; // ecx
  float v12; // [esp+0h] [ebp-1Ch]
  __int64 v13; // [esp+4h] [ebp-18h]
  __int64 v14; // [esp+10h] [ebp-Ch]
  float v15; // [esp+18h] [ebp-4h]

  m_radius = this->m_radius;
  m_half_length = this->m_half_length;
  v4 = this->m_matrix.j.y * m_half_length;
  v12 = this->m_matrix.j.z * m_half_length;
  v5 = fabs(this->m_matrix.j.x * m_half_length) + m_radius;
  *(float *)&v14 = this->m_matrix.c.x + v5;
  v6 = result;
  v7 = COERCE_FLOAT(LODWORD(v4) & 0x7FFFFFFF) + m_radius;
  *((float *)&v14 + 1) = this->m_matrix.c.y + v7;
  v8 = COERCE_FLOAT(LODWORD(v12) & 0x7FFFFFFF) + m_radius;
  v15 = this->m_matrix.c.z + v8;
  v9 = v15;
  v10 = this->m_matrix.c.x - v5;
  *((float *)&v13 + 1) = this->m_matrix.c.y - v7;
  v11 = this->m_matrix.c.z - v8;
  *(float *)&v13 = v10;
  *(_QWORD *)&result->min.x = v13;
  *(_QWORD *)&result->max.x = v14;
  result->min.z = v11;
  result->max.z = v9;
  return v6;
}
