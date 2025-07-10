void __thiscall survarium::player_input_handler::on_focus(survarium::player_input_handler *this, bool b_focus_enter)
{
  int v3; // eax

  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this->m_game_actions.m_buffer[31].m_store[4] + 168) + 40))(*(_DWORD *)(*(_DWORD *)&this->m_game_actions.m_buffer[31].m_store[4] + 168));
  if ( b_focus_enter )
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v3 + 16))(v3, &this[-1].m_key_binder_context);
  else
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v3 + 20))(v3, &this[-1].m_key_binder_context);
}
