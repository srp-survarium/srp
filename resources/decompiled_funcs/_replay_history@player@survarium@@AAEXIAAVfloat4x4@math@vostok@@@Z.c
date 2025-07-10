void __userpurge survarium::player::replay_history(
        survarium::player *this@<esi>,
        unsigned int from_index@<eax>,
        vostok::math::float4x4 *previous_transform)
{
  unsigned int i; // edi
  survarium::player *v4; // ecx
  survarium::client_player_history_item *v5; // ebx

  for ( i = from_index;
        i != *(int *)((char *)&dword_10E28 + (_DWORD)this);
        i = (i + 1) % *(int *)((char *)&dword_10E24 + (_DWORD)this) )
  {
    v4 = *(survarium::player **)((char *)&dword_10E1C + (_DWORD)this);
    v5 = (survarium::client_player_history_item *)((char *)v4 + 96 * i);
    survarium::player::update_history_item_from_previous(
      v4,
      this,
      (survarium::client_player_history_item *)v4
    + (i + *(int *)((char *)&dword_10E24 + (_DWORD)this) - 1) % *(int *)((char *)&dword_10E24 + (_DWORD)this),
      v5,
      previous_transform);
    survarium::inventory::action(
      this->m_inventory.m_object,
      (const survarium::profile_slot_enum)v5->action.weapon_state.slot_id,
      1);
  }
  vostok::animation::mixing::n_ary_tree::set_object_transform(
    *(vostok::animation::mixing::n_ary_tree **)((char *)&dword_10E1C + (_DWORD)this),
    this,
    (const vostok::math::float4x4 *)(96
                                   * ((unsigned int)(*(int *)((char *)&dword_10E28 + (_DWORD)this)
                                                   + *(int *)((char *)&dword_10E24 + (_DWORD)this)
                                                   - 1)
                                    % *(int *)((char *)&dword_10E24 + (_DWORD)this))
                                   + *(int *)((char *)&dword_10E1C + (_DWORD)this)
                                   + 20));
}
