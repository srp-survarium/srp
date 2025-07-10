void __userpurge vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::resource_link *object,
        bool *out_pushed_first)
{
  vostok::threading::simple_lock *v4; // edi
  bool v5; // zf

  object->next_link = 0;
  if ( a2 )
    v4 = (vostok::threading::simple_lock *)(a2 + 1);
  else
    v4 = 0;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, v4);
  ++*a2;
  if ( a2[4] )
  {
    *(_DWORD *)(a2[5] + 4) = object;
    a2[5] = object;
    v5 = v4->m_lock-- == 1;
    if ( !v5 )
      return;
  }
  else
  {
    a2[4] = object;
    a2[5] = object;
    v5 = v4->m_lock-- == 1;
    if ( !v5 )
      return;
  }
  _InterlockedExchange(&v4->m_thread_id, 0);
}
