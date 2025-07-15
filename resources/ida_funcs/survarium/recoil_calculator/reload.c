void __thiscall survarium::recoil_calculator::reload(survarium::recoil_calculator *this)
{
  survarium::weapon_recoil_calculator::reload(&this->m_weapon_calculator);
}
