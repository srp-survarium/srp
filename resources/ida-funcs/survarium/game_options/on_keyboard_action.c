char __thiscall survarium::game_options::on_keyboard_action(
        survarium::game_options *this,
        survarium::swf_input_translator *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  survarium::game_options *v5; // ecx
  survarium::game *m_game; // ebx
  survarium::game_options *v7; // ecx
  survarium::game *v8; // ecx
  survarium::toggle_action_enum actions_mask_type; // [esp+Ch] [ebp-4h] BYREF

  if ( this->m_waiting_for_bind_action == kLASTACTION || action != kb_key_down )
  {
    m_game = this->m_game;
    if ( survarium::key_binder::get_binded_action(m_game->m_key_binder, key, &actions_mask_type, 2) == kOPTIONS
      && action == kb_key_down )
    {
      survarium::game_options::show_options(v7, (int)&m_game->m_game_options, 0);
      survarium::game::deactivate_main_menu(v8, (int)this->m_game);
    }
    else
    {
      survarium::swf_input_translator::process_keyboard(
        input_world,
        &this->m_parent_scene->m_game->m_swf_input_translator,
        key,
        action,
        this->m_options_ui.m_object->movie,
        m_game->m_current_time_in_ms);
    }
  }
  else if ( survarium::game_options::process_key_input(this, this, key) )
  {
    survarium::game_options::finish_binding(v5, (int)this);
  }
  return 1;
}
