void __usercall vostok::network::login_client_impl::establish_connection(
        vostok::network::login_client_impl *this@<ecx>,
        boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl(enum vostok::connection_error_types_enum)> const &>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::connection_error_types_enum)> > > > *a2@<eax>)
{
  boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v5; // [esp-50h] [ebp-78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl(enum vostok::connection_error_types_enum)> const &>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client_impl *>,boost::arg<1>,boost::arg<2>,boost::_bi::value<unsigned int>,boost::_bi::value<boost::function<void __cdecl(enum vostok::connection_error_types_enum)> > > > v6; // [esp-30h] [ebp-58h] BYREF
  int v7; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)> v8; // [esp+8h] [ebp-20h] BYREF

  if ( !a2[7].l_.a5_.t_.functor.obj_ptr )
  {
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
      &v5);
    boost::bind<void,vostok::network::login_client_impl,enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>,unsigned int,boost::function<void __cdecl (enum vostok::connection_error_types_enum)> const &,vostok::network::login_client_impl *,boost::arg<1>,boost::arg<2>,unsigned int,boost::function<void __cdecl (enum vostok::connection_error_types_enum)>>(
      (int)&v6,
      a2,
      (void (__thiscall *)(vostok::network::login_client_impl *, vostok::resolve_error_types_enum, boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>, unsigned int, const boost::function<void __cdecl(enum vostok::connection_error_types_enum)> *))*(unsigned __int8 *)&1_203,
      (vostok::network::login_client_impl *)*(unsigned __int8 *)&2_54,
      (int)v5.vtable);
    boost::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)>::function<void __cdecl (enum vostok::resolve_error_types_enum,boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>)>(
      v3,
      (int)&v8,
      v6,
      v7);
    vostok::network::login_client_impl::resolve(
      (vostok::network::login_client_impl *)a2,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&v8,
      (vostok::network::login_client_impl *)6);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&v8);
  }
}
