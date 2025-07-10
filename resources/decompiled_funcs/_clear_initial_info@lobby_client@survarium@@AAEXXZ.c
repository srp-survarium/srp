void __usercall survarium::lobby_client::clear_initial_info(survarium::lobby_client *this@<ecx>, int a2@<edi>)
{
  vostok::sound::sound_world *v2; // ecx
  void *v3; // eax
  void *m_start_time_high; // esi
  vostok::sound::sound_world *v5; // ecx
  void *v6; // eax
  void *v7; // esi

  v2 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v3 = *(void **)(a2 + 2124);
  if ( v3 )
  {
    m_start_time_high = (void *)HIDWORD(v2->m_timer.m_start_time);
    BYTE2(v2->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, v3);
    *(_DWORD *)(a2 + 2124) = 0;
  }
  v5 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v6 = *(void **)(a2 + 2132);
  if ( v6 )
  {
    v7 = (void *)HIDWORD(v5->m_timer.m_start_time);
    BYTE2(v5->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(v7, v6);
    *(_DWORD *)(a2 + 2132) = 0;
  }
}
