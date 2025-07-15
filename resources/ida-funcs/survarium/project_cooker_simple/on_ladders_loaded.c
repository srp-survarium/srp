void __thiscall survarium::project_cooker_simple::on_ladders_loaded(
        survarium::project_cooker_simple *this,
        survarium::simple_game_project *project,
        vostok::resources::queries_result *data)
{
  survarium::pure_game_effect_emitter_base *m_object; // esi
  vostok::configs::binary_config_value *v4; // ecx
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  survarium::ladder *v6; // esi
  vostok::configs::binary_config_value *v7; // eax
  vostok::variant<32> *v8; // ecx
  survarium::base_project::resolve_link_object *v9; // eax
  survarium::base_game_object *v10; // esi
  survarium::base_game_object **v11; // eax
  survarium::base_project *v12; // ecx
  int v13; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // eax
  vostok::resources::query_result_for_cook *v15; // ecx
  vostok::resources::query_result_for_cook *v16; // ecx
  vostok::configs::binary_config_value v17; // [esp-18h] [ebp-50h] BYREF
  unsigned int v18; // [esp+0h] [ebp-38h]
  bool v19; // [esp+4h] [ebp-34h]
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base> > > v20; // [esp+10h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp+1Ch] [ebp-1Ch] BYREF
  vostok::configs::binary_config_value v22; // [esp+20h] [ebp-18h] BYREF

  v20._M_end_of_storage._M_data = 0;
  if ( data->m_size )
  {
    v20._M_finish = (vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_user_data;
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v21,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v20._M_finish[-11]);
      m_object = v21.m_object;
      v20._M_start = 0;
      if ( v21.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
        v20._M_start = (vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base> *)m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21);
      M_finish = (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)project->m_ladders._M_impl._M_finish;
      if ( M_finish == (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)project->m_ladders._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
          &v20,
          (int)&project->m_ladders,
          M_finish,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20,
          v18,
          v19);
      }
      else
      {
        if ( M_finish )
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)M_finish,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
        ++project->m_ladders._M_impl._M_finish;
      }
      v6 = v20._M_finish->m_object;
      vostok::configs::binary_config_value::binary_config_value(v4, (int)&v22);
      vostok::variant<32>::try_get<vostok::configs::binary_config_value>(v8, (int)v6, v7);
      if ( v20._M_start )
        v9 = (survarium::base_project::resolve_link_object *)&v20._M_start[67];
      else
        v9 = 0;
      qmemcpy((void *)&v17, &v22, sizeof(v17));
      survarium::base_project::register_object_to_resolve(v9, project, v17);
      if ( v20._M_start )
        v10 = (survarium::base_game_object *)&v20._M_start[67];
      else
        v10 = 0;
      v11 = (survarium::base_game_object **)vostok::configs::binary_config_value::operator[](&v22, "full_name");
      survarium::base_project::register_named_object(v12, (const char *const *)project, *v11, v10);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v20);
      ++v20._M_end_of_storage._M_data;
      v20._M_finish += 184;
    }
    while ( v20._M_end_of_storage._M_data < (vostok::resources::resource_ptr<survarium::ladder,vostok::resources::unmanaged_intrusive_base> *)data->m_size );
  }
  project->m_loaded.ladders_loaded = 1;
  if ( survarium::simple_game_project::all_loaded((survarium::simple_game_project *)this, (int)project) )
  {
    m_parent_query = data->m_parent_query;
    *(_DWORD *)&v17.type = 488;
    v17.id_crc = (unsigned int)&vostok::resources::nocache_memory;
    HIDWORD(v17.id.max_storage) = v13;
    v21.m_object = (survarium::pure_game_effect_emitter_base *)m_parent_query;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v17.id.max_storage
    + 1,
      (survarium::pure_game_effect_emitter_base *)&project->vostok::resources::unmanaged_resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v15,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v21.m_object,
      *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&v17.id.max_storage + 4),
      (const vostok::resources::memory_type *)v17.id_crc,
      *(unsigned int *)&v17.type);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v16,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
