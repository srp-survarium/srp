void __thiscall survarium::network_client::disconnect(survarium::network_client *this)
{
  void (*unload)(void); // edx
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::messaging_client *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)> callback; // [esp+10h] [ebp-40h] BYREF
  boost::function<void __cdecl(unsigned int,unsigned int)> v7; // [esp+30h] [ebp-20h] BYREF

  if ( this->m_game_status )
  {
    unload = (void (*)(void))this->unload;
    this->m_game_status = game_status_inactive;
    unload();
    v7.vtable = 0;
    boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=(
      &v7,
      (boost::function2<void,unsigned int,unsigned int> *)&this->m_match_client.m_client.m_on_disconnected);
    if ( v7.vtable )
    {
      if ( ((int)v7.vtable & 1) == 0 )
      {
        v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v7.vtable & 0xFFFFFFFE);
        if ( v3 )
          v3(&v7.functor, &v7.functor, 2);
      }
      v7.vtable = 0;
    }
    vostok::network::match_client::disconnect(&this->m_match_client.m_client);
  }
  survarium::lobby_client::disconnect((survarium::lobby_client *)this);
  survarium::messaging_client::disconnect(v4);
  callback.vtable = 0;
  if ( `boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>::assign_to<void (__cdecl *)(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>'::`2'::stored_vtable )
    `boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>::assign_to<void (__cdecl *)(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>'::`2'::stored_vtable(
      &callback.functor,
      &callback.functor,
      destroy_functor_tag);
  if ( survarium::on_signed_out )
  {
    callback.functor.obj_ptr = survarium::on_signed_out;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function4<void,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>::assign_to<void (__cdecl *)(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>'::`2'::stored_vtable
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  vostok::network::login_client::sign_out(
    &this->m_login_client,
    (boost::function<void __cdecl(unsigned int,unsigned int)> *)&callback);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v5 )
      v5(&callback.functor, &callback.functor, 2);
  }
}
