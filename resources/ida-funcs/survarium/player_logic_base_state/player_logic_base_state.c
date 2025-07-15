void __userpurge survarium::player_logic_base_state::player_logic_base_state(
        survarium::player_logic_base_state *this@<eax>,
        survarium::weapon_user_animations_selector *owner@<edx>,
        survarium::weapon_user_state_enum weapon_user_state_id)
{
  this->transitions.m_size = 0;
  this->transitions.m_first = 0;
  this->transitions.m_last = 0;
  this->m_owner = owner;
  this->__vftable = (survarium::player_logic_base_state_vtbl *)&survarium::player_logic_base_state::`vftable';
  this->m_user = 0;
  this->m_weapon_user_state_id = weapon_user_state_id;
  this->m_is_weapon_visible = 1;
  this->m_is_smoothing_needed = 1;
  this->m_is_physics_transform_allowed = 1;
  this->m_is_ready_to_be_deactivated = 1;
  this->m_is_sprinting = 0;
}
