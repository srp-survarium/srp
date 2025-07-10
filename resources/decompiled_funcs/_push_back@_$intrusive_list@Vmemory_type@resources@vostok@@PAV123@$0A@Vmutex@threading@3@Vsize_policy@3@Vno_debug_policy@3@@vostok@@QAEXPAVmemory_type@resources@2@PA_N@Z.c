void __userpurge vostok::intrusive_list<vostok::resources::memory_type,vostok::resources::memory_type *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::resources::unmanaged_resource_buffer,vostok::resources::unmanaged_resource_buffer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>,
        vostok::resources::unmanaged_resource_buffer *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex *v4; // edi

  object->m_next_to_deallocate = 0;
  if ( a2 )
    v4 = (vostok::threading::mutex *)(a2 + 8);
  else
    v4 = 0;
  vostok::threading::mutex::lock(v4);
  ++*(_DWORD *)a2;
  if ( *(_DWORD *)(a2 + 36) )
    **(_DWORD **)(a2 + 40) = object;
  else
    *(_DWORD *)(a2 + 36) = object;
  *(_DWORD *)(a2 + 40) = object;
  LeaveCriticalSection((LPCRITICAL_SECTION)v4);
}
