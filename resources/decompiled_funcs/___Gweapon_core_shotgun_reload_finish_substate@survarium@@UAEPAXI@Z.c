survarium::weapon_core_shotgun_reload_finish_substate *__thiscall survarium::weapon_core_shotgun_reload_finish_substate::`scalar deleting destructor'(
        survarium::weapon_core_shotgun_reload_finish_substate *this,
        char a2)
{
  survarium::weapon_core_shotgun_reload_one_round_substate::~weapon_core_shotgun_reload_one_round_substate((survarium::weapon_core_shotgun_reload_start_substate *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
