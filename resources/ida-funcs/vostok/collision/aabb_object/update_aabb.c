vostok::math::aabb *__thiscall vostok::collision::aabb_object::update_aabb(
        vostok::collision::aabb_object *this,
        vostok::math::aabb *result,
        vostok::math::aabb *local_to_world)
{
  vostok::math::aabb *p_m_aabb; // esi
  vostok::math::aabb *v4; // eax

  p_m_aabb = &this->m_aabb;
  v4 = vostok::math::aabb::modify(local_to_world, &this->m_aabb);
  *p_m_aabb = *v4;
  *result = *v4;
  return result;
}
