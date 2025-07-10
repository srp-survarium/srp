void __usercall survarium::network_client::process_affect_damage_model(
        survarium::network_client *this@<ecx>,
        vostok::network_core::packet_reader *packet@<eax>)
{
  const unsigned __int8 *m_pointer; // eax
  survarium::player *m_object; // edx
  unsigned __int8 *v5; // edi
  unsigned int v6; // ebx
  const unsigned __int8 *v7; // edi
  survarium::hit_affects_type_enum v8; // edx
  survarium::affect_event_type_enum v9; // eax
  survarium::player *v10; // ecx
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+Ch] [ebp-18h] BYREF
  char body_part_name[20]; // [esp+10h] [ebp-14h] BYREF

  m_pointer = packet->m_pointer;
  LOBYTE(player.m_object) = *m_pointer;
  m_object = player.m_object;
  packet->m_pointer = m_pointer + 1;
  this->get_player(this, &player, (const unsigned __int8)m_object);
  v5 = (unsigned __int8 *)packet->m_pointer;
  v6 = *v5++;
  packet->m_pointer = v5;
  memcpy((unsigned __int8 *)body_part_name, v5, v6);
  v7 = &v5[v6];
  packet->m_pointer = v7;
  body_part_name[v6] = 0;
  v8 = *(_DWORD *)v7;
  packet->m_pointer = v7 + 4;
  v9 = *((_DWORD *)v7 + 1);
  packet->m_pointer = v7 + 8;
  v10 = player.m_object;
  if ( player.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      survarium::player::apply_damage_model_affect(player.m_object, body_part_name, v8, v9);
      v10 = player.m_object;
    }
    if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    {
      if ( player.m_object )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &player.m_object->vostok::resources::unmanaged_intrusive_base,
          &player.m_object->vostok::resources::unmanaged_resource);
      else
        vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
    }
  }
}
