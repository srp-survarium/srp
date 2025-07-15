void __usercall survarium::game_world_core::fill_debug_info(
        survarium::game_world_core *this@<ecx>,
        survarium::game_state_history_item *item@<eax>)
{
  survarium::game_state_history_item *v4; // ecx
  survarium::game_state_history_item *v5; // ecx
  survarium::game_world_core *v6; // ecx
  survarium::game_state_history_item *v7; // ecx
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  vostok::network_core::g_debug_hash_mismatches_enabled = 1;
  survarium::game_world_core::deserialize(this, item);
  v9 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9933 + 1];
  v8 = *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B992B + 5];
  survarium::game_state_history_item::~game_state_history_item(v4, (char *)item);
  survarium::game_state_history_item::game_state_history_item(v5, item->players.elems);
  survarium::game_world_core::serialize(
    v6,
    (int)this,
    (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)item);
  *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B9933 + 1] = v9;
  *(_DWORD *)&item->players.elems[0].player_state.m_raw_buffer.elems[(_DWORD)&loc_B992B + 5] = v8;
  survarium::game_state_history_item::hash(
    v7,
    (const survarium::fixed_history<survarium::players_mask_history_item,40> *)item,
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&this->m_active_clients_history);
  survarium::game_world_core::deserialize(this, this->m_game_states_history.m_items.m_last);
  vostok::network_core::g_debug_hash_mismatches_enabled = 0;
}
