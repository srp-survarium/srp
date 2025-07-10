void __userpurge vostok::intrusive_list<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,16,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,16,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::resources::name_registry_entry *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->next_to_delete = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 2);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*a2;
  if ( a2[9] )
    *(_DWORD *)(a2[10] + 16) = object;
  else
    a2[9] = object;
  a2[10] = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}
