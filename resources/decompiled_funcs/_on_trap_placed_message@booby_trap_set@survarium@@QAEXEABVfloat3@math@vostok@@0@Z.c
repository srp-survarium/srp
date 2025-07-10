void __userpurge survarium::booby_trap_set::on_trap_placed_message(
        survarium::booby_trap_set *this@<ecx>,
        unsigned __int8 index@<al>,
        const vostok::math::float3 *position,
        const vostok::math::float3 *angles)
{
  survarium::booby_trap_core *m_object; // eax
  survarium::booby_trap_core *v6; // ebp
  const vostok::math::float4x4 *v7; // edi
  const vostok::math::float4x4 *v8; // eax
  survarium::inventory *m_inventory; // ecx
  int v10; // eax
  survarium::game_world *m_game_world; // ecx
  char v12; // bl
  survarium::player *v13; // eax
  survarium::game_action_id *M_finish; // eax
  survarium::game_action_id m_slot_id; // esi
  const stlp_std::__false_type *v16; // [esp+0h] [ebp-DCh]
  unsigned int v17; // [esp+4h] [ebp-D8h]
  bool v18; // [esp+8h] [ebp-D4h]
  survarium::game_action_id __x; // [esp+14h] [ebp-C8h] BYREF
  vostok::math::float4x4 transform; // [esp+18h] [ebp-C4h] BYREF
  vostok::math::float4x4 result; // [esp+58h] [ebp-84h] BYREF
  vostok::math::float4x4 v22; // [esp+98h] [ebp-44h] BYREF

  m_object = this->m_traps.m_begin[index].m_object;
  v6 = 0;
  if ( m_object )
  {
    v6 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v7 = vostok::math::create_translation(&result, position);
  v8 = vostok::math::create_rotation(&v22, angles);
  vostok::math::mul4x3(&transform, v8, v7);
  this->insert_trap(this, v6, &transform);
  m_inventory = this->m_inventory;
  --this->m_amount;
  v10 = (int)m_inventory->m_holder->cast_to_base_player(m_inventory->m_holder);
  m_game_world = this->m_game_world;
  v12 = *(_BYTE *)(v10 + 52);
  v13 = m_game_world->m_game->m_network_client->m_current_player.m_object;
  if ( v13
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && v13->id == v12 )
  {
    M_finish = (survarium::game_action_id *)m_game_world->game_ui.m_slots_to_update._M_impl._M_finish;
    m_slot_id = this->m_slot_id;
    __x = m_slot_id;
    if ( M_finish == (survarium::game_action_id *)m_game_world->game_ui.m_slots_to_update._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_insert_overflow_aux(
        (stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id> > *)&m_game_world->game_ui.m_slots_to_update,
        M_finish,
        (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)&__x,
        (survarium::damage_zone **)&__x,
        v16,
        v17,
        v18);
    }
    else
    {
      if ( M_finish )
        *M_finish = m_slot_id;
      ++m_game_world->game_ui.m_slots_to_update._M_impl._M_finish;
    }
  }
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  }
}
