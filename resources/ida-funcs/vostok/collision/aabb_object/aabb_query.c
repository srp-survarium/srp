char __thiscall vostok::collision::aabb_object::aabb_query(
        vostok::collision::aabb_object *this,
        const vostok::math::aabb *aabb,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_result value; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_aabb.max.x < aabb->min.x
    || this->m_aabb.max.y < aabb->min.y
    || this->m_aabb.max.z < aabb->min.z
    || aabb->max.x < this->m_aabb.min.x
    || aabb->max.y < this->m_aabb.min.y
    || aabb->max.z < this->m_aabb.min.z )
  {
    return 0;
  }
  value.triangle_id = -1;
  value.object = this;
  vostok::buffer_vector<vostok::collision::triangle_result>::push_back(triangles, &value);
  return 1;
}
