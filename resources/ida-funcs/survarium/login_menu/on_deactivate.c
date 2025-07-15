void __thiscall survarium::login_menu::on_deactivate(survarium::login_menu *this)
{
  vostok::input::handler *v2; // edi
  vostok::input::world *v3; // eax

  survarium::base_game_scene::on_deactivate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->remove_handler(v3, v2);
}
