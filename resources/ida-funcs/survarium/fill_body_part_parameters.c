void __usercall survarium::fill_body_part_parameters(
        survarium::body_part_parameters *body_part@<esi>,
        survarium::damage_model *const model,
        vostok::memory::stack_allocator *allocator,
        const vostok::configs::binary_config_value *part_value,
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *const threshold_emitters,
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *const hit_emitters)
{
  unsigned int v6; // ebx
  vostok::configs::binary_config_value *v7; // ecx
  char **v8; // edi
  const vostok::configs::binary_config_value *v9; // edi
  vostok::configs::binary_config_value *v10; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // eax
  survarium::hit_type_parameters *hit_type_parameters; // edi
  const vostok::configs::binary_config_value *v13; // eax
  const vostok::configs::binary_config_value *pointer; // ebx
  int v15; // edi
  survarium::affects_threshold *threshold; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+Ch] [ebp-10h] BYREF
  vostok::configs::binary_config_value *v18; // [esp+10h] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]

  v6 = 0;
  v20 = 0;
  v18 = vostok::configs::binary_config_value::operator[](part_value, "hit_types");
  v19 = hit_emitters;
  do
  {
    v8 = (char **)&hit_type_names_37[v6];
    if ( vostok::configs::binary_config_value::value_exists(v7, (int)v18, (unsigned int)*v8) )
    {
      v9 = vostok::configs::binary_config_value::operator[](v18, *v8);
      if ( vostok::configs::binary_config_value::value_exists(v10, (int)v9, (unsigned int)"effect") )
      {
        v11 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v19++;
      }
      else
      {
        v20 |= 1u;
        v17.m_object = 0;
        v11 = &v17;
      }
      hit_type_parameters = survarium::create_hit_type_parameters(
                              model,
                              allocator,
                              (vostok::particle::particle_system_instance_impl *)v6,
                              v9,
                              v11);
      if ( (v20 & 1) != 0 )
      {
        v20 &= ~1u;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
      }
      hit_type_parameters->next = 0;
      ++body_part->m_hit_types.m_size;
      if ( body_part->m_hit_types.m_first )
        body_part->m_hit_types.m_last->next = hit_type_parameters;
      else
        body_part->m_hit_types.m_first = hit_type_parameters;
      body_part->m_hit_types.m_last = hit_type_parameters;
    }
    ++v6;
  }
  while ( v6 < 8 );
  v13 = vostok::configs::binary_config_value::operator[](part_value, "thresholds");
  pointer = (const vostok::configs::binary_config_value *)v13->data.pointer;
  v15 = (int)v13->data.pointer + 24 * v13->count;
  while ( pointer != (const vostok::configs::binary_config_value *)v15 )
  {
    threshold = (survarium::affects_threshold *)survarium::create_threshold(allocator, pointer, threshold_emitters);
    threshold->next = 0;
    ++body_part->m_thresholds.m_size;
    if ( body_part->m_thresholds.m_first )
      body_part->m_thresholds.m_last->next = threshold;
    else
      body_part->m_thresholds.m_first = threshold;
    body_part->m_thresholds.m_last = threshold;
    ++pointer;
  }
}
