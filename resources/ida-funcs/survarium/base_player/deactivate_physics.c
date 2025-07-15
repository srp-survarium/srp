void __usercall survarium::base_player::deactivate_physics(survarium::base_player *this@<ecx>, int a2@<eax>)
{
  vostok::physics::old_bullet_character_controller *v3; // ecx
  int *v4; // esi

  if ( vostok::physics::bt_character_controller::is_activated(
         (vostok::physics::bt_character_controller *)this,
         *(int *)((char *)&dword_10E74 + a2)) )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 780) + 56))(
      *(_DWORD *)(a2 + 780),
      *(_DWORD *)(*(int *)((char *)&dword_10E78 + a2) + 300));
    v4 = *(int **)((char *)&dword_10E74 + a2);
    if ( s_cc_use_old_controller_value )
      vostok::physics::old_bullet_character_controller::remove(v3, v4[1]);
    else
      vostok::physics::bullet_character_controller::remove((vostok::physics::bullet_character_controller *)v3, *v4);
  }
}
