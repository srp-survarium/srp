vostok::math::aabb *__thiscall vostok::render::render_collision_object<vostok::render::render_model_instance_impl>::update_aabb(
        vostok::render::render_collision_object<vostok::render::render_model_instance_impl> *this,
        vostok::math::aabb *result,
        vostok::math::aabb *local_to_world)
{
  const vostok::math::float4x4 *v4; // [esp+0h] [ebp-18h] BYREF

  this->m_owner->get_aabb(this->m_owner, (vostok::math::aabb *)&v4);
  *result = *vostok::math::aabb::modify(local_to_world, v4);
  return result;
}
