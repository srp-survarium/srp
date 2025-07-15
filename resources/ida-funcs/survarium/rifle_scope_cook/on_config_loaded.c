void __thiscall survarium::rifle_scope_cook::on_config_loaded(
        survarium::rifle_scope_cook *this,
        vostok::resources::queries_result *data)
{
  volatile int m_result; // eax
  vostok::particle::particle_system_instance_impl *m_object; // esi
  boost::function1<void,vostok::resources::queries_result &> *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  _BYTE v6[20]; // [esp-14h] [ebp-84h] BYREF
  const char *v7; // [esp+0h] [ebp-70h]
  bool v8; // [esp+13h] [ebp-5Dh] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+14h] [ebp-5Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v10; // [esp+18h] [ebp-58h] BYREF
  survarium::rifle_scope_cook *f; // [esp+1Ch] [ebp-54h]
  void (__thiscall *__ptr64 f_4)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *); // [esp+20h] [ebp-50h] BYREF
  const void *pointer; // [esp+28h] [ebp-48h]
  int v14; // [esp+2Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > __that; // [esp+30h] [ebp-40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > result; // [esp+40h] [ebp-30h] BYREF
  int v17[8]; // [esp+50h] [ebp-20h] BYREF

  m_result = data->m_result;
  f = this;
  if ( m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v10,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v10.m_object;
    v9.m_object = 0;
    if ( v10.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
      v9.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
    v10.m_object = (survarium::pure_game_effect_emitter_base *)vostok::configs::binary_config_value::operator[](
                                                                 (vostok::configs::binary_config_value *)v9.m_object->m_lods[0].m_template.m_object,
                                                                 "data");
    LODWORD(f_4) = vostok::configs::binary_config_value::operator[](
                     (vostok::configs::binary_config_value *)v10.m_object,
                     "idle_model")->data.pointer;
    HIDWORD(f_4) = 16;
    pointer = vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)v10.m_object,
                "aimed_model")->data.pointer;
    *(_DWORD *)&v6[16] = 0;
    *(_DWORD *)&v6[12] = survarium::rifle_scope_cook::on_subresources_loaded;
    *(_DWORD *)&v6[8] = 0;
    v14 = 16;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v6[8],
      &v9);
    *(_DWORD *)&v6[4] = (unsigned __int8)1_93;
    *(_DWORD *)v6 = f;
    boost::bind<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::animation::skeleton_animation_scene_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &result,
      *(void (__thiscall *__ptr64 *)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *))v6,
      *(survarium::rifle_scope_cook **)&v6[8],
      *(vostok::particle::particle_system_instance_impl **)&v6[12],
      *(vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v6[16]);
    boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &result,
      &__that);
    v17[0] = 0;
    boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &__that,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v6[4]);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>(
      v4,
      (int)v17,
      *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v6[4]);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.l_.a3_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
    vostok::resources::query_resources(
      (const vostok::resources::request *)&f_4,
      2u,
      survarium::g_allocator,
      0,
      (const vostok::variant<32> **)data->m_parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v5, v17);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  }
  else
  {
    if ( !debug_macro_helper_ignore_always_40 )
    {
      v8 = 0;
      vostok::debug::on_error(
        &v8,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\rifle_scope_cook.cpp",
        "survarium::rifle_scope_cook::on_config_loaded",
        (const char *)0x26,
        "This cook requires config value as user data.",
        v7);
      if ( vostok::debug::is_debugger_present() || v8 )
        __debugbreak();
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
