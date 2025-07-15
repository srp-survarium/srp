void __thiscall survarium::grenade::pull_pin(survarium::grenade *this, unsigned int explode_time_ms)
{
  survarium::grenade_set *v3; // ecx

  survarium::grenade_core::pull_pin(this, explode_time_ms);
  survarium::grenade_set::preview(v3, (int)this->m_owner, 1);
}
