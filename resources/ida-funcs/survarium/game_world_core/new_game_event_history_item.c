void __usercall survarium::game_world_core::new_game_event_history_item(
        survarium::game_world_core *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > *v4; // ecx
  vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<360,vostok::threading::single_threading_policy>::node>::free_list_type *v5; // edi
  vostok::memory::single_size_buffer_allocator<360,vostok::threading::single_threading_policy>::node *v6; // eax
  survarium::game_event_history_item *v7; // ecx

  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy> > **)(v3 + 36);
  if ( (unsigned int)v4 >= *(_DWORD *)(v3 + 40) )
    survarium::history<survarium::game_event_history_item,vostok::memory::single_size_fixed_allocator<360,27,vostok::threading::single_threading_policy>>::pop_front(
      v4,
      (_DWORD *)a2);
  v5 = *(vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<360,vostok::threading::single_threading_policy>::node>::free_list_type **)(a2 + 16);
  if ( v5[9].pointer >= v5[10].pointer
    && (v5->pointer != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v4,
      v5,
      *(const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> **)(a2 + 16));
  }
  v6 = vostok::memory::single_threading_single_size_allocator_policy<vostok::memory::single_size_buffer_allocator<360,vostok::threading::single_threading_policy>::node>::allocate(v5 + 8);
  ++v5[9].pointer;
  if ( v6 )
    survarium::game_event_history_item::game_event_history_item(v7, v6);
}
