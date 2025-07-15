survarium::double_barreled_weapon_core_aimed_idle_state *__thiscall survarium::double_barreled_weapon_core_idle_state::`scalar deleting destructor'(
        survarium::double_barreled_weapon_core_aimed_idle_state *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)this->m_weapon_animations,
    4u,
    12,
    (void (__thiscall *)(void *))vostok::animation::mixing::animation_interval::~animation_interval);
  survarium::weapon_core_base_state::~weapon_core_base_state(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
