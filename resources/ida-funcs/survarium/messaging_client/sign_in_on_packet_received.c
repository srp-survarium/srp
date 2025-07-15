void __thiscall survarium::messaging_client::sign_in_on_packet_received(
        survarium::messaging_client *this,
        vostok::network_core::buffer_reader *reader)
{
  unsigned __int8 *v3; // ecx
  bool v4; // al
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // ecx
  bool has_passed_filters; // al
  survarium::messaging_client *v9; // ecx
  survarium::messaging_client *v10; // ecx
  survarium::messaging_client *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > v12; // [esp-8h] [ebp-80h]
  unsigned __int8 *v13; // [esp-4h] [ebp-7Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v14; // [esp-4h] [ebp-7Ch]
  int v15; // [esp+0h] [ebp-78h]
  __int16 v16; // [esp+13h] [ebp-65h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v17; // [esp+18h] [ebp-60h] BYREF
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v18; // [esp+38h] [ebp-40h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v19; // [esp+58h] [ebp-20h] BYREF

  v16 = *reader->m_pointer;
  v3 = (unsigned __int8 *)(reader->m_pointer + 1);
  reader->m_pointer = v3;
  if ( (_BYTE)v16 == 0xCA )
  {
    vostok::network_core::buffer_reader::r_string(
      (vostok::network_core::buffer_reader *)this->m_local_name,
      (char *)reader,
      (unsigned __int8 *)this->m_local_name);
    this->m_connection_info.connection_error_count = 0;
    v12.l_.a1_.t_ = this;
    v12.f_.f_ = survarium::messaging_client::on_packet_received;
    this->m_connection_state = client_connected;
    boost::function<void __cdecl (vostok::network_core::buffer_reader &)>::function<void __cdecl (vostok::network_core::buffer_reader &)>(
      v5,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::messaging_client,vostok::network_core::buffer_reader &>,boost::_bi::list2<boost::_bi::value<survarium::messaging_client *>,boost::arg<1> > > *)&v18,
      v12,
      v15);
    boost::function<void __cdecl (boost::system::error_code)>::operator=(
      &v18,
      (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_network_client);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&v18);
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)4),
          v7 = v14,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v7,
        &v19);
      HIBYTE(v16) = 1;
      vostok::logging::append(
        &v19,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\messaging_client_sign_in.cpp",
        0x1Eu,
        "void __thiscall survarium::messaging_client::sign_in_on_packet_received(class vostok::network_core::buffer_reader &)",
        "game",
        info,
        "Messaging client: signed in!");
    }
    if ( (v16 & 0x100) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v7,
        (int *)&v19);
    survarium::chat_handler::set_local_player_name((const char (*)[64])this->m_local_name, this->m_chat_handler);
    if ( !vostok::strings::compare(g_localization_name.m_begin, "english") )
      this->m_localization_group_channel = english_lang_channel;
    survarium::messaging_client::update_channel_subscriptions(v9, this);
    survarium::messaging_client::query_for_friend_list(v10, (int)this);
    survarium::messaging_client::query_for_ignore_list(v11, (int)this);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (v4 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"game", (const char *)2), v3 = v13, v4) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3,
        &v17);
      HIBYTE(v16) = 2;
      vostok::logging::append(
        &v17,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\messaging_client_sign_in.cpp",
        0x35u,
        "void __thiscall survarium::messaging_client::sign_in_on_packet_received(class vostok::network_core::buffer_reader &)",
        "game",
        error,
        "messaging_client received unknown message:%d",
        (unsigned __int8)v16);
    }
    if ( (v16 & 0x200) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v17);
  }
}
