void __thiscall vostok::fs_new::asynchronous_device_interface::get_synchronous_access(
        vostok::fs_new::asynchronous_device_interface *this,
        vostok::fs_new::asynchronous_device_query_vtbl *in_out_synchronous_interface,
        vostok::memory::base_allocator *allocator,
        vostok::memory::base_allocator *a5)
{
  vostok::fs_new::asynchronous_device_query *v6; // edi
  char *v7; // eax
  vostok::fs_new::device_file_system_interface *execute; // ecx
  vostok::threading::event_tasks_unaware *v9; // ecx
  vostok::threading::event_tasks_unaware *v10; // ecx
  DWORD CurrentThreadId; // [esp+10h] [ebp+8h]

  v6 = 0;
  if ( in_out_synchronous_interface[16].~vostok::fs_new::asynchronous_device_query == (void (__thiscall *)(vostok::fs_new::asynchronous_device_query *))1
    && in_out_synchronous_interface[15].~vostok::fs_new::asynchronous_device_query != (void (__thiscall *)(vostok::fs_new::asynchronous_device_query *))GetCurrentThreadId() )
  {
    v7 = type_info::raw_name(&vostok::fs_new::synchronize_device_query `RTTI Type Descriptor');
    v6 = (vostok::fs_new::asynchronous_device_query *)a5->call_malloc(
                                                        a5,
                                                        64,
                                                        v7,
                                                        "vostok::fs_new::asynchronous_device_interface::get_synchronous_access",
                                                        ".\\asynchronous_device_interface.cpp",
                                                        33);
    if ( v6 )
    {
      CurrentThreadId = GetCurrentThreadId();
      vostok::fs_new::asynchronous_device_query::asynchronous_device_query(v6, a5, 0);
      v6->__vftable = (vostok::fs_new::asynchronous_device_query_vtbl *)&vostok::fs_new::synchronize_device_query::`vftable';
      v6[1].__vftable = in_out_synchronous_interface;
      vostok::threading::event_tasks_unaware::event_tasks_unaware(v9, (HANDLE *)&v6[1].m_next_backward);
      vostok::threading::event_tasks_unaware::event_tasks_unaware(v10, (HANDLE *)&v6[1].m_allocator);
      *(_DWORD *)&v6[1].m_device_query_result = CurrentThreadId;
      vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query>::producer_push_to_process(
        (vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query> *)&in_out_synchronous_interface[7].execute,
        v6);
      SetEvent(in_out_synchronous_interface[15].execute);
    }
    else
    {
      LOBYTE(allocator->m_arena_end) = 1;
    }
  }
  execute = (vostok::fs_new::device_file_system_interface *)in_out_synchronous_interface[16].execute;
  allocator->__vftable = (vostok::memory::base_allocator_vtbl *)v6;
  allocator->m_arena_start = execute;
}
