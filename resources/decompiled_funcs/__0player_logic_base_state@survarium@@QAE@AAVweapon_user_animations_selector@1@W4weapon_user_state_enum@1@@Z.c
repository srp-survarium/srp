void __thiscall survarium::player_logic_base_state::player_logic_base_state(
        survarium::player_logic_base_state *this,
        survarium::weapon_user_animations_selector *owner,
        survarium::weapon_user_state_enum weapon_user_state_id)
{
  vostok::ai::fsm_state::fsm_state(this);
  this->__vftable = (survarium::player_logic_base_state_vtbl *)&survarium::player_logic_base_state::`vftable';
  this->m_owner = owner;
  this->m_user = 0;
  this->m_weapon_user_state_id = weapon_user_state_id;
  this->m_is_weapon_weapon_visible = 1;
  this->m_is_smoothing_needed = 1;
  this->m_is_physics_transform_allowed = 1;
  this->m_is_ready_to_be_deactivated = 1;
}
