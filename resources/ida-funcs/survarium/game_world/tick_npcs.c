void __userpurge survarium::game_world::tick_npcs(
        survarium::game_world *this@<ecx>,
        const vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>,
        vostok::animation::subscribed_channel **current_frame_id,
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> is_game_paused)
{
  char m_object; // bl
  survarium::human_npc *v5; // esi
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  survarium::human_npc *v7; // eax
  survarium::human_npc *v8; // edi
  survarium::human_npc *v9; // eax
  survarium::human_npc *v10; // ecx
  survarium::human_npc *v11; // eax

  m_object = (char)is_game_paused.m_object;
  is_game_paused.m_object = 0;
  vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &is_game_paused,
    a2 + 170);
  v5 = is_game_paused.m_object;
  while ( v5 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &v5->vostok::resources::unmanaged_intrusive_base,
          &v5->survarium::game_object_);
      return;
    }
    survarium::human_npc::tick(v5, current_frame_id, m_object);
    v6 = &v5->vostok::resources::unmanaged_intrusive_base;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
    v7 = v5->next_npc.m_object;
    v8 = 0;
    if ( v7 )
    {
      v8 = v5->next_npc.m_object;
      _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
    }
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v6, &v5->survarium::game_object_);
    v9 = 0;
    if ( v8 )
    {
      v9 = v8;
      _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
    }
    v10 = v9;
    v11 = v5;
    v5 = v10;
    if ( !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v11->vostok::resources::unmanaged_intrusive_base,
        &v11->survarium::game_object_);
    if ( v8 )
    {
      if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &v8->vostok::resources::unmanaged_intrusive_base,
          &v8->survarium::game_object_);
    }
  }
}
