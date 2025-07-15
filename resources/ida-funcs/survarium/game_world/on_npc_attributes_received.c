void __userpurge survarium::game_world::on_npc_attributes_received(
        vostok::configs::binary_config_value *attributes_config@<eax>,
        survarium::human_npc::npc_game_attributes *a2@<ecx>,
        survarium::game_world *this,
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> owner)
{
  const vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  char *v10; // eax
  char *i; // ecx
  const vostok::configs::binary_config_value *v12; // eax
  float *v13; // eoff
  char *v14; // eax
  char *j; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // edi
  const void *v18; // ebp
  const void *v19; // ebx
  _DWORD *v20; // esi
  const char *v21; // eax
  survarium::object_weapon *v22; // ecx
  survarium::object_weapon *v23; // eax
  survarium::object_weapon *v24; // esi
  survarium::human_npc *v25; // ecx
  survarium::human_npc *m_object; // ecx
  bool *v27; // [esp-4h] [ebp-100h]
  unsigned int v28; // [esp+0h] [ebp-FCh]
  int it_end; // [esp+18h] [ebp-E4h]
  survarium::human_npc::npc_game_attributes attributes; // [esp+30h] [ebp-CCh] BYREF

  survarium::human_npc::npc_game_attributes::npc_game_attributes(a2, (int)&attributes);
  attributes.group_id = (unsigned int)vostok::configs::binary_config_value::operator[](attributes_config, "group_id")->data.pointer;
  attributes.class_id = (unsigned int)vostok::configs::binary_config_value::operator[](attributes_config, "class_id")->data.pointer;
  attributes.outfit_id = (unsigned int)vostok::configs::binary_config_value::operator[](attributes_config, "outfit_id")->data.pointer;
  v5 = vostok::configs::binary_config_value::operator[](attributes_config, "debug_draw_color");
  attributes.debug_draw_color.m_value = (unsigned __int8)(__int64)*(float *)v5->data.pointer
                                      | (((unsigned __int8)(__int64)*((float *)v5->data.pointer + 1)
                                        | (((unsigned __int8)(__int64)*((float *)v5->data.pointer + 2) | 0xFFFFFF00) << 8)) << 8);
  v6 = vostok::configs::binary_config_value::operator[](attributes_config, "initial_velocity");
  if ( v6->type == 2 )
    pointer = *(float *)&v6->data.pointer;
  else
    pointer = (float)(int)v6->data.pointer;
  attributes.initial_velocity = pointer;
  v8 = vostok::configs::binary_config_value::operator[](attributes_config, "initial_luminosity");
  if ( v8->type == 2 )
    v9 = *(float *)&v8->data.pointer;
  else
    v9 = (float)(int)v8->data.pointer;
  attributes.initial_luminosity = v9;
  v10 = (char *)vostok::configs::binary_config_value::operator[](attributes_config, "description")->data.pointer;
  attributes.description.m_end = attributes.description.m_begin;
  *attributes.description.m_begin = 0;
  if ( v10 )
  {
    for ( i = attributes.description.m_end; *v10; ++attributes.description.m_end )
    {
      if ( i >= attributes.description.m_max_end )
        break;
      *i = *v10;
      i = attributes.description.m_end + 1;
      ++v10;
    }
    *i = 0;
  }
  v12 = vostok::configs::binary_config_value::operator[](attributes_config, "initial_position");
  v13 = (float *)v12->data.pointer;
  *(_QWORD *)&attributes.initial_position.x = *(_QWORD *)v12->data.pointer;
  attributes.initial_position.z = v13[2];
  attributes.initial_rotation = *(vostok::math::float3 *)vostok::configs::binary_config_value::operator[](
                                                           attributes_config,
                                                           "initial_rotation")->data.pointer;
  attributes.initial_scale = *(vostok::math::float3 *)vostok::configs::binary_config_value::operator[](
                                                        attributes_config,
                                                        "initial_scale")->data.pointer;
  v14 = (char *)vostok::configs::binary_config_value::operator[](attributes_config, "name")->data.pointer;
  attributes.name.m_end = attributes.name.m_begin;
  *attributes.name.m_begin = 0;
  if ( v14 )
  {
    for ( j = attributes.name.m_end; *v14; ++attributes.name.m_end )
    {
      if ( j >= attributes.name.m_max_end )
        break;
      *j = *v14;
      j = attributes.name.m_end + 1;
      ++v14;
    }
    *j = 0;
  }
  attributes.id = (unsigned int)vostok::configs::binary_config_value::operator[](attributes_config, "id")->data.pointer;
  v16 = vostok::configs::binary_config_value::operator[](attributes_config, "weapons");
  v17 = (vostok::configs::binary_config_value *)v16->data.pointer;
  it_end = (int)v16->data.pointer + 24 * v16->count;
  if ( v16->data.pointer != (const void *)it_end )
  {
    do
    {
      v18 = vostok::configs::binary_config_value::operator[](v17, "type")->data.pointer;
      v19 = vostok::configs::binary_config_value::operator[](v17, "id")->data.pointer;
      v20 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
              0x20u);
      if ( v20 )
      {
        v21 = this->m_ai_world->get_weapon_name_by_id(this->m_ai_world, v18, v19);
        survarium::object_weapon::object_weapon(
          v22,
          v20,
          (vostok::ai::weapon_types_enum)v18,
          v21,
          (unsigned int)v19,
          v28);
        v24 = v23;
      }
      else
      {
        v24 = 0;
      }
      v24->m_next = 0;
      vostok::threading::mutex::lock(&attributes.weapons.vostok::threading::mutex);
      ++attributes.weapons.m_size;
      if ( attributes.weapons.m_first )
        attributes.weapons.m_last->m_next = v24;
      else
        attributes.weapons.m_first = v24;
      attributes.weapons.m_last = v24;
      LeaveCriticalSection((LPCRITICAL_SECTION)&attributes.weapons.vostok::threading::mutex);
      ++v17;
    }
    while ( v17 != (vostok::configs::binary_config_value *)it_end );
  }
  survarium::human_npc::set_attributes(owner.m_object, &attributes);
  survarium::human_npc::enable(v25, (int)owner.m_object);
  v27 = 0;
  m_object = owner.m_object;
  if ( owner.m_object )
  {
    v27 = (bool *)owner.m_object;
    m_object = (survarium::human_npc *)_InterlockedExchangeAdd(&owner.m_object->m_reference_count, 1u);
  }
  vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)m_object,
    &this->m_npcs,
    v27);
  DeleteCriticalSection((LPCRITICAL_SECTION)&attributes.weapons.vostok::threading::mutex);
  if ( owner.m_object )
  {
    if ( !_InterlockedExchangeAdd(&owner.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &owner.m_object->vostok::resources::unmanaged_intrusive_base,
        &owner.m_object->survarium::game_object_);
  }
}
