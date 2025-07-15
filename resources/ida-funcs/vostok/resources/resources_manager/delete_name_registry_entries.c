void __usercall vostok::resources::resources_manager::delete_name_registry_entries(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  int *v3; // edi
  int v4; // ebp
  int v5; // eax
  int v6; // edi
  const char *v7; // [esp+0h] [ebp-14h]
  const char *v8; // [esp+4h] [ebp-10h]
  unsigned int v9; // [esp+8h] [ebp-Ch]

  v3 = (int *)((char *)&dword_201AC + a2);
  v4 = 0;
  if ( *(int *)((char *)&dword_201AC + a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, (_RTL_CRITICAL_SECTION *)((char *)nullsub_29 + a2));
    v4 = *v3;
    *v3 = 0;
    *(int *)((char *)dword_201B0 + a2) = 0;
    *(_DWORD *)((char *)&loc_20185 + a2 + 3) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)nullsub_29 + a2));
  }
  v5 = v4;
  if ( v4 )
  {
    do
    {
      v6 = *(_DWORD *)(v5 + 16);
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)this,
        (int)&vostok::memory::g_resources_helper_allocator,
        (char *)v5,
        v7,
        v8,
        v9);
      v5 = v6;
    }
    while ( v6 );
  }
}
