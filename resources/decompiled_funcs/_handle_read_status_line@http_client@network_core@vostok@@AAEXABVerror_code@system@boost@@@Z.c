void __thiscall vostok::network_core::http_client::handle_read_status_line(
        vostok::network_core::http_client *this,
        const boost::system::error_code *err)
{
  int v2; // ecx
  int v3; // edx
  BOOL v4; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *v7; // [esp+10h] [ebp-134h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > v8; // [esp+18h] [ebp-12Ch]
  boost::system::error_code ec; // [esp+20h] [ebp-124h] BYREF
  boost::asio::detail::read_streambuf_op<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> >,stlp_std::allocator<char>,boost::asio::detail::transfer_at_least_t,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > > v10; // [esp+28h] [ebp-11Ch] BYREF
  int v11; // [esp+48h] [ebp-FCh]
  stlp_std::allocator<char> *__a; // [esp+54h] [ebp-F0h]
  int v13; // [esp+5Ch] [ebp-E8h]
  int v14; // [esp+60h] [ebp-E4h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+64h] [ebp-E0h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v16; // [esp+6Ch] [ebp-D8h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8Ch] [ebp-B8h] BYREF
  survarium::game_camera v18; // [esp+B3h] [ebp-91h] BYREF
  int found; // [esp+140h] [ebp-4h]

  v13 = 0;
  if ( err->m_val )
  {
    vostok::network_core::http_client::on_error(this, err);
  }
  else
  {
    *(_DWORD *)((char *)&v18.m_inverted_view_matrix.j.elements[1] + 1) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbtable';
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::basic_ios<char,stlp_std::char_traits<char>>((stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)((char *)&v18.m_inverted_view_matrix.lines[2].elements[1] + 1));
    v13 |= 4u;
    *(_DWORD *)((char *)&v18.m_inverted_view_matrix.j.elements[1] + unk_815C28 + 1) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vftable';
    *(_QWORD *)((char *)&v18.m_inverted_view_matrix.lines[1].elements[3] + 1) = 0;
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::init(
      (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)((char *)&v18.m_inverted_view_matrix.lines[1].elements[1]
                                                               + *(_DWORD *)(*(_DWORD *)((char *)&v18.m_inverted_view_matrix.j.elements[1]
                                                                                       + 1)
                                                                           + 4)
                                                               + 1),
      &this->m_response_buff);
    __a = (stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v18);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_String_base<char,stlp_std::allocator<char>>(
      (stlp_std::priv::_String_base<char,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1),
      __a,
      0x10u);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_terminate_string((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1));
    survarium::weapon_user_dead_state::finalize(&v18);
    stlp_std::getline<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      (stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v18.m_inverted_view_matrix.lines[1].elements[1]
                                                                   + 1),
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1),
      10);
    found = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(
              v2,
              "HTTP/",
              (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1),
              0);
    v3 = *(_DWORD *)(*(_DWORD *)((char *)&v18.m_inverted_view_matrix.j.elements[1] + 1) + 4);
    v4 = (*(_DWORD *)((_BYTE *)v18.m_inverted_view_matrix.k.elements + v3 + 1) & 5) != 0;
    if ( (*(_DWORD *)((_BYTE *)v18.m_inverted_view_matrix.k.elements + v3 + 1) & 5) != 0 || found )
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v4);
        v13 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\http_client.cpp",
          0x84u,
          "void __thiscall vostok::network_core::http_client::handle_read_status_line(const class boost::system::error_code &)",
          "network_core:",
          error,
          "http_client: Invalid response");
      }
      if ( (v13 & 1) != 0 )
      {
        v13 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v4,
          (int *)&log_callback);
      }
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1));
      stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v18.m_inverted_view_matrix.lines[1].elements[1] + 1));
    }
    else
    {
      found = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::find(
                (int)&v18.__vftable + 1,
                "200",
                (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1),
                0);
      if ( found == -1 )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network_core:", error) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v5);
          v13 |= 2u;
          v11 = *(_DWORD *)((char *)v18.m_inverted_view_matrix.j.elements + 1);
          vostok::logging::append(
            &v16,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\http_client.cpp",
            0x8Au,
            "void __thiscall vostok::network_core::http_client::handle_read_status_line(const class boost::system::error_code &)",
            "network_core:",
            error,
            "http_client: Response returned with status code %s",
            *(const char **)((char *)v18.m_inverted_view_matrix.j.elements + 1));
        }
        if ( (v13 & 2) != 0 )
        {
          v13 &= ~2u;
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v5,
            (int *)&v16);
        }
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1));
        stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v18.m_inverted_view_matrix.lines[1].elements[1] + 1));
      }
      else
      {
        vostok::network_core::read_lines_from_stream(
          (survarium::game_camera *)"read_status_line",
          &this->m_response_buff);
        v14 = 1;
        v7 = boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
               (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
               (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::http_client::handle_read_content,
               (vostok::sound::sound_debug_stats *)this);
        ec.m_val = 0;
        ec.m_cat = boost::system::system_category();
        v8 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1> > > *)v7;
        v10.completion_condition_.minimum_ = 1;
        v10.stream_ = &this->m_socket;
        v10.streambuf_ = &this->m_response_buff;
        v10.total_transferred_ = 0;
        v10.handler_ = v8;
        boost::asio::detail::read_streambuf_op<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>,stlp_std::allocator<char>,boost::asio::detail::transfer_at_least_t,boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network_core::http_client,boost::system::error_code const &>,boost::_bi::list2<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>>>>::operator()(
          &v10,
          &ec,
          0,
          1);
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v18.__vftable + 1));
        stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v18.m_inverted_view_matrix.lines[1].elements[1] + 1));
      }
    }
  }
}
