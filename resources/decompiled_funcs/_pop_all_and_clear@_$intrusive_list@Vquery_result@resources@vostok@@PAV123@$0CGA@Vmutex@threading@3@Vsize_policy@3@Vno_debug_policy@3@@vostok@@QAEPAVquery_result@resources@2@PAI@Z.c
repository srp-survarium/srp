vostok::resources::query_result *__userpurge vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear@<eax>(
        vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>,
        unsigned int *out_size)
{
  vostok::resources::query_result *result; // [esp+Ch] [ebp-4h]

  if ( *(_DWORD *)(a2 + 36) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 8));
    result = *(vostok::resources::query_result **)(a2 + 36);
    *(_DWORD *)(a2 + 36) = 0;
    *(_DWORD *)(a2 + 40) = 0;
    if ( out_size )
      *out_size = *(_DWORD *)a2;
    *(_DWORD *)a2 = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
    return result;
  }
  else
  {
    if ( out_size )
      *out_size = 0;
    return 0;
  }
}
