void __thiscall vostok::resources::queries_result::push_to_grm_cache(vostok::resources::queries_result *this, int a2)
{
  unsigned int v2; // ebp
  int v3; // edi
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v4; // esi
  vostok::resources::base_of_intrusive_base *v5; // eax

  v2 = 0;
  if ( *(_DWORD *)(a2 + 56) )
  {
    v3 = a2 + 80;
    do
    {
      if ( !vostok::resources::query_result::is_fs_iterator_query((vostok::resources::query_result *)this, v3) )
      {
        v4 = *(vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> **)(v3 + 720);
        if ( v4 )
        {
          if ( vostok::resources::query_result_for_user::is_successful(
                 (vostok::resources::query_result_for_user *)this,
                 v3) )
          {
            if ( (s_resources_manager_buffer.m_query_finished_callback.vtable != 0
                ? (unsigned int)vostok::memory::process_allocator::finalize_impl
                : 0) != 0 )
              boost::function1<void,vostok::collision::object const &>::operator()(
                (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)this,
                &s_resources_manager_buffer.m_query_finished_callback.vtable,
                v4);
          }
          else
          {
            v5 = vostok::resources::resource_flags::cast_base_of_intrusive_base((vostok::resources::resource_flags *)v4);
            _InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF);
            this = (vostok::resources::queries_result *)-3;
            _InterlockedAnd(&v5->m_flags.m_flags, 0xFFFFFFFD);
          }
        }
      }
      ++v2;
      v3 += 736;
    }
    while ( v2 < *(_DWORD *)(a2 + 56) );
  }
}
