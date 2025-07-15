BOOL __thiscall survarium::weapon_core::auto_reload_AE_not_fire_pred(survarium::weapon_core *this)
{
  return survarium::weapon_core::auto_reload_AE_pred(this) && !survarium::weapon_core::fire_pred(this);
}
