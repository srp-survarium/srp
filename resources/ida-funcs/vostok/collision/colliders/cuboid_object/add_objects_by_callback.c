void __thiscall vostok::collision::colliders::cuboid_object::add_objects_by_callback(
        vostok::collision::colliders::cuboid_object *this,
        const vostok::collision::oct_node *const node)
{
  const vostok::collision::oct_node *v2; // ebx
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *i; // esi
  unsigned int m_max_count; // ecx

  v2 = node;
  do
  {
    if ( v2->octants[0] )
      vostok::collision::colliders::cuboid_object::add_objects_by_callback(this, v2->octants[0]);
    v2 = (const vostok::collision::oct_node *)((char *)v2 + 4);
  }
  while ( v2 != (const vostok::collision::oct_node *)&node->parent );
  for ( i = (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)node->objects;
        i;
        i = (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)i->m_on_out_of_memory.functor.vostok_pointer_size_alignment[5] )
  {
    m_max_count = i->m_max_count;
    if ( (m_max_count & this->m_query_type) != 0 )
      boost::function1<void,vostok::collision::object const &>::operator()(
        (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)m_max_count,
        &this->m_callback->vtable,
        i);
  }
}
