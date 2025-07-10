void __usercall survarium::lobby_client::clear_profile_info(survarium::lobby_client *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  vostok::sound::sound_world *f; // ecx
  int v4; // eax
  vostok::sound::sound_world *v5; // ecx
  void *v6; // eax
  void *m_start_time_high; // esi
  vostok::sound::sound_world *v8; // ecx
  void *v9; // eax
  void *v10; // esi
  vostok::sound::sound_world *v11; // ecx
  void *v12; // eax
  void *v13; // esi
  vostok::sound::sound_world *v14; // [esp-4h] [ebp-18h]
  vostok::sound::sound_world *v15; // [esp-4h] [ebp-18h]
  __int64 v16; // [esp+8h] [ebp-Ch]
  int v17; // [esp+10h] [ebp-4h]

  *(_BYTE *)(a2 + 604) = 0;
  v2 = *(_DWORD *)(a2 + 1928);
  if ( v2 != *(_DWORD *)(a2 + 1932) )
    *(_DWORD *)(a2 + 1932) = v2;
  f = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
  v16 = 0;
  LOBYTE(v17) = 0;
  v4 = v17;
  *(_QWORD *)(a2 + 2088) = 0;
  *(_DWORD *)(a2 + 2096) = v4;
  v5 = boost::get_pointer<vostok::sound::sound_scene>(f);
  v6 = *(void **)(a2 + 1944);
  if ( v6 )
  {
    m_start_time_high = (void *)HIDWORD(v5->m_timer.m_start_time);
    BYTE2(v5->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, v6);
    *(_DWORD *)(a2 + 1944) = 0;
  }
  v14 = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
  *(_BYTE *)(a2 + 1948) = 0;
  v8 = boost::get_pointer<vostok::sound::sound_scene>(v14);
  v9 = *(void **)(a2 + 1952);
  if ( v9 )
  {
    v10 = (void *)HIDWORD(v8->m_timer.m_start_time);
    BYTE2(v8->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(v10, v9);
    *(_DWORD *)(a2 + 1952) = 0;
  }
  v15 = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
  *(_BYTE *)(a2 + 1956) = 0;
  v11 = boost::get_pointer<vostok::sound::sound_scene>(v15);
  v12 = *(void **)(a2 + 2116);
  if ( v12 )
  {
    v13 = (void *)HIDWORD(v11->m_timer.m_start_time);
    BYTE2(v11->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(v13, v12);
    *(_DWORD *)(a2 + 2116) = 0;
  }
  *(_BYTE *)(a2 + 2120) = 0;
}
