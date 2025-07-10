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
