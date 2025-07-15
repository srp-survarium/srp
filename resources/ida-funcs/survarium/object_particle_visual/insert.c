void __thiscall survarium::object_particle_visual::insert(survarium::object_particle_visual *this)
{
  survarium::scheduler::record *v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::object_particle_visual,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::object_particle_visual *>,boost::arg<1>,boost::arg<2> > > v4; // [esp-14h] [ebp-4Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // [esp-4h] [ebp-3Ch]
  bool v6; // [esp+0h] [ebp-38h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+10h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+14h] [ebp-24h] BYREF
  boost::function<void __cdecl(unsigned int,unsigned int)> f; // [esp+18h] [ebp-20h] BYREF

  v8.m_object = 0;
  v7.m_object = 0;
  v5 = &v8;
  *((_DWORD *)&v4.l_ + 1) = &v7;
  v4.l_.a1_.t_ = (survarium::object_particle_visual *)&this->m_transform;
  HIDWORD(v4.f_.f_) = &this->m_transform;
  LODWORD(v4.f_.f_) = this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v4,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_system_instance_ptr);
  vostok::render::scene_renderer::play_particle_system(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    (const vostok::math::float4x4 *)v4.f_.f_,
    (const vostok::math::float4x4 *)HIDWORD(v4.f_.f_),
    (vostok::math::float4x4 *)v4.l_.a1_.t_,
    *((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v4.l_
    + 1),
    v5);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  if ( this->m_track )
  {
    (&f.vtable)[1] = 0;
    f.functor.obj_ptr = this;
    f.vtable = (boost::detail::function::vtable_base *)survarium::object_particle_visual::tick;
    HIDWORD(v4.f_.f_) = survarium::object_particle_visual::tick;
    v4.l_.a1_.t_ = 0;
    *((_DWORD *)&v4.l_ + 1) = this;
    LODWORD(v4.f_.f_) = &f;
    boost::function<void __cdecl (unsigned int,unsigned int)>::function<void __cdecl (unsigned int,unsigned int)>(
      0,
      v4,
      (int)f.functor.vostok_pointer_size_alignment[1]);
    v2 = survarium::scheduler::register_object(
           (survarium::scheduler *)&f,
           (int)&this->m_game_scene->m_scheduler,
           &this->m_scheduler_identifier,
           &f,
           v6);
    v2->m_max_update_count = 0;
    v2->m_last_update_time = 0;
    *(_DWORD *)&v2->survarium::scheduler::scheduler_record = 0x7FFFFFFF;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&f);
  }
}
