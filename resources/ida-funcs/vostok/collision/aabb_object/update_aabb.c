vostok::math::aabb *__thiscall vostok::collision::aabb_object::update_aabb(
        vostok::collision::aabb_object *this,
        vostok::math::aabb *result,
        vostok::math::aabb *local_to_world)
{
  vostok::math::aabb *p_m_aabb; // edi
  vostok::math::aabb *v4; // eax
  vostok::math::aabb *v5; // esi
  vostok::math::aabb *v6; // eax

  p_m_aabb = &this->m_aabb;
  v4 = vostok::math::aabb::modify(local_to_world, &this->m_aabb);
  qmemcpy(p_m_aabb, v4, sizeof(vostok::math::aabb));
  v5 = v4;
  v6 = result;
  qmemcpy(result, v5, sizeof(vostok::math::aabb));
  return v6;
}
