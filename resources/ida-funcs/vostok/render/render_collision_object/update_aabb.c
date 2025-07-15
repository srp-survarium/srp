vostok::math::aabb *__thiscall vostok::render::render_collision_object<vostok::render::render_model_instance_impl>::update_aabb(
        vostok::render::render_collision_object<vostok::render::render_model_instance_impl> *this,
        vostok::math::aabb *result,
        vostok::math::aabb *local_to_world)
{
  vostok::math::aabb *v3; // eax
  vostok::math::aabb *v4; // esi
  vostok::math::aabb *v5; // eax
  _BYTE v6[24]; // [esp+8h] [ebp-18h] BYREF

  v3 = this->m_owner->get_aabb(this->m_owner, v6);
  v4 = vostok::math::aabb::modify(local_to_world, v3);
  v5 = result;
  qmemcpy(result, v4, sizeof(vostok::math::aabb));
  return v5;
}
