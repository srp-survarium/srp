void __thiscall survarium::messaging_client::on_error(
        survarium::messaging_client *this,
        vostok::network_core::client_error_codes_enum client_error_code,
        boost::system::error_code system_error_code)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-4Ch]
  char v7; // [esp+Ch] [ebp-3Ch]
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v8; // [esp+10h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v9; // [esp+28h] [ebp-20h] BYREF

  v7 = 0;
  survarium::chat_handler::add_message(
    (survarium::chat_handler *)this,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)this->m_chat_handler,
    (survarium::private_channel_tab *)2,
    "Lost connection to messaging server. Reconnecting...",
    "System");
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)2),
        v4 = v6,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v4,
      &v9);
    v7 = 3;
    system_error_code.m_cat->message(
      system_error_code.m_cat,
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v8,
      system_error_code.m_val);
    vostok::logging::append(
      &v9,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\messaging_client.cpp",
      0x6Au,
      "void __thiscall survarium::messaging_client::on_error(enum vostok::network_core::client_error_codes_enum,class boo"
      "st::system::error_code)",
      "game",
      error,
      (char *)&stru_7F9BE8.allocator,
      v8._M_start_of_storage._M_data);
  }
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v8);
  }
  if ( (v7 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
      (int *)&v9);
  survarium::messaging_client::disconnect(this);
  ++this->m_connection_info.connection_error_count;
  this->m_connection_info.need_resolve = 1;
}
