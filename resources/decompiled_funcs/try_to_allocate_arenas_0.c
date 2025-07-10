bool __cdecl try_to_allocate_arenas_0(
        vostok::buffer_vector<vostok::memory::platform::region> *arenas,
        vostok::memory::platform::region *managed_arena,
        vostok::memory::platform::region *unmanaged_arena,
        vostok::memory::platform::region *only_resources)
{
  void *v4; // esp
  vostok::memory::platform::region *v5; // edi
  bool result; // al
  vostok::memory::platform::region v7[2]; // [esp-20h] [ebp-58h] BYREF
  _BYTE v8[12]; // [esp+0h] [ebp-38h] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::buffer_vector<vostok::memory::platform::region> resource_arenas; // [esp+30h] [ebp-8h] BYREF

  v4 = alloca(32);
  v5 = v7;
  resource_arenas.m_begin = v7;
  resource_arenas.m_end = v7;
  if ( vostok::memory::g_use_resources_manager )
  {
    if ( v7 )
      v7[0] = *managed_arena;
    if ( v7 != (vostok::memory::platform::region *)-16 )
      v7[1] = *unmanaged_arena;
    v5 = (vostok::memory::platform::region *)v8;
    resource_arenas.m_end = (vostok::memory::platform::region *)v8;
  }
  if ( !(_BYTE)only_resources && try_to_allocate_arenas_as_a_single_block(arenas, &resource_arenas)
    || (GetSystemInfo(&SystemInfo),
        result = allocate_arenas(
                   (vostok::memory::platform::region *)arenas,
                   &resource_arenas,
                   (char *)SystemInfo.dwAllocationGranularity,
                   only_resources)) )
  {
    if ( vostok::memory::g_use_resources_manager )
    {
      if ( v7[0].data == managed_arena )
      {
        *managed_arena = v7[0];
        *unmanaged_arena = v5[-1];
        return 1;
      }
      *managed_arena = v5[-1];
      *unmanaged_arena = v7[0];
    }
    return 1;
  }
  return result;
}
