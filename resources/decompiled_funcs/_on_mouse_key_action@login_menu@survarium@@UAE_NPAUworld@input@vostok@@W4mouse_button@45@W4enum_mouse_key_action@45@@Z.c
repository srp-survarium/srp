char __thiscall survarium::login_menu::on_mouse_key_action(
        survarium::login_menu *this,
        vostok::input::world *input_world,
        vostok::input::mouse_button button,
        survarium::flash_movie *action)
{
  survarium::bullet_manager *(__thiscall *get_bullet_manager)(survarium::engine *); // edx
  float v5; // xmm1_4
  float m_game; // xmm0_4
  unsigned int v7; // ecx

  get_bullet_manager = this->survarium::base_game_scene::survarium::engine::__vftable[66].get_bullet_manager;
  v5 = (float)*(int *)&this[-1].m_is_ui_shown;
  m_game = (float)(int)this[-1].m_game;
  v7 = 0;
  switch ( button )
  {
    case mouse_button_left:
      v7 = 0;
      break;
    case mouse_button_right:
      v7 = 1;
      break;
    case mouse_button_middle:
      v7 = 2;
      break;
  }
  survarium::flash_movie::HandleMouseBtn(action, m_game, (survarium::flash_movie *)get_bullet_manager, v7, v5, v5);
  return 1;
}
