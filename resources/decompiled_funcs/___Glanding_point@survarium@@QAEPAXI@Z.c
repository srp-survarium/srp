survarium::landing_point *__thiscall survarium::landing_point::`scalar deleting destructor'(
        survarium::landing_point *this,
        char a2)
{
  vostok::animation::mixing::animation_interval::~animation_interval(&this->m_end_animation);
  vostok::animation::mixing::animation_interval::~animation_interval(&this->m_start_animation);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
