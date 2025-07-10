void __thiscall vostok::network::match_client::on_connected(
        vostok::network::match_client *this,
        vostok::connection_error_types_enum connection_error,
        vostok::handshaking_error_types_enum handshaking_error,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *socket_error,
        vostok::lobby_server_message_types_enum lobby_error)
{
  vostok::memory::doug_lea_allocator *v5; // eax
  boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum)> v6; // [esp-64h] [ebp-C0h]
  boost::_bi::bind_t<boost::_bi::unspecified,boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::lobby_server_message_types_enum)>,boost::_bi::list4<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>,boost::_bi::value<enum vostok::socket_error_types_enum>,boost::_bi::value<enum vostok::lobby_server_message_types_enum> > > v7; // [esp-34h] [ebp-90h] BYREF
  int v8; // [esp-4h] [ebp-60h]
  vostok::network::response *response; // [esp+4h] [ebp-58h]
  boost::_bi::bind_t<boost::_bi::unspecified,boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>,boost::_bi::list4<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>,boost::_bi::value<enum vostok::socket_error_types_enum>,boost::_bi::value<enum vostok::login_server_message_types_enum> > > *v10; // [esp+8h] [ebp-54h]
  vostok::network::match_client *thisa; // [esp+Ch] [ebp-50h]
  void *_Where; // [esp+1Ch] [ebp-40h]
  vostok::memory::doug_lea_allocator *v13; // [esp+20h] [ebp-3Ch]
  vostok::memory::doug_lea_allocator *v14; // [esp+24h] [ebp-38h]
  int v15; // [esp+28h] [ebp-34h]
  boost::function<void __cdecl(void)> f; // [esp+34h] [ebp-28h] BYREF
  char *v17; // [esp+58h] [ebp-4h]

  thisa = this;
  v15 = 0;
  if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_connected)
      ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
      : 0) != 0 )
  {
    v14 = vostok::network::g_allocator;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)vostok::network::g_allocator);
    v13 = v5;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v5, 0x28u);
    v17 = (char *)operator new(0x28u, _Where);
    if ( v17 )
    {
      v8 = 0;
      boost::function<void __cdecl (unsigned int,float,float,char const *)>::function<void __cdecl (unsigned int,float,float,char const *)>((boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&thisa->m_on_connected);
      v10 = boost::bind<boost::function<void __cdecl (enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>,enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum>(
              (boost::_bi::bind_t<boost::_bi::unspecified,boost::function<void __cdecl(enum vostok::connection_error_types_enum,enum vostok::handshaking_error_types_enum,enum vostok::socket_error_types_enum,enum vostok::login_server_message_types_enum)>,boost::_bi::list4<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>,boost::_bi::value<enum vostok::socket_error_types_enum>,boost::_bi::value<enum vostok::login_server_message_types_enum> > > *)&v7,
              v6,
              connection_error,
              handshaking_error,
              socket_error,
              lobby_error);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&f, v7, v8);
      v15 |= 1u;
      *(_DWORD *)v17 = &vostok::network::response::`vftable';
      *(_DWORD *)v17 = &vostok::network::functor_response::`vftable';
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)(v17 + 8),
        &f);
      response = (vostok::network::response *)v17;
    }
    else
    {
      response = 0;
    }
    vostok::network::network_world::add_response(thisa->m_world, response);
    if ( (v15 & 1) != 0 )
    {
      v15 &= ~1u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
    }
  }
}
