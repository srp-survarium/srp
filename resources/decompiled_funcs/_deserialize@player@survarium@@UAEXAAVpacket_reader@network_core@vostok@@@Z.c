void __thiscall survarium::player::deserialize(survarium::player *this, vostok::resources::unmanaged_resource *reader)
{
  vostok::network_core::packet_reader *v2; // edi
  __int64 v3; // xmm0_8
  const unsigned __int8 *v4; // eax
  float v6; // ecx
  vostok::math::float4x4 *v7; // edx
  survarium::player *v8; // ecx
  bool v9; // zf
  survarium::player *v10; // ecx
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v12; // cl
  unsigned __int8 v13; // dl
  survarium::inventory_item *m_object; // eax
  vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base> *p_m_current_active_object; // ebx
  vostok::resources::unmanaged_resource *v16; // eax
  vostok::resources::unmanaged_resource *v17; // edx
  survarium::engine *v18; // eax
  survarium::engine *v19; // eax
  survarium::inventory *v20; // ecx
  survarium::inventory_item *v21; // eax
  vostok::resources::unmanaged_resource *v22; // ebx
  survarium::interactive_object *v23; // eax
  survarium::interactive_object *v24; // ecx
  survarium::interactive_object *v25; // eax
  survarium::player_stamina *v26; // eax
  float look_pitch; // [esp+18h] [ebp-18h]
  vostok::math::float4x4 *orientation; // [esp+1Ch] [ebp-14h]
  bool server_target_active_slot; // [esp+20h] [ebp-10h]
  survarium::profile_slot_enum server_target_active_slota; // [esp+20h] [ebp-10h]
  vostok::math::float3 position; // [esp+24h] [ebp-Ch] BYREF

  v2 = (vostok::network_core::packet_reader *)reader;
  v3 = *(_QWORD *)reader->type;
  v4 = (const unsigned __int8 *)(reader->type + 12);
  v6 = *(float *)(reader->type + 8);
  reader->type = (unsigned int)v4;
  v7 = *(vostok::math::float4x4 **)v4;
  v4 += 4;
  v2->m_pointer = v4;
  v4 += 4;
  position.z = v6;
  v8 = (survarium::player *)*((_DWORD *)v4 - 1);
  v2->m_pointer = v4;
  orientation = v7;
  LOBYTE(v7) = *v4;
  v2->m_pointer = v4 + 1;
  v9 = !this->m_has_been_inserted;
  *(_QWORD *)&position.x = v3;
  look_pitch = *(float *)&v8;
  server_target_active_slot = (char)v7;
  if ( !v9 )
    survarium::player::remove(v8, (int)this);
  survarium::player::set_character_transform(&position, this, orientation, look_pitch);
  survarium::player::insert(v10, this, server_target_active_slot);
  m_pointer = v2->m_pointer;
  v12 = *m_pointer++;
  v2->m_pointer = m_pointer;
  v13 = *m_pointer;
  v2->m_pointer = m_pointer + 1;
  m_object = this->m_inventory.m_object->m_slots[v12].item.m_object;
  server_target_active_slota = v13;
  reader = 0;
  if ( m_object )
  {
    reader = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  p_m_current_active_object = &this->m_current_active_object;
  if ( this->m_current_active_object.m_object != reader )
  {
    survarium::inventory::action(this->m_inventory.m_object, (const survarium::profile_slot_enum)v12, 1);
    p_m_current_active_object->m_object->deactivate(p_m_current_active_object->m_object);
    this->on_before_active_object_changed(
      this,
      &this->m_current_active_object,
      (const vostok::resources::resource_ptr<survarium::interactive_object,vostok::resources::unmanaged_intrusive_base> *)&reader);
    v16 = 0;
    if ( reader )
    {
      v16 = reader;
      _InterlockedExchangeAdd(&reader->m_reference_count, 1u);
    }
    v17 = p_m_current_active_object->m_object;
    p_m_current_active_object->m_object = (survarium::interactive_object *)v16;
    if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v17->vostok::resources::unmanaged_intrusive_base, v17);
    v18 = *(survarium::engine **)((char *)&dword_10F00 + (_DWORD)this);
    if ( v18 )
      v19 = v18 + 3;
    else
      v19 = 0;
    p_m_current_active_object->m_object->activate(p_m_current_active_object->m_object, this, v19);
  }
  v20 = this->m_inventory.m_object;
  v21 = v20->m_slots[server_target_active_slota].item.m_object;
  v22 = 0;
  if ( v21 )
  {
    v22 = v20->m_slots[server_target_active_slota].item.m_object;
    _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
  }
  v23 = 0;
  if ( v22 )
  {
    v23 = (survarium::interactive_object *)v22;
    _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
  }
  v24 = v23;
  v25 = this->m_target_active_object.m_object;
  this->m_target_active_object.m_object = v24;
  if ( v25 && !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v25->vostok::resources::unmanaged_intrusive_base, v25);
  if ( v22 && !_InterlockedExchangeAdd(&v22->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v22->vostok::resources::unmanaged_intrusive_base, v22);
  v26 = this->stamina(this);
  survarium::player_stamina::deserialize(v26, *(float *)&v3, v2);
  survarium::inventory::deserialize(this->m_inventory.m_object, v2);
  if ( reader )
  {
    if ( !_InterlockedExchangeAdd(&reader->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&reader->vostok::resources::unmanaged_intrusive_base, reader);
  }
}
