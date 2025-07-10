vostok::math::aabb *__thiscall vostok::collision::truncated_sphere_geometry_instance::get_aabb(
        vostok::collision::truncated_sphere_geometry_instance *this,
        vostok::math::aabb *result)
{
  float m_radius; // xmm0_4
  vostok::math::aabb *v3; // eax
  float v4; // edx
  float v5; // xmm1_4
  float v6; // xmm3_4
  __int64 v7; // [esp+0h] [ebp-18h]
  __int64 v8; // [esp+Ch] [ebp-Ch]

  m_radius = this->m_radius;
  *(float *)&v8 = (float)((float)((float)(this->m_matrix.k.x * m_radius) + (float)(this->m_matrix.j.x * m_radius))
                        + (float)(this->m_matrix.i.x * m_radius))
                + this->m_matrix.c.x;
  *((float *)&v8 + 1) = (float)((float)((float)(this->m_matrix.k.y * m_radius) + (float)(this->m_matrix.j.y * m_radius))
                              + (float)(this->m_matrix.i.y * m_radius))
                      + this->m_matrix.c.y;
  v3 = result;
  v4 = (float)((float)((float)(this->m_matrix.k.z * m_radius) + (float)(this->m_matrix.j.z * m_radius))
             + (float)(this->m_matrix.i.z * m_radius))
     + this->m_matrix.c.z;
  v5 = -m_radius;
  *(float *)&v7 = (float)((float)((float)(this->m_matrix.k.x * v5) + (float)(this->m_matrix.j.x * v5))
                        + (float)(this->m_matrix.i.x * v5))
                + this->m_matrix.c.x;
  *((float *)&v7 + 1) = (float)((float)((float)(this->m_matrix.k.y * v5) + (float)(this->m_matrix.j.y * v5))
                              + (float)(this->m_matrix.i.y * v5))
                      + this->m_matrix.c.y;
  v6 = (float)((float)((float)(this->m_matrix.k.z * v5) + (float)(this->m_matrix.j.z * v5))
             + (float)(this->m_matrix.i.z * v5))
     + this->m_matrix.c.z;
  *(_QWORD *)&result->min.x = v7;
  *(_QWORD *)&result->max.x = v8;
  result->min.z = v6;
  result->max.z = v4;
  return v3;
}
