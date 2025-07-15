void __fastcall survarium::base_player::unsubscribe_from_player_death(
        survarium::base_player *this,
        int a2,
        survarium::player_death_subscriber *subscriber)
{
  survarium::player_death_subscriber *v3; // eax
  survarium::player_death_subscriber *v4; // ecx
  survarium::player_death_subscriber *next; // esi
  survarium::player_death_subscriber *v6; // eax

  v3 = *(survarium::player_death_subscriber **)(a2 + 452);
  if ( v3 )
  {
    v4 = 0;
    while ( v3 != subscriber )
    {
      v4 = v3;
      v3 = v3->next;
      if ( !v3 )
      {
        if ( subscriber )
          return;
        break;
      }
    }
    next = v3->next;
    if ( v4 )
      v4->next = next;
    else
      *(_DWORD *)(a2 + 452) = next;
    if ( !v3->next )
    {
      v6 = v4;
      if ( !v4 )
        v6 = *(survarium::player_death_subscriber **)(a2 + 452);
      *(_DWORD *)(a2 + 456) = v6;
    }
  }
}
