void __thiscall survarium::player_profile::player_profile(survarium::player_profile *this)
{
  survarium::skill_booster *boosters; // edi

  boosters = this->boosters;
  this->account_id = 0;
  this->profile_id = 0;
  `vector constructor iterator'(
    (char *)this->boosters,
    8u,
    11,
    (void *(__thiscall *)(void *))survarium::skill_booster::skill_booster);
  `vector constructor iterator'(
    (char *)this->slots,
    0x10u,
    19,
    (void *(__thiscall *)(void *))survarium::profile_slot::profile_slot);
  this->team = team_undefined;
  this->is_local = 0;
  this->profile_name[0] = 0;
  memset(&boosters->id, 0, 0x58u);
}
