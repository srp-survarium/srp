bool __thiscall survarium::player_input_handler::on_mouse_key_action(
        survarium::player_input_handler *this,
        vostok::input::world *input_world,
        survarium::toggle_action_enum button,
        vostok::input::enum_mouse_key_action actions_mask)
{
  survarium::game_action_id binded_action; // eax
  stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *v6; // ecx
  stlp_std::pair<enum survarium::game_action_id,enum survarium::player_input_handler::action_state_enum> *m_end; // ecx

  binded_action = survarium::key_binder::get_binded_action(this->m_game_world->m_game->m_key_binder, button, &button, 1);
  if ( binded_action == kNOTBINDED )
    return 0;
  if ( actions_mask )
  {
    if ( actions_mask != ms_key_hold || button )
      return 0;
    m_end = this->m_game_actions.m_end;
    if ( m_end )
    {
      m_end->second = hold;
      m_end->first = binded_action;
    }
    goto LABEL_10;
  }
  if ( (unsigned int)button <= toggle_action )
  {
    v6 = this->m_game_actions.m_end;
    if ( v6 )
    {
      v6->second = down;
      v6->first = binded_action;
      ++this->m_game_actions.m_end;
      return 0;
    }
LABEL_10:
    ++this->m_game_actions.m_end;
  }
  return 0;
}
