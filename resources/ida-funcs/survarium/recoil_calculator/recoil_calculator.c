void __thiscall survarium::recoil_calculator::recoil_calculator(survarium::recoil_calculator *this)
{
  survarium::weapon_recoil_calculator::weapon_recoil_calculator(&this->m_weapon_calculator);
  survarium::character_recoil_calculator::character_recoil_calculator(&this->m_character_calculator);
  this->m_weapon = 0;
}
