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
