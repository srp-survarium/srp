void __thiscall survarium::player_serialized_state::clear(
        survarium::player_serialized_state *this,
        vostok::network_core::mutable_buffer *a2)
{
  vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v2; // ebx
  vostok::network_core::mutable_buffer *v3; // eax
  vostok::command_line::key *v4; // ecx

  v2 = (vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)a2;
  vostok::network_core::mutable_buffer::resize(a2 + 128, 0);
  while ( v2[129].m_first )
  {
    v3 = (vostok::network_core::mutable_buffer *)vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(v2 + 129);
    if ( v3 )
    {
      a2 = v3;
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&a2, v4);
      pt3free((int)v4, (char *)a2);
    }
  }
}
