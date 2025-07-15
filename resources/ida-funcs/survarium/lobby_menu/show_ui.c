void __thiscall survarium::lobby_menu::show_ui(survarium::lobby_menu *this, bool b_show)
{
  survarium::base_game_scene *v3; // ecx
  survarium::base_game_scene *v4; // ecx
  survarium::chat_handler *m_chat_handler; // esi
  survarium::base_game_scene *v6; // ecx
  int v7; // ecx
  int v8; // ecx

  if ( this->m_is_ui_shown != b_show )
  {
    if ( b_show )
    {
      survarium::base_game_scene::show_movie(&this->m_lobby_menu_ui, this, this);
      survarium::base_game_scene::show_movie(&this->m_message_ui, v3, this);
      survarium::base_game_scene::show_movie(&this->m_cursor_ui, v4, this);
      m_chat_handler = this->m_game->m_chat_handler;
      survarium::base_game_scene::show_movie(&m_chat_handler->m_chat_ui, v6, this);
      m_chat_handler->m_active = 1;
      this->m_is_ui_shown = b_show;
    }
    else
    {
      survarium::base_game_scene::hide_movie(this, &this->m_lobby_menu_ui, (int)this);
      survarium::base_game_scene::hide_movie(this, &this->m_message_ui, v7);
      survarium::base_game_scene::hide_movie(this, &this->m_cursor_ui, v8);
      survarium::chat_handler::hide(this->m_game->m_chat_handler, this, (int)this->m_game);
      this->m_is_ui_shown = 0;
    }
  }
}
