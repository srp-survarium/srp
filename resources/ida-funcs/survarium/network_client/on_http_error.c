void __thiscall survarium::network_client::on_http_error(
        survarium::network_client *this,
        boost::system::error_code __formal)
{
  bool has_passed_filters; // al
  survarium::network_client *v3; // [esp-4h] [ebp-34h]
  char v4; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v5; // [esp+10h] [ebp-20h] BYREF

  v4 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"game",
                               (const char *)2),
        this = v3,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v5);
    v4 = 1;
    vostok::logging::append(
      &v5,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\network_client.cpp",
      0x18Fu,
      "void __thiscall survarium::network_client::on_http_error(class boost::system::error_code)",
      "game",
      error,
      "http client error!");
  }
  if ( (v4 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v5);
}
