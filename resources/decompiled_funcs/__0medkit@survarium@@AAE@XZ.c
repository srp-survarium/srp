void __thiscall survarium::medkit::medkit(survarium::medkit *this)
{
  survarium::inventory_item::inventory_item(this, use_silent);
  this->__vftable = (survarium::medkit_vtbl *)&survarium::medkit::`vftable';
  this->m_influences = 0;
  this->m_influences_count = 0;
  this->m_affects = 0;
  this->m_affects_count = 0;
  this->m_damage_protect = 0;
  this->m_damage_protect_count = 0;
  this->m_config_activity_time_ms = 1;
  this->m_config_delay_ms = 0;
  this->m_active = 0;
  this->m_add_stamina_regen = *(float *)&FLOAT_0_0;
}
