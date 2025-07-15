char __thiscall survarium::weapon_core_shotgun_reload_state::finish_reload_predicate(
        survarium::weapon_core_shotgun_reload_state *this)
{
  survarium::weapon_core *m_weapon; // eax
  unsigned __int16 m_ammo_in_magazine; // cx
  char v4; // bl
  survarium::weapon_core *v5; // ecx
  survarium::weapon_core *v6; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  m_weapon = this->m_weapon;
  m_ammo_in_magazine = m_weapon->m_ammo_in_magazine;
  v4 = 0;
  v9 = 0;
  if ( m_ammo_in_magazine == m_weapon->m_magazine_capacity
    || (v5 = this->m_weapon,
        v9 = 1,
        !LOWORD(survarium::weapon_core::ammunition(v5, &v8)->m_object->m_lods[0].m_emitter_instance_list.m_last))
    || (unsigned __int8)survarium::weapon_core_shotgun_reload_state::player_wants_to_fire_predicate(this)
    || (v6 = this->m_weapon, v6->m_ammo_in_magazine + v6->m_is_round_chambered)
    && (v6->m_user->m_input.actions_mask & 0x100) != 0 )
  {
    v4 = 1;
  }
  if ( (v9 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v8);
  return v4;
}
