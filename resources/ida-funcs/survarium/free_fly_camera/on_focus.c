void __thiscall survarium::free_fly_camera::on_focus(survarium::free_fly_camera *this, bool b_focus_enter)
{
  vostok::input::handler *v2; // esi
  vostok::input::world *v3; // eax
  vostok::input::handler *v4; // esi
  vostok::input::world *v5; // eax

  if ( b_focus_enter )
  {
    if ( this )
      v2 = &this->vostok::input::handler;
    else
      v2 = 0;
    v3 = this->m_game_scene->m_game->input_world(this->m_game_scene->m_game);
    v3->add_handler(v3, v2);
  }
  else
  {
    if ( this )
      v4 = &this->vostok::input::handler;
    else
      v4 = 0;
    v5 = this->m_game_scene->m_game->input_world(this->m_game_scene->m_game);
    v5->remove_handler(v5, v4);
  }
}
