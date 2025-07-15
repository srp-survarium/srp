void __thiscall vostok::render::scene_renderer::set_model_visible(
        vostok::render::scene_renderer *this,
        const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *surface_id,
        unsigned int flags,
        volatile int *a3)
{
  vostok::render::functor_command *v6; // eax
  vostok::render::base_scene *t; // ecx
  boost::function0<void> *v8; // ecx
  vostok::memory::base_allocator *m_object; // ecx
  vostok::render::base_command *v10; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > v12; // [esp-14h] [ebp-9Ch] BYREF
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+10h] [ebp-78h] BYREF
  boost::function<void __cdecl(void)> on_execute; // [esp+30h] [ebp-58h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > result; // [esp+50h] [ebp-38h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::environment_probe_properties const &,long volatile *>,boost::_bi::list5<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1>,boost::_bi::value<long volatile *> > > __that; // [esp+68h] [ebp-20h] BYREF
  vostok::render::functor_command *v17; // [esp+84h] [ebp-4h]
  char v18; // [esp+90h] [ebp+8h]

  v18 = 0;
  v6 = (vostok::render::functor_command *)vostok::memory::new_helper<vostok::render::functor_command>::call<vostok::memory::base_allocator>(
                                            (vostok::memory::base_allocator *)v[2].m_object,
                                            "vostok::render::scene_renderer::set_model_visible",
                                            (const char *const)0x3F0);
  t = (vostok::render::base_scene *)v12.l_.a4_.t_;
  v17 = v6;
  if ( v6 )
  {
    v12.l_.a4_.t_ = (unsigned int)a3;
    v12.l_.a3_.t_ = flags;
    v12.l_.a2_.t_.m_object = (vostok::render::render_model_instance *)t;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12.l_.a2_,
      surface_id);
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>,unsigned int,unsigned int>(
      &result,
      (void (__thiscall *)(vostok::render::engine::world *, const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *, unsigned int, unsigned int))v->m_object,
      (vostok::render::engine::world *)v12.l_.a2_.t_.m_object,
      (vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>)v12.l_.a3_.t_,
      v12.l_.a4_.t_);
    boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>(
      (const boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::environment_probe_properties const &,long volatile *>,boost::_bi::list5<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1>,boost::_bi::value<long volatile *> > > *)&result,
      &__that);
    on_execute.vtable = 0;
    boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>(
      &__that,
      (boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::environment_probe_properties const &,long volatile *>,boost::_bi::list5<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1>,boost::_bi::value<long volatile *> > > *)&v12);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int>>>>(
      v8,
      (int)&on_execute,
      v12);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a2_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a2_);
    m_object = (vostok::memory::base_allocator *)v[2].m_object;
    on_defer_execution.vtable = 0;
    v18 = 3;
    vostok::render::functor_command::functor_command(
      v17,
      m_object,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_defer_execution,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&on_execute);
  }
  else
  {
    v10 = 0;
  }
  vostok::render::one_way_render_channel::owner_push_back((vostok::render::one_way_render_channel *)v[1].m_object, v10);
  if ( (v18 & 2) != 0 )
  {
    v18 &= ~2u;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&on_defer_execution);
  }
  if ( (v18 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v11,
      (int *)&on_execute);
}
