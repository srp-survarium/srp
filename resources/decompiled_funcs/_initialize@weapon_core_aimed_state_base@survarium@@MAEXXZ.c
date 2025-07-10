void __thiscall survarium::weapon_core_aimed_state_base::initialize(survarium::weapon_core_aimed_state_base *this)
{
  ((void (__thiscall *)(survarium::weapon_core *, survarium::weapon_core_aimed_state_base *))this->m_weapon->instant_aim_start)(
    this->m_weapon,
    this);
}
