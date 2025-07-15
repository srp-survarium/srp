void __thiscall survarium::victory_item_core::deserialize(
        survarium::victory_item_core *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  vostok::network_core::buffer_reader *v4; // edx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v7; // eax
  bool v8; // zf
  const unsigned __int8 *v9; // eax
  vostok::threading::mutex *v10; // ecx
  float *v11; // eax
  float *v12; // esi
  survarium::victory_item_core_vtbl *v13; // eax
  survarium::usable_object *v14; // ecx
  survarium::usable_object *v15; // ecx
  float v16; // [esp+0h] [ebp-24h]
  unsigned int v17; // [esp+4h] [ebp-20h]
  vostok::math::float3 v18; // [esp+10h] [ebp-14h] BYREF
  unsigned int v19; // [esp+1Ch] [ebp-8h]
  bool v20; // [esp+22h] [ebp-2h]
  unsigned __int8 v21; // [esp+23h] [ebp-1h]

  v4 = reader;
  m_pointer = reader->m_pointer;
  v19 = *(_DWORD *)m_pointer;
  reader->m_pointer = m_pointer + 4;
  this->m_spotted_mask = v19;
  v7 = reader->m_pointer;
  v20 = this->m_container != 0;
  v21 = *v7;
  v8 = v21 == 0xFF;
  reader->m_pointer = v7 + 1;
  if ( v8 )
    this->m_user = 0;
  v9 = reader->m_pointer;
  v21 = *v9;
  v8 = v21 == 0xFF;
  reader->m_pointer = v9 + 1;
  if ( v8 )
    this->m_container = 0;
  else
    this->m_container = this->m_game_rule->m_containers._M_impl._M_start[v21].m_object;
  if ( this->m_user || (v21 = 0, this->m_container) )
    v21 = 1;
  if ( v20 || this->m_collision_is_inserted && v21 )
  {
    this->remove(this);
    v4 = reader;
  }
  this->m_usable_object_users.m_first = 0;
  this->m_usable_object_users.m_last = 0;
  this->m_usable_object_users.m_size = 0;
  if ( this->m_user )
  {
    vostok::ai::fsm::deserialize(&this->m_logic, v4, client_reader);
    this->m_portable_interactive_object->deserialize(
      this->m_portable_interactive_object,
      reader,
      client_reader,
      time_offset);
    vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_user->m_profile->modifiers.m_modifiers.elems[4],
      &this->m_move_speed_modifier,
      v10);
  }
  else if ( !this->m_container )
  {
    v11 = (float *)v4->m_pointer;
    v18.x = *v11;
    v12 = v11 + 1;
    v18.y = v11[1];
    v11 += 3;
    v18.z = v12[1];
    v4->m_pointer = (const unsigned __int8 *)v11;
    v16 = *v11;
    v4->m_pointer = (const unsigned __int8 *)(v11 + 1);
    v13 = this->survarium::carryable_object::survarium::interactive_object::__vftable;
    if ( this->m_collision_is_inserted )
      v13->set_transform(this, &v18, COERCE_FLOAT(LODWORD(v16)));
    else
      v13->insert(this, &v18, COERCE_FLOAT(LODWORD(v16)));
    survarium::usable_object::deserialize_usable_object(
      v14,
      &this->survarium::carryable_object::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable,
      reader,
      v17);
    survarium::usable_object::post_deserialize_resolve(v15, &this->survarium::usable_object, this->m_game_world_core);
  }
}
