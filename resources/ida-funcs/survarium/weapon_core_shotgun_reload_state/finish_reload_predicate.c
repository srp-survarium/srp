char __thiscall survarium::weapon_core_shotgun_reload_state::finish_reload_predicate(
        survarium::weapon_core_shotgun_reload_state *this)
{
  int v1; // esi
  survarium::game_camera *v2; // ecx
  survarium::inventory_item *v3; // ecx
  survarium::weapon_core *v4; // ecx
  char v6; // [esp+4h] [ebp-30h]
  survarium::weapon_user_animations_container **p_m_ammunition; // [esp+24h] [ebp-10h]
  char v9; // [esp+28h] [ebp-Ch]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+2Ch] [ebp-8h] BYREF
  char v11; // [esp+33h] [ebp-1h]

  v9 = 0;
  v1 = survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)this, (int)this->m_weapon);
  if ( v1 == survarium::weapon_core::get_magazine_capacity((survarium::weapon_core *)this, (int)this->m_weapon) )
    goto LABEL_10;
  v9 = 1;
  p_m_ammunition = (survarium::weapon_user_animations_container **)&this->m_weapon->m_ammunition;
  v10.m_object = 0;
  v2 = 0;
  if ( *p_m_ammunition )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
    v10.m_object = *p_m_ammunition;
    if ( v10.m_object )
      vostok::threading::interlocked_increment(&v10.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  survarium::weapon_user_dead_state::finalize(v2);
  if ( !survarium::inventory_item::amount(v3, (int)v10.m_object)
    || (v4 = (survarium::weapon_core *)(this->m_weapon->m_is_round_chambered + this->m_weapon->m_ammo_in_magazine),
        (_WORD)v4)
    && (survarium::weapon_core::get_target(v4, (int)this->m_weapon) == weapon_target_fire
     || survarium::weapon_core::get_target((survarium::weapon_core *)this, (int)this->m_weapon) == weapon_target_aim_fire) )
  {
LABEL_10:
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  v11 = v6;
  if ( (v9 & 1) != 0 )
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
  return v11;
}
