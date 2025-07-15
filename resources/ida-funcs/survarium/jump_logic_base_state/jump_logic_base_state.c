void __usercall survarium::jump_logic_base_state::jump_logic_base_state(
        survarium::jump_logic_base_state *this@<eax>,
        survarium::jump_logic *owner@<edx>)
{
  this->transitions.m_size = 0;
  this->transitions.m_first = 0;
  this->transitions.m_last = 0;
  this->__vftable = (survarium::jump_logic_base_state_vtbl *)&survarium::jump_logic_base_state::`vftable';
  this->m_jump_logic = owner;
  this->m_user = 0;
  this->m_animation.first.m_object = 0;
  this->m_animation.second.m_object = 0;
  this->m_interval_id_to_wait_for = -1;
  this->m_is_jump_finished = 0;
}
