void __usercall vostok::network_core::buffer_writer::~buffer_writer(
        vostok::network_core::buffer_writer *this@<ecx>,
        vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *a2@<esi>)
{
  vostok::network_core::buffer_writer::serialization_operation_descriptor *v2; // eax
  vostok::command_line::key *v3; // ecx
  char *v4; // [esp+4h] [ebp-4h] BYREF

  while ( a2->m_first )
  {
    v2 = vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(a2);
    if ( v2 )
    {
      v4 = (char *)v2;
      if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
        vostok::memory::monitor::on_free((void **)&v4, v3);
      pt3free((int)v3, v4);
    }
  }
}
