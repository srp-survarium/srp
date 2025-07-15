void __thiscall survarium::lobby_menu::set_mouse_position(survarium::lobby_menu *this, int x, int y, const int z)
{
  survarium::game *m_game; // ecx
  survarium::swf_input_translator *v6; // ecx
  survarium::lobby_menu *v7; // ecx
  survarium::swf_input_translator *v8; // ecx
  float v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+Ch] [ebp-Ch]
  struct survarium::flash_movie *v11; // [esp+10h] [ebp-8h]
  struct survarium::flash_movie *v12; // [esp+10h] [ebp-8h]
  survarium::flash_movie_resource *m_object; // [esp+20h] [ebp+8h]
  survarium::flash_movie_resource *v14; // [esp+20h] [ebp+8h]

  m_game = this->m_game;
  this->m_mouse_x = x;
  this->m_mouse_y = y;
  m_object = this->m_cursor_ui.m_object;
  m_game->input_world(m_game);
  survarium::swf_input_translator::process_mouse_move(
    v6,
    (float)z,
    COERCE_STRUCT_VOSTOK_INPUT_WORLD_((float)this->m_mouse_x),
    (float)this->m_mouse_y,
    *(float *)&m_object->movie,
    v9,
    v11);
  if ( survarium::lobby_menu::lobby_client(v7, (int)this)->m_net_client_connected )
  {
    v14 = this->m_lobby_menu_ui.m_object;
    this->m_game->input_world(this->m_game);
    survarium::swf_input_translator::process_mouse_move(
      v8,
      (float)z,
      COERCE_STRUCT_VOSTOK_INPUT_WORLD_((float)this->m_mouse_x),
      (float)this->m_mouse_y,
      *(float *)&v14->movie,
      v10,
      v12);
  }
}
