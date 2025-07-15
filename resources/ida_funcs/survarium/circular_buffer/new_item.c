survarium::client_player_history_item *__usercall survarium::circular_buffer<survarium::client_player_history_item>::new_item@<eax>(
        survarium::circular_buffer<survarium::client_player_history_item> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  unsigned int v5; // ebx
  int v6; // ecx
  unsigned int v7; // edx
  int v8; // eax
  int v9; // ecx

  v2 = a2[3];
  v3 = *a2 + 96 * v2;
  if ( v3 )
  {
    survarium::player_input::player_input((survarium::player_input *)(*a2 + 96 * v2));
    survarium::weapon_state::weapon_state((survarium::weapon_state *)(v3 + 88));
  }
  v4 = a2[3];
  v5 = a2[2];
  v6 = 3 * v4;
  v7 = (v4 + 1) % v5;
  v8 = a2[4];
  v9 = *a2 + 32 * v6;
  a2[3] = v7;
  if ( v7 == v8 )
    a2[4] = (v8 + 1) % v5;
  return (survarium::client_player_history_item *)v9;
}
