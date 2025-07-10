void __thiscall vostok::network_core::udp_match_connection::process_low_level_message(
        vostok::network_core::udp_match_connection *this,
        vostok::network_core::packet_reader *reader,
        unsigned int time_in_ms)
{
  unsigned __int8 v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  char v6; // [esp+18h] [ebp-30h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-28h] BYREF
  vostok::network_core::udp_match_connection::low_level_message_type_enum message_type; // [esp+44h] [ebp-4h]

  v6 = 0;
  v3 = vostok::network_core::packet_reader::r<unsigned char>((vostok::network_core::packet_reader *)this, (int)reader);
  message_type = v3;
  v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v3;
  if ( !v3 )
  {
LABEL_4:
    if ( this->m_state == connected )
    {
      this->m_state = confirming_disconnection;
      this->m_disconnection_receive_time_in_ms = time_in_ms;
    }
    return;
  }
  if ( v3 != 1 )
  {
    if ( v3 == 2 )
      return;
    goto LABEL_4;
  }
  if ( this->m_state )
  {
    if ( this->m_state == initiating_disconnection )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v3);
      vostok::network_core::udp_match_connection::instant_disconnect(
        this,
        (boost::function4<void,unsigned int,float,float,char const *> *)2);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v4);
      v6 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[348],
        0x24Fu,
        &stru_984D24.m_working_macro_list.m_buffer[5].m_store[76],
        "network_core:",
        error,
        &stru_984D24.m_working_macro_list.m_buffer[4].m_store[532]);
    }
    if ( (v6 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v4,
        (int *)&log_callback);
  }
}
