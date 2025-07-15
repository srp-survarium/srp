char __thiscall survarium::weapon_core::ready_to_reload(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  survarium::inventory_item *v2; // ecx
  char v4; // [esp+4h] [ebp-3Ch]
  int v7; // [esp+2Eh] [ebp-12h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+34h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+38h] [ebp-8h] BYREF
  char v10; // [esp+3Fh] [ebp-1h]

  v7 = (unsigned __int16)(this->m_is_round_chambered + this->m_ammo_in_magazine);
  if ( (unsigned __int16)v7 == survarium::weapon_core::maximum_ammo_in_weapon(this) )
    goto LABEL_16;
  BYTE2(v7) |= 1u;
  v9.m_object = 0;
  if ( this->m_ammunition.m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
    v9.m_object = (survarium::weapon_user_animations_container *)this->m_ammunition.m_object;
    if ( v9.m_object )
      vostok::threading::interlocked_increment(&v9.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  if ( !(v9.m_object
       ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
       : 0) )
    goto LABEL_16;
  BYTE2(v7) |= 2u;
  v8.m_object = 0;
  v1 = 0;
  if ( this->m_ammunition.m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
    v8.m_object = (survarium::weapon_user_animations_container *)this->m_ammunition.m_object;
    if ( v8.m_object )
      vostok::threading::interlocked_increment(&v8.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  survarium::weapon_user_dead_state::finalize(v1);
  if ( !survarium::inventory_item::amount(v2, (int)v8.m_object)
    || this->m_is_in_sprint_transition
    || survarium::weapon_user_animations_selector::is_in_jump(&this->m_user_animations_selector) )
  {
LABEL_16:
    v4 = 0;
  }
  else
  {
    v4 = 1;
  }
  v10 = v4;
  if ( (v7 & 0x20000) != 0 )
  {
    BYTE2(v7) &= ~2u;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  }
  if ( (v7 & 0x10000) != 0 )
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  return v10;
}
