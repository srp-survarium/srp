vostok::math::aabb *__thiscall vostok::physics::bullet_physics_world::get_world_aabb(
        vostok::physics::bullet_physics_world *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax

  v2 = result;
  qmemcpy(result, &this->m_world_aabb, sizeof(vostok::math::aabb));
  return v2;
}
