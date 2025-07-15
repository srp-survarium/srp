bool __thiscall vostok::collision::loose_oct_tree::aabb_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        const vostok::math::aabb *query_aabb,
        vostok::vectora<vostok::collision::object const *> *objects)
{
  char v5; // [esp+4h] [ebp-14h]

  if ( !this->m_initialized )
    return 0;
  vostok::collision::colliders::aabb_object::process((vostok::collision::colliders::aabb_object *)this);
  return v5;
}


bool __thiscall vostok::collision::loose_oct_tree::aabb_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        const vostok::math::aabb *query_aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  char v5; // [esp+4h] [ebp-14h]

  if ( !this->m_initialized )
    return 0;
  vostok::collision::colliders::aabb_object::process((vostok::collision::colliders::aabb_object *)this);
  return v5;
}
