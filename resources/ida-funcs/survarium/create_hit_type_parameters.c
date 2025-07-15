survarium::hit_type_parameters *__cdecl survarium::create_hit_type_parameters(
        survarium::damage_model *const model,
        vostok::memory::stack_allocator *allocator,
        vostok::particle::particle_system_instance_impl *hit_type,
        const vostok::configs::binary_config_value *type_value,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *emitter)
{
  vostok::memory::stack_allocator *v5; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_arena_current_position; // ebx
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  __int64 pointer; // rax
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  __int64 v12; // rax
  bool v13; // al
  const vostok::configs::binary_config_value *v14; // eax
  survarium::damage_model *v15; // ecx
  char **v16; // ebx
  char *v17; // eax
  bool v18; // zf
  float v19; // xmm0_4
  _DWORD v21[6]; // [esp+18h] [ebp-34h] BYREF
  survarium::body_part_parameters *body_part; // [esp+34h] [ebp-18h]
  int v23; // [esp+3Ch] [ebp-10h]
  char **v24; // [esp+40h] [ebp-Ch]
  bool v25; // [esp+47h] [ebp-5h]

  v23 = 24 * vostok::configs::binary_config_value::operator[](type_value, "bdb_coeff")->count / 24;
  type_info::raw_name(&survarium::hit_type_parameters `RTTI Type Descriptor');
  v5 = allocator;
  m_arena_current_position = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)allocator->m_arena_current_position;
  allocator->m_arena_current_position = &m_arena_current_position[8];
  if ( m_arena_current_position )
  {
    v25 = vostok::configs::binary_config_value::operator[](type_value, "invulnerable")->data.pointer != 0;
    v7 = vostok::configs::binary_config_value::operator[](type_value, "reduce");
    if ( v7->type == 2 )
    {
      v8 = *(float *)&v7->data.pointer;
    }
    else
    {
      pointer = (int)v7->data.pointer;
      body_part = (survarium::body_part_parameters *)HIDWORD(pointer);
      v8 = (float)(int)pointer;
    }
    v24 = (char **)LODWORD(v8);
    v10 = vostok::configs::binary_config_value::operator[](type_value, "armor");
    if ( v10->type == 2 )
    {
      v11 = *(float *)&v10->data.pointer;
    }
    else
    {
      v12 = (int)v10->data.pointer;
      body_part = (survarium::body_part_parameters *)HIDWORD(v12);
      v11 = (float)(int)v12;
    }
    m_arena_current_position->m_object = 0;
    m_arena_current_position[1].m_object = hit_type;
    m_arena_current_position[4].m_object = (vostok::particle::particle_system_instance_impl *)v23;
    v13 = v25;
    *(float *)&m_arena_current_position[2].m_object = v11;
    m_arena_current_position[3].m_object = (vostok::particle::particle_system_instance_impl *)v24;
    LOBYTE(m_arena_current_position[5].m_object) = v13;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      m_arena_current_position + 6,
      emitter);
    m_arena_current_position[7].m_object = 0;
    v5 = allocator;
    v23 = (int)m_arena_current_position;
  }
  else
  {
    v23 = 0;
  }
  v24 = (char **)vostok::configs::binary_config_value::operator[](type_value, "bdb_coeff")->data.pointer;
  v14 = vostok::configs::binary_config_value::operator[](type_value, "bdb_coeff");
  v16 = (char **)((char *)v14->data.pointer + 24 * v14->count);
  while ( v24 != v16 )
  {
    body_part = survarium::damage_model::get_body_part(v15, (int)model, v24[2]);
    type_info::raw_name(&stlp_std::pair<survarium::body_part_parameters *,float> `RTTI Type Descriptor');
    v17 = (char *)v5->m_arena_current_position;
    v15 = (survarium::damage_model *)(v17 + 8);
    v5->m_arena_current_position = v17 + 8;
    if ( v17 )
    {
      qmemcpy(v21, v24, sizeof(v21));
      v18 = LOWORD(v21[5]) == 2;
      v15 = (survarium::damage_model *)body_part;
      *(_DWORD *)v17 = body_part;
      if ( v18 )
        v19 = *(float *)v21;
      else
        v19 = (float)v21[0];
      v5 = allocator;
      *((float *)v17 + 1) = v19;
    }
    v24 += 6;
  }
  return (survarium::hit_type_parameters *)v23;
}
