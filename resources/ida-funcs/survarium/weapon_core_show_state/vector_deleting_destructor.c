survarium::weapon_core_hide_state *__thiscall survarium::weapon_core_show_state::`vector deleting destructor'(
        survarium::weapon_core_hide_state *this,
        char a2)
{
  survarium::weapon_core_show_state::~weapon_core_show_state((survarium::weapon_core_show_state *)this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
