void __thiscall survarium::login_menu::on_activate(survarium::login_menu *this)
{
  vostok::input::handler *v2; // ebx
  vostok::input::world *v3; // eax
  vostok::input::world *v4; // eax
  vostok::input::mouse *v5; // ebx
  void (__thiscall **p_set_exclusive_mode)(vostok::input::mouse *, bool); // esi
  bool v7; // al

  survarium::base_game_scene::on_activate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->add_handler(v3, v2);
  v4 = this->m_game->input_world(this->m_game);
  v5 = v4->get_mouse(v4);
  p_set_exclusive_mode = &v5->set_exclusive_mode;
  v7 = this->mouse_exclusive_mode(this);
  (*p_set_exclusive_mode)(v5, v7);
}
