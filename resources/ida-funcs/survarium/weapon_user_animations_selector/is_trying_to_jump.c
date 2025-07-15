BOOL __usercall survarium::weapon_user_animations_selector::is_trying_to_jump@<eax>(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<esi>)
{
  vostok::physics::old_bullet_character_controller *v2; // ecx
  int v3; // eax
  int v4; // eax

  if ( (*(_DWORD *)(*(_DWORD *)(a2 + 60) + 752) & 0x10) == 0 )
    return 0;
  if ( *(_BYTE *)(*(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)(a2 + 60) + 264) + 8))(*(_DWORD *)(a2 + 60) + 264)
                + 1744) )
    return 0;
  v3 = *(_DWORD *)(a2 + 60);
  if ( *(_BYTE *)(v3 + 69896) || *(float *)((char *)&locret_110FB + v3 + 1) < *(float *)(v3 + 69804) )
    return 0;
  v4 = *(int *)((char *)&dword_10E74 + v3);
  if ( !s_cc_use_old_controller_value )
    return vostok::physics::bullet_character_controller::can_jump(*(vostok::physics::bullet_character_controller **)v4);
  if ( *(_BYTE *)(*(_DWORD *)(v4 + 4) + 560) )
    return 0;
  return vostok::physics::old_bullet_character_controller::on_ground(v2);
}
