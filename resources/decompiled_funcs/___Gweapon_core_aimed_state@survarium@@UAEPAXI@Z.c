survarium::weapon_core_aimed_state *__thiscall survarium::weapon_core_aimed_state::`scalar deleting destructor'(
        survarium::weapon_core_aimed_state *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)this->m_weapon_animations,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  survarium::weapon_core_base_state::~weapon_core_base_state(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
