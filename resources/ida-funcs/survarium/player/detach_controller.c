void __usercall survarium::player::detach_controller(survarium::player *this@<ecx>, int a2@<esi>)
{
  int v2; // ecx
  int v3; // ecx
  _DWORD *v4; // eax
  survarium::camera_director *v5; // edi
  survarium::game_camera *v6; // [esp-8h] [ebp-Ch]

  v2 = *(_DWORD *)(a2 + 64);
  if ( v2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 68))(v2, 0);
  }
  v3 = *(int *)((char *)&dword_10F00 + a2);
  *(int *)((char *)&dword_10F7C + a2) = 0;
  *(int *)((char *)&dword_10EF4 + a2) = 0;
  *(int *)((char *)&dword_10EF8 + a2) = 0;
  *(int *)((char *)&dword_10EFC + a2) = 0;
  *(_DWORD *)(v3 + 568) = 0;
  v4 = *(_DWORD **)((char *)&dword_10F00 + a2);
  v5 = (survarium::camera_director *)v4[40];
  v6 = (survarium::game_camera *)v4[141];
  v4[175] = 1;
  survarium::camera_director::switch_to_camera(
    (survarium::camera_director *)v3,
    v5,
    v6,
    (const char *)&stru_96A440.m_inverted_view.lines[1]);
  *(_BYTE *)(a2 + 280) = 1;
}
