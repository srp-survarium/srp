void __thiscall survarium::weapon_core_melee_state::finalize(survarium::weapon_core_melee_state *this)
{
  survarium::weapon_core **p_m_weapon; // esi
  survarium::base_player *v3; // ecx

  p_m_weapon = &this->m_weapon;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
    (const void *)1,
    (int)this);
  survarium::base_player::unsubscribe_animation_player(v3, (int)(*p_m_weapon)->m_user, "shoot", (int)this);
}
