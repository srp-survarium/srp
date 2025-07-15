void __thiscall survarium::artefact_onyx_core::reduce_incoming_damage(
        survarium::artefact_onyx_core *this,
        survarium::hit_type_enum hit_type,
        float *amount,
        float *arp)
{
  float *v4; // eax
  float v5; // xmm0_4
  float m_damage_to_absorb; // xmm1_4

  if ( this->m_config.hit_type == hit_type )
  {
    if ( this->m_state == artefact_state_picked_passive )
    {
      *amount = (float)(this->m_config.passive.damage_add + *amount) * this->m_config.passive.damage_mul;
      v4 = arp;
      v5 = (float)(this->m_config.passive.armor_piercing_add + *arp) * this->m_config.passive.armor_piercing_mul;
    }
    else
    {
      m_damage_to_absorb = *amount
                         - (float)((float)(this->m_config.active.damage_add + *amount) * this->m_config.active.damage_mul);
      if ( this->m_damage_to_absorb <= m_damage_to_absorb )
        m_damage_to_absorb = this->m_damage_to_absorb;
      *amount = *amount - m_damage_to_absorb;
      v4 = arp;
      v5 = (float)(this->m_config.active.armor_piercing_add + *arp) * this->m_config.active.armor_piercing_mul;
    }
    *v4 = v5;
  }
}
