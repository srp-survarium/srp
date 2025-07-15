void __thiscall vostok::sound::sound_instance_proxy_internal::free_object(
        vostok::sound::sound_instance_proxy_internal *this)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  vostok::memory::base_allocator *m_orders_allocator; // esi
  char *v4; // eax
  survarium::pure_game_effect_emitter_base *v5; // ecx
  survarium::pure_game_effect_emitter_base *m_scene; // edi
  __int32 v7; // eax
  vostok::sound::world_user *m_user; // ebx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v9; // [esp+4h] [ebp-34h] BYREF
  vostok::sound::destroy_sound_instance_proxy_order *v10; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void)> v11; // [esp+18h] [ebp-20h] BYREF

  _InterlockedExchange(&this->m_destruction_pending, 1);
  v11.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v11,
    (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_finished_callback);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v11);
  m_orders_allocator = this->m_user->m_orders_allocator;
  v4 = type_info::raw_name(&vostok::sound::destroy_sound_instance_proxy_order `RTTI Type Descriptor');
  v10 = (vostok::sound::destroy_sound_instance_proxy_order *)m_orders_allocator->call_malloc(
                                                               m_orders_allocator,
                                                               32u,
                                                               v4,
                                                               "vostok::sound::sound_instance_proxy_internal::free_object",
                                                               ".\\sound_instance_proxy_internal.cpp",
                                                               227u);
  if ( v10 )
  {
    m_scene = (survarium::pure_game_effect_emitter_base *)this->m_scene;
    v9.m_object = v5;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v9,
      m_scene);
    vostok::sound::destroy_sound_instance_proxy_order::destroy_sound_instance_proxy_order(this->m_user, v10, this, v9);
  }
  else
  {
    v7 = 0;
  }
  m_user = this->m_user;
  *(_DWORD *)(v7 + 8) = 0;
  m_user = (vostok::sound::world_user *)((char *)m_user + 136);
  _InterlockedExchange((volatile __int32 *)&m_user->m_channel.responses.m_forward_queue.m_head->m_next, v7);
  m_user->m_channel.responses.m_forward_queue.m_head = (vostok::sound::sound_response *)v7;
}
