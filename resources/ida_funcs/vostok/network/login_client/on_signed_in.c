void __thiscall vostok::network::login_client::on_signed_in(
        vostok::network::login_client *this,
        vostok::connection_error_types_enum connection_error,
        vostok::handshaking_error_types_enum handshaking_error,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *socket_error,
        vostok::login_server_message_types_enum login_error)
{
  survarium::game_camera *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // eax
  boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum)> v7; // [esp-64h] [ebp-C0h]
  boost::_bi::bind_t<boost::_bi::unspecified,boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>,boost::_bi::list4<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>,boost::_bi::value<enum vostok::socket_error_types_enum>,boost::_bi::value<enum vostok::login_server_message_types_enum> > > v8; // [esp-34h] [ebp-90h] BYREF
  int v9; // [esp-4h] [ebp-60h]
  vostok::network::response *response; // [esp+4h] [ebp-58h]
  boost::_bi::bind_t<boost::_bi::unspecified,boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>,boost::_bi::list4<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>,boost::_bi::value<enum vostok::socket_error_types_enum>,boost::_bi::value<enum vostok::login_server_message_types_enum> > > *v11; // [esp+8h] [ebp-54h]
  vostok::network::login_client *thisa; // [esp+Ch] [ebp-50h]
  void *_Where; // [esp+1Ch] [ebp-40h]
  vostok::memory::doug_lea_allocator *v14; // [esp+20h] [ebp-3Ch]
  vostok::memory::doug_lea_allocator *v15; // [esp+24h] [ebp-38h]
  int v16; // [esp+28h] [ebp-34h]
  boost::function<void __cdecl(void)> f; // [esp+34h] [ebp-28h] BYREF
  char *v18; // [esp+58h] [ebp-4h]

  thisa = this;
  v16 = 0;
  thisa->m_client_state = connection_error == successfully_connected
                       && handshaking_error == successfully_handshaked
                       && !socket_error
                       && login_error == servers_connection_info_message_type;
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_on_sign_in) )
  {
    v15 = vostok::network::g_allocator;
    survarium::weapon_user_dead_state::finalize(v5);
    v14 = v6;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v6, 0x28u);
    v18 = (char *)operator new(0x28u, _Where);
    if ( v18 )
    {
      v9 = 0;
      boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>((boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&thisa->m_on_sign_in);
      v11 = boost::bind<boost::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>(
              &v8,
              v7,
              connection_error,
              handshaking_error,
              socket_error,
              (vostok::lobby_server_message_types_enum)login_error);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&f, v8, v9);
      v16 |= 1u;
      *(_DWORD *)v18 = &vostok::network::response::`vftable';
      *(_DWORD *)v18 = &vostok::network::functor_response::`vftable';
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)(v18 + 8),
        &f);
      response = (vostok::network::response *)v18;
    }
    else
    {
      response = 0;
    }
    vostok::network::network_world::add_response(thisa->m_world, response);
    if ( (v16 & 1) != 0 )
    {
      v16 &= ~1u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
    }
  }
}
