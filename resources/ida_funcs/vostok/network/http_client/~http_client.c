void __thiscall vostok::network::http_client::~http_client(vostok::network::http_client *this)
{
  vostok::memory::base_allocator *v1; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v2; // ecx
  survarium::game_camera *v3; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *> > > f; // [esp+Ch] [ebp-50h]
  void *_Where; // [esp+14h] [ebp-48h]
  survarium::game_camera *m_world; // [esp+1Ch] [ebp-40h]
  char v8; // [esp+28h] [ebp-34h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::tcp_packet_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::tcp_packet_client *> > > result; // [esp+2Ch] [ebp-30h] BYREF
  boost::function0<void> v10; // [esp+34h] [ebp-28h] BYREF
  vostok::network::response *v11; // [esp+58h] [ebp-4h]

  v8 = 0;
  this->m_busy = 1;
  m_world = (survarium::game_camera *)this->m_world;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(m_world);
  _Where = vostok::memory::base_allocator::malloc_impl(v1, 0x28u);
  v11 = (vostok::network::response *)operator new(0x28u, _Where);
  if ( v11 )
  {
    f = *boost::bind<void,vostok::network::match_client_impl * *,vostok::network_core::udp_match_packet &,vostok::network::match_client_impl * *,boost::arg<1>>(
           (boost::_bi::bind_t<void,void (__cdecl*)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *> > > *)&result,
           (void (__cdecl *)(vostok::network_core::tcp_packet_client *))vostok::network::destroy_http_client,
           (vostok::network_core::tcp_packet_client *)this->m_client);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_,
      &v10);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::network_core::http_client *),boost::_bi::list1<boost::_bi::value<vostok::network_core::http_client *>>>>(
      &v10,
      f);
    v8 = 1;
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v11->next_for_responses);
    v11->__vftable = (vostok::network::response_vtbl *)&vostok::network::order::`vftable';
    v11->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_order::`vftable';
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)&v11[1],
      (const boost::function<void __cdecl(void)> *)&v10);
    vostok::network::network_world::add_order(this->m_world, v11);
  }
  else
  {
    vostok::network::network_world::add_order(this->m_world, 0);
  }
  if ( (v8 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v10);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_client_on_error);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_on_error);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (int *)&this->m_on_content_downloaded);
  survarium::weapon_user_dead_state::finalize(v3);
}
