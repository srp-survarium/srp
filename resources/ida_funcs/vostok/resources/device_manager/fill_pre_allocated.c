void __usercall vostok::resources::device_manager::fill_pre_allocated(
        vostok::resources::device_manager *this@<ecx>,
        vostok::resources::device_manager *a2@<edi>)
{
  vostok::resources::device_manager *v2; // ecx
  vostok::resources::query_result *m_first; // eax
  vostok::resources::query_result *m_next_in_device_manager; // esi
  bool grabbed_something; // [esp+Fh] [ebp-11h]
  vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> queries; // [esp+10h] [ebp-10h] BYREF

  queries.m_size = 0;
  queries.m_first = 0;
  queries.m_last = 0;
  do
  {
    a2->grab_sorted_queries(a2, &queries);
    m_first = queries.m_first;
    grabbed_something = queries.m_first != 0;
    if ( queries.m_first )
    {
      do
      {
        m_next_in_device_manager = m_first->m_next_in_device_manager;
        vostok::resources::device_manager::pre_allocate(v2, a2, m_first);
        m_first = m_next_in_device_manager;
      }
      while ( m_next_in_device_manager );
      if ( queries.m_first )
      {
        queries.m_first = 0;
        queries.m_last = 0;
        queries.m_size = 0;
      }
    }
  }
  while ( grabbed_something );
}
