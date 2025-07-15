void __userpurge vostok::memory::managed_node_owner::set_is_unmovable(
        vostok::memory::managed_node_owner *this@<ecx>,
        int a2@<eax>,
        bool is_unmovable)
{
  volatile __int32 *v3; // edi
  _RTL_CRITICAL_SECTION *v4; // esi

  v3 = (volatile __int32 *)(*(_DWORD *)(a2 + 4) + 32);
  if ( (*v3 != 0) != is_unmovable )
  {
    v4 = (_RTL_CRITICAL_SECTION *)(*(_DWORD *)(a2 + 8) + 8368);
    if ( is_unmovable )
      vostok::threading::mutex::lock((vostok::threading::mutex *)(*(_DWORD *)(a2 + 8) + 8368));
    _InterlockedExchange(v3, is_unmovable);
    if ( is_unmovable )
      LeaveCriticalSection(v4);
  }
}
