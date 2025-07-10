void __userpurge vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::resource_base *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  v4 = 0;
  object->m_next_for_query_finished_callback = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 180) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}
