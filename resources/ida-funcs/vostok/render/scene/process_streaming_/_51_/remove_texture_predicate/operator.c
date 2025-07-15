bool __fastcall vostok::render::scene::process_streaming_::_51_::remove_texture_predicate::operator()(
        vostok::render::scene::process_streaming::__l51::remove_texture_predicate *this,
        const vostok::render::streamable_texture_info *info)
{
  vostok::render::res_texture *m_object; // eax
  vostok::render::streaming_texture_instance *instances; // edx
  vostok::memory::single_size_fixed_allocator<36,16384,vostok::threading::single_threading_policy> *allocator; // ecx
  bool result; // al
  vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node *v6; // esi

  m_object = info->texture.m_object;
  if ( !m_object->m_loaded || m_object->m_reference_count != 1 && info->instances )
    return 0;
  instances = info->instances;
  allocator = this->allocator;
  for ( result = 1; instances; --allocator->m_allocated_count )
  {
    v6 = (vostok::memory::single_size_buffer_allocator<36,vostok::threading::single_threading_policy>::node *)instances;
    instances = instances->next;
    v6->next = allocator->m_free_list_head.pointer;
    allocator->m_free_list_head.pointer = v6;
  }
  return result;
}
