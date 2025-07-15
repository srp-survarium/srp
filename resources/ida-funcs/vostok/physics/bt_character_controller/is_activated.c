bool __usercall vostok::physics::bt_character_controller::is_activated@<al>(
        vostok::physics::bt_character_controller *this@<ecx>,
        int a2@<edi>)
{
  int v2; // esi
  vostok::physics::bullet_character_controller *v3; // ecx
  btDynamicsWorld *v4; // eax

  if ( !s_cc_use_old_controller_value )
  {
    v2 = *(_DWORD *)(a2 + 4);
    if ( !*(_DWORD *)(v2 + 20) )
      goto LABEL_8;
    vostok::physics::old_bullet_character_controller::remove(
      (vostok::physics::old_bullet_character_controller *)this,
      v2);
    vostok::physics::bullet_character_controller::insert(
      v3,
      *(btDynamicsWorld **)a2,
      *(btStackAlloc **)(*(_DWORD *)(a2 + 8) + 56));
LABEL_6:
    if ( s_cc_use_old_controller_value )
      goto LABEL_7;
LABEL_8:
    v4 = *(btDynamicsWorld **)a2;
    return *(_DWORD *)&v4->m_collisionObjects.m_ownsMemory != 0;
  }
  if ( *(_DWORD *)(*(_DWORD *)a2 + 20) )
  {
    vostok::physics::bullet_character_controller::remove(
      (vostok::physics::bullet_character_controller *)this,
      *(_DWORD *)a2);
    vostok::physics::old_bullet_character_controller::insert(
      *(vostok::physics::old_bullet_character_controller **)(*(_DWORD *)(a2 + 8) + 56),
      *(btDynamicsWorld **)(a2 + 4));
    goto LABEL_6;
  }
LABEL_7:
  v4 = *(btDynamicsWorld **)(a2 + 4);
  return *(_DWORD *)&v4->m_collisionObjects.m_ownsMemory != 0;
}
