void __usercall vostok::resources::resources_manager::decompress_resources(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<esi>)
{
  unsigned int v2; // ebx
  vostok::resources::resources_manager *v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // ebx

  if ( *(_DWORD *)((char *)&loc_204A4 + (_DWORD)a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)a2 + (_DWORD)&loc_20486 + 2));
    v2 = *(_DWORD *)((char *)&loc_204A4 + (_DWORD)a2);
    *(_DWORD *)((char *)&loc_204A4 + (_DWORD)a2) = 0;
    *(_DWORD *)((char *)&loc_204A8 + (_DWORD)a2) = 0;
    *(volatile int *)((char *)&a2->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_2047F + 1) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)a2 + (_DWORD)&loc_20486 + 2));
    v4 = v2;
    if ( v2 )
    {
      do
      {
        v5 = *(_DWORD *)(v4 + 608);
        vostok::resources::resources_manager::decompress_resource(v3, a2, v4);
        v4 = v5;
        SetEvent(*(HANDLE *)((char *)&dword_203D0 + (_DWORD)a2));
      }
      while ( v5 );
    }
  }
}
