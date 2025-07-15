vostok::math::aabb *__thiscall vostok::collision::box_geometry_instance::get_aabb(
        vostok::collision::box_geometry_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::float4x4 *p_m_matrix; // esi
  vostok::math::aabb *geometry_aabb; // eax
  vostok::math::aabb *v4; // esi
  vostok::math::aabb *v5; // eax
  vostok::math::aabb resulta; // [esp+8h] [ebp-18h] BYREF

  p_m_matrix = &this->m_matrix;
  geometry_aabb = vostok::collision::box_geometry_instance::get_geometry_aabb(
                    (vostok::collision::sphere_geometry_instance *)this,
                    &resulta);
  v4 = vostok::math::aabb::modify((vostok::math::aabb *)p_m_matrix, geometry_aabb);
  v5 = result;
  qmemcpy(result, v4, sizeof(vostok::math::aabb));
  return v5;
}
