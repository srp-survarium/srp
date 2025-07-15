bool __thiscall vostok::collision::loose_oct_tree::cuboid_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        const vostok::math::cuboid *cuboid,
        vostok::buffer_vector<vostok::collision::object const *> *objects)
{
  vostok::collision::colliders::cuboid_object v5; // [esp+0h] [ebp-1Ch] BYREF

  if ( !this->m_initialized )
    return 0;
  v5.m_tree = this;
  v5.m_cuboid = cuboid;
  v5.m_triangles = 0;
  v5.m_callback = 0;
  v5.m_objects = objects;
  v5.m_query_type = query_mask;
  vostok::collision::colliders::cuboid_object::process((vostok::collision::colliders::cuboid_object *)objects, &v5);
  return v5.m_result;
}


bool __thiscall vostok::collision::loose_oct_tree::cuboid_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        const vostok::math::cuboid *cuboid,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::colliders::cuboid_object v5; // [esp+0h] [ebp-1Ch] BYREF

  if ( !this->m_initialized )
    return 0;
  v5.m_tree = this;
  v5.m_cuboid = cuboid;
  v5.m_objects = 0;
  v5.m_callback = 0;
  v5.m_triangles = triangles;
  v5.m_query_type = query_mask;
  vostok::collision::colliders::cuboid_object::process((vostok::collision::colliders::cuboid_object *)triangles, &v5);
  return v5.m_result;
}


bool __thiscall vostok::collision::loose_oct_tree::cuboid_query(
        vostok::collision::loose_oct_tree *this,
        unsigned int query_mask,
        vostok::collision::colliders::cuboid_object *cuboid,
        boost::function<void __cdecl(vostok::collision::object const &)> *callback)
{
  vostok::collision::colliders::cuboid_object v5; // [esp+0h] [ebp-1Ch] BYREF

  if ( !this->m_initialized )
    return 0;
  v5.m_objects = 0;
  v5.m_triangles = 0;
  v5.m_tree = this;
  v5.m_callback = callback;
  v5.m_cuboid = (const vostok::math::cuboid *)cuboid;
  v5.m_query_type = query_mask;
  vostok::collision::colliders::cuboid_object::process(cuboid, &v5);
  return v5.m_result;
}
