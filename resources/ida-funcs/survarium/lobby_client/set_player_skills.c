void __userpurge survarium::lobby_client::set_player_skills(
        vostok::vectora<survarium::player_skill> *skills@<eax>,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *a2@<ecx>,
        int this,
        vostok::vectora<unsigned char> *perks)
{
  survarium::lobby_client *v4; // ebx
  bool has_passed_filters; // al
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  survarium::player_skill *M_start; // eax
  survarium::player_skill *M_finish; // edi
  vostok::vectora<unsigned char> *v14; // edi
  vostok::network_core::buffer_writer *v15; // ecx
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edi
  vostok::network_core::buffer_writer *v18; // ecx
  vostok::network_core::mutable_buffer *v19; // ecx
  int m_selected_profile_idx; // [esp-8h] [ebp-68h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v21; // [esp-4h] [ebp-64h]
  int m_profiles_count; // [esp-4h] [ebp-64h]
  vostok::network_core::tcp_packet v23; // [esp+10h] [ebp-50h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v24; // [esp+38h] [ebp-28h] BYREF
  unsigned int profile_id; // [esp+5Ch] [ebp-4h] BYREF

  v4 = (survarium::lobby_client *)this;
  this = 0;
  profile_id = v4->m_profiles[v4->m_game->m_lobby_menu->m_selected_profile_idx].profile_id;
  if ( profile_id )
  {
    vostok::network_core::tcp_packet::tcp_packet(
      (vostok::network_core::tcp_packet *)&vostok::memory::g_mt_allocator,
      (int)&v23);
    HIBYTE(this) = 37;
    vostok::network_core::buffer_writer::w(
      v7,
      &v23.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&this + 3,
      1u);
    HIBYTE(this) = 0;
    vostok::network_core::buffer_writer::w(
      v8,
      &v23.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&this + 3,
      1u);
    vostok::network_core::buffer_writer::w(
      v9,
      &v23.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&profile_id,
      4u);
    HIBYTE(this) = skills->_M_impl._M_finish - skills->_M_impl._M_start;
    vostok::network_core::buffer_writer::w(
      v10,
      &v23.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&this + 3,
      1u);
    M_start = skills->_M_impl._M_start;
    M_finish = skills->_M_impl._M_finish;
    if ( M_start != M_finish )
      vostok::network_core::buffer_writer::w(
        v11,
        &v23.m_writer.serialization_operations_descriptors.m_size,
        &M_start->skill_id,
        2 * (M_finish - M_start));
    v14 = perks;
    HIBYTE(this) = LOBYTE(perks->_M_impl._M_finish) - LOBYTE(perks->_M_impl._M_start);
    vostok::network_core::buffer_writer::w(
      v11,
      &v23.m_writer.serialization_operations_descriptors.m_size,
      (unsigned __int8 *)&this + 3,
      1u);
    v16 = v14->_M_impl._M_start;
    v17 = v14->_M_impl._M_finish;
    if ( v16 != v17 )
      vostok::network_core::buffer_writer::w(
        v15,
        &v23.m_writer.serialization_operations_descriptors.m_size,
        v16,
        v17 - v16);
    vostok::network::tcp_packet_client::send(
      (vostok::network::tcp_packet_client *)v15,
      (const vostok::network_core::tcp_packet *)&v4->m_packet_client,
      &v23);
    vostok::network_core::buffer_writer::~buffer_writer(v18, &v23.m_writer.serialization_operations_descriptors);
    vostok::network_core::mutable_buffer::~mutable_buffer(v19, &v23);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          a2 = v21,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        a2,
        &v24);
      m_profiles_count = v4->m_profiles_count;
      m_selected_profile_idx = v4->m_game->m_lobby_menu->m_selected_profile_idx;
      this = 1;
      vostok::logging::append(
        &v24,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lobby_client.cpp",
        0x213u,
        "void __thiscall survarium::lobby_client::set_player_skills(class vostok::vectora<struct survarium::player_skill>"
        " &,class vostok::vectora<unsigned char> &)",
        "game",
        error,
        "wrong player profile id for selected profile [%d] from [%d]!!!",
        m_selected_profile_idx,
        m_profiles_count);
    }
    if ( (this & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)a2,
        (int *)&v24);
  }
}
