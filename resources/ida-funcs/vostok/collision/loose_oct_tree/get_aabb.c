vostok::math::aabb *__thiscall vostok::collision::loose_oct_tree::get_aabb(
        vostok::collision::loose_oct_tree *this,
        vostok::math::aabb *result)
{
  vostok::math::float3 v3; // [esp+0h] [ebp-Ch] BYREF

  v3.x = this->m_aabb_extents;
  v3.y = v3.x;
  v3.z = v3.x;
  vostok::math::create_aabb_center_radius(&v3, &this->m_aabb_center, result);
  return result;
}
