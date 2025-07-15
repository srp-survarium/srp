void __thiscall survarium::game_world::switch_to_player_camera(
        survarium::game_world *this,
        int first_person_view,
        char a4)
{
  survarium::player_input_handler *v4; // ecx
  int v5; // eax
  survarium::game_camera *v6; // edi

  v4 = *(survarium::player_input_handler **)(first_person_view + 13616);
  if ( v4 )
  {
    survarium::player_input_handler::set_input_mode(v4, a4 != 0 ? first_person_mode : third_person_mode);
    v5 = *(_DWORD *)(first_person_view + 13616);
    if ( v5 )
      v6 = (survarium::game_camera *)(v5 + 4);
    else
      v6 = 0;
    survarium::camera_director::switch_to_camera(*(survarium::camera_director **)(first_person_view + 152), v6);
  }
}
