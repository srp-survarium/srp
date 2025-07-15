void __thiscall survarium::items_dictionary_cook::on_subresources_loaded(
        survarium::items_dictionary_cook *this,
        vostok::resources::queries_result *data,
        survarium::pure_game_effect_emitter_base *cooked_resource)
{
  vostok::particle::particle_system_instance_impl *m_object; // edi
  survarium::pure_game_effect_emitter_base *v4; // ecx
  unsigned int v5; // eax
  vostok::particle::particle_system_instance_impl *v6; // esi
  vostok::particle::particle_system_instance_impl *v7; // ebx
  int v8; // esi
  vostok::configs::binary_config_value **m_lods; // ebx
  vostok::particle::particle_system_instance_impl *v10; // eax
  vostok::configs::binary_config_value *v11; // ebx
  survarium::dictionary_item *v12; // ecx
  const void *pointer; // ebx
  const vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // ecx
  float v16; // xmm0_4
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  vostok::configs::binary_config_value *v19; // ecx
  char v20; // al
  float *v21; // ebx
  char **v22; // edi
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  vostok::configs::binary_config_value *v25; // ebx
  vostok::configs::binary_config_value *v26; // ecx
  const void *v27; // eax
  const void *v28; // eax
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v29; // edi
  survarium::pure_game_effect_emitter_base *v30; // ecx
  vostok::resources::query_result_for_cook *v31; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v32; // [esp-4h] [ebp-3Ch] BYREF
  vostok::resources::memory_usage_type v33; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::resources::query_result_for_cook *m_parent_query; // [esp+14h] [ebp-24h]
  float v35; // [esp+18h] [ebp-20h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v36; // [esp+1Ch] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v37; // [esp+20h] [ebp-18h] BYREF
  int v38; // [esp+24h] [ebp-14h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other; // [esp+28h] [ebp-10h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v40; // [esp+2Ch] [ebp-Ch] BYREF
  vostok::configs::binary_config_value *v41; // [esp+30h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v42; // [esp+34h] [ebp-4h] BYREF

  m_parent_query = data->m_parent_query;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v37,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v37.m_object;
  v42.m_object = 0;
  if ( v37.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v42);
    v42.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v42,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&cooked_resource[1]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v42);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v37);
  v5 = data->m_size - 1;
  v37.m_object = 0;
  if ( v5 )
  {
    v38 = 0;
    other = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource;
    do
    {
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v36,
        other);
      v6 = (vostok::particle::particle_system_instance_impl *)v36.m_object;
      v7 = 0;
      v40.m_object = 0;
      if ( v36.m_object )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v40);
        v7 = v6;
        v40.m_object = v6;
        _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v36);
      v8 = v38 + LODWORD(cooked_resource[1].m_reconstruction_info_actuality_tick);
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v40,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(v8 + 4));
      m_lods = (vostok::configs::binary_config_value **)v7->m_lods;
      v10 = (vostok::particle::particle_system_instance_impl *)vostok::configs::binary_config_value::operator[](
                                                                 *m_lods,
                                                                 "parameters");
      v11 = *m_lods;
      v42.m_object = v10;
      v41 = vostok::configs::binary_config_value::operator[](v11, "ui_desc");
      if ( survarium::dictionary_item::is_ammo(v12, v8) )
      {
        pointer = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)v42.m_object,
                    "clip_size")->data.pointer;
        v14 = vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)v42.m_object,
                "clip_weight");
        if ( v14->type == 2 )
          v16 = *(float *)&v14->data.pointer;
        else
          v16 = (float)(int)v14->data.pointer;
        v33.size = (unsigned int)pointer;
        v35 = v16;
        *(float *)(v8 + 364) = v16 / (double)(unsigned int)pointer;
      }
      else
      {
        v17 = vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)v42.m_object,
                "weight");
        if ( v17->type == 2 )
          v18 = *(float *)&v17->data.pointer;
        else
          v18 = (float)(int)v17->data.pointer;
        *(float *)(v8 + 364) = v18;
      }
      if ( vostok::configs::binary_config_value::value_exists(v15, (int)v41, (unsigned int)"combat_log_icon") )
        v20 = (char)vostok::configs::binary_config_value::operator[](v41, "combat_log_icon")->data.pointer;
      else
        v20 = 0;
      v41 = 0;
      *(_BYTE *)(v8 + 281) = v20;
      v21 = (float *)(v8 + 284);
      do
      {
        v22 = (char **)((char *)modifier_config_names + (_DWORD)v41);
        if ( vostok::configs::binary_config_value::value_exists(
               v19,
               (int)v42.m_object,
               *(unsigned int *)((char *)modifier_config_names + (_DWORD)v41)) )
        {
          v23 = vostok::configs::binary_config_value::operator[](
                  (vostok::configs::binary_config_value *)v42.m_object,
                  *v22);
          if ( v23->type == 2 )
            v24 = *(float *)&v23->data.pointer;
          else
            v24 = (float)(int)v23->data.pointer;
        }
        else
        {
          v24 = 0.0;
        }
        v41 = (vostok::configs::binary_config_value *)((char *)v41 + 4);
        *v21++ = v24;
      }
      while ( (unsigned int)v41 < 0x50 );
      v25 = (vostok::configs::binary_config_value *)v42.m_object;
      if ( vostok::configs::binary_config_value::value_exists(v19, (int)v42.m_object, (unsigned int)"faction") )
        v27 = vostok::configs::binary_config_value::operator[](v25, "faction")->data.pointer;
      else
        v27 = 0;
      *(_DWORD *)(v8 + 368) = v27;
      if ( vostok::configs::binary_config_value::value_exists(v26, (int)v25, (unsigned int)"faction_affinity") )
        v28 = vostok::configs::binary_config_value::operator[](v25, "faction_affinity")->data.pointer;
      else
        v28 = 0;
      *(_DWORD *)(v8 + 372) = v28;
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v40);
      ++v37.m_object;
      other += 184;
      v38 += 380;
    }
    while ( (unsigned int)v37.m_object < data->m_size - 1 );
  }
  v32.m_object = v4;
  v33.type = &vostok::resources::nocache_memory;
  v33.size = 792;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v32,
    cooked_resource);
  v29 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    &v33,
    v30,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_parent_query,
    v32);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v31,
    v29,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
