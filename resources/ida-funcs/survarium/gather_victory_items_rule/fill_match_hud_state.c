void __thiscall survarium::gather_victory_items_rule::fill_match_hud_state(
        survarium::gather_victory_items_rule *this,
        survarium::match_hud_state *state,
        const unsigned int __formal)
{
  survarium::match_hud_state *v4; // esi
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *i; // eax
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> v6; // ecx
  survarium::game_team_id m_owner_team; // edx
  int v8; // eax
  _DWORD *p_x; // edi
  _DWORD *v10; // esi
  _DWORD *v11; // edi
  void (__thiscall *deserialize)(survarium::base_player *, vostok::network_core::buffer_reader *, vostok::network_core::buffer_reader *, const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *, const unsigned int, const unsigned int, const bool); // edi
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_start; // eax
  _DWORD *v14; // edi
  _DWORD *v15; // esi
  unsigned __int8 v16; // [esp+Fh] [ebp-49h]
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v17; // [esp+10h] [ebp-48h]
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *v18; // [esp+10h] [ebp-48h]
  int v19; // [esp+14h] [ebp-44h]
  vostok::math::float4x4 v20; // [esp+18h] [ebp-40h] BYREF

  v4 = state;
  *(_WORD *)&state->team_1_points = *(_WORD *)this->m_team_points;
  for ( i = this->m_containers._M_impl._M_start; ; ++i )
  {
    v17 = i;
    if ( i == this->m_containers._M_impl._M_finish )
      break;
    v6.m_object = i->m_object;
    m_owner_team = i->m_object->m_owner_team;
    if ( m_owner_team )
    {
      if ( m_owner_team != team_2 )
        continue;
      v8 = ((int (__thiscall *)(vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>, vostok::math::float4x4 *))v6.m_object->get_transform)(
             v6,
             &v20);
      p_x = (_DWORD *)&v4->team2_base_position.x;
    }
    else
    {
      v8 = ((int (__thiscall *)(vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base>, vostok::math::float4x4 *))v6.m_object->get_transform)(
             v6,
             &v20);
      p_x = (_DWORD *)&v4->team1_base_position.x;
    }
    v10 = (_DWORD *)(v8 + 48);
    i = v17;
    *p_x = *v10++;
    v11 = p_x + 1;
    *v11 = *v10;
    v11[1] = v10[1];
    v4 = state;
  }
  if ( v4->current_player_id == 0xFF )
    deserialize = 0;
  else
    deserialize = (*(survarium::base_player_vtbl **)((char *)&survarium::game_world_core::player(
                                                                this->m_game_world_core,
                                                                v4->current_player_id)->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                   + (_DWORD)&loc_11066
                                                   + 2))[6].deserialize;
  M_start = this->m_victory_items._M_impl._M_start;
  v16 = 0;
  v18 = M_start;
  if ( M_start != this->m_victory_items._M_impl._M_finish )
  {
    v19 = (deserialize != 0) + 1;
    do
    {
      if ( (v19 & M_start->m_object->m_spotted_mask) != 0 )
      {
        v14 = (_DWORD *)&v4->spotted_victory_items_positions[v16++].x;
        v15 = (_DWORD *)&M_start->m_object->get_transform(&M_start->m_object->survarium::interactive_object, &v20)->c.x;
        M_start = v18;
        *v14 = *v15++;
        *++v14 = *v15;
        v14[1] = v15[1];
        v4 = state;
      }
      v18 = ++M_start;
    }
    while ( M_start != this->m_victory_items._M_impl._M_finish );
  }
  v4->spotted_victory_items_count = v16;
}
