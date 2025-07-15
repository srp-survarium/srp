void __userpurge survarium::lobby_camera::on_focus(survarium::lobby_camera *this@<ecx>, bool b_focus_enter, char a3)
{
  int *v4; // eax
  int v5; // edx
  char *v6; // [esp+0h] [ebp-4h]

  v4 = (int *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(this->m_inverted_view_matrix.c.w) + 160) + 48))(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.c.w) + 160));
  v5 = *v4;
  v6 = (char *)&this[-1].m_capture_point.elements[1];
  if ( a3 )
    (*(void (__thiscall **)(int *, char *))(v5 + 16))(v4, v6);
  else
    (*(void (__thiscall **)(int *, char *))(v5 + 20))(v4, v6);
}
