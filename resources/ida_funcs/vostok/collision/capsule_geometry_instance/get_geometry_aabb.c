vostok::math::aabb *__thiscall vostok::collision::capsule_geometry_instance::get_geometry_aabb(
        vostok::collision::capsule_geometry_instance *this,
        vostok::math::aabb *result)
{
  float m_radius; // xmm0_4
  vostok::math::aabb *v3; // eax
  __int64 v4; // [esp+0h] [ebp-18h]
  __int64 v5; // [esp+Ch] [ebp-Ch]

  m_radius = this->m_radius;
  v3 = result;
  *((float *)&v5 + 1) = this->m_half_length + m_radius;
  *(float *)&v5 = m_radius;
  *(float *)&v4 = -m_radius;
  *((float *)&v4 + 1) = (float)-this->m_half_length - m_radius;
  *(_QWORD *)&result->min.x = v4;
  *(_QWORD *)&result->max.x = v5;
  result->min.z = -m_radius;
  result->max.z = m_radius;
  return v3;
}
