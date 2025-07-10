int __userpurge survarium::messaging_client::parse_receiver_channel@<eax>(
        const wchar_t *w_receiver_name@<esi>,
        survarium::messaging_client *this,
        bool in_match)
{
  if ( w_receiver_name == wcsstr(w_receiver_name, &word_9711B8)
    || w_receiver_name == wcsstr(w_receiver_name, L"general") )
  {
    return 1;
  }
  if ( w_receiver_name == wcsstr(w_receiver_name, &word_9711D4) || w_receiver_name == wcsstr(w_receiver_name, L"squad") )
    return 8;
  if ( w_receiver_name == wcsstr(w_receiver_name, &word_9711EC) || w_receiver_name == wcsstr(w_receiver_name, L"clan") )
    return 3;
  if ( !in_match )
    return 4;
  if ( w_receiver_name == wcsstr(w_receiver_name, &word_971204) || w_receiver_name == wcsstr(w_receiver_name, L"team") )
    return (this->m_game_team_id != team_1) + 6;
  if ( w_receiver_name == wcsstr(w_receiver_name, &word_97121C) || w_receiver_name == wcsstr(w_receiver_name, L"all") )
    return 5;
  else
    return 4;
}
