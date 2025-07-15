bool __thiscall vostok::collision::loose_oct_tree::aabb_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        const vostok::math::aabb *query_aabb,
        vostok::buffer_vector<vostok::collision::object const *> *objects)
{
  vostok::collision::colliders::aabb_object v5; // [esp+8h] [ebp-18h] BYREF

  if ( !this->m_initialized )
    return 0;
  v5.m_triangles = 0;
  v5.m_aabb = query_aabb;
  v5.m_objects = objects;
  v5.m_tree = this;
  v5.m_query_type = query_mask;
  vostok::collision::colliders::aabb_object::process((vostok::collision::colliders::aabb_object *)this, &v5);
  return v5.m_result;
}


bool __thiscall vostok::collision::loose_oct_tree::aabb_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        const vostok::math::aabb *query_aabb,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::colliders::aabb_object v5; // [esp+8h] [ebp-18h] BYREF

  if ( !this->m_initialized )
    return 0;
  v5.m_objects = 0;
  v5.m_aabb = query_aabb;
  v5.m_triangles = triangles;
  v5.m_tree = this;
  v5.m_query_type = query_mask;
  vostok::collision::colliders::aabb_object::process((vostok::collision::colliders::aabb_object *)this, &v5);
  return v5.m_result;
}
