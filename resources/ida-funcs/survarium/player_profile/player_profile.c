void __thiscall survarium::player_profile::player_profile(survarium::player_profile *this)
{
  survarium::inventory_item_descr *slots; // eax
  int i; // ecx

  this->account_id = 0;
  this->profile_id = 0;
  slots = this->slots;
  for ( i = 22; i >= 0; --i )
  {
    slots->condition_or_stack = 0;
    slots->amount_in_inventory = 0;
    slots->id = 0;
    slots->dict_id = 0;
    ++slots;
  }
  this->team = team_undefined;
  this->is_local = 0;
  survarium::player_params_modifiers_container::player_params_modifiers_container(
    (survarium::player_params_modifiers_container *)i,
    (char *)&this->modifiers);
  this->profile_name[0] = 0;
}
