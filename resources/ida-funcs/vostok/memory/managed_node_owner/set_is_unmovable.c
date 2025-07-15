void __userpurge vostok::memory::managed_node_owner::set_is_unmovable(
        vostok::memory::managed_node_owner *this@<ecx>,
        int a2@<eax>,
        bool is_unmovable)
{
  volatile __int32 *v3; // edi
  vostok::threading::mutex *v4; // ecx
  _RTL_CRITICAL_SECTION *v5; // esi

  v3 = (volatile __int32 *)(*(_DWORD *)(a2 + 4) + 32);
  v4 = (vostok::threading::mutex *)*v3;
  LOBYTE(v4) = *v3 != 0;
  if ( (_BYTE)v4 != is_unmovable )
  {
    v5 = (_RTL_CRITICAL_SECTION *)(*(_DWORD *)(a2 + 8) + 8376);
    if ( is_unmovable )
      vostok::threading::mutex::lock(v4, (_RTL_CRITICAL_SECTION *)(*(_DWORD *)(a2 + 8) + 8376));
    _InterlockedExchange(v3, is_unmovable);
    if ( is_unmovable )
      LeaveCriticalSection(v5);
  }
}
