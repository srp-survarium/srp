void __userpurge survarium::player::kill(
        survarium::player *this@<ecx>,
        survarium::base_player *a2@<edi>,
        vostok::animation::subscribed_channel **current_time_in_ms)
{
  int v3; // eax
  bool v4; // bl
  survarium::player *v5; // ecx
  int v6; // eax
  bool v7; // cl
  float *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  survarium::game_world_ui *v11; // esi
  survarium::game_world_ui *v12; // ecx

  v3 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + (_DWORD)a2) + 952) + 8);
  LOBYTE(this) = a2->id;
  v4 = v3
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && *(_BYTE *)(v3 + 52) == (_BYTE)this;
  survarium::player::remove_alive(this, (int)a2);
  survarium::base_player::on_player_death(a2);
  if ( v4 )
  {
    v6 = *(int *)((char *)&dword_10EF4 + (_DWORD)a2);
    v7 = *(_BYTE *)(v6 + 412) || *(_DWORD *)(v6 + 408) != 2;
    *(_BYTE *)(v6 + 412) = v7;
    *(_DWORD *)(v6 + 408) = 2;
    v8 = *(float **)((char *)&dword_10EF4 + (_DWORD)a2);
    v9 = s_death_camera_pitch;
    v10 = s_death_camera_distance;
    v8[99] = s_death_camera_yaw;
    v8[100] = v9;
    v8[101] = v10;
    *(_DWORD *)(*(int *)((char *)&dword_10EF4 + (_DWORD)a2) + 416) = 16;
    survarium::game_world::switch_camera_mode(
      *(survarium::game_world **)((char *)&dword_10F00 + (_DWORD)a2),
      *(const survarium::input_mode_type_enum *)(*(int *)((char *)&dword_10EF4 + (_DWORD)a2) + 408));
    v11 = *(survarium::game_world_ui **)((char *)&dword_10F7C + (_DWORD)a2);
    survarium::game_world_ui::show_ammo_indicator(v11, 0);
    survarium::game_world_ui::show_quick_slots(v12, v11, 0);
  }
  survarium::player::select_animations(v5, (int)a2, current_time_in_ms);
}
