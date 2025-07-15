void __thiscall survarium::weapon_user_animations_container_cook::on_config_loaded(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::unmanaged_resource *v4; // esi
  const vostok::configs::binary_config_value *v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // edi
  void *v9; // esp
  const vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  const vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  const vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  const vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  const vostok::configs::binary_config_value *v23; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v24; // ecx
  _BYTE v25[28]; // [esp-1Ch] [ebp-98h] BYREF
  _BYTE v26[16]; // [esp+0h] [ebp-7Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_user_animations_container_cook,vostok::resources::queries_result &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::weapon_user_animations_container_cook *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > f; // [esp+10h] [ebp-6Ch] BYREF
  _DWORD v28[10]; // [esp+30h] [ebp-4Ch] BYREF
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+58h] [ebp-24h] BYREF
  survarium::weapon_user_animations_container_cook *v30; // [esp+64h] [ebp-18h]
  const vostok::configs::binary_config_value *v31; // [esp+68h] [ebp-14h]
  const vostok::configs::binary_config_value *cfg; // [esp+6Ch] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v33; // [esp+70h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v34; // [esp+74h] [ebp-8h] BYREF

  v30 = this;
  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v33,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::particle::particle_system_instance_impl *)v33.m_object;
    v34.m_object = 0;
    if ( v33.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
      v34.m_object = m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v33);
    v4 = v34.m_object->m_lods[0].m_template.m_object;
    cfg = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "death_hud");
    v5 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "death");
    v6 = 24 * cfg->count / 24;
    v31 = v5;
    v7 = v6;
    v33.m_object = (survarium::pure_game_effect_emitter_base *)(24 * v5->count / 24);
    v8 = 8 * ((int)&v33.m_object[1].m_construct_thread_id + v6);
    v9 = alloca(v8);
    requests.m_begin = (vostok::resources::request *)v26;
    requests.m_end = (vostok::resources::request *)v26;
    requests.m_max_end = (vostok::resources::request *)&v26[v8];
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(v6, cfg, &requests);
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(
      (unsigned int)v33.m_object,
      v31,
      &requests);
    v10 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "stand_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v10, &requests);
    v11 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "stand");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v11, &requests);
    v12 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v4,
            "aimed_stand_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v12, &requests);
    v13 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "aimed_stand");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v13, &requests);
    v14 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "crouch_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v14, &requests);
    v15 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "crouch");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v15, &requests);
    v16 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v4,
            "aimed_crouch_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v16, &requests);
    v17 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "aimed_crouch");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x1Bu, v17, &requests);
    v18 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "sprint_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(6u, v18, &requests);
    v19 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "sprint");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(6u, v19, &requests);
    v20 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "jump_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x6Cu, v20, &requests);
    v21 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "jump");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(0x6Cu, v21, &requests);
    v22 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "stand_hit_hud");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(8u, v22, &requests);
    v23 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v4, "stand_hit");
    survarium::create_requests_for_animations<vostok::buffer_vector<vostok::resources::request>>(8u, v23, &requests);
    v28[7] = v30;
    v28[1] = 0;
    v28[0] = survarium::weapon_user_animations_container_cook::on_animations_loaded;
    v28[9] = v33.m_object;
    v28[8] = v7;
    v28[2] = v30;
    v28[3] = v7;
    v28[4] = v33.m_object;
    *(_DWORD *)v25 = &f;
    qmemcpy(&v25[4], v28, 0x18u);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::weapon_user_animations_container_cook,vostok::resources::queries_result &,unsigned int,unsigned int>,boost::_bi::list4<boost::_bi::value<survarium::weapon_user_animations_container_cook *>,boost::arg<1>,boost::_bi::value<unsigned int>,boost::_bi::value<unsigned int> > > *)v25,
      *(int *)&v25[24]);
    vostok::resources::query_resources(
      requests.m_begin,
      requests.m_end - requests.m_begin,
      survarium::g_allocator,
      0,
      (const vostok::variant<32> **)data->m_parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v24,
      (int *)&f);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v34);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
