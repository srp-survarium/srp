void __userpurge vostok::resources::queries_result::end_and_delete_self(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<edi>,
        bool finalizing_thread)
{
  DWORD CurrentThreadId; // eax
  vostok::resources::resources_manager *v4; // ecx
  unsigned int *p_disable_translate_query_counter_check; // esi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v6; // ecx
  vostok::resources::queries_result *v7; // ecx

  if ( !finalizing_thread )
  {
    if ( *(_BYTE *)(a2 + 72) )
      vostok::resources::queries_result::mark_inconsistent_qualities_as_failed(this, (_DWORD *)a2);
    if ( !*(_DWORD *)(a2 + 68) )
    {
      CurrentThreadId = GetCurrentThreadId();
      p_disable_translate_query_counter_check = &vostok::resources::resources_manager::get_thread_local_data(
                                                   v4,
                                                   (unsigned int)&s_resources_manager_buffer,
                                                   CurrentThreadId,
                                                   1)->disable_translate_query_counter_check;
      ++*p_disable_translate_query_counter_check;
      boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
        v6,
        (_DWORD *)a2,
        (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)a2);
      --*p_disable_translate_query_counter_check;
      vostok::resources::queries_result::push_to_grm_cache(v7, a2);
    }
  }
  vostok::resources::queries_result::`scalar deleting destructor'(this, a2);
  (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 40) + 24))(
    *(_DWORD *)(a2 + 40),
    a2,
    "vostok::resources::queries_result::end_and_delete_self",
    ".\\resources_queries_result.cpp",
    285);
}
