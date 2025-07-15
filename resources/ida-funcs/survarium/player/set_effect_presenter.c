void __userpurge survarium::player::set_effect_presenter(
        survarium::player *this@<ecx>,
        int a2@<eax>,
        survarium::base_game_effect_presenter *presenter)
{
  _DWORD *v3; // esi
  int v4; // ecx

  v3 = (_DWORD *)(a2 + 840);
  v4 = *(_DWORD *)(a2 + 840);
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
  *v3 = presenter;
}
