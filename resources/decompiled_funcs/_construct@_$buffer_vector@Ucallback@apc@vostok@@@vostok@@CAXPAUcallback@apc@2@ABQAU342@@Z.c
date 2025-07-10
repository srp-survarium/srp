void __cdecl vostok::buffer_vector<vostok::apc::callback>::construct(
        vostok::apc::callback *begin,
        vostok::apc::callback **end)
{
  vostok::apc::callback *v2; // ebx
  vostok::apc::callback *v3; // edi
  vostok::apc::callback *i; // esi

  v2 = begin;
  if ( begin != *end )
  {
    v3 = begin + 1;
    do
    {
      for ( i = v2; i != v3; ++i )
      {
        if ( i )
        {
          i->m_callback.vtable = 0;
          i->m_pending = 0;
          i->m_break_parameters = break_process_loop;
          i->m_thread_id = GetCurrentThreadId();
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 != *end );
  }
}
