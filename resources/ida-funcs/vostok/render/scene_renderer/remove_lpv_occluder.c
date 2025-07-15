void __thiscall vostok::render::scene_renderer::remove_lpv_occluder(
        vostok::render::scene_renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *id,
        vostok::particle::particle_system_instance_impl *a3)
{
  boost::function<void __cdecl(void)> *v4; // ecx
  vostok::memory::base_allocator *m_object; // ecx
  vostok::render::base_command *v6; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-18h] [ebp-70h] BYREF
  vostok::particle::particle_system_instance_impl *v9; // [esp-14h] [ebp-6Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > v10; // [esp-10h] [ebp-68h] BYREF
  int v11; // [esp+0h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > *result; // [esp+10h] [ebp-48h]
  vostok::render::functor_command *v13; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> on_execute; // [esp+38h] [ebp-20h] BYREF

  result = 0;
  v13 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                             (vostok::memory::base_allocator *)scene[2].m_object,
                                             "vostok::render::scene_renderer::remove_lpv_occluder",
                                             (const char *const)0x232);
  if ( v13 )
  {
    v9 = a3;
    result = &v10;
    v8.m_object = (vostok::particle::particle_system_instance_impl *)v10.l_.a3_.t_;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v8,
      id);
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int>(
      result,
      (void (__thiscall *)(vostok::render::engine::world *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, unsigned int))vostok::render::engine::world::remove_lpv_occluder,
      (vostok::render::engine::world *)scene->m_object,
      v8,
      v9);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v4, &on_execute, v10, v11);
    m_object = (vostok::memory::base_allocator *)scene[2].m_object;
    on_defer_execution.vtable = 0;
    result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > *)3;
    vostok::render::functor_command::functor_command(
      v13,
      m_object,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_execute);
  }
  else
  {
    v6 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    (vostok::render::one_way_render_channel *)scene[1].m_object,
    v6);
  if ( ((unsigned __int8)result & 2) != 0 )
  {
    result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > *)((unsigned int)result & 0xFFFFFFFD);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&on_defer_execution);
  }
  if ( ((unsigned __int8)result & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v7,
      (int *)&on_execute);
}
