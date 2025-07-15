void __userpurge survarium::game_world_ui::process_statistic_event(
        survarium::game_world_ui *this@<edi>,
        survarium::game_statistic_event_history_item *item@<esi>,
        const bool is_sealed)
{
  survarium::game_statistic_event_history_item::events_enum type; // eax
  __int32 v4; // eax
  unsigned __int8 v5; // bl
  unsigned int u32_arg; // ecx
  char v7; // al
  char v8; // [esp+0h] [ebp-18h]
  char v9; // [esp+0h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v11; // [esp+10h] [ebp-8h]
  unsigned __int8 v12; // [esp+17h] [ebp-1h]

  type = item->type;
  if ( type == player_killed_event )
  {
    survarium::game_world_ui::on_player_killed(
      0,
      this,
      item->data0.char_arg[0],
      item->data0.char_arg[1],
      item->data0.char_arg[2] != 0,
      item->data1.short_arg[0]);
    goto LABEL_27;
  }
  v4 = type - 1;
  if ( !v4 )
  {
    LOBYTE(v11) = item->data0.char_arg[1];
    if ( item->data0.char_arg[0] )
    {
      switch ( item->data0.char_arg[0] )
      {
        case 1u:
          v9 = 1;
          break;
        case 2u:
          v9 = 0;
          break;
        case 4u:
          v8 = 0;
          goto LABEL_24;
        default:
          goto LABEL_27;
      }
      survarium::game_world_ui::on_victory_item_put_take(0, (int)this, v11, 1, v9);
      goto LABEL_27;
    }
    v8 = 1;
LABEL_24:
    survarium::game_world_ui::on_victory_item_put_take(0, (int)this, v11, 0, v8);
    goto LABEL_27;
  }
  if ( v4 == 1 )
  {
    v5 = item->data0.char_arg[1];
    u32_arg = item->data1.u32_arg;
    v12 = item->data0.char_arg[0];
    v11 = u32_arg;
    if ( v12 != v5 )
    {
      survarium::base_network_client::get_current_player(this->m_game_world->m_game->m_network_client, &v10);
      if ( v10.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v7 = v10.m_object->m_lods[1].m_emitter_instance_list.gap4;
      }
      else
      {
        v7 = -1;
      }
      if ( v12 != v7 || v11 == -1 )
      {
        if ( v5 == v7 )
          survarium::game_world_ui::on_hit_from_pos(&item->position_data0, v11, this);
      }
      else
      {
        survarium::game_world_ui::on_enemy_hitted(v11, v5, this, item->data0.char_arg[2] != 0, item->data2.float_arg);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
    }
  }
LABEL_27:
  if ( is_sealed )
    this->m_last_update_history_time_ms = item->time_in_ms;
}
