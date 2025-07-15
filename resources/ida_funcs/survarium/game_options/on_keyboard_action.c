char __thiscall survarium::game_options::on_keyboard_action(
        survarium::game_options *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  survarium::game_options *v5; // ecx

  if ( this->m_waiting_for_bind_action == kLASTACTION || action != kb_key_down )
  {
    survarium::swf_input_translator::process_keyboard(
      key,
      (survarium::swf_input_translator *)this->m_parent_scene,
      &this->m_parent_scene->m_game->m_swf_input_translator,
      input_world,
      action,
      this->m_options_ui.m_object->movie,
      this->m_game->m_current_time_in_ms);
  }
  else if ( survarium::game_options::process_key_input((int)this, key, this) )
  {
    survarium::game_options::finish_binding(v5, (int)this);
    return 1;
  }
  return 1;
}
