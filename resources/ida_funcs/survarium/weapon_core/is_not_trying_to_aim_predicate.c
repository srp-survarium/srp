BOOL __thiscall survarium::weapon_core::is_not_trying_to_aim_predicate(survarium::weapon_core *this)
{
  return !survarium::weapon_core::is_trying_to_aim(this);
}
