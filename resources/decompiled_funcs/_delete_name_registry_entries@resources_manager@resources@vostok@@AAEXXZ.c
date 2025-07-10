void __usercall vostok::resources::resources_manager::delete_name_registry_entries(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  int v4; // ebp
  int v5; // edi

  if ( *(_DWORD *)((char *)&loc_201A2 + a2 + 2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)&loc_20186 + a2 + 2));
    v4 = *(_DWORD *)((char *)&loc_201A2 + a2 + 2);
    *(_DWORD *)((char *)&loc_201A2 + a2 + 2) = 0;
    *(int *)((char *)&dword_201A8 + a2) = 0;
    *(_DWORD *)((char *)&loc_2017F + a2 + 1) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20186 + a2 + 2));
    v3 = v4;
  }
  else
  {
    v3 = 0;
  }
  if ( v3 )
  {
    do
    {
      v5 = *(_DWORD *)(v3 + 16);
      vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
      vostok_mspace_free((malloc_state *)vostok::memory::g_resources_helper_allocator.m_arena, (char *)v3);
      v3 = v5;
    }
    while ( v5 );
  }
}
