void __thiscall survarium::game::on_render_output_window_created(
        survarium::game *this,
        vostok::resources::queries_result *data)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v5; // [esp-14h] [ebp-54h]
  const char *v6; // [esp+0h] [ebp-40h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+10h] [ebp-30h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp+14h] [ebp-2Ch] BYREF
  vostok::resources::request v9; // [esp+18h] [ebp-28h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > f; // [esp+20h] [ebp-20h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v8,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v8.m_object;
  v7.m_object = 0;
  if ( v8.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
    v7.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v7,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_output_window);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
  vostok::render::game::renderer::set_render_output_window_title(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_output_window,
    this->m_renderer,
    v6);
  f.l_.a1_.t_ = this;
  LODWORD(f.f_.f_) = survarium::game::on_ui_sounds_cfg_loaded;
  HIDWORD(f.f_.f_) = 0;
  HIDWORD(v5.f_.f_) = survarium::game::on_ui_sounds_cfg_loaded;
  *(_QWORD *)&v5.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v5.f_.f_) = &f;
  v9.path = "resources/gameplay/ui_sounds";
  v9.id = binary_config_class_impl;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    0,
    v5,
    *((int *)&f.l_ + 1));
  vostok::resources::query_resources(&v9, 1u, survarium::g_allocator, 0, 0, assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, (int *)&f);
}
