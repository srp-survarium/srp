void __thiscall survarium::jump_logic_state_landing::jump_logic_state_landing(
        survarium::jump_logic_state_landing *this,
        survarium::jump_logic *owner)
{
  survarium::jump_logic_base_state::jump_logic_base_state(this, owner);
  this->__vftable = (survarium::jump_logic_state_landing_vtbl *)&survarium::jump_logic_state_landing::`vftable';
  this->m_landing_type = jump_animations_part_land_run;
}
