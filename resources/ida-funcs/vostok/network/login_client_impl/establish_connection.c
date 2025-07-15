void __thiscall vostok::network::login_client_impl::establish_connection(
        vostok::network::login_client_impl *this,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *functor,
        unsigned int resolve_retry_count,
        unsigned int reconnect_retry_count)
{
  boost::function<void __cdecl(enum vostok::connection_error_types_enum)> v4; // [esp-54h] [ebp-A4h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl(enum vostok::connection_error_types_enum)> const &>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::connection_error_types_enum)> > > > v5; // [esp-34h] [ebp-84h] BYREF
  int v6; // [esp-4h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl(enum vostok::connection_error_types_enum)> const &>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::connection_error_types_enum)> > > > *v7; // [esp+0h] [ebp-50h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl(enum vostok::connection_error_types_enum)> const &>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::connection_error_types_enum)> > > > *result; // [esp+4h] [ebp-4Ch]
  vostok::network::login_client_impl *thisa; // [esp+8h] [ebp-48h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v10; // [esp+24h] [ebp-2Ch]
  boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> v11; // [esp+30h] [ebp-20h] BYREF

  thisa = this;
  if ( this->m_connection_state == connected )
  {
    v6 = 0;
    result = &v5;
    v10 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&v4;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
      &v4);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      v10,
      functor);
    v7 = boost::bind<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl (enum vostok::connection_error_types_enum)> const &,vostok::network::login_client_impl *,boost::arg<1>,boost::arg<2>,unsigned int,boost::function<void __cdecl (enum vostok::connection_error_types_enum)>>(
           result,
           (void (__thiscall *)(vostok::network::login_client_impl *, vostok::resolve_error_types_enum, boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>, unsigned int, const boost::function<void __cdecl(enum vostok::connection_error_types_enum)> *))vostok::network::login_client_impl::connect,
           thisa,
           1_244,
           2_142,
           reconnect_retry_count,
           v4);
    boost::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)>::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)>(
      &v11,
      v5,
      v6);
    vostok::network::login_client_impl::resolve(thisa, &v11, resolve_retry_count);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v11);
  }
}
