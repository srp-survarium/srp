void __thiscall vostok::sound::world_user::remove_sound_scene(
        vostok::sound::world_user *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other)
{
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::resources::unmanaged_resource *v4; // edi
  char *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function0<void> *v7; // ecx
  vostok::memory::base_allocator *v8; // eax
  vostok::resources::unmanaged_resource *v9; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > > v10[2]; // [esp-Ch] [ebp-68h] BYREF
  int v11; // [esp+14h] [ebp-48h]
  vostok::sound::functor_command<vostok::sound::sound_order> *v12; // [esp+18h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > > __that; // [esp+1Ch] [ebp-40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > > result; // [esp+2Ch] [ebp-30h] BYREF
  boost::function<void __cdecl(void)> functor; // [esp+3Ch] [ebp-20h] BYREF

  m_object = scene[71].m_object;
  v4 = 0;
  v11 = 0;
  v5 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
  v12 = (vostok::sound::functor_command<vostok::sound::sound_order> *)((int (__thiscall *)(vostok::resources::unmanaged_resource *, int, char *, const char *, const char *, int))m_object->decrease_quality)(
                                                                        m_object,
                                                                        48,
                                                                        v5,
                                                                        "vostok::sound::world_user::remove_sound_scene",
                                                                        ".\\world_user.cpp",
                                                                        178);
  if ( v12 )
  {
    v10[0].l_.a2_.t_.m_object = 0;
    v10[0].l_.a1_.t_ = (vostok::sound::sound_world *)vostok::sound::sound_world::remove_sound_scene_impl;
    HIDWORD(v10[0].f_.f_) = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v10[0].f_.f_
    + 1,
      other);
    LODWORD(v10[0].f_.f_) = scene[70];
    boost::bind<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::sound::sound_world *,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
      &result,
      v10[0].f_.f_,
      v10[0].l_.a1_.t_,
      v10[0].l_.a2_.t_);
    boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>(
      &result,
      &__that);
    functor.vtable = 0;
    boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>(
      &__that,
      v10);
    boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>>(
      v7,
      (int)&functor,
      v10[0]);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a2_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a2_);
    v8 = (vostok::memory::base_allocator *)scene[71].m_object;
    v11 = 1;
    vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
      v12,
      v8,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&functor);
    v4 = v9;
  }
  if ( (v11 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&functor);
  v4->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
  _InterlockedExchange(&scene[34].m_object->m_flags.m_flags, (__int32)v4);
  scene[34].m_object = v4;
}
