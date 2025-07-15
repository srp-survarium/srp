void __thiscall vostok::animation::skeleton_cook::on_sub_resources_loaded(
        vostok::animation::skeleton_cook *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // edi
  vostok::resources::queries_result *m_object; // esi
  vostok::resources::queries_result *v5; // ebx
  int bones_count; // eax
  int v7; // esi
  char *unmanaged_memory; // eax
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v9; // edi
  int v10; // ecx
  char *v11; // edi
  char *v12; // esi
  int v13; // ebx
  void *v14; // esp
  vostok::animation::skeleton_bone **v15; // ecx
  char *v16; // edx
  const char *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  vostok::animation::skeleton_bone **v19; // ebx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  vostok::animation::skeleton_bone *v23; // esi
  int v24; // edx
  survarium::pure_game_effect_emitter_base *v25; // edi
  survarium::pure_game_effect_emitter_base_vtbl *v26; // eax
  survarium::pure_game_effect_emitter_base *v27; // ecx
  vostok::resources::query_result_for_cook *v28; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v29; // [esp-Ch] [ebp-48h] BYREF
  assert_on_fail_bool v30; // [esp-8h] [ebp-44h]
  vostok::resources::cook_base::result_enum v31; // [esp-4h] [ebp-40h]
  _BYTE v32[12]; // [esp+0h] [ebp-3Ch] BYREF
  survarium::pure_game_effect_emitter_base *v33; // [esp+Ch] [ebp-30h]
  int v34; // [esp+10h] [ebp-2Ch]
  unsigned int v35; // [esp+14h] [ebp-28h]
  unsigned int v36; // [esp+18h] [ebp-24h] BYREF
  char *v37; // [esp+1Ch] [ebp-20h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v38; // [esp+20h] [ebp-1Ch]
  int v39; // [esp+24h] [ebp-18h]
  bone_crc_predicate __comp[4]; // [esp+28h] [ebp-14h] BYREF
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> v41; // [esp+2Ch] [ebp-10h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v42; // [esp+30h] [ebp-Ch] BYREF
  vostok::resources::resource_base_vtbl *v43; // [esp+34h] [ebp-8h] BYREF
  unsigned int v44; // [esp+38h] [ebp-4h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)result->m_result;
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)result->m_parent_query;
  v38 = m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v42,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
    m_object = (vostok::resources::queries_result *)v42.m_object;
    v5 = 0;
    result = 0;
    if ( v42.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
      v5 = m_object;
      result = m_object;
      _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v42);
    v44 = 0;
    bones_count = get_bones_count(
                    (const vostok::configs::binary_config_value *)v5->m_queries[0].m_next_for_grm_observer_list,
                    &v44);
    v7 = 28 * bones_count;
    v39 = bones_count;
    unmanaged_memory = (char *)vostok::resources::allocate_unmanaged_memory(28 * bones_count + v44 + 272, "skeleton");
    v33 = (survarium::pure_game_effect_emitter_base *)unmanaged_memory;
    if ( unmanaged_memory )
    {
      v11 = unmanaged_memory + 272;
      v12 = &unmanaged_memory[v7 + 272];
      v37 = v12;
      v36 = 1;
      v43 = v5->m_queries[0].m_next_for_grm_observer_list->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::__vftable;
      add_bone(
        0,
        (vostok::configs::binary_config_value *)(unmanaged_memory + 272),
        0,
        &v36,
        (const vostok::configs::binary_config_value *const *)&v43,
        &v37,
        &v44);
      v13 = v39;
      v14 = alloca(4 * v39);
      v15 = (vostok::animation::skeleton_bone **)v32;
      v42.m_object = (survarium::pure_game_effect_emitter_base *)v32;
      v43 = (vostok::resources::resource_base_vtbl *)v32;
      if ( v11 != v12 )
      {
        v35 = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
        do
        {
          v41.rem_ = v35;
          boost::detail::crc_table_t<32,79764919,1>::init_table();
          v16 = *(char **)v11;
          v17 = *(const char **)v11;
          v34 = *(_DWORD *)v11 + 1;
          boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
            &v41,
            v16,
            (char *)&v17[strlen(v17) + 1 - v34 + (_DWORD)v16]);
          *((_DWORD *)v11 + 5) = ~v41.rem_;
          v18 = (const vostok::configs::binary_config_value *)v43;
          v43 = (vostok::resources::resource_base_vtbl *)((char *)v43 + 4);
          v18->data.pointer = v11;
          v11 += 28;
        }
        while ( v11 != v12 );
        v15 = (vostok::animation::skeleton_bone **)v42.m_object;
      }
      v19 = &v15[v13];
      __comp[0] = 0;
      if ( v15 != v19 )
      {
        v20 = v19 - v15;
        v21 = 0;
        while ( v20 != 1 )
        {
          ++v21;
          v20 >>= 1;
        }
        stlp_std::priv::__introsort_loop<vostok::animation::skeleton_bone * *,vostok::animation::skeleton_bone *,int,bone_crc_predicate>(
          &__comp[1],
          v15,
          v19,
          0,
          2 * v21,
          *(vostok::animation::skeleton_bone ***)__comp);
        stlp_std::priv::__final_insertion_sort<vostok::animation::skeleton_bone * *,bone_crc_predicate>(
          (vostok::animation::skeleton_bone **)v42.m_object,
          v19,
          __comp[0]);
        v15 = (vostok::animation::skeleton_bone **)v42.m_object;
        if ( (vostok::animation::skeleton_bone **)v42.m_object != v19 )
        {
          v22 = 0;
          do
          {
            v23 = *v15;
            v24 = v22 >> 2;
            ++v15;
            v22 += 4;
            v23->m_sorted_by_id_bone_index = v24;
          }
          while ( v15 != v19 );
        }
      }
      v25 = v33;
      vostok::resources::unmanaged_resource::unmanaged_resource(
        (vostok::resources::unmanaged_resource *)v15,
        v33,
        fs_iterator_class);
      v26 = (survarium::pure_game_effect_emitter_base_vtbl *)v39;
      v31 = 272;
      v30 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
      v29.m_object = v27;
      v25->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&vostok::animation::skeleton::`vftable';
      v25[1].__vftable = v26;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        &v29,
        v25);
      v9 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v38;
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        v28,
        v38,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v29.m_object,
        (const vostok::resources::memory_type *)v30,
        v31);
      v31 = result_fail;
      v30 = assert_on_fail_true;
      v29.m_object = (survarium::pure_game_effect_emitter_base *)3;
    }
    else
    {
      v9 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v38;
      v31 = result_fail;
      v10 = 272;
      v30 = assert_on_fail_true;
      v38[81].m_object = (vostok::resources::unmanaged_resource *)&vostok::resources::unmanaged_memory;
      v9[6].m_max_count = 272;
      v29.m_object = (survarium::pure_game_effect_emitter_base *)5;
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v10,
      v9,
      (vostok::resources::cook_base::result_enum)v29.m_object,
      v30,
      v31);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
