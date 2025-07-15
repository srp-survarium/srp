void __userpurge survarium::player_input_handler::on_focus(
        survarium::player_input_handler *this@<ecx>,
        bool b_focus_enter,
        char a3)
{
  int *v4; // eax
  int v5; // edx
  char *p_m_key_binder_context; // [esp+0h] [ebp-4h]

  v4 = (int *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this->m_game_toggle_actions.m_buffer[31] + 160)
                                            + 48))(*(_DWORD *)(*(_DWORD *)&this->m_game_toggle_actions.m_buffer[31] + 160));
  v5 = *v4;
  p_m_key_binder_context = (char *)&this[-1].m_key_binder_context;
  if ( a3 )
    (*(void (__thiscall **)(int *, char *))(v5 + 16))(v4, p_m_key_binder_context);
  else
    (*(void (__thiscall **)(int *, char *))(v5 + 20))(v4, p_m_key_binder_context);
}
