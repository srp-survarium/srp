void __thiscall survarium::recoil_calculator::set_weapon(
        survarium::recoil_calculator *this,
        survarium::weapon_core *weapon)
{
  this->m_weapon = weapon;
  survarium::weapon_recoil_calculator::set_weapon(&this->m_weapon_calculator, weapon);
}
