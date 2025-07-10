void __thiscall survarium::weapon_core_fire_state_base::execute(survarium::weapon_core_fire_state_base *this)
{
  survarium::weapon_core_base_state::execute(this);
  this->m_animation_has_been_ended = 0;
}
