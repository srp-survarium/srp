void __userpurge survarium::base_network_client::attach_to_player(
        survarium::base_network_client *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player)
{
  int v4; // esi
  survarium::player *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  int v7; // eax
  survarium::player *v8; // eax
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> v9; // [esp-4h] [ebp-Ch] BYREF

  v4 = *(_DWORD *)(a2 + 8);
  if ( v4
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::player::detach_controller((survarium::player *)this, v4);
  }
  m_object = 0;
  if ( player.m_object )
  {
    m_object = player.m_object;
    _InterlockedExchangeAdd(&player.m_object->m_reference_count, 1u);
  }
  v6 = (vostok::resources::unmanaged_intrusive_base *)m_object;
  v7 = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(a2 + 8) = v6;
  if ( v7 )
  {
    v6 = (vostok::resources::unmanaged_intrusive_base *)(v7 + 496);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 496), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v6, (vostok::resources::unmanaged_resource *)(v7 + 288));
  }
  v9.m_object = 0;
  if ( *(_DWORD *)(a2 + 8) )
  {
    vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>((vostok::memory::detail::call_destructor_predicate *)&v9);
    v8 = *(survarium::player **)(a2 + 8);
    v9.m_object = v8;
    if ( v8 )
      v6 = (vostok::resources::unmanaged_intrusive_base *)_InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  survarium::game_world_ui::on_attached_to_player(
    (survarium::game_world_ui *)v6,
    (survarium::game_world_ui *)(*(_DWORD *)(a2 + 24) + 620),
    v9);
  survarium::player::attach_controller(
    player.m_object,
    *(survarium::player_input_handler **)(a2 + 12),
    (survarium::game_world_ui *)(*(_DWORD *)(a2 + 24) + 620),
    *(survarium::stats_graph **)(a2 + 16),
    *(survarium::stats_graph **)(a2 + 20));
  if ( player.m_object )
  {
    if ( !_InterlockedExchangeAdd(&player.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &player.m_object->vostok::resources::unmanaged_intrusive_base,
        &player.m_object->vostok::resources::unmanaged_resource);
  }
}
