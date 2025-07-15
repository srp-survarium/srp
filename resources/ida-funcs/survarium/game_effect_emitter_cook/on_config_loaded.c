void __thiscall survarium::game_effect_emitter_cook::on_config_loaded(
        survarium::game_effect_emitter_cook *this,
        vostok::resources::queries_result *data)
{
  const vostok::variant<32> **m_parent_query; // ebx
  volatile int m_result; // ecx
  survarium::pure_game_effect_emitter_base *v4; // ecx
  vostok::resources::query_result_for_cook *v5; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v7; // ebx
  vostok::configs::binary_config_value *v8; // eax
  const void *pointer; // eax
  vostok::configs::binary_config_value *v10; // ebx
  vostok::variant<32> *v11; // ecx
  boost::function1<void,vostok::resources::queries_result &> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::variant<32> *v14; // ecx
  _BYTE v15[20]; // [esp-14h] [ebp-B4h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+10h] [ebp-90h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp+14h] [ebp-8Ch] BYREF
  vostok::resources::memory_usage_type v18; // [esp+18h] [ebp-88h] BYREF
  const vostok::variant<32> **v19; // [esp+24h] [ebp-7Ch]
  const vostok::configs::binary_config_value *v20; // [esp+28h] [ebp-78h] BYREF
  survarium::game_effect_emitter_cook *f; // [esp+2Ch] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > f_4; // [esp+30h] [ebp-70h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > result; // [esp+40h] [ebp-60h] BYREF
  int v24[8]; // [esp+50h] [ebp-50h] BYREF
  vostok::variant<32> v25; // [esp+70h] [ebp-30h] BYREF

  m_parent_query = (const vostok::variant<32> **)data->m_parent_query;
  f = this;
  m_result = data->m_result;
  v19 = m_parent_query;
  if ( m_result == 1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v17,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v17.m_object;
    v7 = 0;
    v16.m_object = 0;
    if ( v17.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
      v7 = m_object;
      v16.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v17);
    v8 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)v7->m_lods[0].m_template.m_object,
           "effect");
    pointer = vostok::configs::binary_config_value::operator[](v8, "type")->data.pointer;
    v25.m_helper = 0;
    v25.m_type_id = 0;
    v10 = (vostok::configs::binary_config_value *)v7->m_lods[0].m_template.m_object;
    v18 = (vostok::resources::memory_usage_type)(int)pointer;
    v20 = vostok::configs::binary_config_value::operator[](v10, "effect");
    vostok::variant<32>::set<vostok::configs::binary_config_value const *>(v11, &v25, &v20);
    *(_DWORD *)&v15[16] = 0;
    *(_DWORD *)&v15[12] = survarium::game_effect_emitter_cook::on_effect_loaded;
    *(_DWORD *)&v15[8] = 0;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15[8],
      &v16);
    *(_DWORD *)&v15[4] = (unsigned __int8)1_137;
    *(_DWORD *)v15 = f;
    boost::bind<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::animation::skeleton_animation_scene_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &result,
      *(void (__thiscall *__ptr64 *)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *))v15,
      *(survarium::rifle_scope_cook **)&v15[8],
      *(vostok::particle::particle_system_instance_impl **)&v15[12],
      *(vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&v15[16]);
    boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &result,
      &f_4);
    v24[0] = 0;
    boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>::bind_t<void,boost::_mfi::mf2<void,vostok::animation::skeleton_animation_scene_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::animation::skeleton_animation_scene_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>(
      &f_4,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v15[4]);
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::game_effect_emitter_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::game_effect_emitter_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>>>>(
      v12,
      (int)v24,
      *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v15[4]);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&f_4.l_.a3_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
    vostok::resources::query_resource(
      uri,
      (vostok::variant<32> *)v18.type,
      survarium::g_allocator,
      &v25,
      v19,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v13, v24);
    vostok::variant<32>::destroy_previous_variable_if_needed(v14, (int)&v25);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v16);
  }
  else
  {
    v18.size = 0;
    *(_DWORD *)&v15[16] = m_result;
    v18.type = &vostok::resources::nocache_memory;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v15[16],
      0);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      &v18,
      v4,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_parent_query,
      *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v15[16]);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
