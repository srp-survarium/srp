bool __thiscall survarium::player_input_handler::on_mouse_key_action(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        int button,
        vostok::input::enum_mouse_key_action actions_mask)
{
  survarium::game_action_id binded_action; // eax
  survarium::player_input_handler *v6; // ecx
  survarium::action_state_enum v7; // esi
  __int32 v8; // ebx
  survarium::player_input_handler *v9; // ecx
  stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum> actions_mask_type; // [esp+10h] [ebp-8h] BYREF

  binded_action = survarium::key_binder::get_binded_action(
                    this->m_game_world->m_game->m_key_binder,
                    button,
                    (survarium::toggle_action_enum *)&actions_mask_type,
                    1);
  v7 = binded_action;
  if ( binded_action != kNOTBINDED )
  {
    v8 = 0;
    if ( actions_mask_type.first )
    {
      if ( actions_mask_type.first == kRIGHT && actions_mask == ms_key_down )
        survarium::player_input_handler::process_toggle_action(v6, (const survarium::game_action_id)this, binded_action);
    }
    else if ( actions_mask == ms_key_down
           || (v8 = 2, actions_mask == ms_key_hold)
           || (v8 = 1, actions_mask == ms_key_up) )
    {
      actions_mask_type.first = binded_action;
      actions_mask_type.second = v8;
      vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::push_back(
        &this->m_game_actions,
        &actions_mask_type);
      survarium::player_input_handler::process_dependent_actions(v9, (const survarium::game_action_id)this, v7, v8);
    }
  }
  return 0;
}
