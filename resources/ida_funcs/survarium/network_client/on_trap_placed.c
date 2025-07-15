void __usercall survarium::network_client::on_trap_placed(
        survarium::network_client *this@<esi>,
        vostok::network_core::packet_reader *packet@<eax>)
{
  const unsigned __int8 *m_pointer; // edx
  char v3; // cl
  unsigned __int8 v4; // bl
  unsigned __int8 v5; // cl
  __int64 v6; // xmm0_8
  float v7; // ecx
  float v8; // ecx
  __int64 v9; // xmm0_8
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *(__thiscall *get_player)(struct survarium::network_client *, vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *, const unsigned __int8); // edx
  unsigned __int8 index; // [esp+Bh] [ebp-21h]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+Ch] [ebp-20h] BYREF
  vostok::math::float3 angles; // [esp+10h] [ebp-1Ch] BYREF
  vostok::math::float3 position; // [esp+1Ch] [ebp-10h] BYREF

  m_pointer = packet->m_pointer;
  v3 = *m_pointer++;
  packet->m_pointer = m_pointer;
  LOBYTE(player.m_object) = v3;
  v4 = *m_pointer++;
  packet->m_pointer = m_pointer;
  v5 = *m_pointer++;
  packet->m_pointer = m_pointer;
  v6 = *(_QWORD *)m_pointer;
  index = v5;
  v7 = *((float *)m_pointer + 2);
  m_pointer += 12;
  packet->m_pointer = m_pointer;
  position.z = v7;
  v8 = *((float *)m_pointer + 2);
  *(_QWORD *)&position.x = v6;
  v9 = *(_QWORD *)m_pointer;
  packet->m_pointer = m_pointer + 12;
  get_player = this->get_player;
  angles.z = v8;
  *(_QWORD *)&angles.x = v9;
  get_player(this, &player, (const unsigned __int8)player.m_object);
  survarium::booby_trap_set::on_trap_placed_message(
    (survarium::booby_trap_set *)player.m_object->m_inventory.m_object->m_slots[v4].item.m_object,
    index,
    &position,
    &angles);
  if ( player.m_object && !_InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( player.m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &player.m_object->vostok::resources::unmanaged_intrusive_base,
        &player.m_object->vostok::resources::unmanaged_resource);
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
