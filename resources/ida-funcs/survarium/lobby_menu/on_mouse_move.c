char __thiscall survarium::lobby_menu::on_mouse_move(
        survarium::login_menu *this,
        vostok::input::world *input_world,
        int x,
        int y,
        int z)
{
  bool *p_m_is_ui_shown; // ebx
  int *p_m_scheduler; // edi
  int *v9; // [esp+18h] [ebp+Ch]

  p_m_is_ui_shown = &this[-1].m_is_ui_shown;
  p_m_scheduler = (int *)&this[-1].m_scheduler;
  if ( *(_BYTE *)(*(_DWORD *)LODWORD(this->m_inverted_view_matrix.i.z) + 276) )
  {
    survarium::mouse_helper::get_position(
      (survarium::mouse_helper *)&this->m_inverted_view_matrix.lines[0].elements[2],
      p_m_scheduler,
      (int *)&this[-1].m_is_ui_shown);
  }
  else
  {
    *(_DWORD *)p_m_is_ui_shown += x;
    *p_m_scheduler += y;
    v9 = (int *)&this[-1].m_scheduler.m_active_objects._M_impl._M_start[2].m_id[66];
    vostok::math::clamp<int>(*v9);
    vostok::math::clamp<int>(v9[1]);
  }
  (*(void (__thiscall **)(float *, _DWORD, int, int))(LODWORD(this[-1].m_inverted_view_matrix.i.w) + 48))(
    &this[-1].m_inverted_view_matrix.i.w,
    *(_DWORD *)p_m_is_ui_shown,
    *p_m_scheduler,
    z);
  return 1;
}
