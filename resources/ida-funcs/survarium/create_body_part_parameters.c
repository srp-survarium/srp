void __usercall survarium::create_body_part_parameters(
        vostok::memory::stack_allocator *allocator@<eax>,
        const vostok::configs::binary_config_value *part_value,
        survarium::damage_model *model,
        vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base> *damage_group,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *effect)
{
  const char *m_arena_current_position; // ebx
  const vostok::configs::binary_config_value *v7; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  const vostok::configs::binary_config_value *v13; // eax
  float regeneration_speed; // xmm0_4
  char **v15; // eax
  survarium::body_part_parameters *v16; // ecx
  survarium::damage_model *owner; // [esp+2Ch] [ebp-14h]
  float regeneration_timeout; // [esp+34h] [ebp-Ch]
  float regeneration_threshold; // [esp+38h] [ebp-8h]
  int can_be_assigned; // [esp+3Ch] [ebp-4h]

  type_info::raw_name(&survarium::body_part_parameters `RTTI Type Descriptor');
  m_arena_current_position = (const char *)allocator->m_arena_current_position;
  allocator->m_arena_current_position = (void *)(m_arena_current_position + 224);
  if ( m_arena_current_position )
  {
    LOBYTE(owner) = vostok::configs::binary_config_value::operator[](part_value, "can_be_assigned")->data.pointer != 0;
    v7 = vostok::configs::binary_config_value::operator[](part_value, "regeneration_threshold");
    if ( v7->type == 2 )
      pointer = *(float *)&v7->data.pointer;
    else
      pointer = (float)(int)v7->data.pointer;
    can_be_assigned = LODWORD(pointer);
    v9 = vostok::configs::binary_config_value::operator[](part_value, "regeneration_timeout");
    if ( v9->type == 2 )
      v10 = *(float *)&v9->data.pointer;
    else
      v10 = (float)(int)v9->data.pointer;
    regeneration_threshold = v10;
    v11 = vostok::configs::binary_config_value::operator[](part_value, "regeneration_speed");
    if ( v11->type == 2 )
      v12 = *(float *)&v11->data.pointer;
    else
      v12 = (float)(int)v11->data.pointer;
    regeneration_timeout = v12;
    v13 = vostok::configs::binary_config_value::operator[](part_value, "health");
    if ( v13->type == 2 )
      regeneration_speed = *(float *)&v13->data.pointer;
    else
      regeneration_speed = (float)(int)v13->data.pointer;
    v15 = (char **)vostok::configs::binary_config_value::operator[](part_value, "name");
    survarium::body_part_parameters::body_part_parameters(
      v16,
      m_arena_current_position,
      *v15,
      regeneration_speed,
      regeneration_timeout,
      regeneration_threshold,
      can_be_assigned,
      owner,
      (int)model,
      damage_group,
      effect);
  }
}
