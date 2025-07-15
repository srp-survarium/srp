// local variable allocation has failed, the output may be wrong!
void __userpurge survarium::network_client::process_player_hit(
        survarium::network_client *this@<ecx>,
        int a2@<esi>,
        vostok::network_core::packet_reader *packet)
{
  survarium::player *m_object; // eax
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+8h] [ebp-54h] BYREF
  _BYTE info[73]; // [esp+Ch] [ebp-50h] OVERLAPPED BYREF

  survarium::hit_info::hit_info((survarium::hit_info *)info);
  survarium::hit_info::deserialize((survarium::hit_info *)info, packet);
  (*(void (__thiscall **)(int, vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *, _DWORD))(*(_DWORD *)a2 + 72))(
    a2,
    &player,
    *(_DWORD *)&info[69]);
  m_object = player.m_object;
  if ( player.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      survarium::player::apply_hit_directly(
        (survarium::player *)info,
        (const survarium::hit_info *)player.m_object,
        (unsigned int)info);
      m_object = player.m_object;
    }
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
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
