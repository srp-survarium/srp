void __userpurge survarium::project_cooker_simple::on_game_effects_loaded(
        survarium::project_cooker_simple *this@<ecx>,
        survarium::simple_game_project *project,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> > > data)
{
  vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *M_start; // ebx
  survarium::pure_game_effect_emitter_base *m_object; // esi
  vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *M_finish; // esi
  survarium::pure_game_effect_emitter_base *v7; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v8; // eax
  vostok::resources::query_result_for_cook *v9; // ecx
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-Ch] [ebp-24h] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-20h]
  unsigned int v13; // [esp-4h] [ebp-1Ch]
  unsigned int v14; // [esp+0h] [ebp-18h]
  bool v15; // [esp+4h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp+Ch] [ebp-Ch] BYREF
  survarium::post_process_game_effect_emitter *v17; // [esp+10h] [ebp-8h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other; // [esp+14h] [ebp-4h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v19; // [esp+20h] [ebp+8h]

  v17 = 0;
  M_start = data._M_start;
  if ( data._M_start[14].m_object )
  {
    other = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data._M_start[75];
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v16,
        other);
      m_object = v16.m_object;
      data._M_start = 0;
      if ( v16.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
        data._M_start = (vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *)m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
      M_finish = (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)project->m_game_effects._M_impl._M_finish;
      if ( M_finish == (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)project->m_game_effects._M_impl._M_end_of_storage._M_data )
      {
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::post_process_game_effect_emitter,vostok::resources::unmanaged_intrusive_base>>>::_M_insert_overflow_aux(
          &data,
          (int)&project->m_game_effects,
          M_finish,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
          v14,
          v15);
      }
      else
      {
        if ( M_finish )
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)M_finish,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
        ++project->m_game_effects._M_impl._M_finish;
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
      v17 = (survarium::post_process_game_effect_emitter *)((char *)v17 + 1);
      other += 184;
    }
    while ( v17 < M_start[14].m_object );
  }
  project->m_loaded.game_effects_loaded = 1;
  if ( survarium::simple_game_project::all_loaded((survarium::simple_game_project *)this, (int)project) )
  {
    v8 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)M_start[8].m_object;
    v13 = 488;
    v12 = &vostok::resources::nocache_memory;
    v11.m_object = v7;
    v19 = v8;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v11,
      (survarium::pure_game_effect_emitter_base *)&project->vostok::resources::unmanaged_resource);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v9,
      v19,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.m_object,
      v12,
      v13);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v10,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)M_start[8].m_object,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
}
