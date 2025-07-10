void __thiscall survarium::game_world::show_ui(survarium::game_world *this, bool b_show)
{
  survarium::game *m_game; // ecx
  survarium::chat_handler *m_chat_handler; // esi
  int v5; // ecx
  survarium::chat_handler *v6; // esi

  if ( this->m_is_ui_shown != b_show )
  {
    if ( b_show )
    {
      survarium::base_game_scene::show_movie(&this->game_ui.m_game_hud_ui, this, this);
      if ( this->m_game->m_network_client->has_bandwidth(this->m_game->m_network_client) )
      {
        m_game = this->m_game;
        m_chat_handler = m_game->m_chat_handler;
        survarium::base_game_scene::show_movie(&m_chat_handler->m_chat_ui, (survarium::base_game_scene *)m_game, this);
        m_chat_handler->m_active = 1;
        this->m_is_ui_shown = b_show;
        return;
      }
    }
    else
    {
      survarium::base_game_scene::hide_movie(this, &this->game_ui.m_game_hud_ui, (int)this);
      v6 = this->m_game->m_chat_handler;
      if ( v6->m_active )
        survarium::chat_handler::hide(v6, this, v5);
    }
    this->m_is_ui_shown = b_show;
  }
}
