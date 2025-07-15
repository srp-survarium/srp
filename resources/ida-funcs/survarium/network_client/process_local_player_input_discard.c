void __fastcall survarium::network_client::process_local_player_input_discard(survarium::network_client *this, int a2)
{
  survarium::player *m_object; // esi
  unsigned int v3; // [esp+Ch] [ebp-4h]

  m_object = this->m_current_player.m_object;
  v3 = (unsigned int)m_object->survarium::base_player::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable;
  this->m_current_player.m_object = (survarium::player *)&m_object->type;
  survarium::game_world_core::discard_input(
    (survarium::game_world_core *)this,
    *(_DWORD **)(*(_DWORD *)(a2 + 20696) + 312),
    *(_BYTE *)(*(_DWORD *)(a2 + 20700) + 304),
    v3);
}
