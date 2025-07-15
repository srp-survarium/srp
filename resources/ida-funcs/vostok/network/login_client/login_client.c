void __thiscall vostok::network::login_client::login_client(
        vostok::network::login_client *this,
        vostok::network::network_world *world)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v3; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::memory::base_allocator *v6; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::login_client>,boost::_bi::list1<boost::_bi::value<vostok::network::login_client *> > > f; // [esp+Ch] [ebp-5Ch]
  void *_Where; // [esp+1Ch] [ebp-4Ch]
  char v10; // [esp+34h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+38h] [ebp-30h] BYREF
  boost::function0<void> v12; // [esp+40h] [ebp-28h] BYREF
  vostok::network::order *v13; // [esp+64h] [ebp-4h]

  v10 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2, &this->m_on_sign_up.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, &this->m_on_sign_in.vtable);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &this->m_on_sign_out.vtable);
  this->m_world = world;
  this->m_client = 0;
  this->m_client_state = signed_out;
  vostok::strings::copy<128>((char (*)[128])this->m_net_client_account_password, s_net_client_account_password_);
  this->m_local_host_ip[0] = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v5);
  _Where = vostok::memory::base_allocator::malloc_impl(v6, 0x28u);
  v13 = (vostok::network::order *)operator new(0x28u, _Where);
  if ( v13 )
  {
    f = (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::login_client>,boost::_bi::list1<boost::_bi::value<vostok::network::login_client *> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::network::login_client::create_client, (vostok::sound::sound_debug_stats *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
      &v12);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::network::login_client>,boost::_bi::list1<boost::_bi::value<vostok::network::login_client *>>>>(
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
}
