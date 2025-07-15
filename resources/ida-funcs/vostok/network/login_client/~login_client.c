void __thiscall vostok::network::login_client::~login_client(vostok::network::login_client *this)
{
  vostok::memory::base_allocator *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  survarium::game_camera *v5; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::login_client_impl *),boost::_bi::list1<boost::_bi::value<vostok::network::login_client_impl *> > > f; // [esp+Ch] [ebp-50h]
  void *_Where; // [esp+14h] [ebp-48h]
  vostok::network::network_world *m_world; // [esp+1Ch] [ebp-40h]
  char v10; // [esp+28h] [ebp-34h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::tcp_packet_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > result; // [esp+2Ch] [ebp-30h] BYREF
  boost::function0<void> v12; // [esp+34h] [ebp-28h] BYREF
  vostok::network::order *v13; // [esp+58h] [ebp-4h]

  v10 = 0;
  m_world = this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_world->m_channel.orders.m_owner_allocator);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x28u);
  v13 = (vostok::network::order *)operator new(0x28u, _Where);
  if ( v13 )
  {
    f = (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network::login_client_impl *),boost::_bi::list1<boost::_bi::value<vostok::network::login_client_impl *> > >)*boost::bind<void,vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &,vostok::network::match_client_impl * *,boost::arg<1>>((boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *> > > *)&result, (void (__cdecl *)(vostok::network_core::tcp_packet_client *))destroy_client, (vostok::network_core::tcp_packet_client *)this->m_client);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_,
      &v12);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::network::login_client_impl *),boost::_bi::list1<boost::_bi::value<vostok::network::login_client_impl *>>>>(
      &v12,
      f);
    v10 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v13->next_for_orders);
    v13->__vftable = (vostok::network::order_vtbl *)&vostok::network::order::`vftable';
    v13->__vftable = (vostok::network::order_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v13[1],
      (const boost::function<void __cdecl(void)> *)&v12);
    vostok::network::network_world::add_order(this->m_world, v13);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v10 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v12);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&this->m_on_sign_out);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v3,
    (int *)&this->m_on_sign_in);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (int *)&this->m_on_sign_up);
  survarium::weapon_user_dead_state::finalize(v5);
}
