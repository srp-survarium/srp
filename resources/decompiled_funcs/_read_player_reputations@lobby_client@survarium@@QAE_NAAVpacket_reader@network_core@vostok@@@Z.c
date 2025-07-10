char __userpurge survarium::lobby_client::read_player_reputations@<al>(
        survarium::lobby_client *this@<ecx>,
        int a2@<edi>,
        vostok::network_core::packet_reader *reader)
{
  vostok::sound::sound_world *v3; // ecx
  void *v4; // eax
  void *m_start_time_high; // esi
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v7; // cl
  unsigned int v8; // esi
  vostok::memory::doug_lea_allocator *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // cl
  unsigned int v12; // esi

  v3 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v4 = *(void **)(a2 + 1952);
  if ( v4 )
  {
    m_start_time_high = (void *)HIDWORD(v3->m_timer.m_start_time);
    BYTE2(v3->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, v4);
    *(_DWORD *)(a2 + 1952) = 0;
  }
  m_pointer = reader->m_pointer;
  v7 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  *(_BYTE *)(a2 + 1956) = v7;
  v8 = 4 * v7;
  v9 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v10 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(v9, v8);
  v11 = *(_BYTE *)(a2 + 1956);
  v12 = 4 * v11;
  *(_DWORD *)(a2 + 1952) = v10;
  if ( v11 )
  {
    memcpy(v10, (unsigned __int8 *)reader->m_pointer, v12);
    reader->m_pointer += v12;
  }
  return 1;
}
