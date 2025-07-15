vostok::math::aabb *__thiscall vostok::collision::loose_oct_tree::get_aabb(
        vostok::collision::loose_oct_tree *this,
        vostok::math::aabb *result)
{
  float m_aabb_extents; // xmm0_4
  vostok::math::aabb *v3; // eax
  float v4; // edx
  float v5; // xmm3_4
  float v6; // xmm1_4
  __int64 v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+8h] [ebp-4h]

  m_aabb_extents = this->m_aabb_extents;
  v3 = result;
  *(float *)&v7 = this->m_aabb_center.x - m_aabb_extents;
  *((float *)&v7 + 1) = this->m_aabb_center.y - m_aabb_extents;
  v8 = this->m_aabb_center.z - m_aabb_extents;
  v4 = v8;
  *(_QWORD *)&result->min.x = v7;
  result->min.z = v4;
  v5 = this->m_aabb_center.x + m_aabb_extents;
  *((float *)&v7 + 1) = this->m_aabb_center.y + m_aabb_extents;
  v6 = this->m_aabb_center.z + m_aabb_extents;
  *(float *)&v7 = v5;
  *(_QWORD *)&result->max.x = v7;
  result->max.z = v6;
  return v3;
}
