void __cdecl vostok::animation::skeleton_animation_cook::on_bi_spline_animation_arrived(
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *v1; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::animation::bi_spline_skeleton_animation_baked *v3; // ecx
  vostok::animation::bi_spline_skeleton_animation_baked *v4; // ecx
  boost::function1<void,vostok::resources::queries_result &> *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  vostok::const_buffer v7; // [esp-18h] [ebp-60h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> > > > v8; // [esp-8h] [ebp-50h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+10h] [ebp-38h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v10; // [esp+14h] [ebp-34h] BYREF
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> > > > v11; // [esp+18h] [ebp-30h] BYREF
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> > > > resulta; // [esp+20h] [ebp-28h] BYREF
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base> > > > v13[4]; // [esp+28h] [ebp-20h] BYREF

  if ( result->m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v10,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v10.m_object;
    v9.m_object = 0;
    if ( v10.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
      v9.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
    v8.l_.a2_.t_.m_object = v3;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8.l_,
      &v9);
    boost::bind<void,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>,boost::arg<1>,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resulta,
      (void (__cdecl *)(vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>))*(unsigned __int8 *)&1_223,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v8.l_.a2_.t_.m_object);
    boost::_bi::storage2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>>::storage2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>>(
      &resulta,
      &v11);
    v13[0].f_ = 0;
    v8.l_.a2_.t_.m_object = v4;
    v8.f_ = (void (__cdecl *)(vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>))v4;
    boost::_bi::storage2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>>::storage2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>>(
      &v11,
      &v8);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::animation::bi_spline_skeleton_animation_baked,vostok::resources::unmanaged_intrusive_base>>>>>(
      v5,
      v13,
      v8);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.l_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resulta.l_);
    v7.m_size = (unsigned int)&vostok::memory::g_resources_helper_allocator;
    v7.m_data = (const char *)49;
    vostok::resources::query_create_resource(
      uri,
      v7,
      0,
      (const vostok::variant<32> **)result->m_parent_query,
      (const vostok::variant<32> *)v9.m_object,
      (vostok::resources::query_result_for_cook *)4);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)v13);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v1,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)result->m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
