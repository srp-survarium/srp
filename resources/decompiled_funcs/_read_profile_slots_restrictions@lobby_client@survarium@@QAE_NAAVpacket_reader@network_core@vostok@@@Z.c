char __userpurge survarium::lobby_client::read_profile_slots_restrictions@<al>(
        survarium::lobby_client *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::packet_reader *reader)
{
  vostok::sound::sound_world *v4; // ecx
  void *v5; // eax
  void *m_start_time_high; // esi
  const unsigned __int8 *m_pointer; // eax
  int v8; // ecx
  unsigned int v9; // esi
  vostok::memory::doug_lea_allocator *v10; // eax
  unsigned __int8 *v11; // eax
  int v12; // edi

  v4 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v5 = *(void **)(a2 + 2124);
  if ( v5 )
  {
    m_start_time_high = (void *)HIDWORD(v4->m_timer.m_start_time);
    BYTE2(v4->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, v5);
    *(_DWORD *)(a2 + 2124) = 0;
  }
  m_pointer = reader->m_pointer;
  v8 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  *(_DWORD *)(a2 + 2128) = v8;
  v9 = 2 * v8;
  v10 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v11 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(v10, v9);
  *(_DWORD *)(a2 + 2124) = v11;
  v12 = *(_DWORD *)(a2 + 2128);
  if ( v12 )
  {
    memcpy(v11, (unsigned __int8 *)reader->m_pointer, 2 * v12);
    reader->m_pointer += 2 * v12;
  }
  return 1;
}
