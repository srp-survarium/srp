char __thiscall survarium::global_input_handler::on_keyboard_action(
        survarium::global_input_handler *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  vostok::input::keyboard *v5; // eax
  vostok::input::keyboard *v6; // eax
  survarium::game *m_game; // esi
  bool v8; // zf
  vostok::engine::console_vtbl *v9; // eax

  if ( action != kb_key_down )
    return 0;
  if ( key == key_grave )
  {
    m_game = this->m_game;
    v8 = !m_game->m_console->get_active(m_game->m_console);
    v9 = m_game->m_console->__vftable;
    if ( v8 )
      ((void (*)(void))v9->on_activate)();
    else
      ((void (*)(void))v9->on_deactivate)();
  }
  else
  {
    if ( key != key_f4 )
      return 0;
    v5 = input_world->get_keyboard(input_world);
    if ( !v5->is_key_down(v5, key_lmenu) )
    {
      v6 = input_world->get_keyboard(input_world);
      if ( !v6->is_key_down(v6, key_rmenu) )
        return 0;
    }
  }
  return 1;
}
