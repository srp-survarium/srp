void __thiscall vostok::network_core::http_client::handle_read_status_line(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool v4; // al
  bool v5; // zf
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp-4h] [ebp-C4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // [esp-4h] [ebp-C4h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-C4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > handler; // [esp+10h] [ebp-B0h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > __s; // [esp+18h] [ebp-A8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v12; // [esp+30h] [ebp-90h] BYREF
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > __is; // [esp+50h] [ebp-70h] BYREF

  handler.f_.f_ = 0;
  if ( !err->m_val )
  {
    stlp_std::basic_istream<char,stlp_std::char_traits<char>>::basic_istream<char,stlp_std::char_traits<char>>(
      &__is,
      &this->m_response_buff,
      1);
    __s._M_finish = (char *)&__s;
    __s._M_start_of_storage._M_data = (char *)&__s;
    __s._M_buffers._M_static_buf[0] = 0;
    stlp_std::getline<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(&__is, &__s, 10);
    v3 = v7;
    if ( (__is.gap10[*(_DWORD *)(*(_DWORD *)__is.gap0 + 4) - 4] & 5) != 0
      || stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(&__s, "HTTP/") )
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)"network_core",
                                   (const char *)2),
            v3 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v3,
          &v12);
        handler.f_.f_ = (void (__thiscall *)(vostok::network_core::http_client *, const boost::system::error_code *))1;
        vostok::logging::append(
          &v12,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\http_client.cpp",
          0x93u,
          "void __thiscall vostok::network_core::http_client::handle_read_status_line(const class boost::system::error_code &)",
          "network_core",
          error,
          "http_client: Invalid response");
      }
      v5 = ((int)handler.f_.f_ & 1) == 0;
    }
    else
    {
      if ( stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(&__s, "200") != -1 )
      {
        vostok::network_core::read_lines_from_stream(&this->m_response_buff);
        handler.l_.a1_.t_ = this;
        handler.f_.f_ = vostok::network_core::http_client::handle_read_content;
        boost::asio::async_read<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::asio::detail::transfer_at_least_t,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>(
          &handler,
          &this->m_socket,
          &this->m_response_buff,
          (boost::asio::detail::transfer_at_least_t)1);
LABEL_10:
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__s);
        stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'(&__is);
        return;
      }
      if ( !vostok::core::g_log_filter_tree
        || (v4 = vostok::logging::has_passed_filters((vostok::logging::filter_tree *)"network_core", (const char *)2),
            v3 = v8,
            v4) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v3,
          &v12);
        handler.f_.f_ = (void (__thiscall *)(vostok::network_core::http_client *, const boost::system::error_code *))2;
        vostok::logging::append(
          &v12,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\http_client.cpp",
          0x99u,
          "void __thiscall vostok::network_core::http_client::handle_read_status_line(const class boost::system::error_code &)",
          "network_core",
          error,
          "http_client: Response returned with status code %s",
          __s._M_start_of_storage._M_data);
      }
      v5 = ((int)handler.f_.f_ & 2) == 0;
    }
    if ( !v5 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v12);
    goto LABEL_10;
  }
  vostok::network_core::http_client::on_error(
    err,
    (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
    this);
}
