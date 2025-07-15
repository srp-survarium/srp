void __thiscall vostok::network::tcp_packet_client::connect(
        vostok::network::tcp_packet_client *this,
        char *host,
        unsigned __int16 port)
{
  vostok::memory::base_allocator *v3; // eax
  vostok::network::response *v4; // eax
  vostok::network::network_world *v6; // [esp+14h] [ebp-6Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client,char const *,unsigned short,char const *,char const *>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client *>,boost::arg<1>,boost::_bi::value<unsigned short>,boost::arg<2>,boost::arg<3> > > v7; // [esp+20h] [ebp-60h]
  void *_Where; // [esp+34h] [ebp-4Ch]
  vostok::network::network_world *m_world; // [esp+3Ch] [ebp-44h]
  char v10; // [esp+48h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,char const *,unsigned short>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::_bi::value<unsigned short> > > result; // [esp+4Ch] [ebp-34h] BYREF
  boost::function1<void,char const *> v12; // [esp+58h] [ebp-28h] BYREF
  vostok::network::string_order *v13; // [esp+7Ch] [ebp-4h]

  v10 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v3, 0x78u);
  v13 = (vostok::network::string_order *)operator new(0x78u, _Where);
  if ( v13 )
  {
    v7 = *boost::bind<void,vostok::network::login_client,char const *,unsigned short,char const *,char const *,vostok::network::login_client *,boost::arg<1>,unsigned short,boost::arg<2>,boost::arg<3>>(
            (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::network::login_client,char const *,unsigned short,char const *,char const *>,boost::_bi::list5<boost::_bi::value<vostok::network::login_client *>,boost::arg<1>,boost::_bi::value<unsigned short>,boost::arg<2>,boost::arg<3> > > *)&result,
            vostok::network::tcp_packet_client::connect_impl,
            (vostok::network::login_client *)this,
            1_243,
            port);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v7.f_.f_,
      &v12);
    boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,char const *,unsigned short>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::_bi::value<unsigned short>>>>(
      &v12,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::tcp_packet_client,char const *,unsigned short>,boost::_bi::list3<boost::_bi::value<vostok::network::tcp_packet_client *>,boost::arg<1>,boost::_bi::value<unsigned short> > >)v7);
    v10 = 1;
    v6 = this->m_world;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
    vostok::network::string_order::string_order(
      v13,
      v6->m_channel.orders.m_owner_allocator,
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)&v12,
      host);
    vostok::network::network_world::add_order(this->m_world, v4);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v10 & 1) != 0 )
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v10 & 1),
      (int *)&v12);
}
