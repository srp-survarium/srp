void __userpurge survarium::game_effect_player::present(
        survarium::game_effect_player *this@<ecx>,
        int a2@<eax>,
        survarium::base_game_effect_presenter *presenter,
        survarium::base_player *player)
{
  _DWORD *i; // edi
  int v5; // esi
  unsigned int v6; // ebx
  int v7; // ecx
  unsigned int v8; // [esp+4h] [ebp-4h]

  for ( i = *(_DWORD **)(a2 + 44); i; i = (_DWORD *)i[22] )
  {
    v5 = i[1] + 16 * i[6];
    v6 = 0;
    v8 = *(_DWORD *)(v5 + 12);
    if ( v8 )
    {
      do
      {
        v7 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * v6);
        (*(void (__thiscall **)(int, survarium::base_game_effect_presenter *, _DWORD *))(*(_DWORD *)v7 + 12))(
          v7,
          presenter,
          i + 4);
        ++v6;
      }
      while ( v6 < v8 );
    }
  }
  presenter->present(presenter, player);
}
