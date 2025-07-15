void __usercall survarium::lobby_menu::on_friendship_status_recivied(
        survarium::lobby_menu *this@<esi>,
        const vostok::messaging::friendship_actions_enum type@<eax>,
        survarium::lobby_menu *a3@<ecx>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  survarium::scheduler *v6; // ecx

  v3 = type - 6;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( !v5 )
      {
        survarium::lobby_menu::fill_ignore_list(a3, (int)this);
        return;
      }
      if ( v5 != 1 )
        return;
    }
    survarium::lobby_menu::fill_friend_list(a3, (int)this);
    if ( *(_DWORD *)&this->m_update_friends_status_handler < 0 )
      survarium::scheduler::unregister(v6, (int)&this->m_scheduler, &this->m_update_friends_status_handler);
    survarium::lobby_menu::request_friends_status_from_server((survarium::lobby_menu *)v6, (unsigned int)this);
  }
  else
  {
    survarium::lobby_menu::fill_found_players(a3, (int)this);
  }
}
