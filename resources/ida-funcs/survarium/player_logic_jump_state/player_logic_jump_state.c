void __thiscall survarium::player_logic_jump_state::player_logic_jump_state(
        survarium::player_logic_jump_state *this,
        survarium::weapon_user_animations_selector *owner)
{
  survarium::player_logic_base_state::player_logic_base_state(this, owner, type_jump);
  this->__vftable = (survarium::player_logic_jump_state_vtbl *)&survarium::player_logic_jump_state::`vftable';
  survarium::jump_logic::jump_logic(&this->m_logic, owner);
}
