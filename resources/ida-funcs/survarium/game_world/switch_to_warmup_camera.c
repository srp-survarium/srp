void __thiscall survarium::game_world::switch_to_warmup_camera(survarium::game_world *this, int a3)
{
  survarium::player_input_handler *v3; // ecx
  int v4; // edi
  survarium::game_camera *v5; // edi

  v3 = *(survarium::player_input_handler **)(a3 + 13616);
  if ( v3 )
  {
    survarium::player_input_handler::set_input_mode(v3, warmup_mode);
    v4 = *(_DWORD *)(a3 + 13616);
    if ( v4 )
      v5 = (survarium::game_camera *)(v4 + 4);
    else
      v5 = 0;
    survarium::camera_director::switch_to_camera(*(survarium::camera_director **)(a3 + 152), v5);
  }
}
