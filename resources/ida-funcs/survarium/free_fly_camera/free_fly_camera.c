void __userpurge survarium::free_fly_camera::free_fly_camera(
        survarium::free_fly_camera *this@<ecx>,
        int a2@<edi>,
        survarium::base_game_scene *w,
        survarium::camera_director *cd)
{
  survarium::game_effect_player *v4; // ecx

  survarium::game_camera::game_camera(this, a2);
  *(_DWORD *)a2 = &survarium::free_fly_camera::`vftable'{for `survarium::game_camera'};
  *(_DWORD *)(a2 + 148) = &survarium::free_fly_camera::`vftable'{for `vostok::input::handler'};
  survarium::game_effect_player::game_effect_player(v4, a2 + 152);
  *(_DWORD *)(a2 + 208) = w;
  *(float *)(a2 + 216) = FLOAT_N1_0;
  *(_DWORD *)(a2 + 212) = 0;
  *(_DWORD *)(a2 + 220) = 0;
  *(_DWORD *)(a2 + 224) = 0;
  *(_DWORD *)(a2 + 228) = 0;
  *(_DWORD *)(a2 + 232) = 0;
  *(_DWORD *)(a2 + 236) = 0;
  *(_DWORD *)(a2 + 240) = 0;
  *(_DWORD *)(a2 + 244) = 0;
  *(_DWORD *)(a2 + 248) = 0;
  *(_DWORD *)(a2 + 252) = 0;
}
