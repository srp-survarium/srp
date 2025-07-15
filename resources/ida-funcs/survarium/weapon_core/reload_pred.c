BOOL __thiscall survarium::weapon_core::reload_pred(survarium::weapon_core *this)
{
  survarium::weapon_core *v2; // ecx

  return survarium::weapon_core::is_trying_to_reload(this, (int)this) && survarium::weapon_core::can_reload(v2, this);
}
