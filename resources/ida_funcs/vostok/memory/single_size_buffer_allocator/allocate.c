vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy> *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node *allocated_node; // [esp+1Ch] [ebp-4h]

  allocated_node = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  survarium::weapon_user_dead_state::finalize(v1);
  ++this->m_allocated_count;
  return allocated_node;
}


vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy> *this)
{
  vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<28,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}


vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> *this)
{
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node *result; // eax

  result = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>::node>::allocate(&this->m_free_list_head);
  _InterlockedExchangeAdd(&this->m_allocated_count, 1u);
  return result;
}


vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy> *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node *allocated_node; // [esp+1Ch] [ebp-4h]

  allocated_node = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<44,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  survarium::weapon_user_dead_state::finalize(v1);
  ++this->m_allocated_count;
  return allocated_node;
}


vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy> *this)
{
  vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}


vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *__thiscall vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::allocate(
        vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node *allocated_node; // [esp+24h] [ebp-4h]

  allocated_node = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>::node>::allocate(&this->m_free_list_head);
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::threading::interlocked_increment((vostok::resources::unmanaged_intrusive_base *)&this->m_allocated_count);
  return allocated_node;
}


vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *__thiscall vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::allocate(
        vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy> *this)
{
  vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node *result; // eax

  result = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<44200,vostok::threading::single_threading_policy>::node>::allocate(&this->m_free_list_head);
  ++this->m_allocated_count;
  return result;
}


vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *__thiscall vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::allocate(
        vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex> *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node *allocated_node; // [esp+24h] [ebp-4h]

  allocated_node = vostok::memory::multi_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::node>::allocate(&this->m_free_list_head);
  survarium::weapon_user_dead_state::finalize(v1);
  vostok::threading::interlocked_increment((vostok::resources::unmanaged_intrusive_base *)&this->m_allocated_count);
  return allocated_node;
}
