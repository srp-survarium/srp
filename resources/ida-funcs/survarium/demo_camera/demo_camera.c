void __userpurge survarium::demo_camera::demo_camera(
        survarium::demo_camera *this@<ecx>,
        int a2@<eax>,
        survarium::base_game_scene *w,
        survarium::camera_director *cd)
{
  _DWORD *v4; // eax

  survarium::game_camera::game_camera(this, a2);
  v4[37] = 0;
  *v4 = &survarium::demo_camera::`vftable';
  v4[40] = w;
}
