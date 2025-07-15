void __userpurge survarium::game_world::switch_to_player_camera(
        survarium::game_world *this@<ecx>,
        int a2@<esi>,
        bool first_person_view)
{
  int v3; // eax
  int v4; // ecx
  bool v5; // dl
  survarium::camera_director *v6; // ecx
  int v7; // eax

  v3 = *(_DWORD *)(a2 + 568);
  if ( v3 )
  {
    v4 = first_person_view ? 0 : 2;
    *(_DWORD *)(a2 + 700) = v4;
    v5 = *(_BYTE *)(v3 + 412) || *(_DWORD *)(v3 + 408) != v4;
    *(_DWORD *)(v3 + 408) = v4;
    *(_BYTE *)(v3 + 412) = v5;
    v6 = (survarium::camera_director *)"First Person View";
    if ( !first_person_view )
      v6 = (survarium::camera_director *)&stru_96A440;
    v7 = *(_DWORD *)(a2 + 568);
    if ( v7 )
      survarium::camera_director::switch_to_camera(
        v6,
        *(survarium::camera_director **)(a2 + 160),
        (survarium::game_camera *)(v7 + 4),
        (const char *)v6);
    else
      survarium::camera_director::switch_to_camera(v6, *(survarium::camera_director **)(a2 + 160), 0, (const char *)v6);
  }
}
