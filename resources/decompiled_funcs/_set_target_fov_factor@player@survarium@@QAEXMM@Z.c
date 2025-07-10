void __userpurge survarium::player::set_target_fov_factor(
        survarium::player *this@<ecx>,
        int a2@<eax>,
        float target_fov_factor,
        float transition_time)
{
  int v4; // ecx

  v4 = *(int *)((char *)&dword_10F0C + a2);
  *(float *)(a2 + 69404) = *(float *)(a2 + 69408);
  *(int *)((char *)&dword_10F24 + a2) = LODWORD(s_aim_transition_time);
  *(int *)((char *)&dword_10F28 + a2) = v4;
  *(float *)((char *)&dword_10F18 + a2) = target_fov_factor;
}
