void __userpurge vostok::sound::world_user::set_active_sound_scene(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene@<eax>,
        vostok::sound::world_user *this)
{
  vostok::memory::base_allocator *m_orders_allocator; // esi
  vostok::resources::unmanaged_resource *m_object; // edi
  char *v4; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  vostok::sound::sound_order *v6; // eax
  vostok::sound::sound_order *v7; // edi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::sound::sound_scene &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::reference_wrapper<vostok::sound::sound_scene> > > v8; // [esp-10h] [ebp-5Ch]
  char v9; // [esp+14h] [ebp-38h]
  vostok::sound::functor_command<vostok::sound::sound_order> *v10; // [esp+18h] [ebp-34h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+2Ch] [ebp-20h] BYREF

  v9 = 0;
  m_orders_allocator = this->m_orders_allocator;
  m_object = scene->m_object;
  v4 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
  v10 = (vostok::sound::functor_command<vostok::sound::sound_order> *)m_orders_allocator->call_malloc(
                                                                        m_orders_allocator,
                                                                        48u,
                                                                        v4,
                                                                        "vostok::sound::world_user::set_active_sound_scene",
                                                                        ".\\world_user.cpp",
                                                                        152u);
  if ( v10 )
  {
    HIDWORD(v8.f_.f_) = vostok::sound::sound_world::set_active_sound_scene_impl;
    v8.l_.a1_.t_ = 0;
    v8.l_.a2_.t_ = (vostok::sound::sound_scene *)this->m_owner_world;
    LODWORD(v8.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function<void __cdecl(void)> *)vostok::sound::sound_world::set_active_sound_scene_impl,
      v8,
      (int)m_object);
    v9 = 1;
    vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
      v10,
      this->m_orders_allocator,
      &f);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v9 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&f);
  v7->m_next_for_orders = 0;
  _InterlockedExchange(
    (volatile __int32 *)&this->m_channel.orders.m_forward_queue.m_head->m_next_for_orders,
    (__int32)v7);
  this->m_channel.orders.m_forward_queue.m_head = v7;
}
