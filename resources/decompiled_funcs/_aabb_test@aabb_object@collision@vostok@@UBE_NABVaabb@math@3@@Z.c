BOOL __thiscall vostok::collision::aabb_object::aabb_test(
        vostok::collision::aabb_object *this,
        const vostok::math::aabb *aabb)
{
  return this->m_aabb.max.x >= aabb->min.x
      && this->m_aabb.max.y >= aabb->min.y
      && this->m_aabb.max.z >= aabb->min.z
      && aabb->max.x >= this->m_aabb.min.x
      && aabb->max.y >= this->m_aabb.min.y
      && aabb->max.z >= this->m_aabb.min.z;
}
