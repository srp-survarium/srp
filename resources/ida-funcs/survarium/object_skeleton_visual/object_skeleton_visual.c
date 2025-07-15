void __userpurge survarium::object_skeleton_visual::object_skeleton_visual(
        survarium::object_skeleton_visual *this@<ecx>,
        LARGE_INTEGER *a2@<edi>,
        survarium::base_game_scene *w,
        survarium::simple_game_project *project)
{
  vostok::animation::hand_to_weapon_ik_solver *v4; // ecx
  vostok::animation::fingers_to_weapon_corrector *v5; // ecx
  vostok::animation::animation_player *v6; // ecx
  vostok::timing::timer *v7; // ecx

  survarium::game_object_static::game_object_static(this, a2, w);
  a2->LowPart = (unsigned int)&survarium::object_skeleton_visual::`vftable';
  vostok::animation::hand_to_weapon_ik_solver::hand_to_weapon_ik_solver(v4, (int)&a2[42]);
  vostok::animation::fingers_to_weapon_corrector::fingers_to_weapon_corrector(v5, (int)&a2[201].HighPart);
  *(__int64 *)((char *)&a2[942].QuadPart + 4) = (unsigned int)project;
  a2[943].HighPart = 0;
  a2[945].HighPart = 0;
  a2[947].LowPart = 0;
  vostok::animation::animation_player::animation_player(v6, (int)&a2[950]);
  vostok::timing::timer::timer(v7, a2 + 9489);
  a2[9492].HighPart = -1;
}
