void __thiscall survarium::project_cooker_simple::on_anomalies_loaded(
        survarium::project_cooker_simple *this,
        survarium::simple_game_project *project,
        vostok::resources::queries_result *data)
{
  vostok::flags_type<enum vostok::resources::unmanaged_resource::flag_enum,vostok::threading::single_threading_policy> *p_m_flags; // esi
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *M_start; // esi
  survarium::base_game_object *v6; // esi
  survarium::base_game_object **v7; // eax
  survarium::base_project *v8; // ecx
  int v9; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // eax
  vostok::resources::query_result_for_cook *v11; // ecx
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::configs::binary_config_value v13; // [esp-18h] [ebp-40h] BYREF
  unsigned int v14; // [esp+0h] [ebp-28h]
  bool v15; // [esp+4h] [ebp-24h]
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> > > v16; // [esp+10h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp+1Ch] [ebp-Ch] BYREF
  survarium::anomaly_cook_data out_value; // [esp+20h] [ebp-8h] BYREF

  v16._M_end_of_storage._M_data = 0;
  if ( data->m_size )
  {
    v16._M_finish = (vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_user_data;
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v17,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v16._M_finish[-11]);
      if ( v17.m_object )
        p_m_flags = &v17.m_object[-1].vostok::resources::unmanaged_resource::m_flags;
      else
        p_m_flags = 0;
      v16._M_start = 0;
      if ( p_m_flags )
      {
        vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
        v16._M_start = (vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *)p_m_flags;
        _InterlockedExchangeAdd((volatile signed __int32 *)&p_m_flags[54], 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v17);
      M_finish = project->m_anomalies._M_impl._M_finish;
      if ( M_finish == project->m_anomalies._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
          &v16,
          (int)&project->m_anomalies,
          M_finish,
          (vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *)&v16,
          v14,
          v15);
      }
      else
      {
        if ( M_finish )
          vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>(
            M_finish,
            (const vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *)&v16);
        ++project->m_anomalies._M_impl._M_finish;
      }
      vostok::variant<32>::try_get<survarium::anomaly_cook_data>(
        (vostok::variant<32> *)v16._M_finish->m_object,
        &out_value);
      qmemcpy((void *)&v13, out_value.config, sizeof(v13));
      M_start = v16._M_start;
      survarium::base_project::register_object_to_resolve(
        (survarium::base_project::resolve_link_object *)v16._M_start,
        project,
        v13);
      if ( M_start )
        v6 = (survarium::base_game_object *)&M_start[74];
      else
        v6 = 0;
      v7 = (survarium::base_game_object **)vostok::configs::binary_config_value::operator[](
                                             out_value.config,
                                             "full_name");
      survarium::base_project::register_named_object(v8, (const char *const *)project, *v7, v6);
      vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
      ++v16._M_end_of_storage._M_data;
      v16._M_finish += 184;
    }
    while ( v16._M_end_of_storage._M_data < (vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> *)data->m_size );
  }
  project->m_loaded.anomalies_loaded = 1;
  if ( survarium::simple_game_project::all_loaded((survarium::simple_game_project *)this, (int)project) )
  {
    m_parent_query = data->m_parent_query;
    *(_DWORD *)&v13.type = 488;
    v13.id_crc = (unsigned int)&vostok::resources::nocache_memory;
    HIDWORD(v13.id.max_storage) = v9;
    v17.m_object = (survarium::pure_game_effect_emitter_base *)m_parent_query;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v13.id.max_storage
    + 1,
      (survarium::pure_game_effect_emitter_base *)&project->vostok::resources::unmanaged_resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v11,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v17.m_object,
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&v13.id.max_storage + 4),
      (const vostok::resources::memory_type *)v13.id_crc,
      *(unsigned int *)&v13.type);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v12,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
