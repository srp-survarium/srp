void __thiscall survarium::recoil_calculator::fire(survarium::recoil_calculator *this)
{
  survarium::weapon_recoil_calculator::fire(&this->m_weapon_calculator);
}
