bool __thiscall survarium::player_input_handler::on_keyboard_action(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action actions_mask)
{
  int m_key_binder_context; // edi
  survarium::game *v6; // ecx
  survarium::game_action_id binded_action; // esi
  stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *m_end; // eax
  stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v10; // eax
  stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v11; // eax
  survarium::toggle_action_enum actions_mask_type; // [esp+10h] [ebp-8h] BYREF
  survarium::game *m_game; // [esp+14h] [ebp-4h]

  m_key_binder_context = this->m_key_binder_context;
  m_game = this->m_game_world->m_game;
  binded_action = survarium::key_binder::get_binded_action(
                    m_game->m_key_binder,
                    key,
                    &actions_mask_type,
                    m_key_binder_context);
  if ( binded_action == kNOTBINDED )
    return 0;
  if ( actions_mask == kb_key_down )
  {
    switch ( binded_action )
    {
      case kPAUSE:
        survarium::game::toggle_pause(v6);
        break;
      case kSERIALIZE_PLAYER_STATE:
        vostok::console_commands::execute("serialize_player_state", execution_filter_all);
        break;
      case kDESERIALIZE_PLAYER_STATE:
        vostok::console_commands::execute("deserialize_player_state", execution_filter_all);
        break;
    }
    if ( (unsigned int)actions_mask_type > toggle_action )
      return 0;
    m_end = this->m_game_actions.m_end;
    if ( m_end )
    {
      m_end->second = down;
      m_end->first = binded_action;
      ++this->m_game_actions.m_end;
      return 0;
    }
    goto LABEL_20;
  }
  if ( actions_mask != kb_key_hold )
  {
    if ( actions_mask != kb_key_up || actions_mask_type )
      return 0;
    v11 = this->m_game_actions.m_end;
    if ( v11 )
    {
      v11->second = up;
      v11->first = binded_action;
    }
    goto LABEL_20;
  }
  if ( actions_mask_type == hold_action )
  {
    v10 = this->m_game_actions.m_end;
    if ( v10 )
    {
      v10->second = hold;
      v10->first = binded_action;
      ++this->m_game_actions.m_end;
      return 0;
    }
LABEL_20:
    ++this->m_game_actions.m_end;
  }
  return 0;
}
