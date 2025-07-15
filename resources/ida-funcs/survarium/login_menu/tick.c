void __thiscall survarium::login_menu::tick(
        survarium::login_menu *this,
        unsigned int frame_delta_in_ms,
        unsigned int current_time_in_ms,
        bool is_game_paused)
{
  survarium::login_menu *m_block_btn_time; // ecx
  survarium::flash_movie *v6; // ecx
  float current_time_in_msa; // [esp+18h] [ebp+Ch]

  survarium::base_game_scene::tick(this, frame_delta_in_ms, current_time_in_ms, is_game_paused);
  m_block_btn_time = (survarium::login_menu *)this->m_block_btn_time;
  if ( m_block_btn_time && (unsigned int)m_block_btn_time < current_time_in_ms )
  {
    this->m_block_btn_time = 0;
    survarium::login_menu::enable_button(m_block_btn_time, (int)this, 1);
  }
  current_time_in_msa = (double)frame_delta_in_ms * 0.001;
  survarium::flash_movie::Advance(
    (survarium::flash_movie *)m_block_btn_time,
    (int)this->m_login_menu_ui.m_object->movie,
    current_time_in_msa,
    0);
  survarium::flash_movie::Advance(v6, (int)this->m_cursor_ui.m_object->movie, current_time_in_msa, 0);
}
