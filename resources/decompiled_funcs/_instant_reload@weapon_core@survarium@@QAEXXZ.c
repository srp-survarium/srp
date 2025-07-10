void __thiscall survarium::weapon_core::instant_reload(survarium::weapon_core *this)
{
  this->m_aimed = 0;
  survarium::weapon_core::load_magazine(this);
  this->on_reload(this);
  survarium::recoil_calculator::reload(&this->m_recoil_calculator);
  survarium::dispersion_calculator::reload(&this->m_dispersion_calculator);
  survarium::weapon_core::reset_fire_queue(this);
}
