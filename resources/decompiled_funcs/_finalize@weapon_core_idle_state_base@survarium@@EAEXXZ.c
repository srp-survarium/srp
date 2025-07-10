void __thiscall survarium::weapon_core_idle_state_base::finalize(survarium::weapon_core_idle_state_base *this)
{
  survarium::weapon_core::instant_idle_end(this->m_weapon);
}
