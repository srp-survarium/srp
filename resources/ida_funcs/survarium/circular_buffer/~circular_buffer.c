void __usercall survarium::circular_buffer<survarium::client_player_history_item>::~circular_buffer<survarium::client_player_history_item>(
        survarium::circular_buffer<survarium::client_player_history_item> *this@<ecx>,
        int a2@<esi>)
{
  unsigned int v2; // ecx

  if ( *(_DWORD *)(a2 + 12) != *(_DWORD *)(a2 + 16) )
  {
    v2 = *(_DWORD *)(a2 + 8);
    do
      *(_DWORD *)(a2 + 16) = (*(_DWORD *)(a2 + 16) + 1) % v2;
    while ( *(_DWORD *)(a2 + 12) != *(_DWORD *)(a2 + 16) );
  }
  if ( *(_DWORD *)a2 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 4) + 24))(*(_DWORD *)(a2 + 4), *(_DWORD *)a2);
    *(_DWORD *)a2 = 0;
  }
}
