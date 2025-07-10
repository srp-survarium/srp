void __cdecl vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
        vostok::memory::doug_lea_allocator *allocator,
        vostok::memory::writer **pointer)
{
  void *v2; // esi
  void *v3; // eax
  void *m_arena; // esi

  if ( *pointer )
  {
    v2 = __RTCastToVoid(*pointer);
    ((void (__thiscall *)(_DWORD, _DWORD))(*pointer)->~vostok::memory::writer)(*pointer, 0);
    if ( v2 )
    {
      v3 = v2;
      m_arena = allocator->m_arena;
      allocator->m_out_of_memory = 0;
      vostok_mspace_free(m_arena, v3);
    }
    *pointer = 0;
  }
}
