void __thiscall vostok::network_core::http_client::get(
        vostok::network_core::http_client *this,
        char *server,
        const char *path,
        const boost::function<void __cdecl(void)> *callback)
{
  unsigned int v4; // eax
  survarium::game_options *v5; // eax
  survarium::game_options *v6; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2> > > *v8; // [esp+8h] [ebp-148h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+58h] [ebp-F8h] BYREF
  survarium::game_camera v10; // [esp+63h] [ebp-EDh] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v11; // [esp+B8h] [ebp-98h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v12; // [esp+D0h] [ebp-80h] BYREF
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > request_stream; // [esp+E8h] [ebp-68h] BYREF

  v4 = stlp_std::char_traits<char>::length((const char *)&buf);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
    &this->m_result_content,
    (char *)&buf,
    (const char *)&buf + v4);
  boost::function<void __cdecl (void)>::operator=(&this->m_on_content_downloaded, callback);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::basic_ostream<char,stlp_std::char_traits<char>>(
    &request_stream,
    &this->m_request_buff,
    1);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, "GET ");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, path);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, " HTTP/1.0\r\n");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, "Host: ");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, server);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, "\r\n");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(&request_stream, "Accept: */*\r\n");
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(
    &request_stream,
    "Connection: close\r\n\r\n");
  v5 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10.m_inverted_view_matrix.lines[1].elements[2]);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v10.m_inverted_view_matrix.lines[1].elements[2]
                                                                                          + 1),
    "http",
    (const stlp_std::allocator<char> *)v5);
  v6 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v10.__vftable + 1),
    server,
    (const stlp_std::allocator<char> *)v6);
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
    (boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *)((char *)&v10.m_inverted_view_matrix.lines[3].x + 1),
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v10.__vftable
                                                                                                + 1),
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v10.m_inverted_view_matrix.lines[1].elements[2]
                                                                                                + 1),
    address_configured);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v10.__vftable + 1));
  survarium::weapon_user_dead_state::finalize(&v10);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v10.m_inverted_view_matrix.lines[1].elements[2] + 1));
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v10.m_inverted_view_matrix.lines[1].elements[2]);
  v8 = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2> > > *)boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network_core::http_client::handle_resolve, (vostok::sound::sound_debug_stats *)this);
  boost::asio::detail::resolver_service<boost::asio::ip::tcp>::async_resolve<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network_core::http_client,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list3<boost::_bi::value<vostok::network_core::http_client *>,boost::arg<1>,boost::arg<2>>>>(
    &this->m_resolver.service->service_impl_,
    &this->m_resolver.implementation,
    (const boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> *)((char *)&v10.m_inverted_view_matrix.lines[3].x
                                                                        + 1),
    *v8);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v12);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v11);
  stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::~basic_ostream<char,stlp_std::char_traits<char>>((stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *)&request_stream.gap0[8]);
  *(_DWORD *)&request_stream.gap0[8] = &stlp_std::basic_ios<char,stlp_std::char_traits<char>>::`vftable';
  stlp_std::ios_base::~ios_base((stlp_std::ios_base *)&request_stream.gap0[8]);
}
