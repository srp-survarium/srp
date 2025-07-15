char __thiscall survarium::global_input_handler::on_keyboard_action(
        survarium::global_input_handler *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  const vostok::input::keyboard *v6; // eax
  const vostok::input::keyboard *v7; // eax
  survarium::game *m_game; // esi
  bool v9; // al
  vostok::engine::console_vtbl *v10; // edx

  if ( action != kb_key_down )
    return 0;
  if ( key == key_grave )
  {
    m_game = this->m_game;
    v9 = m_game->m_console->get_active(m_game->m_console);
    v10 = m_game->m_console->__vftable;
    if ( v9 )
      ((void (*)(void))v10->on_deactivate)();
    else
      ((void (*)(void))v10->on_activate)();
    return 1;
  }
  else if ( key == key_f4
         && ((v6 = input_world->get_keyboard(input_world), v6->is_key_down(v6, key_lmenu))
          || (v7 = input_world->get_keyboard(input_world), v7->is_key_down(v7, key_rmenu))) )
  {
    survarium::game::exit(this->m_game, "quit");
    return 1;
  }
  else
  {
    return 0;
  }
}
