void __userpurge vostok::collision::colliders::cuboid_object::add_objects(
        vostok::collision::colliders::cuboid_object *this@<ecx>,
        vostok::buffer_vector<vostok::collision::object const *> node)
{
  const vostok::collision::object **m_begin; // esi
  const vostok::collision::object **v3; // edi
  const vostok::collision::object **v4; // ebx
  vostok::collision::object *i; // edi
  vostok::buffer_vector<vostok::collision::object const *> v6; // [esp-4h] [ebp-18h]

  m_begin = node.m_begin;
  v3 = node.m_begin + 8;
  v4 = node.m_begin;
  do
  {
    if ( *v4 )
    {
      v6.m_begin = (const vostok::collision::object **)*v4;
      vostok::collision::colliders::cuboid_object::add_objects(this, v6);
    }
    ++v4;
  }
  while ( v4 != v3 );
  for ( i = (vostok::collision::object *)m_begin[9]; ; i = i->m_next )
  {
    node.m_begin = (const vostok::collision::object **)i;
    if ( !i )
      break;
    if ( (i->m_type & this->m_query_type) != 0 )
      vostok::buffer_vector<vostok::collision::object const *>::push_back(
        &node,
        (int)this->m_objects,
        (const vostok::collision::object **)&node);
  }
}
