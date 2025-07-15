bool __thiscall survarium::player_input_handler::on_keyboard_action(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        int key,
        vostok::input::enum_keyboard_action actions_mask)
{
  survarium::game_action_id binded_action; // eax
  survarium::game *v6; // ecx
  survarium::game_action_id v7; // ebx
  __int32 v8; // esi
  __int32 v9; // eax
  __int32 v10; // eax
  survarium::player_input_handler *v11; // ecx
  survarium::player_input_handler *v12; // ecx
  int m_key_binder_context; // [esp-4h] [ebp-1Ch]
  survarium::toggle_action_enum actions_mask_type; // [esp+Ch] [ebp-Ch] BYREF
  stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum> item; // [esp+10h] [ebp-8h] BYREF

  m_key_binder_context = this->m_key_binder_context;
  item.first = (survarium::game_action_id)this->m_game_world->m_game;
  binded_action = survarium::key_binder::get_binded_action(
                    *(survarium::key_binder **)(item.first + 144),
                    key,
                    &actions_mask_type,
                    m_key_binder_context);
  v7 = binded_action;
  if ( binded_action != kNOTBINDED )
  {
    v8 = 1;
    if ( actions_mask == kb_key_down )
    {
      v9 = binded_action - 51;
      if ( v9 )
      {
        v10 = v9 - 3;
        if ( v10 )
        {
          if ( v10 == 1 )
            vostok::console_commands::execute("deserialize_player_state", execution_filter_all, 1u);
        }
        else
        {
          vostok::console_commands::execute("serialize_player_state", execution_filter_all, 1u);
        }
      }
      else
      {
        survarium::game::toggle_pause(v6, (survarium::game *)item.first);
        v8 = 1;
      }
    }
    if ( actions_mask_type )
    {
      if ( actions_mask_type == toggle_action && actions_mask == kb_key_down )
        survarium::player_input_handler::process_toggle_action(
          (survarium::player_input_handler *)v6,
          (const survarium::game_action_id)this,
          v7);
    }
    else
    {
      if ( actions_mask != kb_key_down )
      {
        if ( actions_mask == kb_key_hold )
        {
          v8 = 2;
        }
        else if ( actions_mask != kb_key_up )
        {
          return 0;
        }
        item.first = v7;
        item.second = v8;
        vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::push_back(
          &this->m_game_actions,
          &item);
        survarium::player_input_handler::process_dependent_actions(
          v12,
          (const survarium::game_action_id)this,
          (const survarium::action_state_enum)v7,
          v8);
        return 0;
      }
      item.second = action_down;
      item.first = v7;
      vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::push_back(
        &this->m_game_actions,
        &item);
      survarium::player_input_handler::process_dependent_actions(
        v11,
        (const survarium::game_action_id)this,
        (const survarium::action_state_enum)v7,
        0);
    }
  }
  return 0;
}
