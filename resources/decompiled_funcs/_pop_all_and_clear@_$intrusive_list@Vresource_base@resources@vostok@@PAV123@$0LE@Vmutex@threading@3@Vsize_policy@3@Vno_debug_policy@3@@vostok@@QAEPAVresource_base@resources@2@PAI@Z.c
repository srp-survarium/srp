vostok::resources::resource_base *__usercall vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear@<eax>(
        vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>)
{
  int v3; // ebx

  if ( !*(_DWORD *)(a2 + 36) )
    return 0;
  vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 8));
  v3 = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)a2 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
  return (vostok::resources::resource_base *)v3;
}
