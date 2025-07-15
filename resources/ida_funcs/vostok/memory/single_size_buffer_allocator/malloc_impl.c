vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<8,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}


vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}


void *__thiscall vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *this,
        unsigned int size)
{
  _BYTE *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v2 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(size == 128));
  return vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::allocate(this);
}


vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<136,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}


vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::malloc_impl(
        vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy> *this,
        unsigned int size)
{
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}
