void __usercall survarium::game_world::switch_to_free_fly_camera(survarium::game_world *this@<ecx>, _DWORD *a2@<eax>)
{
  survarium::camera_director *v2; // edi
  survarium::camera_director *v3; // [esp-8h] [ebp-Ch]

  v2 = (survarium::camera_director *)a2[40];
  v3 = (survarium::camera_director *)a2[141];
  a2[175] = 1;
  survarium::camera_director::switch_to_camera(
    v3,
    v2,
    (survarium::game_camera *)v3,
    (const char *)&stru_96A440.m_inverted_view.lines[1]);
}
