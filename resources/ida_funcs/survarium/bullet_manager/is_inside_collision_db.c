bool __thiscall survarium::bullet_manager::is_inside_collision_db(
        survarium::bullet_manager *this,
        const vostok::math::float3 *position)
{
  vostok::math::aabb *left; // [esp+8h] [ebp-1Ch]
  _BYTE v5[24]; // [esp+Ch] [ebp-18h] BYREF

  left = this->m_physics_world->get_world_aabb(this->m_physics_world, v5);
  return vostok::math::operator<=(&left->min, position) && vostok::math::operator>=(&left->max, position);
}
