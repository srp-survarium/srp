char __thiscall survarium::game_options::on_mouse_key_action(
        survarium::game_options *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        survarium::flash_movie *action)
{
  survarium::base_game_scene *v5; // ecx
  unsigned int v7; // edx
  float v8; // [esp+4h] [ebp-10h]

  if ( this->m_waiting_for_bind_action == kLASTACTION || action )
  {
    v7 = 0;
    switch ( button )
    {
      case mouse_button_left:
        v7 = 0;
        break;
      case mouse_button_right:
        v7 = 1;
        break;
      case mouse_button_middle:
        v7 = 2;
        break;
    }
    survarium::flash_movie::HandleMouseBtn(
      action,
      (float)this->m_mouse_pos.x,
      this->m_options_ui.m_object->movie,
      v7,
      (float)this->m_mouse_pos.y,
      v8);
  }
  else if ( survarium::game_options::process_key_input(0, button, this) )
  {
    Scaleform::GFx::Movie::Invoke(this->m_options_ui.m_object->movie->m_movie, "root.end_keybind", 0, 0, 0);
    survarium::base_game_scene::show_movie(&this->m_cursor_ui, v5, this->m_parent_scene);
    this->m_waiting_for_bind_action = kLASTACTION;
    return 1;
  }
  return 1;
}
