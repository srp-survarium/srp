BOOL __thiscall survarium::weapon_core::chamber_a_round_on_reload_break_pred(survarium::weapon_core *this)
{
  survarium::weapon_core *v2; // ecx

  return survarium::weapon_core::chamber_a_round_pred(this)
      && (unsigned __int8)survarium::weapon_core::reload_break_pred(v2, (int)this);
}
