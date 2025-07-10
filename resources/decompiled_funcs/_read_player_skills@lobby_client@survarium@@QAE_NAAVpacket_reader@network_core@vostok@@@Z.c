char __userpurge survarium::lobby_client::read_player_skills@<al>(
        vostok::network_core::packet_reader *reader@<edi>,
        survarium::lobby_client *this)
{
  vostok::sound::sound_world *v2; // ecx
  survarium::player_skill *m_player_skills; // eax
  void *m_start_time_high; // esi
  const unsigned __int8 *m_pointer; // eax
  unsigned int v6; // ecx
  const unsigned __int8 *v7; // eax
  unsigned int v8; // ecx
  const unsigned __int8 *v9; // eax
  unsigned int v10; // ecx
  const unsigned __int8 *v11; // eax
  unsigned int v12; // esi
  vostok::memory::doug_lea_allocator *v13; // eax
  survarium::player_skill *v14; // eax
  unsigned __int8 m_player_skills_count; // cl
  unsigned int v16; // esi
  vostok::sound::sound_world *v17; // ecx
  unsigned __int8 *m_player_perks; // eax
  void *v19; // esi
  const unsigned __int8 *v20; // eax
  unsigned __int8 v21; // cl
  unsigned int v22; // esi
  vostok::memory::doug_lea_allocator *v23; // eax
  unsigned __int8 *v24; // eax
  unsigned __int8 m_player_perks_count; // cl
  int v26; // esi
  vostok::sound::sound_world *f; // [esp-4h] [ebp-14h]

  v2 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  m_player_skills = this->m_player_skills;
  if ( m_player_skills )
  {
    m_start_time_high = (void *)HIDWORD(v2->m_timer.m_start_time);
    BYTE2(v2->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(m_start_time_high, m_player_skills);
    this->m_player_skills = 0;
  }
  m_pointer = reader->m_pointer;
  v6 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_player_leveling_info.total_experience = v6;
  v7 = reader->m_pointer;
  v8 = *(_DWORD *)v7;
  reader->m_pointer = v7 + 4;
  this->m_player_leveling_info.next_level_experience = v8;
  v9 = reader->m_pointer;
  v10 = *(_DWORD *)v9;
  reader->m_pointer = v9 + 4;
  this->m_player_leveling_info.prev_level_experience = v10;
  v11 = reader->m_pointer;
  LOBYTE(v10) = *v11;
  reader->m_pointer = v11 + 1;
  this->m_player_skills_count = v10;
  v12 = 2 * (unsigned __int8)v10;
  v13 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v14 = (survarium::player_skill *)vostok::memory::doug_lea_allocator::malloc_impl(v13, v12);
  m_player_skills_count = this->m_player_skills_count;
  v16 = 2 * m_player_skills_count;
  this->m_player_skills = v14;
  if ( m_player_skills_count )
  {
    memcpy(&v14->skill_id, (unsigned __int8 *)reader->m_pointer, v16);
    reader->m_pointer += v16;
  }
  v17 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  m_player_perks = this->m_player_perks;
  if ( m_player_perks )
  {
    v19 = (void *)HIDWORD(v17->m_timer.m_start_time);
    BYTE2(v17->m_xaudio_callback_orders.m_pop_thread_id) = 0;
    vostok_mspace_free(v19, m_player_perks);
    this->m_player_perks = 0;
  }
  v20 = reader->m_pointer;
  v21 = *v20;
  reader->m_pointer = v20 + 1;
  f = (vostok::sound::sound_world *)survarium::g_allocator.f_.f_;
  this->m_player_perks_count = v21;
  v22 = v21;
  v23 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>(f);
  v24 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(v23, v22);
  m_player_perks_count = this->m_player_perks_count;
  this->m_player_perks = v24;
  v26 = m_player_perks_count;
  if ( m_player_perks_count )
  {
    memcpy(v24, (unsigned __int8 *)reader->m_pointer, m_player_perks_count);
    reader->m_pointer += v26;
  }
  return 1;
}
