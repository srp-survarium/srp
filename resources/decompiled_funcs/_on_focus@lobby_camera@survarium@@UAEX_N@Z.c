void __thiscall survarium::lobby_camera::on_focus(survarium::lobby_camera *this, bool b_focus_enter)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(this->m_inverted_view_matrix.c.w) + 168) + 40))(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.c.w) + 168));
  if ( b_focus_enter )
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)v3 + 16))(v3, &this[-1].m_rotation_delta.y);
  else
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)v3 + 20))(v3, &this[-1].m_rotation_delta.y);
}
