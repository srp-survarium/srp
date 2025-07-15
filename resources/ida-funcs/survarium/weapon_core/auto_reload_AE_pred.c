BOOL __thiscall survarium::weapon_core::auto_reload_AE_pred(survarium::weapon_core *this)
{
  survarium::weapon_core *v2; // ecx

  return survarium::weapon_core::can_reload(this, this)
      && (survarium::weapon_core::is_trying_to_reload(v2, (int)this)
       || !(this->m_ammo_in_magazine + this->m_is_round_chambered))
      && *(&this->m_logic->m_current_state[12].transitions.gap4 + 1);
}
