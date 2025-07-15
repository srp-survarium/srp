char __thiscall survarium::login_menu::on_mouse_move(
        survarium::login_menu *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  const vostok::math::uint2 *v6; // eax
  survarium::game *m_game; // ecx
  survarium::flash_movie *v8; // ecx
  int v9; // eax
  survarium::flash_movie *v10; // ecx
  unsigned int xa; // [esp+1Ch] [ebp+8h]

  this[-1].m_game = (survarium::game *)((char *)this[-1].m_game + x);
  *(_DWORD *)&this[-1].m_is_ui_shown += y;
  v6 = survarium::base_game_scene::output_window_size((survarium::base_game_scene *)y);
  m_game = this[-1].m_game;
  if ( (int)m_game > 0 )
  {
    if ( (int)m_game > (signed int)v6->x )
      m_game = (survarium::game *)v6->x;
  }
  else
  {
    m_game = 0;
  }
  this[-1].m_game = m_game;
  v8 = (survarium::flash_movie *)v6->y;
  v9 = *(_DWORD *)&this[-1].m_is_ui_shown;
  if ( v9 > 0 )
  {
    if ( v9 > (int)v8 )
      v9 = (int)v8;
  }
  else
  {
    v9 = 0;
  }
  *(_DWORD *)&this[-1].m_is_ui_shown = v9;
  *(float *)&xa = (float)z;
  survarium::flash_movie::HandleMouseMove(
    v8,
    (int)this->survarium::base_game_scene::survarium::engine::__vftable[66].get_bullet_manager,
    (float)(int)this[-1].m_game,
    (float)v9,
    xa);
  survarium::flash_movie::HandleMouseMove(
    v10,
    *(_DWORD *)(*(_DWORD *)&this->gap10 + 264),
    (float)(int)this[-1].m_game,
    (float)*(int *)&this[-1].m_is_ui_shown,
    xa);
  return 1;
}
