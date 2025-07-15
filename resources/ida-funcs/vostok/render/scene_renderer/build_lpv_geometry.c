void __thiscall vostok::render::scene_renderer::build_lpv_geometry(
        vostok::render::scene_renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other)
{
  boost::function<void __cdecl(void)> *v3; // ecx
  vostok::memory::base_allocator *m_object; // ecx
  vostok::render::base_command *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-10h] [ebp-68h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> > > > v8; // [esp-Ch] [ebp-64h] BYREF
  int v9; // [esp+0h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> > > > *result; // [esp+10h] [ebp-48h]
  vostok::render::functor_command *v11; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> on_execute; // [esp+38h] [ebp-20h] BYREF

  result = 0;
  v11 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                             (vostok::memory::base_allocator *)scene[2].m_object,
                                             "vostok::render::scene_renderer::build_lpv_geometry",
                                             (const char *const)0x3F5);
  if ( v11 )
  {
    v7.m_object = (vostok::particle::particle_system_instance_impl *)v8.l_.a2_.t_.m_object;
    result = &v8;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v7,
      other);
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>(
      result,
      (void (__thiscall *)(vostok::render::engine::world *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *))scene->m_object,
      (vostok::render::engine::world *)v7.m_object);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v3, (int)&on_execute, v8, v9);
    m_object = (vostok::memory::base_allocator *)scene[2].m_object;
    on_defer_execution.vtable = 0;
    result = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> > > > *)3;
    vostok::render::functor_command::functor_command(
      v11,
      m_object,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_execute);
  }
  else
  {
    v5 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    (vostok::render::one_way_render_channel *)scene[1].m_object,
    v5);
  if ( ((unsigned __int8)result & 2) != 0 )
  {
    result = (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> > > > *)((unsigned int)result & 0xFFFFFFFD);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&on_defer_execution);
  }
  if ( ((unsigned __int8)result & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&on_execute);
}
