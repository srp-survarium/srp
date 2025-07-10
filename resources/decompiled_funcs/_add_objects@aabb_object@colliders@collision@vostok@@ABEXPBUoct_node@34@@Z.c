void __thiscall vostok::collision::colliders::aabb_object::add_objects(
        vostok::collision::colliders::aabb_object *this,
        const vostok::collision::oct_node *node)
{
  const vostok::collision::oct_node *v2; // edi
  vostok::collision::oct_node **p_parent; // ebx
  const vostok::collision::oct_node *v5; // esi
  const vostok::collision::oct_node *i; // edi
  vostok::vectora<vostok::collision::object const *> *m_objects; // esi
  const void **M_finish; // eax
  const stlp_std::__true_type *v9; // [esp+0h] [ebp-10h]
  unsigned int v10; // [esp+4h] [ebp-Ch]
  bool v11; // [esp+8h] [ebp-8h]

  v2 = node;
  p_parent = &node->parent;
  v5 = node;
  do
  {
    if ( v5->octants[0] )
      vostok::collision::colliders::aabb_object::add_objects(this, v5->octants[0]);
    v5 = (const vostok::collision::oct_node *)((char *)v5 + 4);
  }
  while ( v5 != (const vostok::collision::oct_node *)p_parent );
  for ( i = (const vostok::collision::oct_node *)v2->objects; i; i = i->octants[7] )
  {
    if ( ((int)i[1].octants[0] & this->m_query_type) != 0 )
    {
      m_objects = this->m_objects;
      M_finish = m_objects->_M_impl._M_finish;
      node = i;
      if ( M_finish == m_objects->_M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&node,
          (unsigned __int8 **)m_objects,
          (int)M_finish,
          (const unsigned int *)&node,
          v9,
          v10,
          v11);
      }
      else
      {
        *M_finish = i;
        ++m_objects->_M_impl._M_finish;
      }
    }
  }
}
