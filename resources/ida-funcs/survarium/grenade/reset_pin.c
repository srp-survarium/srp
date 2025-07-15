void __thiscall survarium::grenade::reset_pin(survarium::grenade *this)
{
  survarium::grenade_set *v2; // ecx

  survarium::grenade_core::reset_pin(this);
  survarium::grenade_set::preview(v2, (int)this->m_owner, 0);
}
