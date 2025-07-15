void __usercall survarium::player_input_handler::set_yaw_pitch_distance(
        survarium::player_input_handler *this@<ecx>,
        float *a2@<eax>)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = s_death_camera_distance;
  v3 = s_death_camera_pitch;
  a2[99] = s_death_camera_yaw;
  a2[100] = v3;
  a2[101] = v2;
}
