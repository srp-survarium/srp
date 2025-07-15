void __userpurge vostok::collision::colliders::aabb_object::add_objects(
        vostok::collision::colliders::aabb_object *this@<ecx>,
        vostok::buffer_vector<vostok::collision::object const *> node)
{
  const vostok::collision::object **m_begin; // esi
  const vostok::collision::object **v3; // edi
  const vostok::collision::object **v4; // ebx
  vostok::collision::object *i; // edi
  vostok::buffer_vector<vostok::collision::object const *> *m_objects; // esi
  vostok::buffer_vector<vostok::collision::object const *> v7; // [esp-4h] [ebp-18h]

  m_begin = node.m_begin;
  v3 = node.m_begin + 8;
  v4 = node.m_begin;
  do
  {
    if ( *v4 )
    {
      v7.m_begin = (const vostok::collision::object **)*v4;
      vostok::collision::colliders::aabb_object::add_objects(this, v7);
    }
    ++v4;
  }
  while ( v4 != v3 );
  for ( i = (vostok::collision::object *)m_begin[9]; i; i = i->m_next )
  {
    if ( (i->m_type & this->m_query_type) != 0 )
    {
      m_objects = this->m_objects;
      node.m_begin = (const vostok::collision::object **)i;
      vostok::buffer_vector<vostok::collision::object const *>::push_back(
        &node,
        (int)m_objects,
        (const vostok::collision::object **)&node);
    }
  }
}
