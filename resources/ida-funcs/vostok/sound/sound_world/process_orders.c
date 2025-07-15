void __usercall vostok::sound::sound_world::process_orders(vostok::sound::sound_world *this@<ecx>, int a2@<eax>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  vostok::sound::sound_response **v6; // ebx
  vostok::sound::sound_response *v7; // esi
  vostok::sound::sound_response *m_next; // eax
  __int32 v9; // eax
  int v10; // ecx
  const char *v11; // [esp+0h] [ebp-10h]
  const char *v12; // [esp+4h] [ebp-Ch]
  unsigned int v13; // [esp+8h] [ebp-8h]
  vostok::sound::sound_order *pointer; // [esp+Ch] [ebp-4h] BYREF

  while ( 1 )
  {
    v3 = *(_DWORD *)(a2 + 96);
    if ( !*(_DWORD *)(v3 + 8) )
      break;
    v4 = *(_DWORD *)(v3 + 8);
    if ( v4 )
    {
      pointer = *(vostok::sound::sound_order **)(a2 + 96);
      *(_DWORD *)(a2 + 96) = v4;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    vostok::memory::delete_helper<vostok::memory::pthreads3_allocator,vostok::sound::sound_order>(
      &vostok::memory::g_mt_allocator,
      &pointer,
      v11,
      v12,
      v13);
  }
  v5 = *(_DWORD *)(a2 + 176);
  v6 = (vostok::sound::sound_response **)(v5 + 132);
  while ( 1 )
  {
    v7 = *v6;
    m_next = (*v6)->m_next;
    if ( !m_next )
      break;
    *v6 = m_next;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,8>>::delete_value(v7);
  }
  while ( 1 )
  {
    v9 = *(_DWORD *)(v5 + 200);
    v10 = *(_DWORD *)(v9 + 8);
    if ( !v10 )
      break;
    *(_DWORD *)(v5 + 200) = v10;
    *(_DWORD *)(v9 + 8) = 0;
    _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(v5 + 204) + 8), v9);
    *(_DWORD *)(v5 + 204) = v9;
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(v10);
  }
}
