survarium::jump_logic_state_start *__thiscall survarium::jump_logic_state_start::`scalar deleting destructor'(
        survarium::jump_logic_state_start *this,
        char a2)
{
  vostok::animation::mixing::animation_interval::~animation_interval(&this->m_preface_animation);
  this->__vftable = (survarium::jump_logic_state_start_vtbl *)&survarium::jump_logic_base_state::`vftable';
  vostok::animation::mixing::animation_interval::~animation_interval(&this->m_animation);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
