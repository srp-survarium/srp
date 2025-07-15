BOOL __thiscall survarium::weapon_user_animations_selector::not_sprint_predicate(
        survarium::weapon_user_animations_selector *this)
{
  survarium::weapon_user_animations_selector *v2; // ecx

  return !survarium::weapon_user_animations_selector::sprint_predicate(this)
      || survarium::weapon_user_animations_selector::is_trying_to_aim(v2, (int)this);
}
