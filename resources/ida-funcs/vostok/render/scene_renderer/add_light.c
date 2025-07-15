void __thiscall vostok::render::scene_renderer::add_light(
        vostok::render::scene_renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *id,
        vostok::render::base_scene *props,
        unsigned int a3)
{
  boost::function<void __cdecl(void)> *v5; // ecx
  vostok::memory::base_allocator *m_object; // ecx
  vostok::render::base_command *v7; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-20h] [ebp-78h] BYREF
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v10; // [esp-1Ch] [ebp-74h]
  unsigned int v11; // [esp-18h] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::environment_probe_properties const &,long volatile *>,boost::_bi::list5<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1>,boost::_bi::value<long volatile *> > > v12; // [esp-14h] [ebp-6Ch] BYREF
  int v13; // [esp+0h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *> > > *result; // [esp+10h] [ebp-48h]
  vostok::render::functor_command *v15; // [esp+14h] [ebp-44h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+18h] [ebp-40h] BYREF
  boost::function<void __cdecl(void)> on_execute; // [esp+38h] [ebp-20h] BYREF

  result = 0;
  v15 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                             (vostok::memory::base_allocator *)scene[2].m_object,
                                             "vostok::render::scene_renderer::add_light",
                                             (const char *const)0x34E);
  if ( v15 )
  {
    v11 = a3;
    result = (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *> > > *)&v12;
    v10.m_object = props;
    v9.m_object = (vostok::particle::particle_system_instance_impl *)v12.l_.a5_.t_;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v9,
      id);
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int,vostok::render::light_props *>(
      result,
      (void (__thiscall *)(vostok::render::engine::world *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, unsigned int, vostok::render::light_props *))scene->m_object,
      (vostok::render::engine::world *)v9.m_object,
      v10,
      v11);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v5, &on_execute, v12, v13);
    m_object = (vostok::memory::base_allocator *)scene[2].m_object;
    on_defer_execution.vtable = 0;
    result = (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *> > > *)3;
    vostok::render::functor_command::functor_command(
      v15,
      m_object,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_execute);
  }
  else
  {
    v7 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back(
    (vostok::render::one_way_render_channel *)scene[1].m_object,
    v7);
  if ( ((unsigned __int8)result & 2) != 0 )
  {
    result = (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *> > > *)((unsigned int)result & 0xFFFFFFFD);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&on_defer_execution);
  }
  if ( ((unsigned __int8)result & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&on_execute);
}
