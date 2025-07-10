survarium::object_weapon *__usercall vostok::intrusive_list<vostok::render::frame_histogram_info,vostok::render::frame_histogram_info *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front@<eax>(
        vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edi
  int v3; // eax

  if ( !*(_DWORD *)(a2 + 36) )
    return 0;
  vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 8));
  if ( !*(_DWORD *)(a2 + 36) )
  {
    LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
    return 0;
  }
  v2 = *(_DWORD *)(a2 + 36);
  --*(_DWORD *)a2;
  v3 = *(_DWORD *)(v2 + 12);
  *(_DWORD *)(a2 + 36) = v3;
  if ( !v3 )
    *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 8));
  return (survarium::object_weapon *)v2;
}
