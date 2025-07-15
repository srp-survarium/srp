void __thiscall vostok::collision::colliders::cuboid_object::add_objects(
        vostok::collision::colliders::cuboid_object *this,
        const vostok::collision::object *node)
{
  const vostok::collision::oct_node *v2; // edi
  vostok::collision::oct_node **p_m_node; // ebx
  const vostok::collision::oct_node *v5; // esi
  const vostok::collision::oct_node *objects; // edi
  vostok::vectora<vostok::collision::object const *> *m_objects; // esi
  const void **M_finish; // eax
  const stlp_std::__true_type *v9; // [esp+0h] [ebp-10h]
  unsigned int v10; // [esp+4h] [ebp-Ch]
  bool v11; // [esp+8h] [ebp-8h]

  v2 = (const vostok::collision::oct_node *)node;
  p_m_node = &node->m_node;
  v5 = (const vostok::collision::oct_node *)node;
  do
  {
    if ( v5->octants[0] )
      vostok::collision::colliders::cuboid_object::add_objects(this, v5->octants[0]);
    v5 = (const vostok::collision::oct_node *)((char *)v5 + 4);
  }
  while ( v5 != (const vostok::collision::oct_node *)p_m_node );
  objects = (const vostok::collision::oct_node *)v2->objects;
  for ( node = (const vostok::collision::object *)objects; objects; node = (const vostok::collision::object *)objects )
  {
    if ( ((int)objects[1].octants[0] & this->m_query_type) != 0 )
    {
      m_objects = this->m_objects;
      M_finish = m_objects->_M_impl._M_finish;
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
        *M_finish = objects;
        ++m_objects->_M_impl._M_finish;
      }
    }
    objects = objects->octants[7];
  }
}
