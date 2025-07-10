char __thiscall survarium::game_options::on_mouse_move(
        survarium::game_options *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  survarium::base_game_scene *m_parent_scene; // eax
  int *v7; // eax
  int v8; // ecx
  survarium::flash_movie *v9; // ecx
  int v10; // eax
  survarium::flash_movie *v11; // ecx
  unsigned int xa; // [esp+1Ch] [ebp+8h]

  if ( this->m_waiting_for_bind_action == kLASTACTION )
  {
    this->m_mouse_pos.x += x;
    m_parent_scene = this->m_parent_scene;
    this->m_mouse_pos.y += y;
    v7 = (int *)survarium::base_game_scene::output_window_size((survarium::base_game_scene *)y, (int)m_parent_scene);
    v8 = this->m_mouse_pos.x;
    if ( v8 > 0 )
    {
      if ( v8 > *v7 )
        v8 = *v7;
    }
    else
    {
      v8 = 0;
    }
    this->m_mouse_pos.x = v8;
    v9 = (survarium::flash_movie *)v7[1];
    v10 = this->m_mouse_pos.y;
    if ( v10 > 0 )
    {
      if ( v10 > (int)v9 )
        v10 = (int)v9;
    }
    else
    {
      v10 = 0;
    }
    this->m_mouse_pos.y = v10;
    *(float *)&xa = (double)z * 0.0083333338;
    survarium::flash_movie::HandleMouseMove(
      v9,
      (int)this->m_cursor_ui.m_object->movie,
      (float)this->m_mouse_pos.x,
      (float)v10,
      xa);
    survarium::flash_movie::HandleMouseMove(
      v11,
      (int)this->m_options_ui.m_object->movie,
      (float)this->m_mouse_pos.x,
      (float)this->m_mouse_pos.y,
      xa);
  }
  return 1;
}
