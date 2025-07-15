void __usercall survarium::base_player::activate_physics(survarium::base_player *this@<ecx>, int a2@<eax>)
{
  vostok::physics::bt_character_controller *v3; // ecx
  vostok::physics::bullet_character_controller *v4; // ecx
  int v5; // esi
  int v6; // eax

  if ( !vostok::physics::bt_character_controller::is_activated(
          (vostok::physics::bt_character_controller *)this,
          *(int *)((char *)&dword_10E74 + a2)) )
    (*(void (__thiscall **)(_DWORD, _DWORD, int, int))(**(_DWORD **)(a2 + 780) + 44))(
      *(_DWORD *)(a2 + 780),
      *(_DWORD *)(*(int *)((char *)&dword_10E78 + a2) + 300),
      64,
      17);
  if ( !vostok::physics::bt_character_controller::is_activated(v3, *(int *)((char *)&dword_10E74 + a2)) )
  {
    v5 = *(int *)((char *)&dword_10E74 + a2);
    v6 = *(_DWORD *)(v5 + 8);
    if ( s_cc_use_old_controller_value )
      vostok::physics::old_bullet_character_controller::insert(
        *(vostok::physics::old_bullet_character_controller **)(v6 + 56),
        *(btDynamicsWorld **)(v5 + 4));
    else
      vostok::physics::bullet_character_controller::insert(v4, *(btDynamicsWorld **)v5, *(btStackAlloc **)(v6 + 56));
  }
}
