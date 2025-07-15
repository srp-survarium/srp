void __userpurge vostok::network::login_client_impl::resolve(
        vostok::network::login_client_impl *this@<ecx>,
        char *a2@<edi>,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *functor,
        unsigned int retry_count)
{
  bool has_passed_filters; // al
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v5; // ecx
  survarium::game_options *v6; // eax
  survarium::game_options *v7; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v8; // ecx
  boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> v9; // [esp-28h] [ebp-150h] BYREF
  int v10; // [esp-8h] [ebp-130h]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v11; // [esp-4h] [ebp-12Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::network::login_client_impl,boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *,unsigned int,boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> const &,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list6<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> >,boost::arg<1>,boost::arg<2> > > *handler; // [esp+4h] [ebp-124h]
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *v13; // [esp+8h] [ebp-120h]
  vostok::network::login_client_impl *thisa; // [esp+Ch] [ebp-11Ch]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v15; // [esp+18h] [ebp-110h]
  int val; // [esp+1Ch] [ebp-10Ch]
  boost::asio::io_service *io_service; // [esp+20h] [ebp-108h]
  int v18; // [esp+24h] [ebp-104h]
  boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::network::login_client_impl,boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *,unsigned int,boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> const &,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> >,boost::_bi::list6<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> >,boost::arg<1>,boost::arg<2> > > result; // [esp+28h] [ebp-100h] BYREF
  boost::asio::ip::tcp protocol; // [esp+64h] [ebp-C4h] BYREF
  survarium::game_camera v21; // [esp+6Bh] [ebp-BDh] BYREF
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp> q; // [esp+C8h] [ebp-60h] BYREF
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *resolver; // [esp+11Ch] [ebp-Ch]
  char port[8]; // [esp+120h] [ebp-8h] BYREF

  thisa = this;
  v18 = 0;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "network:", info),
        (this = (vostok::network::login_client_impl *)has_passed_filters) != 0) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this);
    v18 |= 1u;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)((char *)&v21.m_inverted_view_matrix.lines[3].elements[2] + 1),
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\login_client_impl_resolve.cpp",
      0x4Au,
      "void __thiscall vostok::network::login_client_impl::resolve(const class boost::function<void __cdecl(enum vostok::"
      "resolve_error_types_enum,class boost::asio::ip::basic_resolver_iterator<class boost::asio::ip::tcp>)> &,const unsigned int)",
      "network:",
      info,
      "[LOGIN] resolving...\r\n");
  }
  v5 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v18 & 1);
  if ( (v18 & 1) != 0 )
  {
    v18 &= ~1u;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v5,
      (int *)((char *)&v21.m_inverted_view_matrix.c.elements[2] + 1));
  }
  LOBYTE(v21.m_inverted_view_matrix.lines[3].elements[2]) = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
  thisa->m_connection_state = initiating_disconnection;
  *(_DWORD *)((char *)v21.m_inverted_view_matrix.c.elements + 1) = operator new(0xCu);
  if ( *(_DWORD *)((char *)v21.m_inverted_view_matrix.c.elements + 1) )
  {
    io_service = thisa->m_io_service;
    boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
      *(boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp> > **)((char *)v21.m_inverted_view_matrix.c.elements
                                                                                                 + 1),
      io_service);
    v13 = *(boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > **)((char *)v21.m_inverted_view_matrix.c.elements + 1);
  }
  else
  {
    v13 = 0;
  }
  resolver = v13;
  val = thisa->m_host_port;
  _itoa_s(a2, val, port, 6u, 0xAu);
  v6 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v21.m_inverted_view_matrix.lines[1].elements[2]);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v21.m_inverted_view_matrix.lines[1].elements[2]
                                                                                          + 1),
    port,
    (const stlp_std::allocator<char> *)v6);
  v7 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v21);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v21.__vftable + 1),
    thisa->m_host,
    (const stlp_std::allocator<char> *)v7);
  protocol.family_ = 2;
  boost::asio::ip::basic_resolver_query<boost::asio::ip::tcp>::basic_resolver_query<boost::asio::ip::tcp>(
    &q,
    &protocol,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v21.__vftable
                                                                                                + 1),
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v21.m_inverted_view_matrix.lines[1].elements[2]
                                                                                                + 1),
    address_configured);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v21.__vftable + 1));
  survarium::weapon_user_dead_state::finalize(&v21);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v21.m_inverted_view_matrix.lines[1].elements[2] + 1));
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v21.m_inverted_view_matrix.lines[1].elements[2]);
  v8 = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)*(unsigned __int8 *)boost::asio::placeholders::`anonymous namespace'::bytes_transferred;
  v11 = v8;
  v10 = *(unsigned __int8 *)boost::asio::placeholders::`anonymous namespace'::error;
  v15 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&v9;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, &v9);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    v15,
    functor);
  handler = boost::bind<void,vostok::network::login_client_impl,boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>> *,unsigned int,boost::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> const &,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,vostok::network::login_client_impl *,boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>> *,unsigned int,boost::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)>,boost::arg<1>,boost::arg<2>>(
              &result,
              (void (__thiscall *)(vostok::network::login_client_impl *, boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *, unsigned int, const boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> *, const boost::system::error_code *, boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>))vostok::network::login_client_impl::on_resolved,
              thisa,
              resolver,
              retry_count,
              v9,
              (boost::arg<1>)v10);
  boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::async_resolve<boost::_bi::bind_t<void,boost::_mfi::mf5<void,vostok::network::login_client_impl,boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>> *,unsigned int,boost::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> const &,boost::system::error_code const &,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>>,boost::_bi::list6<boost::_bi::value<vostok::network::login_client_impl *>,boost::_bi::value<boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>> *>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)>>,boost::arg<1>,boost::arg<2>>>>(
    resolver,
    &q,
    handler);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&result.l_.a4_);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&q.service_name_);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&q.host_name_);
}
