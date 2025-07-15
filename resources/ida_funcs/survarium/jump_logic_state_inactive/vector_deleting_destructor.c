survarium::jump_logic_state_landing *__thiscall survarium::jump_logic_state_inactive::`vector deleting destructor'(
        survarium::jump_logic_state_landing *this,
        char a2)
{
  this->__vftable = (survarium::jump_logic_state_landing_vtbl *)&survarium::jump_logic_base_state::`vftable';
  vostok::animation::mixing::animation_interval::~animation_interval(&this->m_animation);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
