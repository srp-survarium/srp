vostok::math::aabb *__thiscall survarium::human_npc::get_aabb(survarium::human_npc *this, vostok::math::aabb *result)
{
  vostok::math::aabb *v3; // [esp+0h] [ebp-4h]

  vostok::collision::animated_object::get_aabb((vostok::collision::animated_object *)this, v3);
  return result;
}
