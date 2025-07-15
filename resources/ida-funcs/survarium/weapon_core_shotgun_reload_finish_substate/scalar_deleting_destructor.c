survarium::weapon_core_shotgun_reload_start_substate *__thiscall survarium::weapon_core_shotgun_reload_finish_substate::`scalar deleting destructor'(
        survarium::weapon_core_shotgun_reload_start_substate *this,
        char a2)
{
  survarium::weapon_core_shotgun_reload_base_substate::~weapon_core_shotgun_reload_base_substate(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
