void __thiscall survarium::game_world::on_deactivate(survarium::game_world *this)
{
  vostok::input::handler *v2; // edi
  vostok::input::world *v3; // eax
  survarium::game *v4; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  vostok::input::world *v6; // edi
  vostok::input::world *v7; // ebx
  void (__thiscall **p_remove_handler)(vostok::input::world *, int); // esi
  int v9; // eax

  survarium::base_game_scene::on_deactivate(this);
  if ( this )
    v2 = &this->vostok::input::handler;
  else
    v2 = 0;
  v3 = this->m_game->input_world(this->m_game);
  v3->remove_handler(v3, v2);
  survarium::game::deactivate_main_menu(v4, (int)this->m_game);
  m_movie = this->game_ui.m_game_hud_ui.m_object->movie->m_movie;
  m_movie->ForceCollectGarbage(m_movie, 2u);
  if ( vostok::core::journal_usage() == record_journal )
  {
    v6 = this->m_game->input_world(this->m_game);
    v7 = this->m_game->input_world(this->m_game);
    p_remove_handler = (void (__thiscall **)(vostok::input::world *, int))&v7->remove_handler;
    v9 = (int)v6->get_journaling_handler(v6);
    (*p_remove_handler)(v7, v9);
  }
}
