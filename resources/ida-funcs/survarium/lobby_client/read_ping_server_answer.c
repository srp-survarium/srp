char __thiscall survarium::lobby_client::read_ping_server_answer(
        survarium::lobby_client *this,
        survarium::lobby_client *reader)
{
  int *v2; // eax
  int v3; // edx

  v2 = *(int **)&this->account_nickname_[4];
  v3 = *v2;
  *(_DWORD *)&this->account_nickname_[4] = v2 + 1;
  survarium::lobby_menu::set_ping(
    reader->m_game->m_lobby_menu,
    (__int64)((double)(reader->m_game->m_current_time_in_ms - v3) * 0.5));
  return 1;
}
