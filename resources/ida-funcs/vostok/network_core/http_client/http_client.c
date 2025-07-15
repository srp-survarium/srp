void __thiscall vostok::network_core::http_client::http_client(
        vostok::network_core::http_client *this,
        boost::asio::io_service *io_service)
{
  survarium::game_options *v2; // eax
  survarium::game_options *v3; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  stlp_std::allocator<char> *__a; // [esp+8h] [ebp-90h]
  char v8; // [esp+95h] [ebp-3h] BYREF
  char v9; // [esp+96h] [ebp-2h] BYREF
  char v10; // [esp+97h] [ebp-1h] BYREF

  boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
    &this->m_resolver,
    io_service);
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
    &this->m_socket,
    io_service);
  v2 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v10);
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::basic_streambuf<stlp_std::allocator<char>>(
    &this->m_request_buff,
    0xFFFFFFFF,
    (const stlp_std::allocator<char> *)v2);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v10);
  v3 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v9);
  boost::asio::basic_streambuf<stlp_std::allocator<char>>::basic_streambuf<stlp_std::allocator<char>>(
    &this->m_response_buff,
    0xFFFFFFFF,
    (const stlp_std::allocator<char> *)v3);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v9);
  __a = (stlp_std::allocator<char> *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v8);
  this->m_result_content._M_finish = (char *)&this->m_result_content;
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>(
    &this->m_result_content._M_start_of_storage,
    __a,
    (char *)&this->m_result_content);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_allocate_block(&this->m_result_content, 0x10u);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_terminate_string(&this->m_result_content);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v8);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &this->m_on_content_downloaded.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &this->m_on_error.vtable);
}
