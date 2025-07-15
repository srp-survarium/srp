char __thiscall vostok::collision::loose_oct_tree::cuboid_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        vostok::collision::colliders::cuboid_object *cuboid,
        boost::function<void __cdecl(vostok::collision::object const &)> *callback)
{
  char v5; // [esp+18h] [ebp-4h]

  if ( !this->m_initialized )
    return 0;
  vostok::collision::colliders::cuboid_object::process(cuboid);
  return v5;
}


char __thiscall vostok::collision::loose_oct_tree::cuboid_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        vostok::collision::colliders::cuboid_object *cuboid,
        vostok::vectora<vostok::collision::object const *> *objects)
{
  char v5; // [esp+18h] [ebp-4h]

  if ( !this->m_initialized )
    return 0;
  vostok::collision::colliders::cuboid_object::process(cuboid);
  return v5;
}


char __thiscall vostok::collision::loose_oct_tree::cuboid_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        vostok::collision::colliders::cuboid_object *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  char v5; // [esp+18h] [ebp-4h]

  if ( !this->m_initialized )
    return 0;
  vostok::collision::colliders::cuboid_object::process(cuboid);
  return v5;
}
