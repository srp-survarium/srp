void __thiscall survarium::pistol_weapon_core_aimed_fire_state::initialize(
        survarium::pistol_weapon_core_aimed_fire_state *this)
{
  survarium::weapon_core *m_weapon; // ecx
  bool v2; // [esp+0h] [ebp-Ch]

  survarium::weapon_core_aimed_fire_state_base::initialize(this);
  m_weapon = this->m_weapon;
  if ( m_weapon->m_bullets_in_queue )
    v2 = survarium::weapon_core::ammo_in_magazine((survarium::weapon_core *)this, (int)this->m_weapon) == 1;
  else
    v2 = survarium::weapon_core::ammo_in_magazine(m_weapon, (int)this->m_weapon) == 0;
  this->m_weapon_animation_index = v2;
}
