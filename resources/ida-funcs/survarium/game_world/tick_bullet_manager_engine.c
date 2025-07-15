void __userpurge survarium::game_world::tick_bullet_manager_engine(
        survarium::game_world *this@<ecx>,
        int a2@<eax>,
        bool is_game_paused)
{
  survarium::bullet_manager *v3; // ecx

  v3 = *(survarium::bullet_manager **)(a2 + 572);
  if ( v3 )
  {
    if ( !is_game_paused )
      survarium::bullet_manager::tick(v3, *(_DWORD *)(*(_DWORD *)(a2 + 168) + 1012));
  }
}
