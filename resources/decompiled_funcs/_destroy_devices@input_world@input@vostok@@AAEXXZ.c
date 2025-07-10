void __usercall vostok::input::input_world::destroy_devices(vostok::input::input_world *this@<ecx>, int a2@<eax>)
{
  vostok::memory::doug_lea_allocator *v2; // ebp
  void **v4; // eax
  char *v5; // esi
  char *v6; // eax
  malloc_state *m_arena; // esi
  vostok::memory::doug_lea_allocator *v8; // ebp
  char *v9; // esi
  char *v10; // eax
  malloc_state *v11; // esi
  vostok::memory::doug_lea_allocator *v12; // ebp
  char *v13; // esi
  char *v14; // eax
  malloc_state *v15; // esi

  v2 = vostok::input::g_allocator;
  v4 = *(void ***)(a2 + 32);
  if ( v4 )
  {
    v5 = __RTCastToVoid(v4);
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 32) + 4))(*(_DWORD *)(a2 + 32), 0);
    if ( v5 )
    {
      v6 = v5;
      m_arena = (malloc_state *)v2->m_arena;
      v2->m_out_of_memory = 0;
      vostok_mspace_free(m_arena, v6);
    }
    *(_DWORD *)(a2 + 32) = 0;
  }
  v8 = vostok::input::g_allocator;
  if ( *(_DWORD *)(a2 + 28) )
  {
    v9 = __RTCastToVoid(*(void ***)(a2 + 28));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 28) + 12))(*(_DWORD *)(a2 + 28), 0);
    if ( v9 )
    {
      v10 = v9;
      v11 = (malloc_state *)v8->m_arena;
      v8->m_out_of_memory = 0;
      vostok_mspace_free(v11, v10);
    }
    *(_DWORD *)(a2 + 28) = 0;
  }
  v12 = vostok::input::g_allocator;
  if ( *(_DWORD *)(a2 + 24) )
  {
    v13 = __RTCastToVoid(*(void ***)(a2 + 24));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 24) + 12))(*(_DWORD *)(a2 + 24), 0);
    if ( v13 )
    {
      v14 = v13;
      v15 = (malloc_state *)v12->m_arena;
      v12->m_out_of_memory = 0;
      vostok_mspace_free(v15, v14);
    }
    *(_DWORD *)(a2 + 24) = 0;
  }
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 20) + 8))(*(_DWORD *)(a2 + 20));
}
