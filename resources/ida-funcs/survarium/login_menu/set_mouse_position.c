void __thiscall survarium::login_menu::set_mouse_position(survarium::login_menu *this, int x, int y, const int z)
{
  survarium::game *m_game; // ecx
  survarium::swf_input_translator *v6; // ecx
  survarium::swf_input_translator *v7; // ecx
  float v8; // [esp+Ch] [ebp-Ch]
  float v9; // [esp+Ch] [ebp-Ch]
  struct survarium::flash_movie *v10; // [esp+10h] [ebp-8h]
  struct survarium::flash_movie *v11; // [esp+10h] [ebp-8h]
  survarium::flash_movie_resource *m_object; // [esp+20h] [ebp+8h]
  survarium::flash_movie_resource *v13; // [esp+20h] [ebp+8h]

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
    v8,
    v10);
  v13 = this->m_login_menu_ui.m_object;
  this->m_game->input_world(this->m_game);
  survarium::swf_input_translator::process_mouse_move(
    v7,
    (float)z,
    COERCE_STRUCT_VOSTOK_INPUT_WORLD_((float)this->m_mouse_x),
    (float)this->m_mouse_y,
    *(float *)&v13->movie,
    v9,
    v11);
}
